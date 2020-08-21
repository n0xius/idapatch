//#pragma once
#ifndef _MINI_CRT_
#define _MINI_CRT_

//#include <yvals.h>
#include <yvals_core.h>

#pragma warning(disable:4273)
#pragma warning(disable:4005)

#define _ACRTIMP

#if defined(_WIN64)
#pragma comment(lib, "msvcrt-light-x64.lib")
#else
#pragma comment(lib, "msvcrt-light.lib")
#endif

#pragma comment(lib, "vcruntime.lib")

_STDEXT_BEGIN
class exception;
_STDEXT_END

_STD_BEGIN
using _STDEXT exception;

// handle exception termination
inline void __CRTDECL terminate() noexcept {}

// FUNCTION _Throw_bad_array_new_length
[[noreturn]] inline void _Throw_bad_array_new_length() {}
_STD_END

_STDEXT_BEGIN
class exception { // base of all library exceptions
public:
    // this constructor is necessary to compile
    // successfully header new for _HAS_EXCEPTIONS==0 scenario
    explicit __CLR_OR_THIS_CALL exception(const char* _Message = nullptr, int = 1) noexcept {}

    __CLR_OR_THIS_CALL exception(const exception& _Right) noexcept {}

    exception& __CLR_OR_THIS_CALL operator=(const exception& _Right) noexcept {
        return *this;
    }

    virtual __CLR_OR_THIS_CALL ~exception() noexcept {}

    _NODISCARD virtual const char* __CLR_OR_THIS_CALL what() const noexcept { // return pointer to message string
        return nullptr;
    }

    void __CLR_OR_THIS_CALL _Raise() const { // raise the exception
        _Doraise(); // call the protected virtual
    }

protected:
    virtual void __CLR_OR_THIS_CALL _Doraise() const { // perform class-specific exception handling
    }

protected:
};
_STDEXT_END

#endif