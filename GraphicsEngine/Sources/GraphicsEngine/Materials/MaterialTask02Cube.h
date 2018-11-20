#pragma once
#include "Materials/Material.h"


class MaterialTask02Cube : public Material
{
public:
	/**
	* @brief Constructs the object.
	*/
	MaterialTask02Cube();

	/**
	* @brief Initialize the material and necessary data here.
	*/
	virtual void Init();

	/**
	* @brief Deinitialize the material and necessary data here.
	*/
	virtual void Deinit();
	
	/**
	* @brief Pass all necessary for rendering data to vertex and pixel shaders (is called before rendering).
	* @param [in] pObject Pointer to an object that is being rendered now.
	*/
	virtual void SetMaterial(const Object * pObject);
};
