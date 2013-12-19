#include "stdafx.h"
#include "string.h"
#include "Calculator.h"

extern "C"
{
    __declspec(dllexport) void* __stdcall CreateInstance(const wchar_t* typeId)
    {
        if (wcscmp(Calculator_IID, typeId) == 0)
            return new  Calculator();

        return nullptr;
    }
}