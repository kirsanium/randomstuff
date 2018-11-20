#include "GraphicsEngine.h"
#include "GraphicsEngineFabric.h"
#include "Time.h"
#include "Internal/GraphicsDevice.h"
#include <cstddef>


GraphicsEngine * GraphicsEngine::pEngine = nullptr;

GraphicsEngine & GraphicsEngine::Instance()
{
	if (nullptr == pEngine)
	{
		pEngine = new GraphicsEngine();
	}

	return *pEngine;
}

GraphicsEngine::GraphicsEngine()
{
	
}

void GraphicsEngine::Init()
{
	pGraphicsEngineImpl = GraphicsEngineFabric::CreateEngine();
	pGraphicsEngineImpl->Init();

	GraphicsDevice::Init();
}

void GraphicsEngine::Deinit()
{
	pGraphicsEngineImpl->Deinit();
}

void GraphicsEngine::Render()
{
	Time::Update();

	pGraphicsEngineImpl->Render();
}

bool GraphicsEngine::IsRunning()
{
	return pGraphicsEngineImpl->IsRunning();
}
