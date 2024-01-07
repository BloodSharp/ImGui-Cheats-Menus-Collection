#include "IGCMC-Precompiled.h"

static std::map<std::string, int> keylist =
{
	{"CTRL", 0x11},		{"ALT", 0x12},		{"SHIFT", 0x10},	{"ENTER", 0x0D},	{"ESC", 0x1B},		{"END", 0x23},		{"HOME", 0x24},		{"LEFT", 0x25},
	{"UP", 0x26},		{"RIGHT", 0x27},	{"DOWN", 0x28},		{"INSERT", 0x2D},	{"DELETE", 0x2E},	{"0", 0x30},		{"1", 0x31},		{"2", 0x32},
	{"3", 0x33},		{"4", 0x34},		{"5", 0x35},		{"6", 0x36},		{"7", 0x37},		{"8", 0x38},		{"9", 0x39},		{"A", 0x41},
	{"B", 0x42},		{"C", 0x43},		{"D", 0x44},		{"E", 0x45},		{"F", 0x46},		{"G", 0x47},		{"H", 0x48},		{"I", 0x49},
	{"J", 0x4A},		{"K", 0x4B},		{"L", 0x4C},		{"M", 0x4D},		{"N", 0x4E},		{"O", 0x4F},		{"P", 0x50},		{"Q", 0x51},
	{"R", 0x52},		{"S", 0x53},		{"T", 0x54},		{"U", 0x55},		{"V", 0x56},		{"W", 0x57},		{"X", 0x58},		{"Y", 0x59},
	{"Z", 0x5A},		{"F1", 0x70},		{"F2", 0x71},		{"F3", 0x72},		{"F4", 0x73},		{"F5", 0x74},		{"F6", 0x75},		{"F7", 0x76},
	{"F8", 0x77},		{"F9", 0x78},		{"F10", 0x79},		{"F11", 0x7A},		{"F12", 0x7B}
};

static int get_key_code(std::string key)
{
	const auto entry = keylist.find(key);
	return entry == end(keylist) ? 0x00 : entry->second;
}

static bool is_pressed(std::string key)
{
	const auto key_code = get_key_code(key);

	if (!key_code)
		return false;

	return GImGui->IO.KeysDown[key_code];
}

static size_t get_keys_count(std::string key)
{
	size_t count = key.size() ? 1 : 0;

	for (size_t i = 0; i < key.size(); i++)
		if (key[i] == '+') {
			count++;
		}

	return count;
}

bool CMenuHotkeys::Is(std::string key)
{
	const auto count = get_keys_count(key);

	if (!count)
		return false;

	if (count > 1)
	{
		char buf[256];

		strcpy(buf, key.c_str());

		//Utils::StringReplace(buf, "+", ",");
		//Utils::StringReplace(buf, " ", "");

		for (size_t i = 0; i < count; i++)
		{
			const std::string sbuffer = buf;
			const auto pos = sbuffer.find(',', i);
			const auto once_key = sbuffer.substr(i, pos - i);

			//Utils::StringReplace(buf, once_key.c_str(), "");

			if (!is_pressed(once_key))
				return false;
		}
	}
	else if (!is_pressed(key))
	{
		return false;
	}

	return true;
}