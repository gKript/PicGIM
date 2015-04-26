; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "PicGIM"
#define MyAppVersion "0.5"
#define MyAppPublisher "gKript.org"
#define MyAppURL "http://www.gKript.org/"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{48068B49-786E-4552-8199-98DAC34D713B}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName=.\{#MyAppName}
DefaultGroupName=PicGIM 0.5
AllowNoIcons=yes
LicenseFile=..\LICENSE
OutputBaseFilename=PicGIM_05_installer
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english";    MessagesFile: "compiler:Default.isl"
Name: "italian";    MessagesFile: "compiler:Languages\Italian.isl"

[Types]
; Name: "fullx";  Description: "PicGIM for Mplab X";
; Name: "full8";  Description: "PicGIM for Mplab 8";
Name: "custom";   Description: "PicGIM custom installation"; Flags: iscustom

[Components]
Name: "license"; Description: "PicGIM license"; Types: custom; Flags: fixed
Name: "sources"; Description: "PicGIM sources"; Types: custom;
Name: "project"; Description: "PicGIM project files"; Types: custom;
Name: "project\mp8"; Description: "Mplab 8 files";  Flags: exclusive
Name: "project\mpx"; Description: "Mplab X files";  Types: custom; Flags: exclusive
Name: "docs"; Description: "PicGIM documentation";

[Files]
Source: "..\LICENSE"; DestDir: "{app}"; Components: license; Flags: ignoreversion
Source: "..\PicGIM_Documentation\*"; DestDir: "{app}\PicGIM_Documentation"; Components: docs; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\PicGIM_MPlab_8\*"; DestDir: "{app}\PicGIM_MPlab_8"; Components: project\mp8; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\PicGIM_MPlab_X\*"; DestDir: "{app}\PicGIM_MPlab_X"; Components: project\mpx; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\PicGIM_Sources\*"; DestDir: "{app}\PicGIM_Sources"; Components: sources; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\gKript.org Web Site"; Filename: "{#MyAppURL}"
Name: "{group}\Submit a bug"; Filename: "https://github.com/gKript/PicGIM_05/issues/new"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"

