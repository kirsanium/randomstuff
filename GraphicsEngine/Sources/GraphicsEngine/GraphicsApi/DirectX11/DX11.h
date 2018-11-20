#pragma once

#include "PlatformApi/Platform.h"
#ifdef CAN_USE_DIRECT_X

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=nullptr; } }
#endif

#endif
