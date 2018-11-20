﻿#pragma once
#include "Application.h"
#include "GraphicsEngine.h"
#include "Light.h"
#include "Materials/MaterialDiffuse.h"
#include "Meshes/MeshSphere.h"
#include "Object.h"
#include "Scene.h"
#include "Transform.h"

#include "Task.h"
#include "ObjectRotator.h"


/**
* @brief Shows how to write lightning materials.
* Key code is situated in the classes MaterialDiffuse, Light.
*/
class Task04: public Task
{
public:
	virtual ~Task04() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
		
		// Camera
		{
			Object * pCameraObj = new Object();
			pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 0.0f,-7.0f), Vector3(0.0f, 0.0f, 0.0f));
			Camera * pCamera = new Camera();
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}

		// Object - Sphere
		{
			Object * pObject1 = new Object();

			pObject1->m_pTransform	= new Transform(0,0,0, 0,0,0, 3,3,3);
			pObject1->m_pMesh		= new MeshSphere(20);
            pObject1->m_pMaterial	= new MaterialDiffuse();
			pObject1->AddComponent( new ObjectRotator(0,10,0) );

			scene.AddObject( pObject1 );
		}

		// Ligth source #1 - Directional
		{
			Light * pLight = new Light(LIGHT_DIRECTIONAL);
			pLight->SetColor(1,1,0);
			pLight->SetIntensity(1);

			Object * pLightObject = new Object();
			pLightObject->m_pTransform	= new Transform(1,0,0, 0,90,0, 1,1,1);
			pLightObject->AddComponent(pLight);

			scene.AddLight(pLight);
		}

		// Ligth source #2 - Point
		{
			Light * pLight = new Light(LIGHT_POINT);
			pLight->SetColor(1,1,1);
			pLight->SetIntensity(1);

			Object * pLightObject = new Object();
			pLightObject->m_pTransform	= new Transform(3,0,0, 0,0,0, 1,1,1);
			pLightObject->AddComponent(pLight);

			scene.AddLight(pLight);
		}
	}

	virtual void Update()
	{
		
	}
};
