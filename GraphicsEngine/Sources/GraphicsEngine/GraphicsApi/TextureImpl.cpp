#pragma once
#include "GraphicsApi/TextureImpl.h"
#include <stddef.h>


TextureImpl::TextureImpl()
	:	m_pTextureSampler(nullptr)
{

}

TextureImpl::~TextureImpl()
{
	if (nullptr != m_pTextureSampler)
	{
		delete m_pTextureSampler;
		m_pTextureSampler = nullptr;
	}
}

void TextureImpl::SetFilterMode(TextureFilterMode filterMode)
{
	if (nullptr != m_pTextureSampler)
	{
		m_pTextureSampler->SetFilterMode( filterMode );
	}
}

void TextureImpl::SetWrapMode(TextureWrapMode wrapMode)
{
	if (nullptr != m_pTextureSampler)
	{
		m_pTextureSampler->SetWrapMode( wrapMode );
	}
}
