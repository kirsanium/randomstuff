#pragma once
#include "Materials/Material.h"
#include "GraphicsApi/FixedFunctionPipelineImpl.h"


class MaterialTask01 : public Material
{
public:
	virtual void Init(Object * pObject);
	virtual void Deinit();
	virtual void SetMaterial();

private:
	FixedFunctionPipelineImpl * pImpl;
	Object* m_pObject;
};
