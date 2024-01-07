#pragma once

#include "IGCMC-Precompiled.h"

struct NotificationData
{
	int draw_state;
	int count;
	std::string name;
	std::string message;
	std::string id;
	double time;
};

enum DrawStatesList
{
	Appearance,
	Normal,
	Disappearance
};

class CNotifications
{
public:
	using DataList_t = std::deque<NotificationData>;

	void Push(std::string name, std::string message);
	void Pop();
	void Draw();

private:
	DataList_t m_data;

	bool m_bIsDescent;
	double m_dbDescentTime;

	double GetAppearanceReachTime(double time);
	double GetNormalReachTime(double time);
	double GetDisappearanceReachTime(double time);

	bool IsAppearance(double time);
	bool IsNormal(double time);
	bool IsDisappearance(double time);

	void GetScreenPosition(const NotificationData& data, float* x, float* y);
	bool IsCursorFocused(float window_pos_x, float window_pos_y);
	void SwipeProcessing(NotificationData& data, float* window_pos_x);
	void Render(NotificationData& data);
};

extern std::unique_ptr<CNotifications> g_pNotifications;