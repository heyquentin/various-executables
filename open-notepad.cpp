/*

Simple DLL that opens Notepad
Compile with: cl.exe /D_USRDLL /D_WINDLL open-notepad.cpp /MT /link /DLL /OUT:notepad.dll
Run with: rundll32 notepad.dll,RunME

*/

#include <Windows.h>
#pragma comment (lib, "user32.lib")


BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {

    switch (ul_reason_for_call)  {
    case DLL_PROCESS_ATTACH:
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
__declspec(dllexport) BOOL WINAPI RunME(void) {
	
	/*
	MessageBox(NULL,"This is a message box","More text",MB_OK);
	*/
	
	STARTUPINFO si = { sizeof(STARTUPINFO) };
    si.cb = sizeof(si);
    //si.dwFlags = STARTF_USESHOWWINDOW; <--- these will hide the window
    //si.wShowWindow = SW_HIDE; <--- these will hide the window
    PROCESS_INFORMATION pi;
    CreateProcessA("c:\\windows\\system32\\notepad.exe", NULL , NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
	 
		 return TRUE;
	}
}
