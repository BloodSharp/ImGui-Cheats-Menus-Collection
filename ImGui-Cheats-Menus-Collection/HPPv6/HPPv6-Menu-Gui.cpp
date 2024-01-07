#include "IGCMC-Precompiled.h"

CMenuGui::CMenuGui()
	: m_pPopupModal(std::make_unique<CMenuPopupModal>())
{
}

bool CMenuGui::Begin(std::string name, const ImVec2& size)
{
	ImVec2 size_const = size;

	size_const.x = std::min(size_const.x, GImGui->IO.DisplaySize.x);
	size_const.y = std::min(size_const.y, GImGui->IO.DisplaySize.y);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2());
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4());

	ImGui::SetNextWindowSizeConstraints(size_const, GImGui->IO.DisplaySize);
	ImGui::SetNextWindowSize(size, ImGuiCond_Once);
	//ImGui::SetNextWindowPosCenter(ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), ImGuiCond_Once, ImVec2(0.5f, 0.5f));

	const bool ret = ImGui::Begin(name.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar);

	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);

	return ret;
}

void CMenuGui::BeginCanvas(std::string name, const ImVec2& size, bool border)
{
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::GetStyleColorVec4(ImGuiCol_WindowBg));
	ImGui::BeginChild(name.c_str(), size, border);
	ImGui::PopStyleColor();
}

void CMenuGui::BeginGroupBox(std::string name, const ImVec2& size, bool border)
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2());
	ImGui::BeginChildCustom_HPPv6(name.c_str(), size, border);
	ImGui::PopStyleVar();
}

void CMenuGui::BeginWidgetsGroup()
{
	ImGui::Spacing_HPPv6(WINDOW_WIDGETS_PADDING_SPACING);
	ImGui::SameLine(WINDOW_WIDGETS_PADDING_SAMELINE);
	ImGui::BeginGroup();
}

void CMenuGui::End()
{
	ImVec2 window_pos = GImGui->CurrentWindow->Pos;
	ImVec2 window_size = GImGui->CurrentWindow->Size;

	GImGui->CurrentWindow->DrawList->PushClipRectFullScreen();

	RectangleShadowSettings_HPPv6 shadowSettings;
	shadowSettings.shadowColor = ImGui::GetStyleColorVec4(ImGuiCol_BorderShadow);
	ImGui::DrawRectangleShadowVerticesAdaptive_HPPv6(shadowSettings, window_pos, window_size);

	ImGui::End();
}

void CMenuGui::EndCanvas()
{
	ImGui::EndChild();
}

void CMenuGui::EndGroupBox()
{
	//ImGui::EndChildCustom_HPPv6(); <= TODO: Fix this
	ImGui::EndChild();
}

void CMenuGui::EndWidgetsGroup()
{
	ImGui::Spacing_HPPv6(3);
	ImGui::EndGroup();
}

void CMenuGui::SmallGroupBox(std::string name, const ImVec2& size, std::function<void()> widget_first, std::function<void()> widget_second)
{
	BeginGroupBox(name, size);

	std::string widgets_names[2] = { name + "widget_first", name + "widget_second" };

	ImGui::BeginChild(widgets_names[0].c_str(), ImVec2(size.x * 0.5f, size.y));
	ImGui::SetCursorPos(ImVec2(WINDOW_WIDGETS_PADDING_SAMELINE, 9));
	widget_first();
	ImGui::EndChild();

	ImGui::SameLine();

	ImGui::BeginChild(widgets_names[1].c_str(), ImVec2(size.x - ImGui::GetCursorPosX(), size.y));
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + WINDOW_WIDGETS_PADDING_SAMELINE, 9));
	widget_second();
	ImGui::EndChild();

	EndGroupBox();
}

void CMenuGui::UnderBackground()
{
	ImVec2 background_pos = GImGui->CurrentWindow->Pos + ImVec2(0, GImGui->CurrentWindow->Size.y - WINDOW_UNDERGROUND_HEIGHT);
	ImVec2 background_size = ImVec2(GImGui->CurrentWindow->Size.x, WINDOW_UNDERGROUND_HEIGHT);

	//g_pRenderer->AddRectFilled(background_pos, background_pos + background_size, GImGui->Style.Colors[ImGuiCol_Tab]);
	ImGui::GetBackgroundDrawList()->AddRectFilled(background_pos, background_pos + background_size, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Tab)));
}

