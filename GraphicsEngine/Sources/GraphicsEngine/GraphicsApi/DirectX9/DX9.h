#pragma once

#include "PlatformApi/Platform.h"
#ifdef CAN_USE_DIRECT_X

#include <d3dx9.h>
#include <d3dx9math.h>

// TODO: Resuse SAFE_RELEASE in DirectX9 code
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=nullptr; } }
#endif

#endif
