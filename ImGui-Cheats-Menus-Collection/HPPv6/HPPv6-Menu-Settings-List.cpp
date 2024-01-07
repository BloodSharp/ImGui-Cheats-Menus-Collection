#include "IGCMC-Precompiled.h"

std::string& CMenuSettingsList::GetFocusSettings()
{
	const auto i = static_cast<int>(m_settings_list.size() - 1);

	m_selected_settings = std::clamp(m_selected_settings, 0, i);

	return m_settings_list[m_selected_settings];
}

void CMenuSettingsList::RefreshSettingsList()
{
	if (!m_settings_list.empty())
		m_settings_list.clear();

	/*
	const auto path = g_pGlobals->m_sSettingsPath + "*";

	WIN32_FIND_DATA FindFileData;
	HANDLE hFileFind = FindFirstFile(path.c_str(), &FindFileData);

	if (!hFileFind || hFileFind == INVALID_HANDLE_VALUE)
		return;

	do
	{
		if (!strstr(FindFileData.cFileName, "."))
		{
			char buf[MAX_PATH];
			LPSTR lpFilePart = NULL;
			GetFullPathName(path.c_str(), MAX_PATH, buf, &lpFilePart);

			if (!strstr(FindFileData.cFileName, "*.ini"))
				m_settings_list.push_back(FindFileData.cFileName);
		}

	} while (FindNextFile(hFileFind, &FindFileData));

	FindClose(hFileFind);
	*/
}

void CMenuSettingsList::SetFocusSettings(std::string name)
{
	for (size_t i = 0; i < m_settings_list.size(); i++)
	{
		if (!m_settings_list[i].compare(name))
		{
			m_selected_settings = static_cast<int>(i);
			break;
		}
	}
}