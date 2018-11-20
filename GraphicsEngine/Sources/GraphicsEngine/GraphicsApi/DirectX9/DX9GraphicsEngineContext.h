#pragma once

#include "PlatformApi/Platform.h"
#ifdef CAN_USE_DIRECT_X

#include "GraphicsApi/DirectX9/DX9.h"
#include "GraphicsApi/GraphicsEngineContext.h"


class DX9GraphicsEngineContext : public GraphicsEngineContext
{
public:
	LPDIRECT3DDEVICE9 m_pDevice;

	DX9GraphicsEngineContext(LPDIRECT3DDEVICE9 pDevice, GraphicsEngineImpl * pImpl)
		: GraphicsEngineContext(pImpl)
	{
		m_pDevice = pDevice;
	}
};

#endif