void CMenuGui::UnderContents()
{
	ImGui::PushFont(g_pFontList[Verdana_13px]);

	GImGui->CurrentWindow->DC.CursorPos = ImVec2(GImGui->CurrentWindow->Pos.x + 6,
		GImGui->CurrentWindow->Pos.y + GImGui->CurrentWindow->Size.y - 16);

	if (m_message.empty())
	{
		std::string hackinfo = "V6 for Counter-Strike 1.6 | Online: ";

		//if (!g_pGlobals->m_iOnlineNum)
		if (false)
		{
			static int count, i;
			while (i++ < count) { hackinfo.append("."); } i = 0;
			if (++count > 3) count = 0;
		}
		//else
			//hackinfo.append(std::to_string(g_pGlobals->m_iOnlineNum));

		ImGui::Text(hackinfo.c_str());
	}
	else
	{
		ImGui::Text(m_message.c_str());

		m_message.clear();
	}

	std::string url = "https://hpp.ovh";

	ImVec2 text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, FLT_MAX, 0, url.c_str());

	ImGui::SameLine(GImGui->CurrentWindow->Size.x - text_size.x - WINDOW_PADDING_SAMELINE * 0.5f);

	Link(url);

	ImGui::PopFont();
}

void CMenuGui::TabBackground()
{
	ImVec2 background_size = ImVec2(ImGui::GetWindowSize().x, MENU_TAB_HEIGHT);
	ImVec2 currentWindowPosition = ImGui::GetCurrentWindow()->Pos;

	ImGui::GetWindowDrawList()->AddRectFilled(currentWindowPosition, currentWindowPosition + background_size, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Tab)));

	ImGui::Image((void*)(intptr_t)g_pImageList[MenuTitleBg].data, ImVec2(g_pImageList[MenuTitleBg].size.x - 70.f, MENU_TAB_HEIGHT - 2));
}

bool CMenuGui::TabList(std::vector<TabWidgetsData>& data, int& selected, int& hovered)
{
	ImGui::SameLine(GImGui->CurrentWindow->Size.x / 3.5f);

	ImGuiStyle backup_style = GImGui->Style;

	GImGui->Style.ItemSpacing = ImVec2(0, 1);

	ImVec2 button_size = ImVec2((GImGui->CurrentWindow->Size.x - ImGui::GetCursorPosX()) / data.size(), MENU_TAB_HEIGHT);
	ImVec4 button_color = GImGui->Style.Colors[ImGuiCol_TabHovered];

	button_color.w = 0.00f;

	bool changed = false;

	ImGui::PushFont(g_pFontList[Verdana_16px]);

	for (size_t i = 0; i < data.size(); i++)
	{
		GImGui->Style.Colors[ImGuiCol_ButtonActive] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_TabHovered], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_ButtonHovered] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_TabHovered], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_Button] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_TabHovered], ImSaturate(data[i].fading_value));

		bool pressed_button = false;

		if (selected == static_cast<int>(i))
		{
			GImGui->Style.Colors[ImGuiCol_Button] = GImGui->Style.Colors[ImGuiCol_TabActive];
			GImGui->Style.Colors[ImGuiCol_ButtonHovered] = GImGui->Style.Colors[ImGuiCol_TabActive];
			GImGui->Style.Colors[ImGuiCol_ButtonActive] = GImGui->Style.Colors[ImGuiCol_TabActive];

			pressed_button = ImGui::ButtonTabsNormal_HPPv6(data[i].label.c_str(), button_size);
		}
		else if (hovered == static_cast<int>(i))
		{
			pressed_button = ImGui::ButtonTabsNormal_HPPv6(data[i].label.c_str(), button_size);
		}
		else
		{
			pressed_button = ImGui::ImageButtonTab_HPPv6((void*)(intptr_t)g_pImageList[i + IconsTabsOffset].data, button_size);
		}

		if (pressed_button)
		{
			changed = selected != static_cast<int>(i);
			selected = static_cast<int>(i);
		}

		if (ImGui::IsItemHovered())
		{
			hovered = static_cast<int>(i);

			data[i].fading_value = std::min(data[i].fading_value + GImGui->IO.DeltaTime * 6.f, 1.00f);
		}
		else
		{
			data[i].fading_value = std::max(data[i].fading_value - GImGui->IO.DeltaTime * 6.f, 0.00f);

			if (hovered == static_cast<int>(i))
				hovered = -1;
		}

		if (i < data.size() - 1)
			ImGui::SameLine();
	}

	ImGui::PopFont();

	GImGui->Style = backup_style;

	return changed;
}

