// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "LibStHook.h"

#pragma comment(lib, "shlwapi.lib")

HMODULE g_hDllModule = NULL;
char szPath[MAX_PATH] = { 0 };

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_hDllModule = hModule;
		GetModuleFileName(NULL, szPath, MAX_PATH);
		PathStripPath(szPath);

		if (strcmp(szPath, "StudentMain.exe") != 0) break;
		SetupDebugConsole();
		ObtainBasicInformation();
		if (!SetStModulesProc()) return FALSE;
		if (SetAPIHooks()) MessageBox(NULL, "上钩了", "StudentRock", MB_OK);
		else return FALSE;
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (strcmp(szPath, "StudentMain.exe") != 0) break;
		UnsetAPIHooks();
		break;
	}
	return TRUE;
}
