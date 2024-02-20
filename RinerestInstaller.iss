; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Rinerest"
#define MyAppName_x32 "Rinerest x32"
#define MyAppVersion "0.0.0.6"
#define MyAppPublisher "Rinemest"
#define MyAppURL "https://rinemest.itch.io/rinerest"
#define MyAppExeName_x32 "Rinerest-x32.exe"
#define MyAppExeName "Rinerest.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{EA2E254C-83B5-45E9-B972-26874DDB36C2}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
; Remove the following line to run in administrative install mode (install for all users.)
PrivilegesRequired=lowest
PrivilegesRequiredOverridesAllowed=dialog
OutputBaseFilename=RinerestInstaller
SetupIconFile=C:\GLOBAL_PROJECT\Rinegine\icon.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\GLOBAL_PROJECT\Rinegine\files\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\GLOBAL_PROJECT\Rinegine\files\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{autoprograms}\{#MyAppName_x32}"; Filename: "{app}\{#MyAppExeName_x32}"
Name: "{autodesktop}\{#MyAppName_x32}"; Filename: "{app}\{#MyAppExeName_x32}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName_x32}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
