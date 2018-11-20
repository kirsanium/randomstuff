﻿#pragma once
#include "Component.h"
#include "Object.h"
#include "Transform.h"
#include "Time.h"
#include "Vector3.h"


class ObjectRotator : public Component
{
	Vector3 speed;

public:
	ObjectRotator(float x, float y, float z) 
	{
		speed = Vector3(x, y, z);
	}

	virtual ~ObjectRotator() {}

	virtual void Update() 
	{
		if ((NULL == m_pObject) || (NULL == m_pObject->m_pTransform))
		{
			return;
		}
		
		double deltaTime = Time::GetDeltaTime();

		m_pObject->m_pTransform->Rotate(speed * deltaTime);
	}
};