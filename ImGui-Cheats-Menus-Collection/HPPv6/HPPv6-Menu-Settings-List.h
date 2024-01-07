#pragma once

#include "IGCMC-Precompiled.h"

class CMenuSettingsList
{
public:
	std::vector<std::string> m_settings_list;

	int m_selected_settings;
	int m_selected_file;

	std::string& GetFocusSettings();

	void RefreshSettingsList();
	void SetFocusSettings(std::string name);
};