#pragma once

#include "IGCMC-Precompiled.h"

#define ITEM_WIDTH_WITH_COLOR	-1.f
#define ITEM_WIDTH_WITH_COLOR2	-2.f

constexpr auto MENU_TAB_HEIGHT = 52.f;
constexpr auto WINDOW_PADDING_SAMELINE = 15.f;
constexpr auto WINDOW_PADDING_SPACING = 5;
constexpr auto WINDOW_WIDGETS_PADDING_SAMELINE = 17.f;
constexpr auto WINDOW_WIDGETS_PADDING_SPACING = 6;
constexpr auto WINDOW_UNDERGROUND_HEIGHT = 18.f;
constexpr auto FEATURE_BUTTON_SIZE = 32.f;

struct LinkData
{
	std::string url;
	bool hovered;
	bool clicked;
};

struct TabWidgetsData
{
	std::string label;
	float fading_value;
};

class CMenuGui
{
public:
	CMenuGui();

	bool Begin(std::string name, const ImVec2& size);
	void BeginCanvas(std::string name, const ImVec2& size, bool border = false);
	void BeginGroupBox(std::string name, const ImVec2& size, bool border = true);
	void BeginWidgetsGroup();

	void End();
	void EndCanvas();
	void EndGroupBox();
	void EndWidgetsGroup();

	void SmallGroupBox(std::string name, const ImVec2& size, std::function<void()> widget_first, std::function<void()> widget_second);

	void UnderBackground();
	void UnderContents();

	void TabBackground();
	bool TabList(std::vector<TabWidgetsData>& data, int& selected, int& hovered);
	bool TabFeaturesList(std::vector<TabWidgetsData>& data, int& selected, int& hovered);
	bool TabWeaponList(std::vector<TabWidgetsData>& data, int& selected, int& hovered);
	void TabSeparator();
	void TabShadow(const ImVec2& pos, const ImVec2& size, const ImVec4& color);

	void SetID(const char* str_id);
	void SetChildSize(ImVec2& size);

	void Text(const char* fmt, ...);
	bool Checkbox(bool* v, std::string label, std::string message = "");
	bool Combo(int* v, std::string label, const char* items[], int size, std::string message = "", bool owned = false);
	bool MultiCombo(bool* v, std::string label, const char* items[], int size, std::string message = "");
	bool Slider(float* v, std::string label, float min, float max, const char* format, float power, std::string message = "");
	bool Slider(int* v, std::string label, int min, int max, const char* format, std::string message = "");
	bool ListBox(const char* label, int* current_item, std::vector<std::string>& values, int height_in_items);
	void Separator();
	void Link(std::string url);
	bool Key(void* v, std::string label, bool owned = false);
	bool KeyToggle(void* v, std::string label, bool owned = false);
	bool KeyPress(void* v, std::string label, bool owned = false);
	bool ColorEdit(float* v, std::string label);

	void BeginCheckChangeValue();
	void EndCheckChangeValue();

	bool IsChangedValue();

private:
	std::map<std::string, float> m_widgets_list;

	std::string m_id;
	std::string m_message;

	bool m_check_change_value;
	bool m_changed_value;

	std::unique_ptr<CMenuPopupModal> m_pPopupModal;

	float& FindWidgetsFadingValue(std::string label);
	void UpdateWidgetsFadingValue(float& fading_value);
};