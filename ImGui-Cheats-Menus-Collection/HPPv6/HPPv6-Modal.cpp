#include "IGCMC-Precompiled.h"

bool CMenuPopupModal::Begin(std::string name, const ImVec2& size)
{
	ImGui::SetNextWindowSize(size);

	const auto flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground;
	const auto ret = ImGui::BeginPopupModal(name.c_str(), nullptr, flags);

	if (ret)
	{
		ImGui::Spacing_HPPv6(2);
		ImGui::SameLine(WINDOW_PADDING_SAMELINE);
		ImGui::BeginGroup();
	}

	return ret;
}

void CMenuPopupModal::End()
{
	ImGui::EndGroup();
	ImGui::EndPopup();
}

float CMenuPopupModal::GetItemWidth()
{
	return GImGui->CurrentWindow->Size.x - WINDOW_PADDING_SAMELINE * 2.f;
}

void CMenuPopupModal::Input(std::string name, char* buf, size_t buf_size)
{
	ImGui::Text(name.c_str());

	const auto item_width = GetItemWidth();
	const auto str_id = "##" + name;

	ImGui::SetNextItemWidth(item_width);
	ImGui::InputText(str_id.c_str(), buf, buf_size);

	ImGui::Spacing();
}

void CMenuPopupModal::Message(std::string message)
{
	const auto item_width = GetItemWidth();
	const auto text_size = GImGui->Font->CalcTextSizeA(GImGui->Font->FontSize, item_width, 0, message.c_str());

	ImGui::SameLine((item_width - text_size.x) * 0.5f);
	ImGui::Text(message.c_str());

	ImGui::Spacing();
}

bool CMenuPopupModal::Button(std::string name)
{
	ImGui::PushStyleColor(ImGuiCol_Border, ImVec4());

	const auto ret = ImGui::Button(name.c_str(), ImVec2(106, 20));

	ImGui::PopStyleColor();
	ImGui::SameLine();

	return ret;
}