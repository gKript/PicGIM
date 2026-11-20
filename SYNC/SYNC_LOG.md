# SYNC_LOG - modifiche al contratto Gim <-> PicGIM
Formato: `data | repo che ha cambiato | cosa | stato altro repo (da allineare / allineato)`
Copia identica in entrambi i repo. Piu' recente in alto.

2026-11-20 | PicGIM | pg_gcp_crc32_calc riscritta: CRC-32 IEEE bitwise (vettore 0xCBF43926 ok). Non compilata con C18 | Gim: da implementare; PicGIM e Gim ora NON compatibili finche Gim non ha il CRC
2026-11-20 | PicGIM+Gim | Deciso CRC GCP = CRC-32 IEEE 802.3 (vettore 0xCBF43926 su "123456789", byte sul filo little-endian) | PicGIM: da implementare in pg_gcp_crc32_calc; Gim: da implementare
2026-11-20 | PicGIM+Gim | Contratto: GCP documentato (comandi, sequenza, timeout, version, CRC). Trovati bug: CRC GCP sempre 0, tx_string non termina, SSP >255 byte | Gim: da implementare; decisione aperta sul CRC-32
2026-11-20 | PicGIM+Gim | Creato contratto iniziale (SSP completo, GCP parziale) e script check_sync | Gim: da implementare (nessun codice SSP/GCP lato PC)
