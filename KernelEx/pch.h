// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

#define _KERNEL32_
#define _ADVAPI32_

#define _ATL_XP_TARGETING

// 添加要在此处预编译的标头
#include "framework.h"

#include <strsafe.h>

#include <Wct.h>

//JKSDK
#define __DO_NOT_USE_JKSDK_OUTPUTDEBUGSTRING__
#define __DO_NOT_USE_JKSDK_TRACE__
#define __DO_NOT_USE_JKSDK_ASSERT__
#define __DO_NOT_USE_COM__
//#define __DO_NOT_USE_ATL_CSTRING__
#define __DO_NOT_USE_JKSDK_CDLG__
#define __DO_NOT_USE_JKSDK_AUTOLOCK__
#define __DO_NOT_USE_JKSDK_SHOWCALLSTACKTRACK_SOURCEFILEPATHMAPPINGS__
#include "F:\MyCppProjects\JKSDK\Lib\JKSDK.H"

//ntdll.h++
//wine
#define TRACE ATLTRACE
#define WARN ATLTRACE
#define FIXME ATLTRACE

#define sprintfW wsprintfW
#define strlenW wcslen
#define strcatW wcscat
#define strncmpiW _wcsnicmp

#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
#define __WINE_ALLOC_SIZE(x) __attribute__((__alloc_size__(x)))
#else
#define __WINE_ALLOC_SIZE(x)
#endif

EXTERN_C const char* debugstr_an(const char* s, int n);
EXTERN_C const char* debugstr_wn(const WCHAR* s, int n);

EXTERN_C const char* debugstr_a(const char* s);
EXTERN_C const char* debugstr_w(const WCHAR* s);

#endif //PCH_H
