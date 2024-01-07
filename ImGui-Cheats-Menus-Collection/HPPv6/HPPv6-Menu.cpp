#include "IGCMC-Precompiled.h"

CMenu::CMenu()
	: m_pGui(std::make_unique<CMenuGui>())
	, m_pPopupModal(std::make_unique<CMenuPopupModal>())
	, m_pHotkeys(std::make_unique<CMenuHotkeys>())
	, m_pSettingsList(std::make_unique<CMenuSettingsList>())
	, m_pFadeBg(std::make_unique<CMenuFadeBg>())
	//, m_pThemes(std::make_unique<CMenuThemes>())
	, m_bIsOpened(true)
{
	this->m_iHoveredTab = 0;
	//m_pThemes->SetDefaultDarkTheme();
}

bool CMenu::IsOpened()
{
	return m_bIsOpened;
}

void CMenu::Open()
{
	if (!m_bIsOpened)
		m_bIsOpened = true;
}

void CMenu::Close()
{
	if (m_bIsOpened)
		m_bIsOpened = false;
}

void CMenu::Toggle()
{
	m_bIsOpened ? Close() : Open();
}

void CMenu::CursorState(void* hwnd)
{
	/*
	bool bUseMouse = this->IsOpened();
	bool bWindowHasFocus = hwnd ? hwnd == (void*)GetActiveWindow() : (g_pGlobals->m_bIsSDL2Hooked ? true : false);
	GImGui->IO.MouseDrawCursor = bUseMouse;
	if (bWindowHasFocus)
	{
		if (bUseMouse && g_pClient->IN_DeactivateMouse)
			g_pClient->IN_DeactivateMouse();
		else if (!bUseMouse && g_pClient->IN_ActivateMouse)
		{
			g_pClient->IN_ActivateMouse();
			ImGui::SetMouseCursor(ImGuiMouseCursor_None);
		}
	}
	*/

	/*
	static bool SetCursorState;
	static int nCenterCursorFrames;

	if (GImGui->IO.MouseDrawCursor = IsOpened())
	{
		g_pISurface->UnlockCursor();
		g_pISurface->SetCursor(Cursor::dc_arrow);

		if (!SetCursorState && (!cvars::visuals.streamer_mode || !g_pIGameUI->IsGameUIActive()))
		{
			ShowCursor(FALSE);

			nCenterCursorFrames = 2;
			SetCursorState = true;
		}

		if (!g_pIGameUI->IsGameUIActive() && !(nCenterCursorFrames--))
			g_pISurface->SurfaceSetCursorPos((int)(GImGui->IO.DisplaySize.x) / 2, (int)(GImGui->IO.DisplaySize.y) / 2);
	}
	else if (SetCursorState)
	{
		ShowCursor(TRUE);

		g_pISurface->CalculateMouseVisible();

		SetCursorState = false;
	}
	*/
}

void CMenu::DrawFadeBg()
{
	m_pFadeBg->Init();
	m_pFadeBg->Run();
}

static char input_buf[64];

enum WeaponTablesList { PISTOL, SMG, RIFLE, SHOTGUN, SNIPER, MAX_WEPON_GROUPS };

void WeaponCombo(const std::unique_ptr<CMenuGui>& m_pGui, int selected_weapon_group, int* selected_weapon)
{
	switch (selected_weapon_group)
	{
	case PISTOL:	m_pGui->Combo(selected_weapon, "##weapon_group", weapons_pistols_HPPv6, IM_ARRAYSIZE(weapons_pistols_HPPv6), "", true); break;
	case SMG:		m_pGui->Combo(selected_weapon, "##weapon_group", weapons_submachineguns_HPPv6, IM_ARRAYSIZE(weapons_submachineguns_HPPv6), "", true); break;
	case RIFLE:		m_pGui->Combo(selected_weapon, "##weapon_group", weapons_rifles_HPPv6, IM_ARRAYSIZE(weapons_rifles_HPPv6), "", true); break;
	case SHOTGUN:	m_pGui->Combo(selected_weapon, "##weapon_group", weapons_shotguns_HPPv6, IM_ARRAYSIZE(weapons_shotguns_HPPv6), "", true); break;
	case SNIPER:	m_pGui->Combo(selected_weapon, "##weapon_group", weapons_snipers_HPPv6, IM_ARRAYSIZE(weapons_snipers_HPPv6), "", true);
	}
}

void ChangeToCurrentWeapon(int* selected_weapon_group, int* selected_weapon)
{
	//if (g_pGlobals->m_bIsInGame && g_Local->m_bIsConnected && g_Weapon->m_iWeaponID)
	if (0)
	{
		//const auto weapon_name = Game::GetWeaponName(g_Weapon->m_iWeaponID);

		/*
		for (int i = 1; i < IM_ARRAYSIZE(weapons_pistols_HPPv6); i++)
		{
			if (!weapon_name.compare(weapons_pistols_HPPv6[i]))
			{
				*selected_weapon_group = PISTOL;
				*selected_weapon = i;
				break;
			}
		}

		for (int i = 1; i < IM_ARRAYSIZE(weapons_submachineguns_HPPv6); i++)
		{
			if (!weapon_name.compare(weapons_submachineguns_HPPv6[i]))
			{
				*selected_weapon_group = SMG;
				*selected_weapon = i;
				break;
			}
		}

		for (int i = 1; i < IM_ARRAYSIZE(weapons_rifles_HPPv6); i++)
		{
			if (!weapon_name.compare(weapons_rifles_HPPv6[i]))
			{
				*selected_weapon_group = RIFLE;
				*selected_weapon = i;
				break;
			}
		}

		for (int i = 1; i < IM_ARRAYSIZE(weapons_shotguns_HPPv6); i++)
		{
			if (!weapon_name.compare(weapons_shotguns_HPPv6[i]))
			{
				*selected_weapon_group = SHOTGUN;
				*selected_weapon = i;
				break;
			}
		}

		for (int i = 1; i < IM_ARRAYSIZE(weapons_snipers_HPPv6); i++)
		{
			if (!weapon_name.compare(weapons_snipers_HPPv6[i]))
			{
				*selected_weapon_group = SNIPER;
				*selected_weapon = i;
				break;
			}
		}
		*/
	}
}

void GetCurrentWeaponId(int selected_weapon_group, int selected_weapon, int* current_weapon_id)
{
	/*
	if (selected_weapon)
	{
		switch (selected_weapon_group)
		{
		case PISTOL:	*current_weapon_id = Game::GetWeaponIndex(weapons_pistols_HPPv6[selected_weapon]); break;
		case SMG:		*current_weapon_id = Game::GetWeaponIndex(weapons_submachineguns_HPPv6[selected_weapon]); break;
		case RIFLE:		*current_weapon_id = Game::GetWeaponIndex(weapons_rifles_HPPv6[selected_weapon]); break;
		case SHOTGUN:	*current_weapon_id = Game::GetWeaponIndex(weapons_shotguns_HPPv6[selected_weapon]); break;
		case SNIPER:	*current_weapon_id = Game::GetWeaponIndex(weapons_snipers_HPPv6[selected_weapon]);
		}
	}
	else
	*/
	{
		switch (selected_weapon_group)
		{
		case PISTOL:	*current_weapon_id = WEAPON_DEAGLE; break;
		case SMG:		*current_weapon_id = WEAPON_UMP45; break;
		case RIFLE:		*current_weapon_id = WEAPON_AK47; break;
		case SHOTGUN:	*current_weapon_id = WEAPON_XM1014; break;
		case SNIPER:	*current_weapon_id = WEAPON_AWP;
		}
	}
}

static void ChangeValuesWholeGroup(int selected_weapon_group, int current_weapon_id)
{
	switch (selected_weapon_group)
	{
	case PISTOL:
		//for (int i = 1; i < IM_ARRAYSIZE(weapons_pistols_HPPv6); i++)
			//cvars::weapons[Game::GetWeaponIndex(weapons_pistols_HPPv6[i])] = cvars::weapons[current_weapon_id];
		break;
	case SMG:
		//for (int i = 1; i < IM_ARRAYSIZE(weapons_submachineguns_HPPv6); i++)
			//cvars::weapons[Game::GetWeaponIndex(weapons_submachineguns_HPPv6[i])] = cvars::weapons[current_weapon_id];
		break;
	case RIFLE:
		//for (int i = 1; i < IM_ARRAYSIZE(weapons_rifles_HPPv6); i++)
			//cvars::weapons[Game::GetWeaponIndex(weapons_rifles_HPPv6[i])] = cvars::weapons[current_weapon_id];
		break;
	case SHOTGUN:
		//for (int i = 1; i < IM_ARRAYSIZE(weapons_shotguns_HPPv6); i++)
			//cvars::weapons[Game::GetWeaponIndex(weapons_shotguns_HPPv6[i])] = cvars::weapons[current_weapon_id];
		break;
	case SNIPER:
		//for (int i = 1; i < IM_ARRAYSIZE(weapons_snipers_HPPv6); i++)
			//cvars::weapons[Game::GetWeaponIndex(weapons_snipers_HPPv6[i])] = cvars::weapons[current_weapon_id];
		break;
	}
}

void CMenu::DialogSettingsSaveAs(char* buf, size_t size)
{
	m_pPopupModal->Input("Settings name:", buf, size);

	if (m_pPopupModal->Button("Save") || m_pHotkeys->Is("ENTER"))
	{
		if (strlen(buf))
		{
			//const auto path = g_pGlobals->m_sSettingsPath + buf;
			//const auto result = CreateDirectory(path.c_str(), 0);
			const auto result = false;

			if (result)
			{
				m_pSettingsList->RefreshSettingsList();
				m_pSettingsList->SetFocusSettings(buf);

				//g_pSettings->Save(m_pSettingsList->GetFocusSettings().c_str());
			}
			else
			{
				std::string name, message;

				name = HPPv6__Utils__FormatString("Error saving settings \"%s\".", buf);

				/*
				const auto error_code = GetLastError();

				switch (error_code)
				{
				case ERROR_ALREADY_EXISTS:
					message = "The specified directory already exists.";
					break;
				case ERROR_PATH_NOT_FOUND:
					message = "One or more intermediate directories do not exist.";
					break;
				default:
					message = "Could not create directory.";
				}
				*/
				message = "Not supported for menus colection.";

				g_pNotifications->Push(name, message);
			}

			RtlSecureZeroMemory(buf, size);
			ImGui::CloseCurrentPopup();
		}
	}

	if (m_pPopupModal->Button("Cancel") || m_pHotkeys->Is("ESC"))
	{
		RtlSecureZeroMemory(buf, size);
		ImGui::CloseCurrentPopup();
	}
}

void CMenu::DialogSettingsRename(char* buf, size_t size)
{
	m_pPopupModal->Input("Settings name:", buf, size);

	if (m_pPopupModal->Button("Rename") || m_pHotkeys->Is("ENTER"))
	{
		if (strlen(buf) && _strcmpi(buf, "Default"))
		{
			/*
			const auto path_exist = g_pGlobals->m_sSettingsPath + m_pSettingsList->GetFocusSettings();
			const auto path_new = g_pGlobals->m_sSettingsPath + buf;
			const auto result = MoveFile(path_exist.c_str(), path_new.c_str());
			*/
			const auto result = false;

			if (result)
			{
				m_pSettingsList->RefreshSettingsList();
				m_pSettingsList->SetFocusSettings(buf);
			}
			else
			{
				const auto name = HPPv6__Utils__FormatString("Error renaming settings \"%s\".", buf);

				g_pNotifications->Push(name, "Could not rename directory.");
			}
		}

		RtlSecureZeroMemory(buf, size);
		ImGui::CloseCurrentPopup();
	}

	if (m_pPopupModal->Button("Cancel") || m_pHotkeys->Is("ESC"))
	{
		RtlSecureZeroMemory(buf, size);
		ImGui::CloseCurrentPopup();
	}
}

