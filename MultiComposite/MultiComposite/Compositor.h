#pragma once
#include "openvr.h"
#include <d3d11.h>

#pragma comment( lib, "user32" )          // link against the win32 library
#pragma comment( lib, "d3d11.lib" )       // direct3D library
#pragma comment( lib, "dxgi.lib" )        // directx graphics interface
#pragma comment( lib, "d3dcompiler.lib" ) // shader compiler

class ICompositor
{
public:
	static ICompositor* pD11Compositor;
	virtual void Init() = 0;
	virtual void SetupTexture(vr::Texture_t* texture, HANDLE handle) = 0;
	virtual void ReleaseTexture(vr::Texture_t* texture) = 0;
};

class D3D11Compositor : public ICompositor
{
public:
	void Init();
	void SetupTexture(vr::Texture_t* texture, HANDLE handle);
	void ReleaseTexture(vr::Texture_t* texture);
private:
	ID3D11Device* pDevice;
	ID3D11DeviceContext* pContext;
	IDXGISwapChain* pSwapChain;
	ID3D11RenderTargetView* pRenderTargetView;
};
