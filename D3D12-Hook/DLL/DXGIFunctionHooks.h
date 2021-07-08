#pragma once
#include "FunctionHook.h"

extern FunctionHook hookCreateDXGIFactory;
extern FunctionHook hookCreateDXGIFactory1;
extern FunctionHook hookCreateDXGIFactory2;

HRESULT WINAPI FakeCreateDXGIFactory(
	REFIID riid,
	void** ppFactory
);

HRESULT WINAPI FakeCreateDXGIFactory1(
	REFIID riid,
	void** ppFactory
);

HRESULT WINAPI FakeCreateDXGIFactory2(
	UINT   Flags,
	REFIID riid,
	void** ppFactory
);