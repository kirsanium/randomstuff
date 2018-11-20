#include "GL20GraphicsEngineFabric.h"
#include "GraphicsApi/OpenGL20/GL20GraphicsDevice.h"
#include "GraphicsApi/OpenGL20/GL20GraphicsEngine.h"
#include "GraphicsApi/OpenGL20/GL20GUI.h"
#include "GraphicsApi/OpenGL20/GL20Material.h"
#include "GraphicsApi/OpenGL20/GL20Mesh.h"
//#include "GraphicsApi/DirectX11/DX11VertexShader.h"
//#include "GraphicsApi/DirectX11/DX11PixelShader.h"
#include "GraphicsApi/OpenGL20/GL20RenderTexture.h"
#include "GraphicsApi/OpenGL20/GL20Texture2D.h"
//#include "GraphicsApi/DirectX9/FixedFunctionPipelineDX9.h"


GraphicsDeviceImpl * GL20GraphicsEngineFabric::CreateDevice()
{
	return new GL20GraphicsDevice();
}

GraphicsEngineImpl * GL20GraphicsEngineFabric::CreateEngine()
{
	return new GL20GraphicsEngine();
}

GUIImpl * GL20GraphicsEngineFabric::CreateGUI()
{
	return new GL20GUI();
}

MeshImpl * GL20GraphicsEngineFabric::CreateMesh()
{
	return new GL20Mesh();
}

Texture2DImpl * GL20GraphicsEngineFabric::CreateTexture2D(const char * filepath)
{
	return new GL20Texture2D(filepath);
}

RenderTextureImpl * GL20GraphicsEngineFabric::CreateRenderTexture(int size)
{
	return new GL20RenderTexture(size, size);
}

MaterialImpl * GL20GraphicsEngineFabric::CreateMaterial(const char * vertexShaderFilePath, const char * fragmentShaderFilePath)
{
	return new GL20Material(vertexShaderFilePath, fragmentShaderFilePath);
}

VertexShaderImpl * GL20GraphicsEngineFabric::CreateVertexShader(const char * filepath)
{
	return nullptr;
}

VertexShaderImpl * GL20GraphicsEngineFabric::CreateVertexShader(const unsigned long * pFunction)
{
	return nullptr;
}

PixelShaderImpl * GL20GraphicsEngineFabric::CreatePixelShader(const char * filepath)
{
	return nullptr;
}

PixelShaderImpl * GL20GraphicsEngineFabric::CreatePixelShader(const unsigned long * pFunction)
{
	return nullptr;
}

FixedFunctionPipelineImpl * GL20GraphicsEngineFabric::CreateFixedFunctionPipeline()
{
	return nullptr;
}
