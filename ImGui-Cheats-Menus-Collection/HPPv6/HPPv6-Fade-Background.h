#pragma once

#include "IGCMC-Precompiled.h"

class CMenuFadeBg
{
public:
	void Init();
	void Run();

private:
	bool m_active;
	bool m_state;

	double m_prevtime;
};