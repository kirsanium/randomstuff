#include "Object.h"
#include "Component.h"
#include "Materials/Material.h"
#include "Meshes/Mesh.h"
#include "Transform.h"


Object::Object(const char * name)
	:	m_pTransform( nullptr ),
		m_pMesh		( nullptr ),
		m_pMaterial	( nullptr ),
		m_isActive	( true )
{
	m_name = (nullptr == name) ? "Object" : name;
}

Object::~Object()
{
	// Очищаем список компонент
	{
		std::list<Component *>::iterator iter;
		for (iter = m_components.begin(); iter != m_components.end(); iter++)
		{
			Component * pComponent = (*iter);
			if (nullptr != pComponent)
			{
				delete pComponent;
			}
		}

		m_components.clear();
	}

	if (nullptr != m_pMaterial)
	{
		m_pMaterial->Deinit();
		delete m_pMaterial;
		m_pMaterial = nullptr;
	}

	if (nullptr != m_pMesh)
	{
		m_pMesh->Deinit();
		delete m_pMesh;
		m_pMesh = nullptr;
	}

	if (nullptr != m_pTransform)
	{
		delete m_pTransform;
		m_pTransform = nullptr;
	}	
}

void Object::Init()
{
	if (nullptr != m_pMesh)
	{
		m_pMesh->Init();
	}

	if (nullptr != m_pMaterial)
	{
		m_pMaterial->Init();
	}
}

void Object::AddComponent(Component * pComponent)
{
	m_components.push_back(pComponent);
	pComponent->Init(this);
}

bool Object::IsActive() const
{
	return m_isActive;
}

void Object::SetActive(bool isActive)
{
	m_isActive = isActive;
}

void Object::Update() const
{
	std::list<Component *>::const_iterator iter;
	for (iter = m_components.begin(); iter != m_components.end(); iter++)
	{
		Component * pComponent = (*iter);
		if (nullptr != pComponent)
		{
			pComponent->Update();
		}
	}
}
