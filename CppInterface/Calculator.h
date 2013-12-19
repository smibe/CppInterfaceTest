#pragma once
#include "unknwnbase.h"

extern const wchar_t *Calculator_IID;

class ICalculator : public IUnknown
{
public:
    virtual int __stdcall Add( int op1, int op2) = 0;
};

class Calculator : ICalculator
{
public:
	Calculator() {};
	virtual ~Calculator() {};

    virtual int __stdcall Add( int op1, int op2);

    virtual ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall QueryInterface(const IID& riid,void **ppvObject);
protected:
    int refCount;
};

