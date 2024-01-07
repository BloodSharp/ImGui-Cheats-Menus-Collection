#pragma once

#include "IGCMC-Precompiled.h"

#define MAX_TOTAL_CMDS		62 //if (build_num < 5971) choke_limit = 16;

enum EFontList_HPPv6
{
	ProggyClean_13px,
	Verdana_1px,
	Verdana_2px,
	Verdana_3px,
	Verdana_4px,
	Verdana_5px,
	Verdana_6px,
	Verdana_7px,
	Verdana_8px,
	Verdana_9px,
	Verdana_10px,
	Verdana_11px,
	Verdana_12px,
	Verdana_13px,
	Verdana_14px,
	Verdana_15px,
	Verdana_16px,
	Verdana_17px,
	Verdana_18px,
	Verdana_19px,
	Verdana_20px,
	Verdana_21px,
	Verdana_22px,
	Verdana_23px,
	Verdana_24px,
	Verdana_25px,
	MAX_FONTS
};

enum EFontOffsetList_HPPv6
{
	FontProggyCleanOffset = 0,
	FontVerdanaOffset = 1
};

enum EImageList_HPPv6
{
	MenuTitleBg,

	TabRageIcon,
	TabLegitIcon,
	TabVisualsIcon,
	TabKreedzIcon,
	TabMiscIcon,
	TabConfigsIcon,
	TabConsoleIcon,

	WpnPistolsIcon,
	WpnSmgsIcon,
	WpnRiflesIcon,
	WpnShotgunsIcon,
	WpnSnipersIcon,

	WPN_NONE,
	WPN_P228,
	WPN_GLOCK,
	WPN_SCOUT,
	WPN_HEGRENADE,
	WPN_XM1014,
	WPN_C4,
	WPN_MAC10,
	WPN_AUG,
	WPN_SMOKEGRENADE,
	WPN_ELITE,
	WPN_FIVESEVEN,
	WPN_UMP45,
	WPN_SG550,
	WPN_GALIL,
	WPN_FAMAS,
	WPN_USP,
	WPN_GLOCK18,
	WPN_AWP,
	WPN_MP5N,
	WPN_M249,
	WPN_M3,
	WPN_M4A1,
	WPN_TMP,
	WPN_G3SG1,
	WPN_FLASHBANG,
	WPN_DEAGLE,
	WPN_SG552,
	WPN_AK47,
	WPN_KNIFE,
	WPN_P90,

	DefuserIcon,

	MAX_IMAGES
};

struct ImageInfo_HPPv6
{
	//ImTextureID data;
	GLuint data;
	ImVec2 size;
};

enum EImageOffsetsList_HPPv6
{
	IconsTabsOffset = 1,
	IconsWpnsOffset = 8,
	IconsEspWpnsOffset = 13
};

extern ImFont* g_pFontList[MAX_FONTS];
extern ImageInfo_HPPv6 g_pImageList[MAX_IMAGES];

namespace IGCMC
{
	namespace Interfaces
	{
		namespace Cheats
		{
			namespace HPPv6
			{
				void Setup(bool* pbIsInitialized);
				void Destroy(bool* pbIsInitialized);
				void Render(bool* pbMustOpenThisMenu);
			}
		}
	}
}