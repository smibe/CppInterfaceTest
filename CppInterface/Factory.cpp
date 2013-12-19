#include "stdafx.h"
#include "string.h"
#include "Calculator.h"

extern "C"
{
    __declspec(dllexport) void* __stdcall CreateInstance(GUID guid)
    {
        if (IID_Calculator == guid)
            return new  Calculator();

        return nullptr;
    }
}