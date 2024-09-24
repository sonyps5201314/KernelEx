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

//有实现的
HWCT WINAPI OpenThreadWaitChainSession(DWORD flags, PWAITCHAINCALLBACK callback)
{
	FIXME("flags %ld, callback %p stub!\n", flags, callback);
	SetLastError(ERROR_NOT_SUPPORTED);
	return NULL;
}

BOOL WINAPI GetThreadWaitChain(HWCT handle, DWORD_PTR ctx, DWORD flags, DWORD thread_id, DWORD* node_count,
	WAITCHAIN_NODE_INFO* node_info_arr, BOOL* is_cycle)
{
	FIXME("handle %p, ctx %Ix, flags %ld, thread_id %ld, node_count %p, node_info_arr %p, is_cycle %p stub!\n",
		handle, ctx, flags, thread_id, node_count, node_info_arr, is_cycle);
	SetLastError(ERROR_NOT_SUPPORTED);
	return FALSE;
}

//Stub的
VOID WINAPI CloseThreadWaitChainSession(
	__in  HWCT WctHandle
)
{
	FIXME("(%s): stub\n", __FUNCTION__);
	SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
	return;
}

BOOL WINAPI GetNamedPipeClientComputerNameW(
	__in   HANDLE Pipe,
	__out  LPWSTR ClientComputerName,
	__in   ULONG ClientComputerNameLength
)
{
	FIXME("(%s): stub\n", __FUNCTION__);
	SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
	return FALSE;
}

BOOL WINAPI GetNamedPipeClientProcessId(
	__in   HANDLE Pipe,
	__out  PULONG ClientProcessId
)
{
	FIXME("(%s): stub\n", __FUNCTION__);
	SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
	return FALSE;
}

BOOL WINAPI QueryActCtxSettingsW(DWORD flags, HANDLE ctx, const WCHAR* ns,
	const WCHAR* settings, WCHAR* buffer, SIZE_T size,
	SIZE_T* written)
{
	FIXME("(%s): stub\n", __FUNCTION__);
	SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
	return FALSE;
}