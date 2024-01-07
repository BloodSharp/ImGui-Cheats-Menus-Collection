#include "IGCMC-Precompiled.h"

//constexpr auto FADE_BACKGROUND_MENU = 0.1;
constexpr auto FADE_BACKGROUND_MENU = 0.1 * 1000.0;

void CMenuFadeBg::Init()
{
	if (g_pMenu->IsOpened() == m_state)
		return;

	m_active = true;
	m_state = g_pMenu->IsOpened();
	//m_prevtime = client_state->time;
	m_prevtime = SDL_GetTicks64();
}

void CMenuFadeBg::Run()
{
	//const auto max_alpha = g_pGlobals->m_bIsInGame && g_Local->m_bIsConnected ? 0.00f : 0.50f;
	const auto max_alpha = 0.50f * 1000.f;
	const auto end_time = m_prevtime + FADE_BACKGROUND_MENU;

	//if (m_active && client_state->time < end_time)
	if (m_active && SDL_GetTicks64() < end_time)
	{
		const auto start = m_state ? 0.00f : max_alpha;
		const auto end = m_state ? max_alpha : 0.00f;
		//const auto alpha = static_cast<float>(Math::Interp(m_prevtime, client_state->time, end_time, start, end));
		const auto alpha = static_cast<float>(HPPv6__Math__Interp(m_prevtime, SDL_GetTicks64(), end_time, start, end));

		//g_pRenderer->AddRectFilled(ImVec2(), GImGui->IO.DisplaySize, ImVec4(0.00f, 0.00f, 0.00f, alpha));
		ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(), GImGui->IO.DisplaySize, ImColor(ImVec4(0.00f, 0.00f, 0.00f, alpha)));
	}
	else
	{
		if (m_state)
			//g_pRenderer->AddRectFilled(ImVec2(), GImGui->IO.DisplaySize, ImVec4(0.00f, 0.00f, 0.00f, max_alpha));
			ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(), GImGui->IO.DisplaySize, ImColor(ImVec4(0.00f, 0.00f, 0.00f, max_alpha)));

		m_active = false;
	}
}