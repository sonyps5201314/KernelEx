// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Exports.h"

#pragma comment(linker, "/ENTRY:DllMainCRTStartupForYY_Thunks")

EXTERN_C const BOOL __YY_Thunks_Disable_Rreload_Dlls = TRUE;

#if _MSC_VER<=1500
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short const i);
#pragma function(_byteswap_ushort)
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short const i)
{
	unsigned short j;
	j = (i << 8);
	j += (i >> 8);
	return j;
}
#endif

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}