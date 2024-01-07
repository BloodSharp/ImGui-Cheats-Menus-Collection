#pragma once

#include "IGCMC-Precompiled.h"

struct RectangleShadowSettings_HPPv6
{
	// Inputs
	bool    linear = false;
	float   sigma = 6;
	ImVec2  padding = ImVec2(50, 50);
	ImVec2  shadowOffset = ImVec2(0, 0);
	ImVec2  shadowSize = ImVec2(120, 50);
	ImVec4  shadowColor = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);

	int  rings = 10;
	int  spacingBetweenRings = 1;
	int  samplesPerCornerSide = 20;
	int  spacingBetweenSamples = 5;

	// Outputs
	int totalVertices = 0;
	int totalIndices = 0;
};

namespace ImGui
{
	void Spacing_HPPv6(int count);
	//bool BeginCustom_HPPv6(const char* name, bool* p_open, ImGuiWindowFlags flags);
	void EndChildCustom_HPPv6();
	void DrawRectangleShadowVerticesAdaptive_HPPv6(RectangleShadowSettings_HPPv6& settings, ImVec2 pos, ImVec2 size);
	bool BeginChildCustomEx_HPPv6(const char* name, ImGuiID id, const ImVec2& size_arg, bool border, ImGuiWindowFlags flags);
	bool BeginChildCustom_HPPv6(const char* str_id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0);
	bool ButtonTabsNormal_HPPv6(const char* label, const ImVec2& size_arg);
	bool ButtonTabsEx2_HPPv6(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags);
	bool ImageButtonTab_HPPv6(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), int frame_padding = -1, const ImVec4& bg_col = ImVec4(0, 0, 0, 0), const ImVec4& tint_col = ImVec4(1, 1, 1, 1));    // <0 frame_padding uses default frame padding settings. 0 for no padding
	bool KeyButton_HPPv6(const char* label, void* v, bool owned);
	bool ButtonTabs_HPPv6(const char* label, const ImVec2& size_arg);
	bool ButtonTabsEx_HPPv6(const char* label, const ImVec2& size_arg = ImVec2(0, 0), ImGuiButtonFlags flags = 0);
	bool ImageButtonBySize_HPPv6(ImTextureID user_texture_id, const ImVec2& size, const ImVec2 image_size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), const ImVec4& bg_col = ImVec4(0, 0, 0, 0));    // <0 frame_padding uses default frame padding settings. 0 for no padding	
	void Separator_HPPv6(int count);
	bool MultiCombo_HPPv6(const char* name, const char** displayName, bool* data, int dataSize);
	bool Selectable3_HPPv6(const char* label, bool selected = false, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2(0, 0));
	bool KeyButtonToggle_HPPv6(const char* label, void* v, bool owned);
	bool KeyButtonPress_HPPv6(const char* label, void* v, bool owned);
	bool Combo_HPPv6(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1, bool owned = false);
	//bool Combo_HPPv6(const char* label, int* current_item, bool(*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items = -1, bool owned = false);
	float BoxShadow_HPPv6(ImVec2 lower, ImVec2 upper, ImVec2 point, float sigma, bool linearInterpolation);
	ImVec4 BoxGaussianIntegral_HPPv6(ImVec4 x);
	ImVec4 BoxLinearInterpolation_HPPv6(ImVec4 x);
}