#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

void main()
{
	STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    char arg[] = "cmd.exe /c E:/Softwares/program.exe";
    wchar_t text[500];
    mbstowcs(text, arg, strlen(arg) + 1);
    LPWSTR command = text;
    while (1)
    {
        CreateProcess(NULL, command, NULL, NULL, 0,
            CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    }
}