void CMenu::DialogSettingsReset()
{
	m_pPopupModal->Message("Choose the type of reset.");

	if (m_pPopupModal->Button("Set as default") || m_pHotkeys->Is("ENTER"))
	{
		//g_pSettings->Reset(m_pSettingsList->GetFocusSettings(), true);

		ImGui::CloseCurrentPopup();
	}

	if (m_pPopupModal->Button("Save settings") || m_pHotkeys->Is("CTRL + S"))
	{
		//g_pSettings->Reset(m_pSettingsList->GetFocusSettings(), false);

		ImGui::CloseCurrentPopup();
	}

	if (m_pHotkeys->Is("ESC"))
		ImGui::CloseCurrentPopup();
}

void CMenu::DialogSettingsRemove()
{
	m_pPopupModal->Message("Are you sure you want to delete?");

	if (m_pPopupModal->Button("Delete") || m_pHotkeys->Is("ENTER"))
	{
		//g_pSettings->Remove(m_pSettingsList->GetFocusSettings());

		m_pSettingsList->RefreshSettingsList();
		m_pSettingsList->GetFocusSettings();

		ImGui::CloseCurrentPopup();
	}

	if (m_pPopupModal->Button("Cancel") || m_pHotkeys->Is("ESC"))
		ImGui::CloseCurrentPopup();
}

void CMenu::DialogFindAndReplace(char* buf)
{
	static char search_buf[256], replace_buf[256];

	constexpr auto InputTextOffsetX = 64.f;

	ImGui::Text("Find");
	ImGui::SameLine(InputTextOffsetX);
	ImGui::InputText("##find", search_buf, sizeof(search_buf));

	ImGui::Text("Replace");
	ImGui::SameLine(InputTextOffsetX);
	ImGui::InputText("##replace", replace_buf, sizeof(replace_buf));

	ImGui::Spacing();

	if (m_pPopupModal->Button("Apply") || m_pHotkeys->Is("ENTER"))
	{
		HPPv6__Utils__StringReplace(buf, search_buf, replace_buf);
		RtlSecureZeroMemory(search_buf, sizeof(search_buf));
		RtlSecureZeroMemory(replace_buf, sizeof(replace_buf));
		ImGui::CloseCurrentPopup();
	}

	if (m_pPopupModal->Button("Cancel") || m_pHotkeys->Is("ESC"))
	{
		RtlSecureZeroMemory(search_buf, sizeof(search_buf));
		RtlSecureZeroMemory(replace_buf, sizeof(replace_buf));
		ImGui::CloseCurrentPopup();
	}
}

static std::vector<TabWidgetsData> main_tables_data;
static std::vector<TabWidgetsData> weapon_tables_data;
static std::vector<TabWidgetsData> rage_tables_data;
static std::vector<TabWidgetsData> rage_anti_aim_tables_data;
static std::vector<TabWidgetsData> visuals_tables_data;
static std::vector<TabWidgetsData> visuals_other_tables_data;
static std::vector<TabWidgetsData> misc_tables_data;

//ExampleAppConsole g_Console;

