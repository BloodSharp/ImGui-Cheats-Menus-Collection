#pragma once

#include "IGCMC-Precompiled.h"

typedef struct IGCMC_Interface_Menu_s
{
	bool m_bIsThisMenuActive;
	const char* m_szMenuName;
	void* Setup();
	void* Render(bool* pbMustCloseThisMenu);
}IGCMC_Interface_Menu_t;

namespace IGCMC
{
	namespace Interfaces
	{
		void InitializeInterface(IGCMC_Interface_Menu_t* pInterfaceMenu);
		void AddInterfaceData(IGCMC_Interface_Menu_t* pInterfaceMenu);
		void RemoveInterfaceData(IGCMC_Interface_Menu_t* pInterfaceMenu);
		void Render();
	}
}