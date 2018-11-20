#pragma once
#include "Application.h"
#include "Camera.h"
#include "GraphicsEngine.h"
#include "Materials/MaterialUnlitSimple.h"
#include "Meshes/MeshCube.h"
#include "Object.h"
#include "Scene.h"
#include "Transform.h"

#include "Task.h"
#include "FpsCounter.h"
#include "ObjectRotator.h"


/**
* @brief Shows how to write text to the screen.
* Key code is situated in the classes FpsCounter, GUI, InternalGUI, DX9GUI, GL20GUI.
*/
class Task03: public Task
{
public:
	virtual ~Task03() { }

	virtual void Init()
	{
		Scene & scene = Application::Instance().GetScene();
	
		// Camera
		{
			Object * pCameraObj = new Object();
			pCameraObj->m_pTransform = new Transform( Vector3(0, 3, -10), Vector3(20.0f, 0.0f, 0.0f));
			Camera * pCamera = new Camera();
			pCamera->SetFovY(90);
			pCamera->SetNearPlane(0.01f);
			pCamera->SetFarPlane(100);
			pCameraObj->AddComponent( pCamera );

			scene.SetCamera( pCamera );
		}		
		
		// FPS counter
		{
			Object * pObject = new Object();
			pObject->m_pTransform	= new Transform();
			pObject->AddComponent( new FpsCounter() );

			scene.AddObject( pObject );
		}
	}

	virtual void Update()
	{
		
	}
};
