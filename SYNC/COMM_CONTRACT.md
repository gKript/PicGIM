# Contratto di comunicazione Gim <-> PicGIM

Copia identica in `PicGim/SYNC/` e `Gim/SYNC/`. Se cambi qualcosa di qui sotto
o del codice che lo implementa, aggiorna il contratto in ENTRAMBI i repo e
aggiungi una voce in `SYNC_LOG.md` (stessa voce in entrambi).
Verifica: `powershell -ExecutionPolicy Bypass -File SYNC/check_sync.ps1`.

Stato lato Gim: **nessuna implementazione**. Esiste solo `gim_picgim_obj`
(stub vuoto in `include/gim_picgim.h`). Il lato PC va ancora scritto.

## 1. SSP - Simple Serial Protocol  (PicGIM: `pgim_ssp.h/.c`)
Handshake byte per byte (ogni byte inviato e' confermato da una risposta):

| Passo | Mittente | Byte | Risposta attesa |
|---|---|---|---|
| Header | TX | `'K'` | `'k'` |
| Lunghezza | TX | HB, LB (uint16 big-endian) | nessuna |
| Dati | TX | N byte | nessuna |
| CRC (se `PG_SSP_CRC_ENABLE`) | TX | CRC-8 dei dati | `PG_SSP_OK_CRC` (=55) oppure `PG_SSP_ERROR_CRC` (=54) |
| Footer | TX | `'X'` | `'x'` |

- Lunghezza dati: 1..65535.
- CRC-8: init `0x00`, riflesso (LSB first), polinomio `0x8C` (Dallas/Maxim), nessun xorout.
- Codici errore (`enum pg_ssp_error`, base 48 = '0'): NO_ERROR 48, WRONG_HEADER 49,
  WRONG_FOOTER 50, WRONG_HEADER_REPLY 51, WRONG_FOOTER_REPLY 52, RX_TIMEOUT 53, ERROR_CRC 54, OK_CRC 55.

## 2. GCP - General Communication Protocol  (PicGIM: `pgim_gcp.h/.c`, `pgim_gcp_setup_public.h`, v0.1)
Letto da `pgim_gcp.c` (righe di riferimento tra parentesi). Verificato sul codice, non su un trasferimento reale.

### 2.1 Livello di comando (escape + control byte)
Ogni comando: TX `'>'` -> RX `'^'`; poi TX control byte -> RX control + 32 (minuscolo).
Ogni byte e' quindi confermato (`pg_gcp_tx_control_byte`, ~1407). Reply diverso dall'atteso: errore `TX_CONTROL_FAILED`.
Timeout: escape = `TIMEOUT_MS_TX` 5000 ms; reply del control byte = `TIMEOUT_MS_DIAL` 1000 ms;
attesa CRC = `TIMEOUT_MS_CRC` 10000 ms; attesa comando lato RX = `TIMEOUT_MS_RX` 5000 ms.
Con `PG_GCP_AUTORESET_TIMEOUT` un timeout provoca un reset (TX: remoto+locale, RX: solo locale).

### 2.2 Byte di controllo (tutti preceduti da `'>'`)
| Cmd | Reply | Significato | Payload dopo il reply |
|---|---|---|---|
| `E` | `e` | engage (apre sessione) | nessuno |
| `X` | `x` | engage_end (chiude; solo fuori da data mode) | nessuno |
| `V` | `v` | version | 8 byte, vedi 2.3 |
| `C` | `c` | config | 1 byte numero config, eco dal RX, poi `PG_OK` dal TX |
| `D` | `d` | data (entra in data mode) | dati grezzi |
| `Z` | `z` | data_end (esce da data mode) | nessuno |
| `K` | `k` | crc | 4 byte CRC, ciascuno confermato da `PG_GCP_WAITING_DATA` (101), poi 1 byte esito |
| `S` | `s` | status_sync | da verificare (`pgim_gcp.c:999`) |
| `M` | `m` | status_mod | da verificare (`:1085`) |
| `Q` | `q` | request | da verificare (`:1894`) |
| `G` | `g` | streaming ON/OFF | da verificare (`:1171`) |
| `R` | `r` | reset (remoto+locale) | da verificare (`:366`) |
| `A` | `a` | command | 1 byte comando, da verificare (`:1951`) |

Dispatcher RX (`pg_gcp_rx`, ~1570): fuori sessione accetta solo R, V, A, E. In sessione: C sempre;
in data mode D->Z (data_end) e `'>'` come dato; fuori data mode D, X, S, M, Q, K.

### 2.3 Sequenza di una trasmissione (`pg_gcp_send`, ~2032)
`engage` (invia prima VERSION, poi ENGAGE) -> `data` -> `config(n)` -> dati -> `data_end`
-> [`status_mod(FULL)` se stringa] -> [`crc` se richiesto] -> `engage_end` (a cura dell'utente).
- Version: TX `V`, poi 8 byte: nome app (4 caratteri), app major, app minor, PicGIM major, PicGIM minor.
  RX confronta con i propri (`PG_GCP_APPLICATION_NAME` default `"USER"`, app 0.1, `PG_MAJOR`/`PG_MINOR`)
  e risponde 1 byte `PG_OK` se tutto coincide; altrimenti non risponde (il TX va in timeout).
- Dati `PG_GCP_BUFFER`: `xbuffer_length` byte, lunghezza fissa per config.
- Dati `PG_GCP_STRING`: caratteri + terminatore `0x00`. Un dato `'>'` va raddoppiato
  (il RX vede `'>'`, risponde `'^'`; se il byte dopo e' ancora `'>'` lo salva come dato: `pg_gcp_rx_escape`).
- I byte di dato non hanno ack. Fuori dalla data mode i byte non-escape sono ignorati.
- Config 0..16: ognuna e' un buffer di lunghezza e modo fissi, definiti in `pgim_gcp_setup_public.h`
  (es. config 01 = 4 byte). Lato PC servira' la stessa tabella config -> lunghezza/modo.

### 2.4 CRC GCP
Campo di 4 byte (`_pg_Uint32_VAL.v[0..3]`), inviati in ordine di indice 0..3 (PIC18 little-endian: `v[0]` = byte meno significativo).
**ATTENZIONE: l'algoritmo attuale NON e' un CRC-32** (`pg_gcp_crc32_calc`, ~1848): parte da 0 e per ogni byte
fa `if (m % 1) crc -= b; else crc *= b;`. Poiche' `m % 1` e' sempre 0 esegue sempre `crc *= b`, quindi il
risultato e' sempre `0x00000000`. Il controllo passa sempre ed e' inutile.
**DECISO (2026-11-20): CRC-32 IEEE 802.3** (zlib/Ethernet): poly riflesso `0xEDB88320`, init `0xFFFFFFFF`, xorout `0xFFFFFFFF`, input e output riflessi.
Vettore di test: CRC32("123456789") = `0xCBF43926`; sul filo i 4 byte vanno `26 39 F4 CB` (meno significativo per primo, `v[0]` PIC18). Da implementare identico in PicGIM (`pg_gcp_crc32_calc`) e in Gim: **stato PicGIM: FATTO in `pgim_gcp.c` (algoritmo verificato sul vettore, NON compilato con C18 ne' provato su PIC); Gim: DA FARE**.
Lunghezza su cui si calcola: TX = `xbuffer_length`; RX = `xbuffer_index - 1`.
Esito: `PG_OK` se coincide, altrimenti `PG_GCP_ERROR_CRC_FAILED`.

### 2.5 Costanti
- Ritorni `PG_OK`/`PG_NOK`: valori in `pgim_defines.h`, DA VERIFICARE (il byte di esito del CRC e' `PG_OK`).
- `enum _pg_gcp_return_code_enum` base 100: DUMMY 100, WAITING_DATA 101, STATUS_WAITING 102, STREAMING_ON 103,
  STREAMING_OFF 104, poi gli errori nell'ordine di `pgim_gcp.h`.
- Stato buffer: `e` empty, `i` incomplete, `f` full, `c` crc, `r` read, `?` unknown.

## 3. Problemi noti lato PicGIM (da non replicare in Gim)
- **GCP CRC sempre 0** (vedi 2.4). RISOLTO in PicGIM il 2026-11-20.
- **`pg_gcp_tx_string`** (~1541): `sidx` si incrementa solo quando il carattere e' `'>'`, quindi con una
  stringa normale il ciclo `while(tstring[sidx])` non termina.
- **SSP `pg_ssp_tx`/`pg_ssp_rx`**: indice `_pg_Uint8` confrontato con lunghezza uint16: oltre 255 byte il ciclo non termina.
- **SSP `pg_ssp_tx`**: con CRC chiama `pg_lcd_hd44780_put_char` incondizionatamente (debug lasciato nel codice).
- `pg_gcp_send_byte_serial` dichiara `_pg_Uint8` ma non ritorna nulla.
- `pg_gcp_engage`/`pg_gcp_rx_engage` definite due volte (~740 e ~2472, blocchi `#if` diversi): verificare quale e' attivo.
- `pg_gcp_flag_set/get` usano il tipo `_pg_Uin8` (refuso).

## 4. Altro materiale condiviso da verificare
| Tema | PicGIM | Gim |
|---|---|---|
| Endianness | `pgim_endian.c` | da cercare |
| Tipi custom | Custom-Type | `gim_custom_type.h` |
| Checksum | `pg_crc_8`, crc32 GCP | `gim_checksum.h` |
