#pragma once
#include "baseObject.h"

extern const GUID IID_Calculator;

class ICalculator : public IUnknown
{
public:
    virtual int __stdcall Add( int op1, int op2) = 0;
    virtual BSTR __stdcall GetText(int op1, int op2) = 0;
};

class Calculator : BaseObject<ICalculator, &IID_Calculator>
{
public:
	Calculator() { };
	virtual ~Calculator() {};

    virtual int __stdcall Add( int op1, int op2);
    virtual BSTR __stdcall GetText(int op1, int op2);
};