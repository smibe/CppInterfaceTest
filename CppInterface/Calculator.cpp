#include "stdafx.h"
#include "Calculator.h"

const wchar_t *Calculator_IID = L"F3C4F98C-BBDC-4B2E-B67A-12E1475109FE";
const GUID IID_Calculator = { 0xf3c4f98c, 0xbbdc, 0x4b2e, 0xb6, 0x7a, 0x12, 0xe1, 0x47, 0x51, 0x09, 0xfe };

ULONG __stdcall Calculator::AddRef()
{
    return ++refCount;
}
ULONG __stdcall Calculator::Release()
{
    return --refCount;
}
HRESULT __stdcall Calculator::QueryInterface(const IID& riid,void **ppvObject) 
{
    //TODO: check the guid
    if (riid != IID_IUnknown && riid != IID_Calculator)
	{
        *ppvObject = nullptr;
        return S_FALSE;
	}

	*ppvObject=this;
    AddRef();
    return S_OK;
}
int __stdcall Calculator::Add(int op1 , int op2) 
{
    return op1 + op2;
}
