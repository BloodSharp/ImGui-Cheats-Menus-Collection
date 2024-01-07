#pragma once

#include "IGCMC-Precompiled.h"

class CRenderer //: public CDrawList
{
public:
	CRenderer();
	~CRenderer();

	void RenderScene(void(*RenderFn)(void*), void* hDeviceContext);

private:
	std::unique_ptr<CMenuThemes> m_pThemes;
};

extern std::unique_ptr<CRenderer> g_pRenderer;