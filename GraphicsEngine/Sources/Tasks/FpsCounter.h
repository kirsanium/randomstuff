#pragma once
#include "Component.h"
#include "GUI.h"
#include "Object.h"
#include "Transform.h"
#include "Time.h"
#include "Vector3.h"


class FpsCounter : public Component
{
	double	t1;
	int		f1;
	double	fps;

public:
	FpsCounter() 
	{
		t1 = Time::GetTime();
		f1 = Time::GetFrameCount();
		fps = 0;
	}

	virtual ~FpsCounter() {}

	virtual void Update() 
	{
		double t2	= Time::GetTime();
		int f2		= Time::GetFrameCount();

		// TODO: Task03
	}
};
