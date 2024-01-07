#include "IGCMC-Precompiled.h"

static const auto WINDOW_SIZE = ImVec2(270, 110);
static const auto WINDOW_OFFSET = ImVec2(10, 50);
//static const auto DURATION = 0.2;
static const auto DURATION = 200;

void CNotifications::Push(std::string name, std::string message)
{
	//if (!cvars::settings.notifications_enabled)
		//m_data.clear();

	NotificationData data;

	data.count = static_cast<int>(m_data.size());
	data.draw_state = Appearance;
	data.name = name;
	data.message = message;
	data.id = HPPv6__Utils__GenRandomString();
	//data.time = client_state->time;
	data.time = SDL_GetTicks64();

	m_data.push_back(data);
}

void CNotifications::Pop()
{
	m_data.pop_front();

	if (m_data.empty())
		return;

	for (auto& data : m_data)
		data.count--;

	m_bIsDescent = true;
	//m_dbDescentTime = client_state->time;
	m_dbDescentTime = SDL_GetTicks64();
}

void CNotifications::Draw()
{
	if (m_data.empty())
		return;

	//if (!cvars::settings.notifications_enabled)
		//m_data.clear();

	for (auto& data : m_data)
	{
		switch (data.draw_state)
		{
		case Appearance:
			if (!IsAppearance(data.time))
				data.draw_state = Normal;
			break;
		case Normal:
			if (!IsNormal(data.time))
				data.draw_state = Disappearance;
			break;
		case Disappearance:
			if (!IsDisappearance(data.time))
				Pop();
		}

		Render(data);
	}
}

double CNotifications::GetAppearanceReachTime(double time)
{
	return time + DURATION;
}

double CNotifications::GetNormalReachTime(double time)
{
	//return GetAppearanceReachTime(time) + 5.0/* + cvars::settings.notifications_time*/;
	return GetAppearanceReachTime(time) + 5000.0/* + cvars::settings.notifications_time*/;
}

double CNotifications::GetDisappearanceReachTime(double time)
{
	return GetNormalReachTime(time) + DURATION;
}

bool CNotifications::IsAppearance(double time)
{
	//return client_state->time < GetAppearanceReachTime(time);
	return SDL_GetTicks64() < GetAppearanceReachTime(time);
}

bool CNotifications::IsNormal(double time)
{
	//return client_state->time < GetNormalReachTime(time);
	return SDL_GetTicks64() < GetNormalReachTime(time);
}

bool CNotifications::IsDisappearance(double time)
{
	//return client_state->time < GetDisappearanceReachTime(time);
	return SDL_GetTicks64() < GetDisappearanceReachTime(time);
}

void CNotifications::GetScreenPosition(const NotificationData& data, float* x, float* y)
{
	const auto flWindowSizeWithOffsetX = WINDOW_SIZE.x + WINDOW_OFFSET.x;
	const auto flWindowSizeWithOffsetY = WINDOW_SIZE.y + WINDOW_OFFSET.y;
	const auto flWindowInterval = WINDOW_SIZE.y + 5.f;

	switch (data.draw_state)
	{
	case Appearance:
		//*x = GImGui->IO.DisplaySize.x - static_cast<float>(Math::Interp_F2(data.time, client_state->time, DURATION, 0.0, flWindowSizeWithOffsetX));
		*x = GImGui->IO.DisplaySize.x - static_cast<float>(HPPv6__Math__Interp_F2(data.time, SDL_GetTicks64(), DURATION, 0.0, flWindowSizeWithOffsetX));
		*y = GImGui->IO.DisplaySize.y - flWindowSizeWithOffsetY - flWindowInterval * static_cast<float>(data.count);
		break;
	case Normal:
		*x = GImGui->IO.DisplaySize.x - flWindowSizeWithOffsetX;
		*y = GImGui->IO.DisplaySize.y - flWindowSizeWithOffsetY - flWindowInterval * static_cast<float>(data.count);
		break;
	case Disappearance:
		//*x = GImGui->IO.DisplaySize.x - static_cast<float>(Math::Interp_F2(GetNormalReachTime(data.time), client_state->time, DURATION, flWindowSizeWithOffsetX, 0.0));
		*x = GImGui->IO.DisplaySize.x - static_cast<float>(HPPv6__Math__Interp_F2(GetNormalReachTime(data.time), SDL_GetTicks64(), DURATION, flWindowSizeWithOffsetX, 0.0));
		*y = GImGui->IO.DisplaySize.y - flWindowSizeWithOffsetY - flWindowInterval * static_cast<float>(data.count);
	}

	if (m_bIsDescent)
	{
		//if (client_state->time < m_dbDescentTime + DURATION)
		if (SDL_GetTicks64() < m_dbDescentTime + DURATION)
			//*y -= static_cast<float>(Math::Interp_F2(m_dbDescentTime, client_state->time, DURATION, flWindowInterval, 0.0));
			*y -= static_cast<float>(HPPv6__Math__Interp_F2(m_dbDescentTime, SDL_GetTicks64(), DURATION, flWindowInterval, 0.0));
		else
			m_bIsDescent = false;
	}
}

