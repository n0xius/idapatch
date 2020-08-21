#include "mini_crt.hpp"

#include <cstdlib>
#include <yvals.h>

_STD_BEGIN
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xbad_alloc(){}
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xinvalid_argument(_In_z_ const char*){}
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xlength_error(_In_z_ const char*){}
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xout_of_range(_In_z_ const char*){}
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xoverflow_error(_In_z_ const char*){}
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Xruntime_error(_In_z_ const char*){}
_STD_END

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)          (P)
#endif

#pragma warning(push)
#pragma warning(disable: 4595) // non-member operator may not be declared inline

void *__CRTDECL operator new(size_t size) noexcept // NOLINT(clang-diagnostic-microsoft-exception-spec)
{
	return malloc(size);
}

void *__CRTDECL operator new[](size_t size) noexcept // NOLINT(clang-diagnostic-microsoft-exception-spec)
{
	return operator new(size);
}

void __CRTDECL operator delete(void *block) noexcept // NOLINT(clang-diagnostic-microsoft-exception-spec)
{
	free(block);
}

void __CRTDECL operator delete[](void *block) noexcept // NOLINT(clang-diagnostic-microsoft-exception-spec)
{
	free(block);
}

void __CRTDECL operator delete(void *block, size_t _Size) noexcept // NOLINT(clang-diagnostic-microsoft-exception-spec)
{
	UNREFERENCED_PARAMETER(_Size);
	free(block);
}

extern "C" int __cdecl _purecall()
{
	return 0;
}

__declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void) {}
__declspec(noreturn) void __cdecl _invoke_watson(wchar_t const* _Expression, wchar_t const* _FunctionName, wchar_t const* _FileName, unsigned int _LineNo, uintptr_t _Reserved){}

#ifdef UNREFERENCED_PARAMETER
#undef UNREFERENCED_PARAMETER
#endif

#pragma warning(pop)