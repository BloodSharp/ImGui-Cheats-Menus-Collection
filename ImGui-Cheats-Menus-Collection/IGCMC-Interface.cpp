#include "IGCMC-Precompiled.h"

std::vector<IGCMC_Interface_Menu_t*> gInterfacesLoaded;

void IGCMC::Interfaces::AddInterfaceData(IGCMC_Interface_Menu_t* pInterfaceMenu)
{
	bool bInterfaceFound = false;

	for (size_t uiInterfaceIndex = 0; uiInterfaceIndex < gInterfacesLoaded.size(); uiInterfaceIndex++)
	{
		if (gInterfacesLoaded[uiInterfaceIndex] == pInterfaceMenu)
		{
			bInterfaceFound = true;
		}
	}

	if (!bInterfaceFound)
	{
		gInterfacesLoaded.push_back(pInterfaceMenu);
	}
}

void IGCMC::Interfaces::RemoveInterfaceData(IGCMC_Interface_Menu_t* pInterfaceMenu)
{
	for (size_t uiInterfaceIndex = 0; uiInterfaceIndex < gInterfacesLoaded.size(); uiInterfaceIndex++)
	{
		if (gInterfacesLoaded[uiInterfaceIndex] == pInterfaceMenu)
		{
			gInterfacesLoaded.erase(gInterfacesLoaded.begin() + uiInterfaceIndex);
		}
	}
}

void IGCMC::Interfaces::Render()
{
	size_t uiInterfaceIndex;

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("All menus##IGCMC::Interfaces::Render"))
		{
			for (uiInterfaceIndex = 0; uiInterfaceIndex < gInterfacesLoaded.size(); uiInterfaceIndex++)
			{
				ImGui::MenuItem(gInterfacesLoaded[uiInterfaceIndex]->m_szMenuName, 0, gInterfacesLoaded[uiInterfaceIndex]->m_bIsThisMenuActive);
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	for (uiInterfaceIndex = 0; uiInterfaceIndex < gInterfacesLoaded.size(); uiInterfaceIndex++)
	{
		if (gInterfacesLoaded[uiInterfaceIndex]->m_bIsThisMenuActive)
		{
			if (gInterfacesLoaded[uiInterfaceIndex]->SetupInterface)
				gInterfacesLoaded[uiInterfaceIndex]->SetupInterface(&gInterfacesLoaded[uiInterfaceIndex]->m_bIsInitialized);
			if (gInterfacesLoaded[uiInterfaceIndex]->Render)
				gInterfacesLoaded[uiInterfaceIndex]->Render(&gInterfacesLoaded[uiInterfaceIndex]->m_bIsThisMenuActive);
		}
	}
}

void IGCMC::Interfaces::ClearAllInterfaceData()
{
	for (size_t uiInterfaceIndex = 0; uiInterfaceIndex < gInterfacesLoaded.size(); uiInterfaceIndex++)
	{
		if (gInterfacesLoaded[uiInterfaceIndex])
		{
			if (gInterfacesLoaded[uiInterfaceIndex]->SetupInterface)
				gInterfacesLoaded[uiInterfaceIndex]->SetupInterface = 0;
			if (gInterfacesLoaded[uiInterfaceIndex]->Render)
				gInterfacesLoaded[uiInterfaceIndex]->Render = 0;
			if (gInterfacesLoaded[uiInterfaceIndex]->DestroyInterface)
				gInterfacesLoaded[uiInterfaceIndex]->DestroyInterface(&gInterfacesLoaded[uiInterfaceIndex]->m_bIsInitialized);

			delete gInterfacesLoaded[uiInterfaceIndex];
			gInterfacesLoaded[uiInterfaceIndex] = 0;
		}
	}

	gInterfacesLoaded.clear();
}