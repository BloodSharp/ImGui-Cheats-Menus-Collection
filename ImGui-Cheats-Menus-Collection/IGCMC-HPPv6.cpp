#include "IGCMC-Precompiled.h"

ImFont* g_pFontList[MAX_FONTS];
ImageInfo_HPPv6 g_pImageList[MAX_IMAGES];

/*
Source leaked, idk who actually leaked...
*/

void IGCMC::Interfaces::Cheats::HPPv6::Setup(bool* pbIsInitialized)
{
	if (!*pbIsInitialized)
	{
		*pbIsInitialized = true;
		g_pRenderer = std::make_unique<CRenderer>();
		g_pMenu = std::make_unique<CMenu>();
		g_pNotifications = std::make_unique<CNotifications>();

		IGCMC::Utils::LoadTextureFromMemory(menu_title_bytes, sizeof(menu_title_bytes), &g_pImageList[MenuTitleBg].data, &g_pImageList[MenuTitleBg].size.x, &g_pImageList[MenuTitleBg].size.y);

		IGCMC::Utils::LoadTextureFromMemory(rage_icon_bytes, sizeof(rage_icon_bytes), &g_pImageList[TabRageIcon].data, &g_pImageList[TabRageIcon].size.x, &g_pImageList[TabRageIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(legit_icon_bytes, sizeof(legit_icon_bytes), &g_pImageList[TabLegitIcon].data, &g_pImageList[TabLegitIcon].size.x, &g_pImageList[TabLegitIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(visuals_icon_bytes, sizeof(visuals_icon_bytes), &g_pImageList[TabVisualsIcon].data, &g_pImageList[TabVisualsIcon].size.x, &g_pImageList[TabVisualsIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(kreedz_icon_bytes, sizeof(kreedz_icon_bytes), &g_pImageList[TabKreedzIcon].data, &g_pImageList[TabKreedzIcon].size.x, &g_pImageList[TabKreedzIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(misc_icon_bytes, sizeof(misc_icon_bytes), &g_pImageList[TabMiscIcon].data, &g_pImageList[TabMiscIcon].size.x, &g_pImageList[TabMiscIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(configs_icon_bytes, sizeof(configs_icon_bytes), &g_pImageList[TabConfigsIcon].data, &g_pImageList[TabConfigsIcon].size.x, &g_pImageList[TabConfigsIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(console_icon_bytes, sizeof(console_icon_bytes), &g_pImageList[TabConsoleIcon].data, &g_pImageList[TabConsoleIcon].size.x, &g_pImageList[TabConsoleIcon].size.y);

		IGCMC::Utils::LoadTextureFromMemory(wpn_pistols_icon_bytes, sizeof(wpn_pistols_icon_bytes), &g_pImageList[WpnPistolsIcon].data, &g_pImageList[WpnPistolsIcon].size.x, &g_pImageList[WpnPistolsIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(wpn_rifles_icon_bytes, sizeof(wpn_rifles_icon_bytes), &g_pImageList[WpnRiflesIcon].data, &g_pImageList[WpnRiflesIcon].size.x, &g_pImageList[WpnRiflesIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(wpn_snipers_icon_bytes, sizeof(wpn_snipers_icon_bytes), &g_pImageList[WpnSnipersIcon].data, &g_pImageList[WpnSnipersIcon].size.x, &g_pImageList[WpnSnipersIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(wpn_shotguns_icon_bytes, sizeof(wpn_shotguns_icon_bytes), &g_pImageList[WpnShotgunsIcon].data, &g_pImageList[WpnShotgunsIcon].size.x, &g_pImageList[WpnShotgunsIcon].size.y);
		IGCMC::Utils::LoadTextureFromMemory(wpn_smgs_icon_bytes, sizeof(wpn_smgs_icon_bytes), &g_pImageList[WpnSmgsIcon].data, &g_pImageList[WpnSmgsIcon].size.x, &g_pImageList[WpnSmgsIcon].size.y);

		IGCMC::Utils::LoadTextureFromMemory(weapon_ak47_bytes, sizeof(weapon_ak47_bytes), &g_pImageList[WPN_AK47].data, &g_pImageList[WPN_AK47].size.x, &g_pImageList[WPN_AK47].size.y);
		IGCMC::Utils::LoadTextureFromMemory(weapon_aug_bytes, sizeof(weapon_aug_bytes), &g_pImageList[WPN_AUG].data, &g_pImageList[WPN_AUG].size.x, &g_pImageList[WPN_AUG].size.y);
		/*
		IGCMC::Utils::LoadTextureFromMemory(weapon_awp_bytes, sizeof(weapon_awp_bytes), &g_pImageList[WPN_AWP]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_c4_bytes, sizeof(weapon_c4_bytes), &g_pImageList[WPN_C4]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_deagle_bytes, sizeof(weapon_deagle_bytes), &g_pImageList[WPN_DEAGLE]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_elite_bytes, sizeof(weapon_elite_bytes), &g_pImageList[WPN_ELITE]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_famas_bytes, sizeof(weapon_famas_bytes), &g_pImageList[WPN_FAMAS]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_fiveseven_bytes, sizeof(weapon_fiveseven_bytes), &g_pImageList[WPN_FIVESEVEN]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_flashbang_bytes, sizeof(weapon_flashbang_bytes), &g_pImageList[WPN_FLASHBANG]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_g3sg1_bytes, sizeof(weapon_g3sg1_bytes), &g_pImageList[WPN_G3SG1]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_galil_bytes, sizeof(weapon_galil_bytes), &g_pImageList[WPN_GALIL]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_glock18_bytes, sizeof(weapon_glock18_bytes), &g_pImageList[WPN_GLOCK18]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_hegrenade_bytes, sizeof(weapon_hegrenade_bytes), &g_pImageList[WPN_HEGRENADE]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_knife_bytes, sizeof(weapon_knife_bytes), &g_pImageList[WPN_KNIFE]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_m249_bytes, sizeof(weapon_m249_bytes), &g_pImageList[WPN_M249]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_m4a1_bytes, sizeof(weapon_m4a1_bytes), &g_pImageList[WPN_M4A1]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_m3_bytes, sizeof(weapon_m3_bytes), &g_pImageList[WPN_M3]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_mac10_bytes, sizeof(weapon_mac10_bytes), &g_pImageList[WPN_MAC10]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_mp5_bytes, sizeof(weapon_mp5_bytes), &g_pImageList[WPN_MP5N]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_p228_bytes, sizeof(weapon_p228_bytes), &g_pImageList[WPN_P228]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_p90_bytes, sizeof(weapon_p90_bytes), &g_pImageList[WPN_P90]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_scout_bytes, sizeof(weapon_scout_bytes), &g_pImageList[WPN_SCOUT]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_sg550_bytes, sizeof(weapon_sg550_bytes), &g_pImageList[WPN_SG550]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_sg552_bytes, sizeof(weapon_sg552_bytes), &g_pImageList[WPN_SG552]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_smokegrenade_bytes, sizeof(weapon_smokegrenade_bytes), &g_pImageList[WPN_SMOKEGRENADE]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_tmp_bytes, sizeof(weapon_tmp_bytes), &g_pImageList[WPN_TMP]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_ump45_bytes, sizeof(weapon_ump45_bytes), &g_pImageList[WPN_UMP45]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_usp_bytes, sizeof(weapon_usp_bytes), &g_pImageList[WPN_USP]);
		IGCMC::Utils::LoadTextureFromMemory(weapon_xm1014_bytes, sizeof(weapon_xm1014_bytes), &g_pImageList[WPN_XM1014]);

		IGCMC::Utils::LoadTextureFromMemory(defuser_bytes, sizeof(defuser_bytes), &g_pImageList[DefuserIcon]);
		*/
	}
}

void HppRenderScene(void* hDeviceContext)
{
	//if (Game::IsConnected() && !IS_NULLPTR(g_pVisuals))
		//g_pVisuals->Overlay();

	g_pMenu->DrawFadeBg();
	//g_pMenu->CursorState((void*)::WindowFromDC((HDC)hDeviceContext));
	g_pMenu->Draw();

	g_pNotifications->Draw();
}

void IGCMC::Interfaces::Cheats::HPPv6::Destroy(bool* pbIsInitialized)
{
	if (*pbIsInitialized)
	{

	}
}

void IGCMC::Interfaces::Cheats::HPPv6::Render(bool* pbMustOpenThisMenu)
{
	if (*pbMustOpenThisMenu)
	{
		g_pRenderer->RenderScene(&::HppRenderScene, 0);
	}
}
