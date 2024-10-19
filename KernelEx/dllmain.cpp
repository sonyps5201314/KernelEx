// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Exports.h"

#pragma comment(linker, "/ENTRY:DllMainCRTStartupForYY_Thunks")

EXTERN_C const BOOL __YY_Thunks_Disable_Rreload_Dlls = TRUE;

// 直接通过GetModuleHandleW获取，改选项非常危险，如果dll尚未加载会将不会加载！！！
#define USING_GET_MODULE_HANDLE 0x00000001
// 以 LOAD_LIBRARY_AS_DATAFILE 标记作为资源加载。
#define LOAD_AS_DATA_FILE 0x00000002
// 直接使用LoadLibrary，该加载模式存在劫持风险，使用前请确认该DLL处于KnownDll。
#define USING_UNSAFE_LOAD 0x00000004
HMODULE __fastcall YY_Thunks_MyCustomLoadLibrary(const wchar_t* module_name, DWORD Flags)
{
	HMODULE new_handle = NULL;

	if (Flags & USING_GET_MODULE_HANDLE)
	{
		new_handle = GetModuleHandleW(module_name);
	}
	else
	{
		// 始终从系统目录加载
		wchar_t szStringBuffer[MAX_PATH];
		szStringBuffer[0] = 0;
		UINT _cchSystemPath = GetSystemDirectoryW(szStringBuffer, _countof(szStringBuffer));
		if (_cchSystemPath > 0 && _cchSystemPath < _countof(szStringBuffer))
		{
			StringCchCatW(szStringBuffer, _countof(szStringBuffer), L"\\");
			StringCchCatW(szStringBuffer, _countof(szStringBuffer), module_name);
			module_name = szStringBuffer;
		}

		if (Flags & LOAD_AS_DATA_FILE)
		{
			new_handle = LoadLibraryExW(module_name, NULL, LOAD_LIBRARY_AS_DATAFILE);
		}
		else if (Flags & USING_UNSAFE_LOAD)
		{
			new_handle = LoadLibraryExW(module_name, NULL, 0);
		}
		else
		{
			new_handle = LoadLibraryW(module_name);
		}
	}

	return new_handle;
}
EXTERN_C const void* __pfnYY_Thunks_CustomLoadLibrary = YY_Thunks_MyCustomLoadLibrary;

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