bool CNotifications::IsCursorFocused(float window_pos_x, float window_pos_y)
{
	return (GImGui->IO.MousePos.x > window_pos_x && GImGui->IO.MousePos.x < GImGui->IO.DisplaySize.x) &&
		(GImGui->IO.MousePos.y > window_pos_y && GImGui->IO.MousePos.y < window_pos_y + WINDOW_SIZE.y);
}

void CNotifications::SwipeProcessing(NotificationData& data, float* window_pos_x)
{
	static float old_pos_x, drag_pos_x;
	static float different_pos_x;

	if (GImGui->IO.MouseDown[0])
	{
		data.draw_state = Normal;
		different_pos_x = GImGui->IO.MousePos.x - old_pos_x;

		if (old_pos_x - GImGui->IO.MousePos.x < 0.f)
			*window_pos_x = GImGui->IO.MousePos.x - drag_pos_x;
	}
	else
	{
		if (different_pos_x > 5.f)
		{
			data.draw_state = Disappearance;
			//data.time = client_state->time - GetNormalReachTime(0.0);
			data.time = SDL_GetTicks64() - GetNormalReachTime(0.0);
			//data.time -= Math::Interp_F2(data.time, DURATION, GImGui->IO.DisplaySize.x - (WINDOW_SIZE.x + WINDOW_OFFSET.x),
			data.time -= HPPv6__Math__Interp_F2(data.time, DURATION, GImGui->IO.DisplaySize.x - (WINDOW_SIZE.x + WINDOW_OFFSET.x),
				GImGui->IO.MousePos.x - drag_pos_x, GImGui->IO.DisplaySize.x) - data.time;
		}

		different_pos_x = 0.f;
		old_pos_x = GImGui->IO.MousePos.x;
		drag_pos_x = GImGui->IO.MousePos.x - *window_pos_x;
	}
}

static void GetAlpha(const NotificationData& data, float default_alpha, float* out_alpha)
{
	switch (data.draw_state)
	{
	case Appearance:
		//*out_alpha = static_cast<float>(Math::Interp_F2(data.time, client_state->time, DURATION, 0.00, default_alpha));
		*out_alpha = static_cast<float>(HPPv6__Math__Interp_F2(data.time, SDL_GetTicks64(), DURATION, 0.00, default_alpha));
		break;
	case Normal:
		*out_alpha = default_alpha;
		break;
	case Disappearance:
		//*out_alpha = static_cast<float>(Math::Interp_F2(data.time + DURATION + 5.0/*cvar.settings.notifications_time*/, client_state->time, DURATION, default_alpha, 0.00));
		*out_alpha = static_cast<float>(HPPv6__Math__Interp_F2(data.time + DURATION + 5.0/*cvar.settings.notifications_time*/, SDL_GetTicks64(), DURATION, default_alpha, 0.00));
	}
}

