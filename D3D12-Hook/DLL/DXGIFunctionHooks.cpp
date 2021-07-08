#include "DXGIFunctionHooks.h"

#include "GlobalObjects.h"

FunctionHook hookCreateDXGIFactory;
FunctionHook hookCreateDXGIFactory1;
FunctionHook hookCreateDXGIFactory2;

#include <dxgi1_6.h>

#include "FakeDXGIFactory.h"

HRESULT __stdcall FakeCreateDXGIFactory(REFIID riid, void** ppFactory)
{
    InitializeGlobalObjects();
    //messageWriter.WriteMessage({ MessageType::TEXT_MESSAGE, "Starting fake create dxgi factory" });
    hookCreateDXGIFactory.Restore();
    auto toReturn = CreateDXGIFactory(riid, ppFactory);
    FakeDXGIFactory* fake = new FakeDXGIFactory(static_cast<IDXGIFactory7*>(*ppFactory));
    *ppFactory = fake;
    hookCreateDXGIFactory.Inject();
    return toReturn;
}

HRESULT __stdcall FakeCreateDXGIFactory1(REFIID riid, void** ppFactory)
{
    InitializeGlobalObjects();
    //messageWriter.WriteMessage({ MessageType::TEXT_MESSAGE, "Starting fake create dxgi factory 1" });
    hookCreateDXGIFactory1.Restore();
    auto toReturn = CreateDXGIFactory1(riid, ppFactory);
    FakeDXGIFactory* fake = new FakeDXGIFactory(static_cast<IDXGIFactory7*>(*ppFactory));
    *ppFactory = fake;
    hookCreateDXGIFactory1.Inject();
    return toReturn;
}

HRESULT __stdcall FakeCreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory)
{
    //MessageBoxA(0, "Starting fake create dxgi factory 2", "FakeCreateDXGIFactory2", 0);
    InitializeGlobalObjects();
    //messageWriter.WriteMessage({ MessageType::TEXT_MESSAGE, "Starting fake create dxgi factory 2" });
    hookCreateDXGIFactory2.Restore();
    auto toReturn = CreateDXGIFactory2(Flags, riid, ppFactory);
    FakeDXGIFactory* fake = new FakeDXGIFactory(static_cast<IDXGIFactory7*>(*ppFactory));
    *ppFactory = fake;
    hookCreateDXGIFactory2.Inject();
    //MessageBoxA(0, "Finished fake create dxgi factory 2", "FakeCreateDXGIFactory2", 0);
    return toReturn;
}
