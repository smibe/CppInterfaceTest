#include "stdafx.h"
#include "Calculator.h"
#include <atlstr.h>

// "F3C4F98C-BBDC-4B2E-B67A-12E1475109FE";
const GUID IID_Calculator = { 0xf3c4f98c, 0xbbdc, 0x4b2e, 0xb6, 0x7a, 0x12, 0xe1, 0x47, 0x51, 0x09, 0xfe };

int __stdcall Calculator::Add(int op1 , int op2) 
{
    return op1 + op2;
}

BSTR __stdcall Calculator::GetText(int op1, int op2)
{
    CString str;
    str.Format(L"%d + %d = %d", op1, op2, op1 + op2);
    return str.AllocSysString();
}