bool CMenuGui::TabFeaturesList(std::vector<TabWidgetsData>& data, int& selected, int& hovered)
{
	ImGuiStyle backup_style = GImGui->Style;

	GImGui->Style.ItemSpacing = ImVec2(0, 1);
	GImGui->Style.Colors[ImGuiCol_Border] = ImColor();

	ImVec2 button_size = ImVec2(GImGui->CurrentWindow->Size.x / data.size(), 32);
	ImVec4 button_color = GImGui->Style.Colors[ImGuiCol_ChildBg];
	ImVec4 normal_text_color = GImGui->Style.Colors[ImGuiCol_FrameBgHovered];

	bool changed = false;

	ImGui::PushFont(g_pFontList[Verdana_16px]);

	for (size_t i = 0; i < data.size(); i++)
	{
		GImGui->Style.Colors[ImGuiCol_ButtonActive] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_FrameBg], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_ButtonHovered] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_FrameBg], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_Button] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_FrameBg], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_Text] = ImLerp(normal_text_color, GImGui->Style.Colors[ImGuiCol_FrameBgActive], ImSaturate(data[i].fading_value));

		bool pressed_button = false;

		if (selected == static_cast<int>(i))
		{
			GImGui->Style.Colors[ImGuiCol_Button] = GImGui->Style.Colors[ImGuiCol_FrameBg];
			GImGui->Style.Colors[ImGuiCol_ButtonHovered] = GImGui->Style.Colors[ImGuiCol_FrameBg];
			GImGui->Style.Colors[ImGuiCol_ButtonActive] = GImGui->Style.Colors[ImGuiCol_FrameBg];
			GImGui->Style.Colors[ImGuiCol_Text] = GImGui->Style.Colors[ImGuiCol_FrameBgActive];

			pressed_button = ImGui::ButtonTabs_HPPv6(data[i].label.c_str(), button_size);
		}
		else if (hovered == static_cast<int>(i))
		{
			pressed_button = ImGui::ButtonTabs_HPPv6(data[i].label.c_str(), button_size);
		}
		else
		{
			pressed_button = ImGui::ButtonTabs_HPPv6(data[i].label.c_str(), button_size);
		}

		if (pressed_button)
		{
			changed = selected != static_cast<int>(i);
			selected = static_cast<int>(i);
		}

		if (ImGui::IsItemHovered())
		{
			hovered = static_cast<int>(i);

			data[i].fading_value = std::min(data[i].fading_value + GImGui->IO.DeltaTime * 6.f, 1.00f);
		}
		else
		{
			data[i].fading_value = std::max(data[i].fading_value - GImGui->IO.DeltaTime * 6.f, 0.00f);

			if (hovered == static_cast<int>(i))
				hovered = -1;
		}

		if (i < data.size() - 1)
			ImGui::SameLine();
	}

	ImGui::PopFont();

	GImGui->Style = backup_style;

	return changed;
}

