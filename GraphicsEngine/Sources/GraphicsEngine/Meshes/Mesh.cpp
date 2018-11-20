#include "Mesh.h"
#include "GraphicsEngineFabric.h"
#include <cstddef>


Mesh::Mesh()
{
	meshImpl = nullptr;
}

void Mesh::Init()
{
	if (nullptr != meshImpl)
	{
		Deinit();
	}

	meshImpl = GraphicsEngineFabric::CreateMesh();
	meshImpl->Init();
}

void Mesh::Deinit()
{
	meshImpl->Deinit();
}

void Mesh::Render()
{
	meshImpl->Render();
}
