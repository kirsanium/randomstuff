#include "GraphicsDevice.h"
#include "GraphicsEngineFabric.h"


GraphicsDeviceImpl * GraphicsDevice::pImpl = nullptr;


GraphicsDevice::~GraphicsDevice()
{
	if (nullptr != pImpl)
	{
		delete pImpl;
	}
}

void GraphicsDevice::Init()
{
	pImpl = GraphicsEngineFabric::CreateDevice();
}

void GraphicsDevice::SetFillMode( FillMode fillMode )
{
	pImpl->SetFillMode( fillMode );
}

void GraphicsDevice::SetZWrite( bool enable )
{
	pImpl->SetZWrite( enable );
}
