#include "MaterialTask02Cylinder.h"
#include "Transform.h"
#include "MathUtils.h"
#include "SceneUtils.h"
#include "Time.h"
#include <cmath>


MaterialTask02Cylinder::MaterialTask02Cylinder()
{
    m_vsFileName = "ShaderTask02Cylinder";
    m_psFileName = "ShaderTask02Cylinder";
}

// TODO: Реализовать переключение Graphics API при нажатии на кнопки (1 - DirectX 11, 2 - OpenGL 2.0, 9 - DirectX 9)
// и отладить на этом механизм использования функций Init() и Deinit()
void MaterialTask02Cylinder::Init()
{
    Material::Init();

    // TODO: Нужно при компиляции скопировать папку с шейдерами
    // Google it: "visual studio during build copy files into application folder"
}

void MaterialTask02Cylinder::Deinit()
{
    Material::Deinit();
}

void MaterialTask02Cylinder::SetMaterial(const Object * pObject)
{
    // Заполняем матрицы World, View, Proj
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

    const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

    SetMaterialBegin();
    {
        SetVertexShaderBegin();
        SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
        SetVertexShaderVector4("constColor", Vector4(1, 1, 1, 1));

        double time = Time::GetTime();

        SetVertexShaderVector4("time", Vector4(time, 1, 1, 1));
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
