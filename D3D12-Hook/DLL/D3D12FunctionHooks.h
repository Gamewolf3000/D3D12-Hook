#pragma once
#include "FunctionHook.h"

extern FunctionHook hookD3D12CreateDevice;

#include <d3d12.h>

HRESULT WINAPI FakeD3D12CreateDevice(
    _In_opt_ IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    _In_ REFIID riid,
    _COM_Outptr_opt_ void** ppDevice);