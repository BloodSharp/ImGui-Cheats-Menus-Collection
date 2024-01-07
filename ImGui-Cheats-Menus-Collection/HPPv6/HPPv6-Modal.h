#pragma once

#include "IGCMC-Precompiled.h"

class CMenuPopupModal
{
public:
	bool Begin(std::string name, const ImVec2& size);
	void End();

	void Input(std::string name, char* buf, size_t buf_size);
	void Message(std::string message);
	bool Button(std::string name);

private:
	float GetItemWidth();
};