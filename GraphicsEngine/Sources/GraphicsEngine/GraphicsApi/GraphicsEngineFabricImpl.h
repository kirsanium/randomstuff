#pragma once
#include "GraphicsApi/GraphicsDeviceImpl.h"
#include "GraphicsApi/GraphicsEngineImpl.h"
#include "GraphicsApi/GUIImpl.h"
#include "GraphicsApi/FixedFunctionPipelineImpl.h"
#include "GraphicsApi/MaterialImpl.h"
#include "GraphicsApi/MeshImpl.h"
#include "GraphicsApi/VertexShaderImpl.h"
#include "GraphicsApi/PixelShaderImpl.h"
#include "GraphicsApi/RenderTextureImpl.h"
#include "GraphicsApi/Texture2DImpl.h"


// Interface to create objects listed below.
// This class is Abstract factory, derived classes implement this interface.
// Separates objects usage from objects creation (a concrete implementation in DX9, DX11, GL20).
// E.g. separates an interface MeshImpl from concrete implementations: DX9Mesh, DX11Mesh.
// Design Patterns: Abstract Factory (role - Abstract Factory).
class GraphicsEngineFabricImpl
{
public:
	virtual GraphicsDeviceImpl *	CreateDevice() = 0;

	virtual GraphicsEngineImpl *	CreateEngine() = 0;

	virtual GUIImpl *				CreateGUI() = 0;

	virtual MeshImpl *				CreateMesh() = 0;
	
	virtual Texture2DImpl *			CreateTexture2D(const char * filepath) = 0;

	virtual RenderTextureImpl *		CreateRenderTexture(int size) = 0;

	virtual MaterialImpl *			CreateMaterial(const char * vertexShaderFilePath, const char * fragmentShaderFilePath) = 0;

	virtual VertexShaderImpl *		CreateVertexShader(const char * filepath) = 0;
	virtual VertexShaderImpl *		CreateVertexShader(const unsigned long * pFunction) = 0;
	
	virtual PixelShaderImpl *		CreatePixelShader(const char * filepath) = 0;
	virtual PixelShaderImpl *		CreatePixelShader(const unsigned long * pFunction) = 0;

	virtual FixedFunctionPipelineImpl * CreateFixedFunctionPipeline() = 0;
};