bool CMenuGui::TabWeaponList(std::vector<TabWidgetsData>& data, int& selected, int& hovered)
{
	ImGuiStyle backup_style = GImGui->Style;

	GImGui->Style.ItemSpacing = ImVec2(0, 1);
	GImGui->Style.Colors[ImGuiCol_Border] = ImColor();

	ImVec2 button_size = ImVec2(GImGui->CurrentWindow->Size.x / data.size(), 32);
	ImVec4 button_color = GImGui->Style.Colors[ImGuiCol_ChildBg];
	ImVec4 normal_text_color = GImGui->Style.Colors[ImGuiCol_FrameBgHovered];

	bool changed = false;

	ImGui::PushFont(g_pFontList[Verdana_16px]);

	for (size_t i = 0; i < data.size(); i++)
	{
		GImGui->Style.Colors[ImGuiCol_ButtonActive] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_FrameBg], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_ButtonHovered] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_FrameBg], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_Button] = ImLerp(button_color, GImGui->Style.Colors[ImGuiCol_FrameBg], ImSaturate(data[i].fading_value));
		GImGui->Style.Colors[ImGuiCol_Text] = ImLerp(normal_text_color, GImGui->Style.Colors[ImGuiCol_FrameBgActive], ImSaturate(data[i].fading_value));

		bool pressed_button = false;

		if (selected == static_cast<int>(i))
		{
			GImGui->Style.Colors[ImGuiCol_Button] = GImGui->Style.Colors[ImGuiCol_FrameBg];
			GImGui->Style.Colors[ImGuiCol_ButtonHovered] = GImGui->Style.Colors[ImGuiCol_FrameBg];
			GImGui->Style.Colors[ImGuiCol_ButtonActive] = GImGui->Style.Colors[ImGuiCol_FrameBg];
			GImGui->Style.Colors[ImGuiCol_Text] = GImGui->Style.Colors[ImGuiCol_FrameBgActive];

			pressed_button = ImGui::ButtonTabs_HPPv6(data[i].label.c_str(), button_size);
		}
		else if (hovered == static_cast<int>(i))
		{
			pressed_button = ImGui::ButtonTabs_HPPv6(data[i].label.c_str(), button_size);
		}
		else
		{
			ImageInfo_HPPv6 image = g_pImageList[i + IconsWpnsOffset];
			pressed_button = ImGui::ImageButtonBySize_HPPv6((void*)(intptr_t)image.data, button_size, image.size);
		}

		if (pressed_button)
		{
			changed = selected != static_cast<int>(i);
			selected = static_cast<int>(i);
		}

		if (ImGui::IsItemHovered())
		{
			hovered = static_cast<int>(i);

			data[i].fading_value = std::min(data[i].fading_value + GImGui->IO.DeltaTime * 6.f, 1.00f);
		}
		else
		{
			data[i].fading_value = std::max(data[i].fading_value - GImGui->IO.DeltaTime * 6.f, 0.00f);

			if (hovered == static_cast<int>(i))
				hovered = -1;
		}

		if (i < data.size() - 1)
			ImGui::SameLine();
	}

	ImGui::PopFont();

	GImGui->Style = backup_style;

	return changed;
}

void CMenuGui::TabSeparator()
{
	ImGuiStyle backup_style = GImGui->Style;

	GImGui->Style.ItemSpacing = ImVec2(0, 1);
	GImGui->Style.Colors[ImGuiCol_Separator] = backup_style.Colors[ImGuiCol_TabActive];

	ImGui::Separator_HPPv6(4);

	GImGui->Style = backup_style;
}

void CMenuGui::TabShadow(const ImVec2& pos, const ImVec2& size, const ImVec4& color)
{
	ImColor border_col_low_alpha = color;
	ImColor border_col_no_alpha = color;

	border_col_low_alpha.Value.w = 0.45f;
	border_col_no_alpha.Value.w = 0.00f;

	ImGui::GetWindowDrawList()->AddRectFilledMultiColor(pos, size, border_col_low_alpha, border_col_low_alpha, border_col_no_alpha, border_col_no_alpha);
}

void CMenuGui::SetID(const char* str_id)
{
	m_id = str_id;
}

void CMenuGui::SetChildSize(ImVec2& size)
{
	size.x = (GImGui->CurrentWindow->Size.x - WINDOW_PADDING_SAMELINE * 4.f) / 3.f;
	size.y = GImGui->CurrentWindow->Size.y - ImGui::GetCursorPosY() - WINDOW_PADDING_SAMELINE;
}

void CMenuGui::Text(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	ImGui::TextV(fmt, args);
	va_end(args);
}

bool CMenuGui::Checkbox(bool* v, std::string label, std::string message)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::Checkbox(hashed_string.c_str(), v);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (ImGui::IsItemHovered())
		m_message = message;

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::Combo(int* v, std::string label, const char* items[], int size, std::string message, bool owned)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::Combo_HPPv6(hashed_string.c_str(), v, items, size, -1, owned);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (ImGui::IsItemHovered())
		m_message = message;

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::MultiCombo(bool* v, std::string label, const char* items[], int size, std::string message)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::MultiCombo_HPPv6(hashed_string.c_str(), items, v, size);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (ImGui::IsItemHovered())
		m_message = message;

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::Slider(float* v, std::string label, float min, float max, const char* format, float power, std::string message)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::SliderFloat(hashed_string.c_str(), v, min, max, format);//, power);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (ImGui::IsItemHovered())
		m_message = message;

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::Slider(int* v, std::string label, int min, int max, const char* format, std::string message)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::SliderInt(hashed_string.c_str(), v, min, max, format);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (ImGui::IsItemHovered())
		m_message = message;

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

static bool vector_getter(void* data, int id, const char** out_text)
{
	const auto& vector = *static_cast<std::vector<std::string>*>(data);
	*out_text = vector.at(id).c_str();
	return true;
};

