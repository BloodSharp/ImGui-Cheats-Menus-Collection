#pragma once

#include "IGCMC-Precompiled.h"

class CRenderer //: public CDrawList
{
public:
	CRenderer();
	~CRenderer();

	void RenderScene(void(*RenderFn)(void*), void* hDeviceContext);
};

extern std::unique_ptr<CRenderer> g_pRenderer;