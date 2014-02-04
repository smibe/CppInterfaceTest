#pragma once
#include "unknwnbase.h"

template <class T, GUID const* pIID> 
class BaseObject : public T
{
public:
	BaseObject(void) { this->refCount = 0; }
	virtual ~BaseObject(void) { }

	virtual ULONG __stdcall AddRef()
	{
		return InterlockedIncrement(&this->refCount);;
	}

	virtual ULONG __stdcall Release()
	{
		return InterlockedDecrement(&refCount);
	}

	virtual HRESULT __stdcall QueryInterface(const IID& riid,void **ppvObject) 
	{
		if (riid != IID_IUnknown && riid != *pIID)
		{
			*ppvObject = nullptr;
			return S_FALSE;
		}

		*ppvObject=this;
		AddRef();
		return S_OK;
	}

protected:
	unsigned int refCount;
};