static ImVec4 GetColorWindowBg(const NotificationData& data)
{
	auto ColorWindowBg = GImGui->Style.Colors[ImGuiCol_WindowBg];
	GetAlpha(data, ColorWindowBg.w, &ColorWindowBg.w);
	return ColorWindowBg;
}

static ImVec4 GetColorText(const NotificationData& data)
{
	auto ColorText = GImGui->Style.Colors[ImGuiCol_Text];
	GetAlpha(data, ColorText.w, &ColorText.w);
	return ColorText;
}

static ImVec4 GetColorTextDisabled(const NotificationData& data)
{
	auto ColorTextDisabled = GImGui->Style.Colors[ImGuiCol_TextDisabled];
	GetAlpha(data, ColorTextDisabled.w, &ColorTextDisabled.w);
	return ColorTextDisabled;
}

void CNotifications::Render(NotificationData& data)
{
	static auto prevtime = SDL_GetTicks64();

	float pos_x, pos_y;
	GetScreenPosition(data, &pos_x, &pos_y);

	if (!data.count && data.draw_state == Normal)
	{
		static bool bMouseDownMissed;
		static bool bMouseDownCatch;

		if (IsCursorFocused(pos_x, pos_y))
		{
			if (GImGui->IO.MouseDown[0] && !bMouseDownMissed && !bMouseDownCatch)
			{
				//data.time += 5.0/*cvars::settings.notifications_time*/ - (client_state->time - data.time);
				data.time += 5.0/*cvars::settings.notifications_time*/ - (SDL_GetTicks64() - data.time);
				bMouseDownCatch = true;
			}
		}
		else if (GImGui->IO.MouseDown[0] && !bMouseDownMissed && !bMouseDownCatch)
		{
			bMouseDownMissed = true;
		}

		if (!GImGui->IO.MouseDown[0] && bMouseDownMissed)
			bMouseDownMissed = false;

		if (!GImGui->IO.MouseDown[0] && bMouseDownCatch)
			bMouseDownCatch = false;

		if (IsCursorFocused(pos_x, pos_y) || bMouseDownCatch)
		{
			SwipeProcessing(data, &pos_x);

			if (bMouseDownCatch)
				//data.time += client_state->time - prevtime;
				data.time += SDL_GetTicks64() - prevtime;
		}

		if (data.draw_state == Disappearance)
			GetScreenPosition(data, &pos_x, &pos_y);
	}

	prevtime = SDL_GetTicks64();

	GImGui->Style.Alpha = 1.00f;

	ImGui::SetNextWindowPos(ImVec2(pos_x, pos_y));
	ImGui::SetNextWindowSize(WINDOW_SIZE);

	ImGui::PushStyleColor(ImGuiCol_WindowBg, GetColorWindowBg(data));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2());
	ImGui::PushFont(g_pFontList[Verdana_13px]);

	const auto flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoFocusOnAppearing;

	if (ImGui::Begin(data.id.c_str(), nullptr, flags))
	{
		ImGui::SameLine(WINDOW_PADDING_SAMELINE);
		ImGui::BeginGroup();

		ImGui::Spacing_HPPv6(WINDOW_PADDING_SPACING);

		ImGui::PushTextWrapPos(WINDOW_SIZE.x - WINDOW_PADDING_SAMELINE * 2.f);

		ImGui::PushStyleColor(ImGuiCol_Text, GetColorText(data));
		ImGui::TextWrapped(data.name.c_str());
		ImGui::PopStyleColor();

		ImGui::Spacing();

		ImGui::PushStyleColor(ImGuiCol_Text, GetColorTextDisabled(data));
		ImGui::TextWrapped(data.message.c_str());
		ImGui::PopStyleColor();

		ImGui::PopTextWrapPos();

		ImGui::EndGroup();
		ImGui::End();
	}

	ImGui::PopFont();
	ImGui::PopStyleVar(2);
	ImGui::PopStyleColor();
}

std::unique_ptr<CNotifications> g_pNotifications;