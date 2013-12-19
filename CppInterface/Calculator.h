#pragma once
#include "unknwnbase.h"

extern const GUID IID_Calculator;

class ICalculator : public IUnknown
{
public:
    virtual int __stdcall Add( int op1, int op2) = 0;
};

class Calculator : ICalculator
{
public:
	Calculator() { this->refCount = 0; };
	virtual ~Calculator() {};

    virtual int __stdcall Add( int op1, int op2);

    virtual ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall QueryInterface(const IID& riid,void **ppvObject);
protected:
    unsigned int refCount;
};

