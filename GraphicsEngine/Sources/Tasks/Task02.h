#pragma once

#include <Materials/MaterialTask02Cylinder.h>
#include "Application.h"
#include "Camera.h"
#include "GraphicsEngine.h"
#include "Meshes/MeshCube.h"
#include "Meshes/MeshCylinder.h"
#include "Object.h"
#include "Scene.h"
#include "Transform.h"

#include "Task.h"
#include "ObjectRotator.h"
#include "CameraController.h"

#include "Materials/MaterialTask02Cube.h"


/**
* @brief Shows how to morph the objects.
* Key code is situated in the classes MaterialTask02Cube, MaterialTask02Cylinder.
*/
class Task02: public Task
{
private:
	Object * cube;
	Object * cylinder;

public:
	virtual ~Task02() { }

	virtual void Init() {
		Scene &scene = Application::Instance().GetScene();

		// Camera
		{
			Object *pCameraObj = new Object();
			pCameraObj->m_pTransform = new Transform(Vector3(0, 1.5, -3), Vector3(20.0f, 0.0f, 0.0f));
			Camera *pCamera = new Camera();
			pCamera->SetFovY(90);
			pCamera->SetNearPlane(0.01f);
			pCamera->SetFarPlane(100);
			pCameraObj->AddComponent(pCamera);
			pCameraObj->AddComponent(new CameraController());

			scene.SetCamera(pCamera);
		}

		// Object # 1 - Cube (is morphed to sphere)
		{
			Object *cube = new Object();
			cube->m_pTransform = new Transform(Vector3(-1.5, 0, 0), Vector3(0, 30, 0));
			cube->m_pMesh = new MeshCube(10);
			cube->m_pMaterial = new MaterialTask02Cube();

			scene.AddObject(cube);
		}

		// Object #2 - Cylinder (is twisted)
		{
			Object *pObject = new Object();
			pObject->m_pTransform = new Transform(Vector3(1.5, 0, 0), Vector3(0, 30, 0));
			pObject->m_pMesh = new MeshCylinder(20);
			pObject->m_pMaterial = new MaterialTask02Cylinder();

			scene.AddObject(pObject);
		}
	}

	virtual void Update() {
	}
};
