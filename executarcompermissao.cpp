#include <iostream>
#include <Windows.h>
#include <Shellapi.h>

int main()
{
    char *application = "c:\\windows\\system32\\notepad.exe"; // substitua pelo aplicativo (script) que você quer executar
    ShellExecute(NULL, "runas", application, NULL, NULL, SW_SHOWDEFAULT);
}
