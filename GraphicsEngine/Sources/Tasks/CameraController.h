#pragma once
#include "Component.h"
#include "Input.h"
#include "Object.h"
#include "Transform.h"
#include "Time.h"
#include "Vector3.h"


class CameraController : public Component
{
	Vector3 mousePos;
	Vector3 mousePosPrev;

public:
	CameraController()
	{
		mousePos		= Vector3::Zero();
		mousePosPrev	= Vector3::Zero();
	}

	virtual ~CameraController() {}

	virtual void Update() 
	{
		Transform * pTransform = m_pObject->m_pTransform;
		
		// Camera Translation
		{
			Vector3 forward	= pTransform->GetForward();
			Vector3 right	= pTransform->GetRight();
			double dt = Time::GetDeltaTime();

			const double speed = 1.0;
			Vector3 direction;

			if (Input::GetKey(KEY_CODE_W) || Input::GetKey(KEY_CODE_UP_ARROW))
			{
				direction += forward;
			}
			
			// TODO : Task08

			pTransform->Translate( speed * dt * direction );
		}

		// Camera Rotation
		{
			mousePos = Input::GetMousePosition();

			// TODO : Task08

			mousePosPrev = mousePos;
		}
	}
};
