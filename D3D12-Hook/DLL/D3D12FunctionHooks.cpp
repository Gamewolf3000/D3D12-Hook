#include "D3D12FunctionHooks.h"

#include "GlobalObjects.h"

FunctionHook hookD3D12CreateDevice;

#include "FakeD3D12Device.h"

HRESULT __stdcall FakeD3D12CreateDevice(IUnknown* pAdapter, D3D_FEATURE_LEVEL MinimumFeatureLevel, REFIID riid, void** ppDevice)
{
    InitializeGlobalObjects();
    hookD3D12CreateDevice.Restore();
    auto toReturn = D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice);
    if (ppDevice != nullptr)
    {
        FakeD3D12Device* fake = new FakeD3D12Device(static_cast<ID3D12Device6*>(*ppDevice));
        *ppDevice = fake;
    }
    hookD3D12CreateDevice.Inject();
    messageWriter.WriteMessage({ MessageType::TEXT_MESSAGE, "Finished fake create d3d12device" });
    return toReturn;
}
