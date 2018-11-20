﻿#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"
#include "Texture2D.h"


class VertexShaderImpl
{
public:
	virtual void SetShaderBegin() = 0;
	
	virtual void SetShaderVector4(Vector3 vector, float w) = 0;
	virtual void SetShaderVector4(Vector4 vector) = 0;

	virtual void SetShaderMatrix4x4(Matrix4x4 matrix) = 0;
	virtual void SetShaderMatrix4x3(Matrix4x4 matrix) = 0;
	
	virtual void SetShaderEnd() = 0;
};
