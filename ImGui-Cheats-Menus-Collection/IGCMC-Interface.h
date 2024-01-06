#pragma once

#include "IGCMC-Precompiled.h"

class IGCMC_Interface_Menu_t
{
public:
	bool m_bIsThisMenuActive;
	bool m_bIsInitialized;
	const char* m_szMenuName;
	const char* m_szWebsite;
	void(*SetupInterface)(bool *pbIsInitialized);
	void(*DestroyInterface)(bool* pbIsInitialized);
	void(*Render)(bool* pbMustCloseThisMenu);

	IGCMC_Interface_Menu_t()
	{
		this->m_bIsThisMenuActive = false;
		this->m_bIsInitialized = false;
		this->m_szMenuName = 0;
		this->m_szWebsite = 0;
		this->SetupInterface = 0;
		this->DestroyInterface = 0;
		this->Render = 0;
	}

	IGCMC_Interface_Menu_t(const char* szMenuName, decltype(Render) pRender = 0, decltype(SetupInterface) pSetup = 0, decltype(DestroyInterface) pDestroy = 0, const char* szWebsite = 0)
	{
		this->m_bIsThisMenuActive = false;
		this->m_bIsInitialized = false;
		this->m_szMenuName = szMenuName;
		this->m_szWebsite = szWebsite;
		this->SetupInterface = pSetup;
		this->DestroyInterface = pDestroy;
		this->Render = pRender;
	}
};

namespace IGCMC
{
	namespace Interfaces
	{
		void AddInterfaceData(IGCMC_Interface_Menu_t* pInterfaceMenu);
		void RemoveInterfaceData(IGCMC_Interface_Menu_t* pInterfaceMenu);
		void Render();
		void ClearAllInterfaceData();
	}
}