bool CMenuGui::ListBox(const char* label, int* current_item, std::vector<std::string>& values, int height_in_items)
{
	ImGui::PushStyleColor(ImGuiCol_Header, ImGui::GetColorU32(ImGuiCol_FrameBg));
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, ImGui::GetColorU32(ImGuiCol_FrameBg));
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, ImGui::GetColorU32(ImGuiCol_FrameBg));

	const bool ret = ImGui::ListBox(label, current_item, vector_getter, &values, values.size(), height_in_items);

	ImGui::PopStyleColor(3);

	return ret;
}

void CMenuGui::Separator()
{
	ImGui::Spacing();
	ImGui::Separator_HPPv6(ImGui::GetWindowSize().x - WINDOW_PADDING_SAMELINE);
	ImGui::Spacing();
}

void CMenuGui::Link(std::string url)
{
	static std::vector<LinkData> url_list;

	int id = -1;

	if (!url_list.empty())
	{
		for (size_t i = 0; i < url_list.size(); i++)
		{
			if (url_list[i].url.compare(url))
				continue;

			id = static_cast<int>(i);
			break;
		}
	}

	if (id == -1)
	{
		url_list.push_back(LinkData{ url, false, false });
		id = static_cast<int>(url_list.size()) - 1;
	}

	bool ret = false;

	for (size_t i = 0; i < url_list.size(); i++)
	{
		if (id == static_cast<int>(i))
			continue;

		if (url_list[i].hovered || url_list[i].clicked)
			ret = true;
	}

	ImGui::Text(url.c_str());

	if (ret)
		return;

	url_list[id].hovered = ImGui::IsItemHovered();

	if (url_list[id].hovered)
	{
		ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);

		GImGui->CurrentWindow->Flags |= ImGuiWindowFlags_NoMove;

		if (ImGui::IsItemClicked(0))
			url_list[id].clicked = true;

		if (url_list[id].clicked && ImGui::IsMouseReleased(0))
		{
			//ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOW);
			IGCMC::Interfaces::OpenLink(url.c_str());
			url_list[id].clicked = false;
		}
	}
	else
	{
		GImGui->CurrentWindow->Flags &= ~ImGuiWindowFlags_NoMove;

		url_list[id].clicked = false;
	}
}

bool CMenuGui::Key(void* v, std::string label, bool owned)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::KeyButton_HPPv6(hashed_string.c_str(), v, owned);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::KeyToggle(void* v, std::string label, bool owned)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::KeyButtonToggle_HPPv6(hashed_string.c_str(), v, owned);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::KeyPress(void* v, std::string label, bool owned)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	const bool ret = ImGui::KeyButtonPress_HPPv6(hashed_string.c_str(), v, owned);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

bool CMenuGui::ColorEdit(float* v, std::string label)
{
	std::string hashed_string = label + m_id;

	float& fading_value = FindWidgetsFadingValue(hashed_string);

	ImGui::PushStyleColor(ImGuiCol_Border, ImLerp(GImGui->Style.Colors[ImGuiCol_ChildBg],
		GImGui->Style.Colors[ImGuiCol_Border], ImSaturate(fading_value)));

	//const bool ret = ImGui::ColorEdit(hashed_string.c_str(), v);
	const bool ret = ImGui::ColorEdit3(hashed_string.c_str(), v);

	ImGui::PopStyleColor();

	UpdateWidgetsFadingValue(fading_value);

	if (m_check_change_value && !m_changed_value)
		m_changed_value = ret;

	return ret;
}

void CMenuGui::BeginCheckChangeValue()
{
	if (!m_check_change_value)
		m_check_change_value = true;
}

void CMenuGui::EndCheckChangeValue()
{
	if (m_check_change_value)
	{
		m_check_change_value = false;
		m_changed_value = false;
	}
}

bool CMenuGui::IsChangedValue()
{
	return m_changed_value;
}

float& CMenuGui::FindWidgetsFadingValue(std::string label)
{
	auto it = m_widgets_list.find(label);

	if (it == m_widgets_list.end())
	{
		m_widgets_list.insert({ label, 0.00f });
		it = m_widgets_list.find(label);
	}

	return it->second;
}

void CMenuGui::UpdateWidgetsFadingValue(float& fading_value)
{
	if (ImGui::IsItemHovered())
		fading_value = std::min(fading_value + GImGui->IO.DeltaTime * 6.f, 1.00f);
	else
		fading_value = std::max(fading_value - GImGui->IO.DeltaTime * 6.f, 0.00f);
}