#include "IGCMC-Precompiled.h"

std::string HPPv6__Utils__FormatString(const char* fmt, ...)
{
	char buf[4096] = { 0 };

	va_list args;
	va_start(args, fmt);
	vsprintf_s(buf, fmt, args);
	va_end(args);

	return buf;
}

std::string HPPv6__Utils__GenRandomString()
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	char s[50];
	for (size_t i = 0; i < sizeof(s) - 1; i++)
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	s[49] = 0;

	return std::string(s);
}

int HPPv6__Game__GetWeaponIndex(std::string name)
{
	for (auto& weapon : weapon_id_name)
		if (strstr(name.c_str(), weapon.name))
			return weapon.id;

	return WEAPON_NONE;
}

void HPPv6__Utils__StringReplace(char* buf, const char* search, const char* replace)
{
	if (!strlen(buf) || !strlen(search))
		return;

	char* p = buf;

	const auto l1 = strlen(search);
	const auto l2 = strlen(replace);

	while ((p = strstr(p, search)) != 0)
	{
		memmove(p + l2, p + l1, strlen(p + l1) + 1U);
		memcpy(p, replace, l2);

		p += l2;
	}
}

double HPPv6__Math__Interp_F2(double s1, double s2, double s3, double f1, double f3)
{
	return f1 + ((s2 - s1) / s3) * (f3 - f1);
}

double HPPv6__Math__Interp(double s1, double s2, double s3, double f1, double f3)
{
	if (s2 == s1)
		return f1;

	if (s2 == s3)
		return f3;

	if (s3 == s1)
		return f1;

	return f1 + ((s2 - s1) / (s3 - s1)) * (f3 - f1);
}