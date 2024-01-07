#include "IGCMC-Precompiled.h"

void CMenuThemes::SetDefaultDarkTheme()
{
	ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 255, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_WindowBg,  ImColor(26, 24, 28, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_PopupBg,  ImColor(41, 38, 43, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_ChildBg,  ImColor(32, 30, 35, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_FrameBg,  ImColor(61, 59, 63, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered,  ImColor(96, 93, 96, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_FrameBgActive,  ImColor(146, 36, 248, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_CheckMark,  ImColor(146, 36, 248, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_TitleBg,  ImColor(146, 36, 248, 150).Value);
	ImGui::PushStyleColor(ImGuiCol_TitleBgActive,  ImColor(146, 36, 248, 150).Value);
	ImGui::PushStyleColor(ImGuiCol_Tab,  ImColor(146, 36, 248, 150).Value);
	ImGui::PushStyleColor(ImGuiCol_TabHovered,  ImColor(146, 36, 248, 150).Value);
	ImGui::PushStyleColor(ImGuiCol_TabActive,  ImColor(146, 36, 248, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_Button,  ImColor(61, 59, 63, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered,  ImColor(96, 93, 96, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_ButtonActive,  ImColor(103, 100, 103, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_Header,  ImColor(0, 0, 0, 0).Value);
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered,  ImColor(61, 59, 63, 150).Value);
	ImGui::PushStyleColor(ImGuiCol_HeaderActive,  ImColor(61, 59, 63, 150).Value);
	ImGui::PushStyleColor(ImGuiCol_Border,  ImColor(41, 38, 43, 255).Value);
	ImGui::PushStyleColor(ImGuiCol_BorderShadow,  ImColor(18, 18, 35, 255).Value);//ImVec4(0.08f, 0.08f, 0.08f, 1.00f));
	ImGui::PushStyleColor(ImGuiCol_ScrollbarBg,  ImVec4(0.37f, 0.37f, 0.37f, 0.00f));
	ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab,  ImColor(80, 80, 80, 204).Value);
	ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered,  ImColor(100, 100, 100, 204).Value);
	ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive,  ImColor(100, 100, 100, 255).Value);
	//ImGui::PushStyleColor(ImGuiCol_ModalWindowDarkening,  ImColor(0, 0, 0, 180));
}

void CMenuThemes::UnsetDefaultDarkTheme()
{
	ImGui::PopStyleColor(25);
}