#pragma once

#include "IGCMC-Precompiled.h"

static const char* weapons_pistols_HPPv6[] = { "subsection", "glock18", "usp", "p228", "deagle", "elite", "fiveseven" };
static const char* weapons_submachineguns_HPPv6[] = { "subsection", "m249", "tmp", "p90", "mp5", "mac10", "ump45" };
static const char* weapons_rifles_HPPv6[] = { "subsection", "m4a1", "galil", "famas", "aug", "ak47", "sg552" };
static const char* weapons_shotguns_HPPv6[] = { "subsection", "xm1014", "m3" };
static const char* weapons_snipers_HPPv6[] = { "subsection", "awp", "scout", "g3sg1", "sg550" };

class CMenu
{
public:
	CMenu();

	bool IsOpened();

	void Open();
	void Close();
	void Toggle();

	void CursorState(void* hwnd);
	void DrawFadeBg();
	void Draw();

private:
	std::unique_ptr<CMenuGui> m_pGui;
	std::unique_ptr<CMenuPopupModal> m_pPopupModal;
	std::unique_ptr<CMenuHotkeys> m_pHotkeys;
	std::unique_ptr<CMenuSettingsList> m_pSettingsList;
	std::unique_ptr<CMenuFadeBg> m_pFadeBg;
	std::unique_ptr<CMenuThemes> m_pThemes;

	bool m_bIsOpened;

	ImVec2 m_WindowPos;
	ImVec2 m_WindowSize;
	ImVec2 m_WindowCanvasPos;
	ImVec2 m_WindowCanvasSize;

	int m_iSelectedTab;
	int m_iHoveredTab;

	void DialogSettingsSaveAs(char* buf, size_t size);
	void DialogSettingsRename(char* buf, size_t size);
	void DialogSettingsReset();
	void DialogSettingsRemove();
	void DialogFindAndReplace(char* buf);

	void DrawRage();
	void DrawLegit();
	void DrawVisuals();
};

extern std::unique_ptr<CMenu> g_pMenu;