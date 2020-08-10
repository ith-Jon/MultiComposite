#pragma once
#include "IGraphicsBackend.h"

#include <d3d11.h>

class D3D11Backend : public IGraphicsBackend
{
public:
	void Init();
private:
	ID3D11Device* pDevice;
	ID3D11DeviceContext* pContext;
	IDXGISwapChain* pSwapChain;
	ID3D11RenderTargetView* pRenderTargetView;
};