void CMenu::Draw()
{
	enum MainTablesList { LEGIT, RAGE, VISUALS, KREEDZ, MISC, CONFIGS, CONSOLE };
	enum RageTablesList { RAGE_MAIN, RAGE_WEAPON };
	enum RageAntiAimTablesList { RAGE_ANTIAIM_MAIN, RAGE_ANTIAIM_STAND, RAGE_ANTIAIM_MOVE };
	enum VisualsTablesList { VISUALS_ESP, VISUALS_CHAMS, VISUALS_OTHER, VISUALS_GUI, VISUALS_COLORS };
	enum VisualsOtherTablesList { VISUALS_OTHER_LOCAL, VISUALS_OTHER_WORLD };
	enum MiscTablesList { MISC_GENERAL, MISC_ENHANCEMENT };

	if (main_tables_data.empty())
	{
		main_tables_data.push_back(TabWidgetsData{ "LEGIT", 0.f });
		main_tables_data.push_back(TabWidgetsData{ "RAGE", 0.f });
		main_tables_data.push_back(TabWidgetsData{ "VISUALS", 0.f });
		main_tables_data.push_back(TabWidgetsData{ "KREEDZ", 0.f });
		main_tables_data.push_back(TabWidgetsData{ "MISC", 0.f });
		main_tables_data.push_back(TabWidgetsData{ "CONFIGS", 0.f });
		main_tables_data.push_back(TabWidgetsData{ "CONSOLE", 0.f });
	}

	if (weapon_tables_data.empty())
	{
		weapon_tables_data.push_back(TabWidgetsData{ "PISTOL", 0.f });
		weapon_tables_data.push_back(TabWidgetsData{ "SMG", 0.f });
		weapon_tables_data.push_back(TabWidgetsData{ "RIFLE", 0.f });
		weapon_tables_data.push_back(TabWidgetsData{ "SHOTGUN", 0.f });
		weapon_tables_data.push_back(TabWidgetsData{ "SNIPER", 0.f });
	}

	if (rage_tables_data.empty())
	{
		rage_tables_data.push_back(TabWidgetsData{ "MAIN", 0.f });
		rage_tables_data.push_back(TabWidgetsData{ "WEAPON", 0.f });
	}

	if (rage_anti_aim_tables_data.empty())
	{
		rage_anti_aim_tables_data.push_back(TabWidgetsData{ "MAIN", 0.f });
		rage_anti_aim_tables_data.push_back(TabWidgetsData{ "STAND", 0.f });
		rage_anti_aim_tables_data.push_back(TabWidgetsData{ "MOVE", 0.f });
	}

	if (visuals_tables_data.empty())
	{
		visuals_tables_data.push_back(TabWidgetsData{ "ESP", 0.f });
		visuals_tables_data.push_back(TabWidgetsData{ "CHAMS", 0.f });
		visuals_tables_data.push_back(TabWidgetsData{ "OTHER", 0.f });
		visuals_tables_data.push_back(TabWidgetsData{ "GUI", 0.f });
		visuals_tables_data.push_back(TabWidgetsData{ "COLORS", 0.f });
	}

	if (visuals_other_tables_data.empty())
	{
		visuals_other_tables_data.push_back(TabWidgetsData{ "LOCAL", 0.f });
		visuals_other_tables_data.push_back(TabWidgetsData{ "WORLD", 0.f });
	}

	if (misc_tables_data.empty())
	{
		misc_tables_data.push_back(TabWidgetsData{ "GENERAL", 0.f });
		misc_tables_data.push_back(TabWidgetsData{ "ENHANCEMENT", 0.f });
	}

	if (!m_bIsOpened)
		return;

	if (m_pGui->Begin("##menu", ImVec2(800, 600)))
	{
		m_WindowPos = GImGui->CurrentWindow->Pos;
		m_WindowSize = GImGui->CurrentWindow->Size;
		m_WindowCanvasPos = ImVec2(m_WindowPos.x, m_WindowPos.y + MENU_TAB_HEIGHT);
		m_WindowCanvasSize = ImVec2(m_WindowSize.x, m_WindowSize.y - MENU_TAB_HEIGHT - WINDOW_UNDERGROUND_HEIGHT);

		m_pGui->TabBackground();
		m_pGui->TabList(main_tables_data, m_iSelectedTab, m_iHoveredTab);

		ImGui::SetNextWindowPos(m_WindowCanvasPos);

		m_pGui->BeginCanvas("##menu_canvas", m_WindowCanvasSize);
		m_pGui->TabSeparator();

		ImGui::PushFont(g_pFontList[Verdana_13px]);

		ImVec2 child_size;

		switch (m_iSelectedTab)
		{
		case LEGIT:
		{
			static int weapon_tables_selected, weapon_tables_hovered;
			static int current_weapon_id, selected_weapon[MAX_WEPON_GROUPS];
			static bool auto_change_current_weapon;

			if (cvars::legitbot.active && cvars::ragebot.active)
				cvars::ragebot.active = false;

			ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
			ImGui::SameLine(WINDOW_PADDING_SAMELINE);

			ImGui::BeginGroup();

			m_pGui->SetChildSize(child_size);

			child_size.y = FEATURE_BUTTON_SIZE;

			m_pGui->SmallGroupBox("##visuals_general", child_size, [&]()
				{ m_pGui->Checkbox(&auto_change_current_weapon, "Current"); }, [&]()
				{ WeaponCombo(m_pGui, weapon_tables_selected, &selected_weapon[weapon_tables_selected]); });

			if (auto_change_current_weapon)
				ChangeToCurrentWeapon(&weapon_tables_selected, &selected_weapon[weapon_tables_selected]);

			GetCurrentWeaponId(weapon_tables_selected, selected_weapon[weapon_tables_selected], &current_weapon_id);

			m_pGui->BeginCheckChangeValue();

			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			child_size.x += child_size.x + WINDOW_PADDING_SAMELINE;

			m_pGui->BeginGroupBox("##LegitWeaponList", child_size);
			m_pGui->TabWeaponList(weapon_tables_data, weapon_tables_selected, weapon_tables_hovered);
			m_pGui->EndGroupBox();

			ImGui::Spacing_HPPv6(3);

			ImGui::BeginGroup();

			m_pGui->SetChildSize(child_size);

			child_size.y -= WINDOW_PADDING_SAMELINE * 2.f;
			child_size.y *= 0.33f;

			m_pGui->BeginGroupBox("General", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##legit_general");
			m_pGui->Checkbox(&cvars::legitbot.active, "Enabled");
			m_pGui->Checkbox(&cvars::legitbot.friendly_fire, "Friendly fire");
			m_pGui->Checkbox(&cvars::legitbot.position_adjustment, "Position adjustment");
			m_pGui->Checkbox(&cvars::legitbot.desync_helper, "Desync helper");
			m_pGui->Slider(&cvars::legitbot.target_switch_delay, "Target switch delay", 0, 1000, "%ims");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::Spacing_HPPv6(3);

			const char* aim_recoil_standalone[] = { "None", "Default", "Return angles" };

			m_pGui->BeginGroupBox("Aimbot main", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##legit_aimbot_main");
			m_pGui->Key(&cvars::legitbot.aim_key, "Key");
			m_pGui->Key(&cvars::legitbot.aim_psilent_key, "Perfect silent key");
			m_pGui->Checkbox(&cvars::legitbot.aim_auto_scope, "Automatic scope");
			m_pGui->Checkbox(&cvars::legitbot.aim_smooth_independence_fps, "Smooth independence FPS");
			m_pGui->Checkbox(&cvars::legitbot.aim_dont_shoot_in_shield, "Don't shoot in shield");
			m_pGui->Checkbox(&cvars::legitbot.aim_demochecker_bypass, "Demochecker bypass");
			m_pGui->Slider(&cvars::legitbot.aim_block_attack_after_kill, "Block attack after kill", 0, 1000, "%ims");
			m_pGui->Combo(&cvars::legitbot.aim_recoil_standalone, "Recoil compensation standalone", aim_recoil_standalone, IM_ARRAYSIZE(aim_recoil_standalone));
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::Spacing_HPPv6(3);

			child_size.y = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_SAMELINE;

			m_pGui->BeginGroupBox("Triggerbot main", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##legit_triggerbot_main");
			m_pGui->Key(&cvars::legitbot.trigger_key, "Key");
			m_pGui->Checkbox(&cvars::legitbot.trigger_accurate_traces, "Accurate traces");
			m_pGui->Checkbox(&cvars::legitbot.trigger_only_scoped, "Only scoped");
			m_pGui->Slider(&cvars::legitbot.trigger_hitbox_scale, "Hitbox scale", 1.f, 200.f, "%.0f%%", 1.f);
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::EndGroup();

			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			const char* aim_psilent_type[] = { "Manual", "Automatic fire" };
			const char* aim_psilent_triggers[] = { "Standing", "On land", "In air" };
			const char* aim_accuracy_boost[] = { "None", "Bound box (Recoil)", "Bound box (Recoil / Spread)", "Recoil", "Recoil / Spread" };
			const char* aim_hitboxes[] = { "Head", "Neck", "Chest", "Stomach", "Arms", "Legs" };

			m_pGui->SetChildSize(child_size);
			m_pGui->BeginGroupBox("Aimbot", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##legit_aimbot");
			m_pGui->Checkbox(&cvars::weapons[current_weapon_id].aim_enabled, "Enabled");
			m_pGui->Checkbox(&cvars::weapons[current_weapon_id].aim_auto_fire, "Automatic fire");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_fov, "Maximum FOV", 0.f, 180.f, "%.1f�", 2.5f);
			m_pGui->MultiCombo(cvars::weapons[current_weapon_id].aim_hitboxes, "Hitboxes", aim_hitboxes, IM_ARRAYSIZE(aim_hitboxes));
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_smooth_auto, "Smooth automatic", 0.f, 300.f, "%.1f", 2.5f);
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_smooth_in_attack, "Smooth in attack", 1.f, 300.f, "%.1f", 2.5f);
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_smooth_scale_fov, "Smooth scale - FOV", 0.f, 100.f, "%.0f%%", 1.f);
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_recoil_fov, "Recoil compensation maximum FOV", 0.f, 180.f, "%.1f�", 2.5f);
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_recoil_smooth, "Recoil compensation smooth", 1.f, 300.f, "%.1f", 2.5f);
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_recoil_pitch, "Recoil compensation pitch", 1.f, 100.f, "%.0f%%", 1.f, "Vertical.");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_recoil_yaw, "Recoil compensation yaw", 1.f, 100.f, "%.0f%%", 1.f, "Horizontal.");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_recoil_start, "Recoil compensation start", 0, 15, cvars::weapons[current_weapon_id].aim_recoil_start ? "%i bullet" : "if there is recoil");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_psilent_angle, "Perfect silent maximum angle", 0.f, 1.f, "%.1f�", 1.f);
			m_pGui->Combo(&cvars::weapons[current_weapon_id].aim_psilent_type, "Perfect silent type", aim_psilent_type, IM_ARRAYSIZE(aim_psilent_type));
			m_pGui->MultiCombo(cvars::weapons[current_weapon_id].aim_psilent_triggers, "Perfect silent triggers", aim_psilent_triggers, IM_ARRAYSIZE(aim_psilent_triggers));
			m_pGui->Checkbox(&cvars::weapons[current_weapon_id].aim_psilent_tapping_mode, "Perfect silent tapping mode");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_maximum_lock_on_time, "Maximum lock-on time", 0, 10000, "%ims");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_delay_before_aiming, "Delay before aiming", 0, 1000, "%ims");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_delay_before_firing, "Delay before firing", 0, 1000, "%ims");
			m_pGui->Combo(&cvars::weapons[current_weapon_id].aim_accuracy_boost, "Accuracy boost", aim_accuracy_boost, IM_ARRAYSIZE(aim_accuracy_boost));
			m_pGui->Checkbox(&cvars::weapons[current_weapon_id].aim_auto_penetration, "Automatic penetration");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].aim_auto_penetration_min_damage, "Automatic penetration min. damage", 1, 100, "%i");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			m_pGui->SetChildSize(child_size);

			const char* trigger_hitboxes[] = { "Head", "Neck", "Chest", "Stomach", "Arms", "Legs" };
			const char* trigger_accuracy_boost[] = { "None", "Recoil", "Recoil / Spread" };

			m_pGui->BeginGroupBox("Triggerbot", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##legit_triggerbot");
			m_pGui->Checkbox(&cvars::weapons[current_weapon_id].trigger_enabled, "Enabled");
			m_pGui->MultiCombo(cvars::weapons[current_weapon_id].trigger_hitboxes, "Hitboxes", trigger_hitboxes, IM_ARRAYSIZE(trigger_hitboxes));
			m_pGui->Combo(&cvars::weapons[current_weapon_id].trigger_accuracy_boost, "Accuracy boost", trigger_accuracy_boost, IM_ARRAYSIZE(trigger_accuracy_boost));
			m_pGui->Checkbox(&cvars::weapons[current_weapon_id].trigger_auto_penetration, "Automatic penetration");
			m_pGui->Slider(&cvars::weapons[current_weapon_id].trigger_auto_penetration_min_damage, "Automatic penetration min. damage", 1, 100, "%i");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::EndGroup();

			if (!selected_weapon[weapon_tables_selected] && m_pGui->IsChangedValue())
				ChangeValuesWholeGroup(weapon_tables_selected, current_weapon_id);

			m_pGui->EndCheckChangeValue();

			break;
		}
		case RAGE:
		{
			static int rage_tables_selected, rage_tables_hovered;
			static int rage_anti_aim_tables_selected, rage_anti_aim_tables_hovered;

			if (cvars::ragebot.active && cvars::legitbot.active)
				cvars::legitbot.active = false;

			m_pGui->TabFeaturesList(rage_tables_data, rage_tables_selected, rage_tables_hovered);

			switch (rage_tables_selected)
			{
			case RAGE_MAIN:
			{
				ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
				ImGui::SameLine(WINDOW_PADDING_SAMELINE);

				const char* raim_type[] = { "Visible", "Silent (Client-Side)", "Perfect silent (Server-Side)" };
				const char* raim_auto_scope[] = { "None", "No unzoom", "Unzoom" };
				const char* raim_remove_spread[] = { "None", "Pitch / Yaw", "Pitch / Roll", "Pitch / Yaw / Roll" };
				const char* raim_resolver_pitch[] = { "None", "Breakpoint 90�" };
				const char* raim_resolver_yaw[] = { "None", "Desyns bruteforce" };
				const char* raim_delayshot[] = { "Unlag", "History" };
				const char* raim_fps_mitigations[] = { "Traces only if can attack", "Don't trace arms points", "Don't trace legs points" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("General", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##rage_general");
				m_pGui->Checkbox(&cvars::ragebot.active, "Enabled");
				m_pGui->Checkbox(&cvars::ragebot.friendly_fire, "Friendly fire");
				m_pGui->Checkbox(&cvars::ragebot.raim_auto_fire, "Automatic fire");
				m_pGui->Slider(&cvars::ragebot.raim_fov, "Maximum FOV", 0.f, 180.f, "%.0f�", 1.f);
				m_pGui->Combo(&cvars::ragebot.raim_type, "Aim type", raim_type, IM_ARRAYSIZE(raim_type));
				m_pGui->Checkbox(&cvars::ragebot.raim_remove_recoil, "Remove recoil");
				m_pGui->Combo(&cvars::ragebot.raim_remove_spread, "Remove spread", raim_remove_spread, IM_ARRAYSIZE(raim_remove_spread));
				m_pGui->Combo(&cvars::ragebot.raim_auto_scope, "Automatic scope", raim_auto_scope, IM_ARRAYSIZE(raim_auto_scope));
				m_pGui->Key(&cvars::ragebot.raim_force_body_key, "Force body aim");
				m_pGui->Combo(&cvars::ragebot.raim_resolver_pitch, "Pitch resolver", raim_resolver_pitch, IM_ARRAYSIZE(raim_resolver_pitch));
				//m_pGui->Combo(&cvars::ragebot.raim_resolver_yaw, "Yaw resolver", raim_resolver_yaw, IM_ARRAYSIZE(raim_resolver_yaw));
				m_pGui->MultiCombo(cvars::ragebot.raim_delayshot, "Delay shot", raim_delayshot, IM_ARRAYSIZE(raim_delayshot));
				m_pGui->Checkbox(&cvars::ragebot.raim_tapping_mode, "Tapping mode");
				m_pGui->MultiCombo(cvars::ragebot.raim_low_fps_mitigations, "Low FPS mitigations", raim_fps_mitigations, IM_ARRAYSIZE(raim_fps_mitigations));
				m_pGui->Slider(&cvars::ragebot.raim_low_fps_value, "Low FPS value", 20.f, 1001.f, "%.0f fps", 1.f);
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				child_size.y = 32.f;

				m_pGui->BeginGroupBox("##Anti-Aim", child_size);
				m_pGui->TabFeaturesList(rage_anti_aim_tables_data, rage_anti_aim_tables_selected, rage_anti_aim_tables_hovered);
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Anti-Aim", child_size);
				m_pGui->BeginWidgetsGroup();

				switch (rage_anti_aim_tables_selected)
				{
				case RAGE_ANTIAIM_MAIN:
				{
					const char* aa_roll[] = { "None", "Sideways 50�", "Sideways 90�", "Sideways 180�", "Static" };
					const char* aa_conditions[] = { "On knife", "On grenades", "On freeze period" };
					const char* aa_at_targets[] = { "None", "Closest by FOV", "Average" };

					m_pGui->SetID("##rage_antiaim_main");
					m_pGui->Checkbox(&cvars::ragebot.aa_enabled, "Enabled");
					m_pGui->Checkbox(&cvars::ragebot.aa_teammates, "Teammates");
					m_pGui->Combo(&cvars::ragebot.aa_at_targets, "At targets", aa_at_targets, IM_ARRAYSIZE(aa_at_targets));
					m_pGui->Combo(&cvars::ragebot.aa_roll, "Roll", aa_roll, IM_ARRAYSIZE(aa_roll), "It works only on special servers. (Example: hvh.hpp.ovh:27015)");
					m_pGui->Slider(&cvars::ragebot.aa_roll_static, "Roll static", -180.f, 180.f, "%.0f�", 1.f);
					m_pGui->MultiCombo(cvars::ragebot.aa_conditions, "Conditions", aa_conditions, IM_ARRAYSIZE(aa_conditions));
					m_pGui->Checkbox(&cvars::ragebot.aa_untrusted_checks, "Untrusted checks", "Use only trusted angles.");
					break;
				}
				case RAGE_ANTIAIM_STAND:
				{
					const char* aa_side[] = { "Left", "Right" };
					const char* aa_stand_pitch[] = { "None", "Down", "Up", "Fake down", "Fake up", "Jitter", "Fake jitter" };
					const char* aa_stand_yaw[] = { "None", "Backwards", "Sideways 90�", "Sideways 140�", "Static", "Local view", "Backwards desyns", };
					const char* aa_stand_desync[] = { "None", "Default", "Max delta" };

					m_pGui->SetID("##rage_antiaim_stand");
					m_pGui->Combo(&cvars::ragebot.aa_stand_pitch, "Pitch", aa_stand_pitch, IM_ARRAYSIZE(aa_stand_pitch));
					m_pGui->Combo(&cvars::ragebot.aa_stand_yaw, "Yaw", aa_stand_yaw, IM_ARRAYSIZE(aa_stand_yaw));
					m_pGui->Slider(&cvars::ragebot.aa_stand_yaw_static, "Yaw static", -180.f, 180.f, "%.0f�", 1.f);
					m_pGui->Combo(&cvars::ragebot.aa_stand_desync, "Desync", aa_stand_desync, IM_ARRAYSIZE(aa_stand_desync));
					m_pGui->Checkbox(&cvars::ragebot.aa_stand_desync_helper, "Desync helper");
					m_pGui->Combo(&cvars::ragebot.aa_side, "Side", aa_side, IM_ARRAYSIZE(aa_side));
					m_pGui->KeyToggle(&cvars::ragebot.aa_side_key, "Side switch key");
					m_pGui->Checkbox(&cvars::ragebot.aa_side_switch_when_take_damage, "Side switch when take damage");
					break;
				}
				case RAGE_ANTIAIM_MOVE:
				{
					const char* aa_move_pitch[] = { "None", "Down", "Up", "Fake down", "Fake up", "Jitter", "Fake jitter" };
					const char* aa_move_yaw[] = { "None", "Backwards", "Local view", "Gait sideways 120�" };

					m_pGui->SetID("##rage_antiaim_move");
					m_pGui->Combo(&cvars::ragebot.aa_move_pitch, "Pitch", aa_move_pitch, IM_ARRAYSIZE(aa_move_pitch));
					m_pGui->Combo(&cvars::ragebot.aa_move_yaw, "Yaw", aa_move_yaw, IM_ARRAYSIZE(aa_move_yaw));
				}
				}

				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

				const char* fakelag_triggers[] = { "In move", "In air" };
				const char* fakelag_type[] = { "Maximum", "Break lag compensation" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Fakelag", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##rage_fakelag");
				m_pGui->Checkbox(&cvars::ragebot.fakelag_enabled, "Enabled");
				m_pGui->Combo(&cvars::ragebot.fakelag_type, "Type", fakelag_type, IM_ARRAYSIZE(fakelag_type));
				m_pGui->MultiCombo(cvars::ragebot.fakelag_triggers, "Triggers", fakelag_triggers, IM_ARRAYSIZE(fakelag_triggers));
				//m_pGui->Slider(&cvars::ragebot.fakelag_choke_limit, "Choke limit", 1, MAX_TOTAL_CMDS, "%i cmd", "Server max commands: " + std::to_string(g_pGlobals->m_nNewCommands));
				m_pGui->Slider(&cvars::ragebot.fakelag_choke_limit, "Choke limit", 1, MAX_TOTAL_CMDS, "%i cmd", "Server max commands: " + std::to_string(MAX_TOTAL_CMDS));
				m_pGui->Checkbox(&cvars::ragebot.fakelag_while_shooting, "While shooting");
				m_pGui->Checkbox(&cvars::ragebot.fakelag_on_enemy_in_pvs, "On enemy in PVS");
				m_pGui->Checkbox(&cvars::ragebot.fakelag_on_peek, "On peek");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				break;
			}
			case RAGE_WEAPON:
			{
				static int weapon_tables_selected, weapon_tables_hovered;
				static int current_weapon_id, selected_weapon[MAX_WEPON_GROUPS];
				static bool auto_change_current_weapon;

				ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
				ImGui::SameLine(WINDOW_PADDING_SAMELINE);

				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y = FEATURE_BUTTON_SIZE;

				m_pGui->SmallGroupBox("##visuals_general", child_size, [&]()
					{ m_pGui->Checkbox(&auto_change_current_weapon, "Current"); }, [&]()
					{ WeaponCombo(m_pGui, weapon_tables_selected, &selected_weapon[weapon_tables_selected]); });

				if (auto_change_current_weapon)
					ChangeToCurrentWeapon(&weapon_tables_selected, &selected_weapon[weapon_tables_selected]);

				GetCurrentWeaponId(weapon_tables_selected, selected_weapon[weapon_tables_selected], &current_weapon_id);

				m_pGui->BeginCheckChangeValue();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

				child_size.x += child_size.x + WINDOW_PADDING_SAMELINE;

				m_pGui->BeginGroupBox("##RageWeaponList", child_size);
				m_pGui->TabWeaponList(weapon_tables_data, weapon_tables_selected, weapon_tables_hovered);
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				const char* raim_target_selection[] = { "Highest damage", "Closest by FOV", "Hitbox weights" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Target", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##rage_weapon_target");
				m_pGui->MultiCombo(cvars::ragebot.raim_target_selection, "Target selection", raim_target_selection, IM_ARRAYSIZE(raim_target_selection));
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_damage, "Damage weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_fov, "FOV weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_head, "Head weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_neck, "Neck weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_chest, "Chest weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_stomach, "Stomach weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_arms, "Arms weight", 1, 100, "%i");
				m_pGui->Slider(&cvars::ragebot.raim_target_weight_legs, "Legs weight", 1, 100, "%i");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

				const char* raim_hitboxes[] = { "Head", "Neck", "Chest", "Stomach", "Arms", "Legs" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Aimbot", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##rage_weapon_aimbot");
				m_pGui->Checkbox(&cvars::weapons[current_weapon_id].raim_enabled, "Enabled");
				m_pGui->MultiCombo(cvars::weapons[current_weapon_id].raim_hitboxes, "Hitboxes", raim_hitboxes, IM_ARRAYSIZE(raim_hitboxes));
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_head_scale, "Head points scale", 0.f, 100.f, "%.0f%%", 1.f);
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_neck_scale, "Neck points scale", 0.f, 100.f, "%.0f%%", 1.f);
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_chest_scale, "Chest points scale", 0.f, 100.f, "%.0f%%", 1.f);
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_stomach_scale, "Stomach points scale", 0.f, 100.f, "%.0f%%", 1.f);
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_arms_scale, "Arms points scale", 0.f, 100.f, "%.0f%%", 1.f);
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_legs_scale, "Legs points scale", 0.f, 100.f, "%.0f%%", 1.f);
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

				const char* raim_autostop[] = { "None", "Minimal speed", "Full stop" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Accuracy", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##rage_weapon_accuracy");
				m_pGui->Checkbox(&cvars::weapons[current_weapon_id].raim_auto_penetration, "Auto penetration");
				m_pGui->Slider(&cvars::weapons[current_weapon_id].raim_auto_penetration_min_damage, "Auto penetration min. damage", 1, 100, "%i");
				m_pGui->Combo(&cvars::weapons[current_weapon_id].raim_autostop, "Auto stop", raim_autostop, IM_ARRAYSIZE(raim_autostop));
				m_pGui->Checkbox(&cvars::weapons[current_weapon_id].raim_autostop_crouch, "Auto stop crouch");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();

				if (!selected_weapon[weapon_tables_selected] && m_pGui->IsChangedValue())
					ChangeValuesWholeGroup(weapon_tables_selected, current_weapon_id);

				m_pGui->EndCheckChangeValue();

				break;
			}
			}

			m_pGui->TabShadow(GImGui->CurrentWindow->Pos + ImVec2(0, 36), GImGui->CurrentWindow->Pos + ImVec2(0, 36) +
				ImVec2(GImGui->CurrentWindow->Size.x, 20), ImVec4(0.08f, 0.08f, 0.08f, 1.00f));

			break;
		}
		case VISUALS:
		{
			static int visuals_tables_selected, visuals_tables_hovered;
			static int visuals_other_tables_selected, visuals_other_tables_hovered;

			m_pGui->TabFeaturesList(visuals_tables_data, visuals_tables_selected, visuals_tables_hovered);

			ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
			ImGui::SameLine(WINDOW_PADDING_SAMELINE);

			switch (visuals_tables_selected)
			{
			case VISUALS_ESP:
			{
				const char* player_filters[] = { "Local", "Enemies", "Teammates" };
				const char* player_filters_without_local[] = { "Enemies", "Teammates" };
				const char* player_box_types[] = { "None", "Default", "Corner", "Round" };
				const char* player_pos[] = { "None", "Left", "Right", "Top", "Bot" };
				const char* player_distance_measurement[] = { "Units", "Meters" };
				const char* player_hiboxes[] = { "None", "Only head", "All hitboxes" };
				const char* player_out_of_fov[] = { "Arrows", "Circles", "Rhombuses" };
				const char* player_out_of_fov_additional_info[] = { "Name", "Weapon", "Distance" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Player", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_players_player");
				m_pGui->Checkbox(&cvars::visuals.esp_player, "Enabled", "Enable rendering of players.");
				m_pGui->MultiCombo(cvars::visuals.esp_player_players, "Players", player_filters, IM_ARRAYSIZE(player_filters), "Choose the players on whom rendering will work.");
				m_pGui->Combo(&cvars::visuals.esp_player_box, "Bound box", player_box_types, IM_ARRAYSIZE(player_box_types), "Draw a box on the players.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_box_outline, "Bound box outline", "Draw the outline of the boxes.");
				m_pGui->Slider(&cvars::visuals.esp_player_box_filled, "Bound box filled", 0, 100, "%i%%", "Transparency of the filled box.");
				m_pGui->Combo(&cvars::visuals.esp_player_health, "Health bar", player_pos, IM_ARRAYSIZE(player_pos), "Draw a health bar.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_health_percentage, "Health percentage", "Show health percentage on the bar.");
				m_pGui->Combo(&cvars::visuals.esp_player_armor, "Armor bar", player_pos, IM_ARRAYSIZE(player_pos), "Draw a armor bar.");
				m_pGui->Combo(&cvars::visuals.esp_player_name, "Name", player_pos, IM_ARRAYSIZE(player_pos), "Display player name.");
				m_pGui->Combo(&cvars::visuals.esp_player_weapon_text, "Weapon text", player_pos, IM_ARRAYSIZE(player_pos), "Display player's weapon in text.");
				m_pGui->Combo(&cvars::visuals.esp_player_weapon_icon, "Weapon icon", player_pos, IM_ARRAYSIZE(player_pos), "Display player's weapon with icon.");
				m_pGui->Combo(&cvars::visuals.esp_player_money, "Money", player_pos, IM_ARRAYSIZE(player_pos), "Display player money.");
				m_pGui->Combo(&cvars::visuals.esp_player_distance, "Distance", player_pos, IM_ARRAYSIZE(player_pos), "Display player distance from you.");
				m_pGui->Combo(&cvars::visuals.esp_player_distance_measurement, "Distance measurement", player_distance_measurement, IM_ARRAYSIZE(player_distance_measurement));
				m_pGui->Combo(&cvars::visuals.esp_player_actions, "Actions", player_pos, IM_ARRAYSIZE(player_pos), "Display player actions.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_actions_bar, "Actions bar");
				m_pGui->Combo(&cvars::visuals.esp_player_has_c4, "Has C4", player_pos, IM_ARRAYSIZE(player_pos), "Display player with c4.");
				m_pGui->Combo(&cvars::visuals.esp_player_has_defusal_kits, "Has defusal kits", player_pos, IM_ARRAYSIZE(player_pos), "Display player with defusal kits.");
				m_pGui->Slider(&cvars::visuals.esp_player_line_of_sight, "Line of sight", 0.f, 4096.f, "%.0f", 2.f, "Draw player line of sight.");
				m_pGui->Combo(&cvars::visuals.esp_player_hitboxes, "Hitboxes", player_hiboxes, IM_ARRAYSIZE(player_hiboxes), "Draw player hitboxes.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_hitboxes_hit_position, "Hitboxes hit position", "Draw player hitboxes in hit position.");
				m_pGui->Slider(&cvars::visuals.esp_player_hitboxes_hit_position_time, "Hitboxes hit position time", 0.1f, 5.f, "%.1fs", 1.f, "Display time of the player hitboxes in hit position.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_skeleton, "Skeleton", "Draw player skeleton.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_skeleton_backtrack, "Skeleton backtrack", "Draw player skeleton on backtrack position.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y -= WINDOW_PADDING_SAMELINE;
				child_size.y *= 0.5f;

				m_pGui->BeginGroupBox("Filter", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_players_globals");
				m_pGui->Slider(&cvars::visuals.esp_dormant_time, "Dormant time", 0.f, 5.f, "%.1fs", 1.f, "Display time of dormant player in the last updated position.");
				m_pGui->Checkbox(&cvars::visuals.esp_dormant_fadeout, "Dormant fade out", "Smooth fade out dormant player.");
				m_pGui->Checkbox(&cvars::visuals.esp_dormant_update_by_sound, "Dormant update by sound", "Update dormant players by sound.");
				m_pGui->Checkbox(&cvars::visuals.esp_interpolate_history, "Interpolate history", "Smooth movements of dormant players.");
				m_pGui->Slider(&cvars::visuals.esp_font_size, "Font size", 8, 16, "%i");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->BeginGroupBox("Radar", child_size);
				m_pGui->BeginWidgetsGroup();
				ImGui::Text("Soon...");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y -= WINDOW_PADDING_SAMELINE * 2.f;
				child_size.y *= 0.33f;

				m_pGui->BeginGroupBox("Glow", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_players_glow");
				m_pGui->Checkbox(&cvars::visuals.esp_player_glow, "Enabled", "Turn on the glow of the players.");
				m_pGui->MultiCombo(cvars::visuals.esp_player_glow_players, "Players", player_filters, IM_ARRAYSIZE(player_filters), "Choose the players on whom the glow will work.");
				m_pGui->Slider(&cvars::visuals.esp_player_glow_amount, "Amount", 1, 10, "%i", "Amount of glow.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_glow_color_health_based, "Color health based", "Sets color based on health.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->BeginGroupBox("Sound", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_players_sound");
				m_pGui->Checkbox(&cvars::visuals.esp_player_sounds, "Enabled", "Enable display of player sounds.");
				m_pGui->MultiCombo(cvars::visuals.esp_player_sounds_players, "Players", player_filters, IM_ARRAYSIZE(player_filters), "Choose the players on whom the sound esp will work.");
				m_pGui->Slider(&cvars::visuals.esp_player_sounds_time, "Fade out time", 0.1f, 2.f, "%.1fs", 1.f, "The time after which the player's sound disappears completely.");
				m_pGui->Slider(&cvars::visuals.esp_player_sounds_circle_radius, "Circle radius", 1.f, 20.f, "%.0f", 1.f, "The circle radius of the drawn sound.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				child_size.y = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_SAMELINE;

				m_pGui->BeginGroupBox("Out of FOV", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_players_out_of_fov");
				m_pGui->Checkbox(&cvars::visuals.esp_player_out_of_fov, "Enabled", "Enable display of players out of sight.");
				m_pGui->Combo(&cvars::visuals.esp_player_out_of_fov_draw_type, "Draw type", player_out_of_fov, IM_ARRAYSIZE(player_out_of_fov), "Type of drawing players out of sight.");
				m_pGui->MultiCombo(cvars::visuals.esp_player_out_of_fov_players, "Players", player_filters_without_local, IM_ARRAYSIZE(player_filters_without_local), "Choose the players on whom the out of fov will work.");
				m_pGui->MultiCombo(cvars::visuals.esp_player_out_of_fov_additional_info, "Additional info", player_out_of_fov_additional_info, IM_ARRAYSIZE(player_out_of_fov_additional_info), "Enable display of player additional info out of sight.");
				m_pGui->Slider(&cvars::visuals.esp_player_out_of_fov_size, "Size", 5.f, 15.f, "%.0fpx", 1.f, "The size of the figures of the displayed players out of sight.");
				m_pGui->Slider(&cvars::visuals.esp_player_out_of_fov_radius, "Radius", 10.f, 100.f, "%.0f%%", 1.f, "The radius of the drawn objects from the center of the screen of the displayed players are out of sight.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_out_of_fov_aspect_ratio, "Aspect ratio", "Follow aspect ratio.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_out_of_fov_impulse_alpha, "Impulse alpha", "Enable impulsive transparency change.");
				m_pGui->Checkbox(&cvars::visuals.esp_player_out_of_fov_outline, "Outline", "Draw the outline.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				break;
			}
			case VISUALS_CHAMS:
			{
				const char* player_filters[] = { "Local", "Enemies", "Teammates" };
				const char* player_filters_without_local[] = { "Enemies", "Teammates" };
				const char* colored_models[] = { "None", "Flat", "Darkened", "Ligthed", "Texture" };
				const char* colored_models_health_based[] = { "None", "Visible", "Always" };
				const char* origin[] = { "Legs", "Body", "Head" };

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Player", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colored_models_players");
				m_pGui->Combo(&cvars::visuals.colored_models_players, "Enabled", colored_models, IM_ARRAYSIZE(colored_models), "Enable rendering of the players with the selected type of painting.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_players_wireframe, "Wireframe", "Enable rendering of the player in the grid.");
				m_pGui->MultiCombo(cvars::visuals.colored_models_players_players, "Players", player_filters, IM_ARRAYSIZE(player_filters), "Choose the players on whom the chams will work.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_players_behind_wall, "Behind wall", "Enable rendering of players behind the wall.");
				m_pGui->Combo(&cvars::visuals.colored_models_players_color_health_based, "Color health based", colored_models_health_based, IM_ARRAYSIZE(colored_models_health_based), "Sets color based on health.");
				m_pGui->Combo(&cvars::visuals.colored_models_players_on_the_dead, "On the dead", colored_models, IM_ARRAYSIZE(colored_models), "Enable rendering on dead players.");
				m_pGui->Combo(&cvars::visuals.colored_models_players_hit_position, "Hit position", colored_models, IM_ARRAYSIZE(colored_models), "Enable rendering of the model in the hit position.");
				m_pGui->Slider(&cvars::visuals.colored_models_players_hit_position_time, "Hit position time", 0.1f, 5.f, "%.1fs", 1.f, "Display time of the hit position.");
				m_pGui->Combo(&cvars::visuals.colored_models_players_desync_aa, "Desync AA", colored_models, IM_ARRAYSIZE(colored_models), "Enable desync local player rendering.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y -= WINDOW_PADDING_SAMELINE;
				child_size.y *= 0.5f;

				m_pGui->BeginGroupBox("Filter", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colored_models_globals");
				m_pGui->Slider(&cvars::visuals.colored_models_dormant_time, "Dormant time", 0.f, 5.f, "%.1fs", 1.f, "Display time of dormant player in the last updated position.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_dormant_fadeout, "Dormant fade out", "Enable smooth fade out dormant player.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_paint_players_weapons, "Paint players weapons", "Paint players weapons.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->BeginGroupBox("Backtrack", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colored_models_backtrack");
				m_pGui->Combo(&cvars::visuals.colored_models_backtrack, "Enabled", colored_models, IM_ARRAYSIZE(colored_models), "Enable rendering of the players in the backtrack position with the selected type of painting.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_backtrack_wireframe, "Wireframe", "Enable rendering of the player in the backtrack position in the grid.");
				m_pGui->MultiCombo(cvars::visuals.colored_models_backtrack_players, "Players", player_filters_without_local, IM_ARRAYSIZE(player_filters_without_local), "Choose the players on whom the chams will work.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_backtrack_behind_wall, "Behind wall", "Enable rendering of players in the backtrack position behind the wall.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y -= WINDOW_PADDING_SAMELINE * 2.f;
				child_size.y *= 0.33f;

				m_pGui->BeginGroupBox("Dlight", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colored_models_dlight");
				m_pGui->Checkbox(&cvars::visuals.colored_models_dlight, "Enabled", "Turn on the dlight on the players.");
				m_pGui->MultiCombo(cvars::visuals.colored_models_dlight_players, "Players", player_filters, IM_ARRAYSIZE(player_filters), "Choose the players on whom the dlight will work.");
				m_pGui->Combo(&cvars::visuals.colored_models_dlight_origin, "Origin", origin, IM_ARRAYSIZE(origin), "Light source.");
				m_pGui->Slider(&cvars::visuals.colored_models_dlight_radius, "Radius", 0.f, 250.f, "%.0f", 1.f, "Lighting radius.");
				m_pGui->Slider(&cvars::visuals.colored_models_dlight_minlight, "Minlight", 0.f, 250.f, "%.0f", 1.f, "Minimum light value.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_dlight_fading_lighting, "Fading lighting", "Enable fading lighting.");
				m_pGui->Slider(&cvars::visuals.colored_models_dlight_fading_lighting_speed, "Fading lighting speed", 0.1f, 2.f, "%.1f", 1.f, "Fading lighting speed.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->BeginGroupBox("Elight", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colored_models_elight");
				m_pGui->Checkbox(&cvars::visuals.colored_models_elight, "Enabled", "Turn on the elight on the players");
				m_pGui->MultiCombo(cvars::visuals.colored_models_elight_players, "Players", player_filters, IM_ARRAYSIZE(player_filters), "Choose the players on whom the elight will work.");
				m_pGui->Slider(&cvars::visuals.colored_models_elight_radius, "Radius", 0.f, 250.f, "%.0f", 1.f, "Lighting radius.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				child_size.y = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_SAMELINE;

				m_pGui->BeginGroupBox("Hands", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colored_models_hands");
				m_pGui->Combo(&cvars::visuals.colored_models_hands, "Enabled", colored_models, IM_ARRAYSIZE(colored_models), "Enable hand rendering of the selected paint type.");
				m_pGui->Checkbox(&cvars::visuals.colored_models_hands_wireframe, "Wireframe", "Enable rendering of the hands in the grid");
				m_pGui->Checkbox(&cvars::visuals.colored_models_hands_color_rainbow, "Rainbow color", "Enable rainbow color change.");
				m_pGui->Slider(&cvars::visuals.colored_models_hands_color_rainbow_speed, "Rainbow speed", 0.1f, 2.f, "%.1f", 1.f, "Color change rate.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				break;
			}
			case VISUALS_OTHER:
			{
				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y -= WINDOW_PADDING_SAMELINE * 2.f;
				child_size.y *= 0.33f;

				m_pGui->BeginGroupBox("Main", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->Checkbox(&cvars::visuals.active, "Enabled", "Global on/off of visuals stuff.");
				m_pGui->Key(&cvars::visuals.panic_key, "Panic key");
				m_pGui->Checkbox(&cvars::visuals.copyright, "Copyright");
				m_pGui->Checkbox(&cvars::visuals.antiscreen, "Antiscreen");
				m_pGui->Checkbox(&cvars::visuals.streamer_mode, "Streamer mode", "All visual functions are not visible on the recording/broadcasting programs.");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				child_size.y = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_SAMELINE;

				m_pGui->BeginGroupBox("Crosshair", child_size);
				m_pGui->BeginWidgetsGroup();
				ImGui::Text("Soon..");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				child_size.y = 32.f;

				m_pGui->BeginGroupBox("##visuals_other_tabs", child_size);
				m_pGui->TabFeaturesList(visuals_other_tables_data, visuals_other_tables_selected, visuals_other_tables_hovered);
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->SetChildSize(child_size);

				switch (visuals_other_tables_selected)
				{
				case VISUALS_OTHER_LOCAL:
				{
					m_pGui->BeginGroupBox("Local", child_size);
					m_pGui->BeginWidgetsGroup();
					m_pGui->SetID("##visuals_other_local");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_aa_side_arrows, "Anti-aimbot side arrows");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_sniper_crosshair, "Sniper crosshair", "Enable crosshair on sniper rifles.");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_recoil_point, "Recoil point");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_spread_point, "Spread point");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_spread_circle, "Spread circle");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_aim_fov, "Aim FOV", "Display aimbot field of view.");
					m_pGui->Checkbox(&cvars::visuals.esp_other_local_toggle_status, "Toggle status");
					break;
				}
				case VISUALS_OTHER_WORLD:
				{
					m_pGui->BeginGroupBox("World", child_size);
					m_pGui->BeginWidgetsGroup();
					m_pGui->SetID("##visuals_other_world");
					ImGui::Text("Soon...");
				}
				}

				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
				ImGui::BeginGroup();

				m_pGui->SetChildSize(child_size);

				child_size.y -= WINDOW_PADDING_SAMELINE;
				child_size.y *= 0.5f;

				m_pGui->BeginGroupBox("Removals", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_other_removals");
				m_pGui->Checkbox(&cvars::visuals.remove_scope, "Remove scope");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::Spacing_HPPv6(3);

				m_pGui->BeginGroupBox("Effects", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_other_effects");
				m_pGui->Checkbox(&cvars::visuals.effects_hud_clear, "HUD clear");
				m_pGui->Slider(&cvars::visuals.effects_thirdperson, "Thirdperson", 0, 512, "%i");
				m_pGui->Key(&cvars::visuals.effects_thirdperson_key, "Thirdperson key");
				m_pGui->Slider(&cvars::visuals.effects_custom_render_fov, "Custom render FOV", 90, 150, "%i");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::EndGroup();
				break;
			}
			case VISUALS_GUI:
			{
				ImGui::Text("Soon...");
				break;
			}
			case VISUALS_COLORS:
			{
				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Player", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colors_player");
				m_pGui->ColorEdit(cvars::visuals.esp_player_box_color_t, "Box T");
				m_pGui->ColorEdit(cvars::visuals.esp_player_box_color_ct, "Box CT");
				m_pGui->ColorEdit(cvars::visuals.esp_player_health_percentage_color, "Health percentage");
				m_pGui->ColorEdit(cvars::visuals.esp_player_armor_color, "Armor");
				m_pGui->ColorEdit(cvars::visuals.esp_player_name_color, "Name");
				m_pGui->ColorEdit(cvars::visuals.esp_player_weapon_text_color, "Weapon text");
				m_pGui->ColorEdit(cvars::visuals.esp_player_weapon_icon_color, "Weapon icon");
				m_pGui->ColorEdit(cvars::visuals.esp_player_money_color, "Money");
				m_pGui->ColorEdit(cvars::visuals.esp_player_distance_color, "Distance");
				m_pGui->ColorEdit(cvars::visuals.esp_player_actions_color, "Actions");
				m_pGui->ColorEdit(cvars::visuals.esp_player_actions_bar_color, "Actions bar");
				m_pGui->ColorEdit(cvars::visuals.esp_player_has_c4_color, "Has C4");
				m_pGui->ColorEdit(cvars::visuals.esp_player_has_defusal_kits_color, "Has defusal kits");
				m_pGui->ColorEdit(cvars::visuals.esp_player_line_of_sight_color, "Line of sight");
				m_pGui->ColorEdit(cvars::visuals.esp_player_hitboxes_color, "Hitboxes");
				m_pGui->ColorEdit(cvars::visuals.esp_player_hitboxes_hit_position_color, "Hitboxes hit position");
				m_pGui->ColorEdit(cvars::visuals.esp_player_hitboxes_hit_position_color2, "Hitboxes hit position 2");
				m_pGui->ColorEdit(cvars::visuals.esp_player_skeleton_color, "Skeleton");
				m_pGui->ColorEdit(cvars::visuals.esp_player_skeleton_backtrack_color, "Skeleton backtrack");
				m_pGui->ColorEdit(cvars::visuals.esp_player_glow_color_t, "Glow T");
				m_pGui->ColorEdit(cvars::visuals.esp_player_glow_color_ct, "Glow CT");
				m_pGui->ColorEdit(cvars::visuals.esp_player_sounds_color_t, "Sound T");
				m_pGui->ColorEdit(cvars::visuals.esp_player_sounds_color_ct, "Sound CT");
				m_pGui->ColorEdit(cvars::visuals.esp_player_out_of_fov_color_t, "Out of FOV T");
				m_pGui->ColorEdit(cvars::visuals.esp_player_out_of_fov_color_ct, "Out of FOV CT");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_color_t_hide, "Chams hide T");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_color_ct_hide, "Chams hide CT");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_color_t_vis, "Chams visible T");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_color_ct_vis, "Chams visible CT");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_on_the_dead_color, "Chams on the dead");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_hit_position_color, "Chams hit position");
				m_pGui->ColorEdit(cvars::visuals.colored_models_players_desync_aa_color, "Chams desync AA");
				m_pGui->ColorEdit(cvars::visuals.colored_models_backtrack_color_t_hide, "Chams backtrack hide T");
				m_pGui->ColorEdit(cvars::visuals.colored_models_backtrack_color_ct_hide, "Chams backtrack hide CT");
				m_pGui->ColorEdit(cvars::visuals.colored_models_backtrack_color_t_vis, "Chams backtrack visible T");
				m_pGui->ColorEdit(cvars::visuals.colored_models_backtrack_color_ct_vis, "Chams backtrack visible CT");
				m_pGui->ColorEdit(cvars::visuals.colored_models_hands_color, "Chams hands");
				m_pGui->ColorEdit(cvars::visuals.colored_models_dlight_color, "Dlight");
				m_pGui->ColorEdit(cvars::visuals.colored_models_elight_color, "Elight");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("Other", child_size);
				m_pGui->BeginWidgetsGroup();
				m_pGui->SetID("##visuals_colors_other");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_recoil_point_color, "Recoil point");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_spread_point_color, "Spread point");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_spread_circle_color, "Spread circle");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_spread_circle_color2, "Spread circle 2");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_aim_fov_color, "Aim FOV");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_aim_fov_color2, "Aim FOV 2");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_toggle_status_color, "Toggle status");
				m_pGui->ColorEdit(cvars::visuals.esp_other_local_toggle_status_color2, "Toggle status 2");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();

				ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

				m_pGui->SetChildSize(child_size);
				m_pGui->BeginGroupBox("GUI", child_size);
				m_pGui->BeginWidgetsGroup();
				ImGui::Text("Soon..");
				m_pGui->EndWidgetsGroup();
				m_pGui->EndGroupBox();
			}
			}

			m_pGui->TabShadow(GImGui->CurrentWindow->Pos + ImVec2(0, 36), GImGui->CurrentWindow->Pos + ImVec2(0, 36) +
				ImVec2(GImGui->CurrentWindow->Size.x, 20), ImVec4(0.08f, 0.08f, 0.08f, 1.00f));

			break;
		}
		case KREEDZ:
		{
			ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
			ImGui::SameLine(WINDOW_PADDING_SAMELINE);
			ImGui::Text("Soon..:)");
			break;
		}
		case MISC:
		{
			static int misc_tables_selected, misc_tables_hovered;

			//m_pGui->TabFeaturesList(misc_tables_data, misc_tables_selected, misc_tables_hovered);

			ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
			ImGui::SameLine(WINDOW_PADDING_SAMELINE);

			//switch (misc_tables_selected)
			//{
			//case MISC_GENERAL:
			//{
			//	m_pGui->SetChildSize(child_size);
			//	m_pGui->BeginGroupBox("Main", child_size);
			//	m_pGui->BeginWidgetsGroup();
			//	m_pGui->EndWidgetsGroup();
			//	m_pGui->EndGroupBox();

			//	ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			//	m_pGui->SetChildSize(child_size);
			//	m_pGui->BeginGroupBox("Extra", child_size);
			//	m_pGui->BeginWidgetsGroup();
			//	m_pGui->EndWidgetsGroup();
			//	m_pGui->EndGroupBox();

			//	ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			//	m_pGui->SetChildSize(child_size);
			//	m_pGui->BeginGroupBox("Bypass", child_size);
			//	m_pGui->BeginWidgetsGroup();
			//	m_pGui->EndWidgetsGroup();
			//	m_pGui->EndGroupBox();
			//	break;
			//}
			//case MISC_ENHANCEMENT:
			//{
			const char* kb_attack_type[] = { "Swing", "Stab" };
			const char* kb_aim_type[] = { "Disabled", "Visible", "Silent (Client-Side)", "Perfect silent (Server-Side)" };
			const char* kb_aim_hitbox[] = { "Head", "Neck", "Chest", "Stomach", "Arms", "Legs" };
			const char* kb_conditions[] = { "Don't shoot spectators", "Don't shoot in back", "Don't shoot in shield" };

			m_pGui->SetChildSize(child_size);
			m_pGui->BeginGroupBox("Knifebot", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##misc_knifebot");
			m_pGui->Checkbox(&cvars::misc.kb_enabled, "Enabled");
			m_pGui->Key(&cvars::misc.kb_key, "Key");
			m_pGui->Checkbox(&cvars::misc.kb_friendly_fire, "Friendly fire");
			m_pGui->Slider(&cvars::misc.kb_fov, "Maximum FOV", 0.f, 180.f, "%.0f�", 1.f);
			m_pGui->Combo(&cvars::misc.kb_attack_type, "Attack type", kb_attack_type, IM_ARRAYSIZE(kb_attack_type));
			m_pGui->Slider(&cvars::misc.kb_swing_distance, "Swing distance", 16.f, 64.f, "%.0f units", 1.f);
			m_pGui->Slider(&cvars::misc.kb_stab_distance, "Stab distance", 16.f, 64.f, "%.0f units", 1.f);
			m_pGui->Combo(&cvars::misc.kb_aim_type, "Aim type", kb_aim_type, IM_ARRAYSIZE(kb_aim_type));
			m_pGui->MultiCombo(cvars::misc.kb_aim_hitbox, "Aim hitbox", kb_aim_hitbox, IM_ARRAYSIZE(kb_aim_hitbox));
			m_pGui->Slider(&cvars::misc.kb_aim_hitbox_scale, "Aim hitbox scale", 1.f, 100.f, "%.0f%%", 1.f);
			m_pGui->MultiCombo(cvars::misc.kb_conditions, "Conditions", kb_conditions, IM_ARRAYSIZE(kb_conditions));
			m_pGui->Checkbox(&cvars::misc.kb_position_adjustment, "Position adjustment", "Exploit allowing you to shoot at multiple positions of the target");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
			ImGui::BeginGroup();

			m_pGui->SetChildSize(child_size);

			child_size.y -= WINDOW_PADDING_SAMELINE;
			child_size.y *= 0.5f;

			m_pGui->BeginGroupBox("Fakelatency", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##misc_fakelatency");
			m_pGui->Checkbox(&cvars::misc.fakelatency, "Enabled");
			m_pGui->Slider(&cvars::misc.fakelatency_amount, "Amount", 0, 500, "%ims");
			m_pGui->Key(&cvars::misc.fakelatency_key, "Key");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::Spacing_HPPv6(3);

			m_pGui->BeginGroupBox("Speedhack", child_size);
			m_pGui->BeginWidgetsGroup();
			ImGui::Text("Soon...");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::EndGroup();
			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);
			ImGui::BeginGroup();

			m_pGui->SetChildSize(child_size);

			child_size.y -= WINDOW_PADDING_SAMELINE * 2.f;
			child_size.y *= 0.33f;

			m_pGui->BeginGroupBox("Namestealer", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->SetID("##misc_namestealer");
			m_pGui->Checkbox(&cvars::misc.namestealer, "Enabled", "The function steals the names of players, changing Russian letters to English and vice versa.");
			m_pGui->Slider(&cvars::misc.namestealer_interval, "Interval", 1, 60, "%isec");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::Spacing_HPPv6(3);

			m_pGui->BeginGroupBox("Automation", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->Checkbox(&cvars::misc.automatic_reload, "Automatic reload");
			m_pGui->Checkbox(&cvars::misc.automatic_pistol, "Automatic pistol");
			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::Spacing_HPPv6(3);

			child_size.y = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_SAMELINE;

			m_pGui->BeginGroupBox("Other", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->Checkbox(&cvars::misc.replace_models_with_original, "Replace models with original");
			m_pGui->Checkbox(&cvars::misc.steamid_spoofer, "SteamID spoofer", "Set random RevEmu SteamID.");

			//if (g_pGlobals->m_bAllowCheats)
			if (true)
			{
				ImVec2 button_size = ImVec2(child_size.x - WINDOW_WIDGETS_PADDING_SAMELINE * 2.f, 26);

				if (ImGui::Button("Bypass sv_cheats", button_size))
					//*g_pGlobals->m_bAllowCheats = true;
					;
			}

			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::EndGroup();
			/*	break;
			}
			}*/

			break;
		}
		case CONFIGS:
		{
			static int selected_settings;

			m_pSettingsList->RefreshSettingsList();

			ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);
			ImGui::SameLine(WINDOW_PADDING_SAMELINE);

			m_pGui->SetChildSize(child_size);

			ImVec2 button_size = ImVec2(child_size.x - WINDOW_WIDGETS_PADDING_SAMELINE * 2.f, 26);

			m_pGui->BeginGroupBox("Configurations", child_size);
			m_pGui->BeginWidgetsGroup();
			m_pGui->ListBox("##settings_list", &m_pSettingsList->m_selected_settings, m_pSettingsList->m_settings_list, 11);

			ImGui::Spacing();

			if (ImGui::Button("Load##settings", button_size) || m_pHotkeys->Is("CTRL + L"))
				//g_pSettings->Load(m_pSettingsList->GetFocusSettings());
				;

			ImGui::Spacing();

			if (ImGui::Button("Save##settings", button_size) || m_pHotkeys->Is("CTRL + L"))
				//g_pSettings->Save(m_pSettingsList->GetFocusSettings());
				;

			ImGui::Spacing();

			if (ImGui::Button("Save as##settings", button_size) || m_pHotkeys->Is("CTRL + ALT + S"))
				ImGui::OpenPopup("Save as##modal");

			ImGui::Spacing();

			if (ImGui::Button("Reset##settings", button_size) || m_pHotkeys->Is("CTRL + ALT + R"))
				ImGui::OpenPopup("Reset##modal");

			ImGui::Spacing();

			if (ImGui::Button("Remove##settings", button_size) || m_pHotkeys->Is("DELETE"))
			{
				if (m_pSettingsList->GetFocusSettings().compare("Default"))
					ImGui::OpenPopup("Remove##modal");
			}

			ImGui::Spacing();

			if (ImGui::Button("Rename##settings", button_size) || m_pHotkeys->Is("CTRL + R"))
			{
				std::string& settings_name = m_pSettingsList->GetFocusSettings();

				if (settings_name.compare("Default"))
				{
					settings_name.copy(input_buf, sizeof(input_buf));
					ImGui::OpenPopup("Rename##modal");
				}
			}

			ImVec2 popup_modal_size_with_input = ImVec2(250, 112);
			ImVec2 popup_modal_size_without_input = ImVec2(250, 92);

			if (m_pPopupModal->Begin("Save as##modal", popup_modal_size_with_input))
			{
				DialogSettingsSaveAs(input_buf, sizeof(input_buf));
				m_pPopupModal->End();
			}

			if (m_pPopupModal->Begin("Rename##modal", popup_modal_size_with_input))
			{
				DialogSettingsRename(input_buf, sizeof(input_buf));
				m_pPopupModal->End();
			}

			if (m_pPopupModal->Begin("Remove##modal", popup_modal_size_without_input))
			{
				DialogSettingsRemove();
				m_pPopupModal->End();
			}

			if (m_pPopupModal->Begin("Reset##modal", popup_modal_size_without_input))
			{
				DialogSettingsReset();
				m_pPopupModal->End();
			}

			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			m_pGui->SetChildSize(child_size);
			m_pGui->BeginGroupBox("Lua Scripts", child_size);
			m_pGui->BeginWidgetsGroup();

			ImGui::Text("Soon..");

			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			ImGui::SameLine(0, WINDOW_PADDING_SAMELINE);

			m_pGui->SetChildSize(child_size);
			m_pGui->BeginGroupBox("Miscellaneous", child_size);
			m_pGui->BeginWidgetsGroup();

			if (ImGui::Button("Open settings folder##settings", button_size))
				//ShellExecute(NULL, "open", g_pGlobals->m_sSettingsPath.c_str(), NULL, NULL, SW_RESTORE);
				;

			ImGui::Spacing();

			if (ImGui::Button("Unload Cheat##settings", button_size))
				//g_pGlobals->m_bIsUnloadingLibrary = true;
				;

			m_pGui->EndWidgetsGroup();
			m_pGui->EndGroupBox();

			break;
		}
		case CONSOLE:
		{
			ImGui::Spacing();
			//g_Console.Draw("##console", nullptr); <= TODO
		}
		}

		ImGui::PopFont();

		m_pGui->TabShadow(GImGui->CurrentWindow->Pos + ImVec2(0, 4), GImGui->CurrentWindow->Pos + ImVec2(GImGui->CurrentWindow->Size.x, 20), GImGui->Style.Colors[ImGuiCol_BorderShadow]);
		m_pGui->EndCanvas();
		m_pGui->UnderBackground();
		m_pGui->UnderContents();
		m_pGui->End();
	}

	//static int hovered_tab;
	//static int selected_tab = LEGIT;

	//ImGui::ShowStyleEditor();

	//m_pFadeGlobal->Init();

	//if (!m_pFadeGlobal->Close() && !m_bIsOpened)
	//	return;

	//m_pFadeGlobal->Open();
	//m_pFadeGlobal->Apply();

	//m_pGui->Begin(ImVec2(900, 675));
	//m_pGui->TabBg(m_pFadeGlobal->GetGlobalAlpha());

	//const auto window_width = ImGui::GetWindowWidth();

	//ImGui::SameLine(window_width / 3.2f);
	//ImGui::PushFont(g_pFontList[Verdana_17px]);

	//if (m_pGui->TabList(TabLabels, IM_ARRAYSIZE(TabLabels), &selected_tab, &hovered_tab))
	//	m_pFadeWidgets->Init();

	//ImGui::PopFont();
	//ImGui::PushFont(g_pFontList[Verdana_13px]);

	//ImGui::PushStyleColor(ImGuiCol_ChildBg, GImGui->Style.Colors[ImGuiCol_WindowBg]);
	//ImGui::BeginChild("##widgets", ImVec2(0, ImGui::GetContentRegionAvail().y - 20));
	//ImGui::PopStyleColor();

	////ImGui::Spacing_HPPv6(WINDOW_PADDING_Y);

	//m_pFadeWidgets->Run();

	//switch (selected_tab)
	//{
	//case RAGE:
	//	DrawRage();
	//	break;
	//case LEGIT:
	//	DrawLegit();
	//	break;
	//case VISUALS:
	//	DrawVisuals();
	//	break;
	//case KREEDZ:
	//	break;
	//case MISC:
	//{
	//	ImGui::Spacing_HPPv6();

	//	const auto child_width = (window_width - WINDOW_PADDING_X * 3.f) / 2.f;

	//	ImGui::SameLine(WINDOW_PADDING_X);

	//	auto child_height = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_X;

	//	m_pGui->BeginChild("Miscellaneous", ImVec2(child_width, child_height));
	//	m_pGui->SetID("##misc_miscellaneous");
	//	//m_pGui->PushCondition(g_pGlobals->m_bIsSDL2Hooked);
	//	//m_pGui->PopCondition();
	//	
	//	
	//	//m_pGui->PushTextColor(ImVec4(1.00f, 1.00f, 0.00f, GImGui->Style.Colors[ImGuiCol_Text].w));


	//	//m_pGui->PopCondition();
	//	//m_pGui->PushTextColor(ImVec4(1.00f, 1.00f, 0.00f, GImGui->Style.Colors[ImGuiCol_Text].w));
	//	
	//	//m_pGui->PopTextColor();
	//	
	//	m_pGui->EndChild();

	//	ImGui::SameLine(0, WINDOW_PADDING_X);

	//	child_height = (GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_X * 2.f) / 1.5f; // change this

	//	ImGui::BeginGroup();

	//	const char* kb_attack_type[] = { "Swing", "Stab" };
	//	const char* kb_aim_type[] = { "Disabled", "Visible", "Silent", "Perfect silent" };
	//	const char* kb_aim_hitbox[] = { "All", "Head" };

	//	m_pGui->BeginChild("Knifebot", ImVec2(child_width, child_height));
	//	m_pGui->SetID("##misc_knifebot");
	//	m_pGui->Checkbox(&cvars::misc.kb_enabled, "Enabled");
	//	//m_pGui->PushCondition(cvars::misc.kb_enabled);
	//	//m_pGui->Key(&cvars::misc.kb_key, "Key", true);
	//	m_pGui->Checkbox(&cvars::misc.kb_friendly_fire, "Friendly fire");
	//	m_pGui->Slider(&cvars::misc.kb_fov, "Maximum FOV", 0.f, 180.f, u8"%.1f�", 1.f);
	//	//m_pGui->PushCondition(cvars::misc.kb_fov > 0.f);
	//	m_pGui->Combo(&cvars::misc.kb_attack_type, "Attack type", kb_attack_type, IM_ARRAYSIZE(kb_attack_type));
	//	m_pGui->Combo(&cvars::misc.kb_aim_type, "Aim type", kb_aim_type, IM_ARRAYSIZE(kb_aim_type));
	//	//m_pGui->PushCondition(cvars::misc.kb_aim_type);
	//	m_pGui->Combo(&cvars::misc.kb_aim_hitbox, "Aim hitbox", kb_aim_hitbox, IM_ARRAYSIZE(kb_aim_hitbox));
	//	m_pGui->Slider(&cvars::misc.kb_aim_hitbox_scale, "Aim hitbox scale", 1.f, 100.f, "%.0f%%", 1.f);
	//	//m_pGui->PopCondition();
	//	m_pGui->Slider(&cvars::misc.kb_swing_distance, "Swing distance", 16.f, 64.f, "%.1f units", 1.f);
	//	m_pGui->Slider(&cvars::misc.kb_stab_distance, "Stab distance", 16.f, 64.f, "%.1f units", 1.f);
	//	//m_pGui->PushTextColor(ImVec4(1.00f, 1.00f, 0.00f, GImGui->Style.Colors[ImGuiCol_Text].w));
	//	m_pGui->Checkbox(&cvars::misc.kb_position_adjustment, "Position adjustment", u8"ENG: Exploit allowing you to shoot at multiple positions of the target.\nRUS: �������� ����������� �������� � ��������� ������� ����.");
	//	//m_pGui->PopTextColor();
	//	m_pGui->Checkbox(&cvars::misc.kb_dont_shoot_spectators, "Don't shoot spectators");
	//	m_pGui->Checkbox(&cvars::misc.kb_dont_shoot_in_back, "Don't shoot in back");
	//	m_pGui->Checkbox(&cvars::misc.kb_dont_shoot_in_shield, "Don't shoot in shield");
	//	//m_pGui->PopCondition(2);
	//	
	//	m_pGui->EndChild();

	//	ImGui::Spacing_HPPv6(WINDOW_PADDING_Y - 1);

	//	const auto multiline_width = window_width - ImGui::GetCursorPosX() - WINDOW_PADDING_X;

	//	auto button_width = (multiline_width);
	//	auto button_height = 22.f;

	//	if (ImGui::Button("Unload cheat from game", ImVec2(button_width, button_height)))
	//		g_pGlobals->m_bIsUnloadingLibrary = true;



	//	ImGui::EndGroup();

	//	break;
	//}
	//case CONFIGS:
	//{
	//	static char input_buf[64];

	//	m_pSettingsList->RefreshSettingsList();

	//	const auto item_width = Math::TranslateToEvenGreatest(window_width * 0.27f);
	//	const auto child_width = (item_width + GImGui->Style.ItemSpacing.x) * 2.f;
	//	const auto child_height = GImGui->CurrentWindow->Size.y - WINDOW_PADDING_X * 2.f - GImGui->Style.ItemSpacing.y - 15.f;

	//	ImGui::BeginChild("##group", ImVec2(child_width, child_height));
	//	ImGui::SameLine(WINDOW_PADDING_X);
	//	ImGui::SetNextItemWidth(item_width);

	//	if (m_pGui->ListBox("##settings", &m_pSettingsList->m_selected_settings, m_pSettingsList->m_settings_list, 13))
	//		update_contents = true;

	//	ImGui::SameLine();
	//	ImGui::BeginGroup();
	//	ImGui::SetNextItemWidth(item_width);
	//	
	//	if (ImGui::ListBox("##ini", &m_pSettingsList->m_selected_file, g_IniFile, IM_ARRAYSIZE(g_IniFile)))
	//		update_contents = true;

	//	auto button_width = (item_width - GImGui->Style.ItemSpacing.x) * 0.5f;
	//	auto button_height = 22.f;

	//	ImGui::Spacing_HPPv6();

	//	if (ImGui::Button("Load##settings", ImVec2(button_width, button_height)) || m_pHotkeys->Is("CTRL + L"))
	//	{
	//		g_pSettings->Load(m_pSettingsList->GetFocusSettings());

	//		update_contents = true;
	//	}

	//	ImGui::SameLine();

	//	if (ImGui::Button("Save##settings", ImVec2(button_width, button_height)) || m_pHotkeys->Is("CTRL + S"))
	//	{
	//		g_pSettings->Save(m_pSettingsList->GetFocusSettings());

	//		update_contents = true;
	//	}

	//	ImGui::Spacing_HPPv6();

	//	if (ImGui::Button("Reset##settings", ImVec2(button_width, button_height)) || m_pHotkeys->Is("CTRL + ALT + R"))
	//		ImGui::OpenPopup("Reset##modal");

	//	ImGui::SameLine();

	//	if (ImGui::Button("Save as##settings", ImVec2(button_width, button_height)) || m_pHotkeys->Is("CTRL + ALT + S"))
	//		ImGui::OpenPopup("Save as##modal");

	//	ImGui::Spacing_HPPv6();

	//	if (ImGui::Button("Remove##settings", ImVec2(button_width, button_height)) || m_pHotkeys->Is("DELETE"))
	//	{
	//		if (m_pSettingsList->GetFocusSettings().compare("Default"))
	//			ImGui::OpenPopup("Remove##modal");
	//	}

	//	ImGui::SameLine();

	//	if (ImGui::Button("Rename##settings", ImVec2(button_width, button_height)) || m_pHotkeys->Is("CTRL + R"))
	//	{
	//		const auto& settings_name = m_pSettingsList->GetFocusSettings();

	//		if (settings_name.compare("Default"))
	//		{
	//			settings_name.copy(input_buf, sizeof(input_buf));
	//			ImGui::OpenPopup("Rename##modal");
	//		}
	//	}

	//	ImGui::Spacing_HPPv6();

	//	if (ImGui::Button("Open folder##settings", ImVec2(button_width, button_height - 1)) || m_pHotkeys->Is("CTRL + ALT + O"))
	//	{
	//		const auto path = g_pGlobals->m_sSettingsPath + m_pSettingsList->GetFocusSettings();
	//		ShellExecute(NULL, "open", path.c_str(), NULL, NULL, SW_RESTORE);
	//	}

	//	ImGui::SameLine();

	//	if (ImGui::Button("Open file##settings", ImVec2(button_width, button_height - 1)) || m_pHotkeys->Is("CTRL + ALT + F"))
	//	{
	//		const auto path = g_pGlobals->m_sSettingsPath + m_pSettingsList->GetFocusSettings() + g_IniFile[m_pSettingsList->m_selected_file];
	//		ShellExecute(NULL, "open", path.c_str(), NULL, NULL, SW_RESTORE);
	//	}

	//	ImGui::EndGroup();
	//	
	//	const auto popup_modal_size_with_input = ImVec2(250, 78);
	//	const auto popup_modal_size_without_input = ImVec2(250, 62);

	//	if (m_pPopupModal->Begin("Save as##modal", popup_modal_size_with_input))
	//	{
	//		DialogSettingsSaveAs(input_buf, sizeof(input_buf));
	//		m_pPopupModal->End();
	//	}

	//	if (m_pPopupModal->Begin("Rename##modal", popup_modal_size_with_input))
	//	{
	//		DialogSettingsRename(input_buf, sizeof(input_buf));
	//		m_pPopupModal->End();
	//	}

	//	if (m_pPopupModal->Begin("Remove##modal", popup_modal_size_without_input))
	//	{
	//		DialogSettingsRemove();
	//		m_pPopupModal->End();
	//	}

	//	if (m_pPopupModal->Begin("Reset##modal", popup_modal_size_without_input))
	//	{
	//		DialogSettingsReset();
	//		m_pPopupModal->End();
	//	}

	//	ImGui::Spacing_HPPv6(WINDOW_PADDING_Y);
	//	ImGui::SameLine(WINDOW_PADDING_X);

	//	const auto child_size = ImVec2(child_width - WINDOW_PADDING_X - 1, child_height - ImGui::GetCursorPosY() - 1);

	//	m_pGui->BeginChild("Other", child_size);

	//	if (ImGui::TreeNode("Information"))
	//	{
	//		ImGui::TextDisabled("[CTRL + L] - Load settings.");
	//		ImGui::TextDisabled("[CTRL + S] - Save settings.");
	//		ImGui::TextDisabled("[CTRL + ALT + R] - Reset settings.");
	//		ImGui::TextDisabled("[CTRL + ALT + S] - Save settings as.");
	//		ImGui::TextDisabled("[DELETE] - Remove settings.");
	//		ImGui::TextDisabled("[CTRL + R] - Rename settings.");
	//		ImGui::TextDisabled("[CTRL + ALT + O] - Open selected settings.");
	//		ImGui::TextDisabled("[CTRL + ALT + F] - Open selected file.");
	//		ImGui::TreePop();
	//	}

	//	m_pGui->EndChild();

	//	ImGui::EndChild();

	//	ImGui::SameLine();

	//	ImGui::BeginGroup();

	//	const auto multiline_width = window_width - ImGui::GetCursorPosX() - WINDOW_PADDING_X;
	//	const auto multiline_height = child_height - button_height - GImGui->Style.ItemSpacing.y * 2.f;

	//	static char buf[104448];

	//	if (update_contents)
	//	{
	//		memset(buf, 0, sizeof(buf));

	//		const auto path = g_pGlobals->m_sSettingsPath + m_pSettingsList->GetFocusSettings() + g_IniFile[m_pSettingsList->m_selected_file];

	//		if (Utils::FileExists(path))
	//			ReadFromFile(path, buf);

	//		update_contents = false;
	//	}

	//	ImGui::PushFont(g_pFontList[ProggyClean_13px]);
	//	ImGui::InputTextMultiline("##�ontents", buf, sizeof(buf), ImVec2(multiline_width, multiline_height), ImGuiInputTextFlags_AllowTabInput);
	//	ImGui::PopFont();

	//	ImGui::Spacing_HPPv6();

	//	button_width = (multiline_width - GImGui->Style.ItemSpacing.x) * 0.5f;

	//	if (ImGui::Button("Find & replace", ImVec2(button_width, button_height)))
	//		ImGui::OpenPopup("Replace##modal");

	//	ImGui::SameLine();

	//	if (ImGui::Button("Apply changes", ImVec2(button_width, button_height)))
	//	{
	//		const auto path = g_pGlobals->m_sSettingsPath + m_pSettingsList->GetFocusSettings() + g_IniFile[m_pSettingsList->m_selected_file];

	//		std::ofstream out;
	//		out.open(path.c_str());

	//		if (out.is_open())
	//		{
	//			out << buf;
	//			out.close();
	//		}
	//	}

	//	ImGui::EndGroup();

	//	if (m_pPopupModal->Begin("Replace##modal", popup_modal_size_with_input))
	//	{
	//		DialogFindAndReplace(buf);
	//		m_pPopupModal->End();
	//	}

	//	ImGui::Spacing_HPPv6(2);
	//	ImGui::SameLine(WINDOW_PADDING_X);

	//	const auto flags = ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_AutoSelectAll;

	//	ImGui::SetNextItemWidth(Math::TranslateToEvenGreatest(window_width * 0.8925f));
	//	ImGui::InputText("##path", g_pGlobals->m_sSettingsPath.data(), g_pGlobals->m_sSettingsPath.size() + 1, flags);

	//	ImGui::SameLine();

	//	if (ImGui::Button("Open##settings", ImVec2(window_width - ImGui::GetCursorPosX() - WINDOW_PADDING_X, 15)))
	//		ShellExecute(NULL, "open", g_pGlobals->m_sSettingsPath.c_str(), NULL, NULL, SW_RESTORE); 

	//	break;
	//}
	//}

	//ImColor border_col_low_alpha = ImVec4(0.00f, 0.00f, 0.00f, 0.25f);
	//ImColor border_col_no_alpha = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

	//GImGui->CurrentWindow->DrawList->AddRectFilledMultiColor(GImGui->CurrentWindow->Pos, GImGui->CurrentWindow->Pos +
	//	ImVec2(GImGui->CurrentWindow->Size.x, 15), border_col_low_alpha, border_col_low_alpha, border_col_no_alpha, border_col_no_alpha);

	//GImGui->Style.ItemSpacing = ImVec2(0, 1);

	//ImGui::EndChild();

	//m_pFadeWidgets->Reset();

	//ImGui::PushStyleColor(ImGuiCol_ChildBg, GImGui->Style.Colors[ImGuiCol_Button]);
	//ImGui::BeginChild("##information");
	//ImGui::PopStyleColor();

	//ImGui::Spacing_HPPv6(WINDOW_PADDING_Y);

	//GImGui->Style.ItemSpacing = ImVec2(8, 4);
	//
	//ImGui::SameLine(WINDOW_PADDING_X * 0.5f);

	//std::string info = "V6 for Counter-Strike 1.6 | Online: ";

	//if (!g_pGlobals->m_iOnlineNum)
	//{
	//	static auto instance = client_state->time;
	//	static auto count = 0;

	//	if (client_state->time > instance + 0.5)
	//	{
	//		for (int i = 0; i < count; i++)
	//			info.append(".");

	//		if (++count > 3)
	//			count = 0;
	//	}
	//}
	//else
	//	info.append(std::to_string(g_pGlobals->m_iOnlineNum));

	//ImGui::Text(info.c_str());

	//const std::string url = "https://hpp.ovh/";
	//const auto text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, FLT_MAX, 0, url.c_str());
	//
	//ImGui::SameLine(window_width - text_size.x - WINDOW_PADDING_X * 0.5f);
	//
	//m_pGui->Link(url);
	//	
	//ImGui::EndChild();
	//ImGui::PopFont();

	//m_pGui->End();

	//m_pFadeGlobal->Reset();
}

std::unique_ptr<CMenu> g_pMenu;