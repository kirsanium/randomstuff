// TODO: ”казать полный путь дл¤ #include во всЄм проекте
#include "Scene.h"

#include "Application.h"
#include "Camera.h"
#include "GraphicsEngine.h"
#include "Light.h"
#include "Materials/Material.h"
#include "Meshes/Mesh.h"
#include "Object.h"

#include "Internal/ObjectStorage.h"


void Scene::Init()
{
	m_pCamera = nullptr;

	m_pSelectedObject = nullptr;
}

void Scene::Deinit()
{
	// ”дал¤ем объекты
	{
		//std::list<const Object *>::iterator iter;
		//for (iter = m_objects.begin(); iter != m_objects.end(); iter++)
		for (size_t i = 0; i < m_objects.size(); ++i)
		{
			//const Object * pObject = (*iter);
			const Object * pObject = m_objects[i];
			delete pObject;
		}
	}

	m_lights.clear();
	m_objects.clear();	

	// ”дал¤ем камеру
	m_pCamera = nullptr;
}

void Scene::AddObject(Object * pObject)
{
	if (nullptr == pObject)
	{
		return;
	}

	pObject->Init();
	m_objects.push_back( pObject );
	ObjectStorage::Push( pObject );
}

void Scene::AddLight(Light * pLight)
{
	if (nullptr == pLight)
	{
		return;
	}

	m_lights.push_back(pLight);

	if (nullptr != pLight->GetObjectPtr())
	{
		AddObject(pLight->GetObjectPtr());
	}
}

void Scene::SetSelectedObject(Object * pObject)
{
	m_pSelectedObject = pObject;
}

Object * Scene::GetSelectedObject()
{
	return m_pSelectedObject;
}

void Scene::SetCamera(Camera * pCamera)
{
	if (nullptr != pCamera)
	{
		m_pCamera = pCamera;
		//m_objects.push_back(m_pCamera->GetObjectPtr());
	}
}

//Camera & Scene::GetCamera() const
//{
//	return (*m_pCamera);
//}

Camera * Scene::GetCamera()
{
	return m_pCamera;
}

const std::list<const Light *> & Scene::GetLights() const
{
	return m_lights;
}

const std::vector<const Object *> & Scene::GetObjects() const
{
	return m_objects;
}

void Scene::Update()
{
	m_pCamera->GetObjectPtr()->Update();

	//std::list<const Object *>::iterator iter;
	//for (iter = m_objects.begin(); iter != m_objects.end(); iter++)
	for (size_t i = 0; i < m_objects.size(); ++i)
	{
		//const Object * pObject = (*iter);
		const Object * pObject = m_objects[i];
		if (nullptr != pObject)
		{
			pObject->Update();
		}
	}
}

void Scene::Render()
{
	if (nullptr == m_pCamera)
	{
		return;
	}

	m_pCamera->Render();
}
