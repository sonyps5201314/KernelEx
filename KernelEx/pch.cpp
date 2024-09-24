// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

//JKSDK
#include "F:\MyCppProjects\JKSDK\Lib\JKSDK.CPP"

CAutoCritSec g_CS_for_debugstr_an;
CAutoCritSec g_CS_for_debugstr_wn;

EXTERN_C const char* debugstr_an(const char* s, int n)
{
	CAutoCritSecLock lock(g_CS_for_debugstr_an);

	static CStringA strA(s, n);
	return strA;
}

EXTERN_C const char* debugstr_wn(const WCHAR* s, int n)
{
	CAutoCritSecLock lock(g_CS_for_debugstr_wn);

	CStringW strW;
	strW.SetString(s, n);
	static CStringA strA(strW);
	return strA;
}

EXTERN_C const char* debugstr_a(const char* s) { return debugstr_an(s, -1); }
EXTERN_C const char* debugstr_w(const WCHAR* s) { return debugstr_wn(s, -1); }
