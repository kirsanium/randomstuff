﻿#pragma once
#include "ObjectRotator.h"
#include "Application.h"
#include "Meshes/MeshSphere.h"
#include "Transform.h"
#include "Object.h"
#include "Scene.h"
#include "GraphicsEngine.h"
#include "Light.h"
#include "Materials/MaterialUnlit.h"

#include "Task.h"


/**
* @brief Shows how to map texture to the sphere.
* Key code is situated in the classes MaterialEarth, MeshSphere.
*/
class Task05_03: public Task
{
public:
	virtual ~Task05_03() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
	
		// Camera
		{
			Object * pCameraObj = new Object();
			Camera * pCamera = new Camera();
			pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 1.0f, -1.25f), Vector3(40.0f, 0.0f, 0.0f) );			
			pCameraObj->AddComponent( pCamera );
			
			scene.SetCamera( pCamera );
		}

		// Object #1 - Sphere with the Earth texture
		{
			Object * pObject1 = new Object();

			pObject1->m_pTransform	= new Transform( 0,0,0, 0,0,0, 1,1,1 );
			pObject1->m_pMesh		= new MeshSphere(20);			
			pObject1->m_pMaterial	= new MaterialUnlit(Vector3(0.5, 0.5, 0.5));
			pObject1->AddComponent( new ObjectRotator(0, 20, 0) );
						
			scene.AddObject( pObject1 );
		}
	}

	virtual void Update()
	{
		
	}
};
