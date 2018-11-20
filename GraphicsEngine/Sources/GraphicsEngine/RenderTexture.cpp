#include "RenderTexture.h"
#include "GraphicsEngineFabric.h"
#include <cstddef>


RenderTexture::RenderTexture(int size)
	:	m_pImpl(nullptr),
		m_size(size)
{
	m_pImpl = GraphicsEngineFabric::CreateRenderTexture(size);
}

RenderTexture::~RenderTexture()
{
	if (nullptr != m_pImpl)
	{
		delete m_pImpl;
		m_pImpl = nullptr;
	}
}

void RenderTexture::SetAsRenderTarget() const
{
	m_pImpl->SetAsRenderTarget();
}

void RenderTexture::RestoreRenderTarget() const
{
	m_pImpl->RestoreRenderTarget();
}

const RenderTextureImpl * RenderTexture::GetImplPointer() const
{
	return m_pImpl;
}

int RenderTexture::GetWidth() const
{
	return m_size;
}

int RenderTexture::GetHeight() const
{
	return m_size;
}
