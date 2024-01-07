#pragma once

#include "IGCMC-Precompiled.h"

enum WeaponIdType
{
	WEAPON_NONE,
	WEAPON_P228,
	WEAPON_GLOCK,
	WEAPON_SCOUT,
	WEAPON_HEGRENADE,
	WEAPON_XM1014,
	WEAPON_C4,
	WEAPON_MAC10,
	WEAPON_AUG,
	WEAPON_SMOKEGRENADE,
	WEAPON_ELITE,
	WEAPON_FIVESEVEN,
	WEAPON_UMP45,
	WEAPON_SG550,
	WEAPON_GALIL,
	WEAPON_FAMAS,
	WEAPON_USP,
	WEAPON_GLOCK18,
	WEAPON_AWP,
	WEAPON_MP5N,
	WEAPON_M249,
	WEAPON_M3,
	WEAPON_M4A1,
	WEAPON_TMP,
	WEAPON_G3SG1,
	WEAPON_FLASHBANG,
	WEAPON_DEAGLE,
	WEAPON_SG552,
	WEAPON_AK47,
	WEAPON_KNIFE,
	WEAPON_P90,
	WEAPON_MAX_COUNT,
	WEAPON_SHIELDGUN = 99
};

struct weapon_id_name_t_HPPv6
{
	int id;
	const char* name;
};

static weapon_id_name_t_HPPv6 weapon_id_name[] =
{
	{WEAPON_P228, "p228"},
	{WEAPON_SCOUT, "scout"},
	{WEAPON_XM1014, "xm1014"},
	{WEAPON_MAC10, "mac10"},
	{WEAPON_AUG, "aug"},
	{WEAPON_ELITE, "elite"},
	{WEAPON_FIVESEVEN, "fiveseven"},
	{WEAPON_UMP45, "ump45"},
	{WEAPON_SG550, "sg550"},
	{WEAPON_GALIL, "galil"},
	{WEAPON_FAMAS, "famas"},
	{WEAPON_USP, "usp"},
	{WEAPON_GLOCK18, "glock18"},
	{WEAPON_AWP, "awp"},
	{WEAPON_MP5N, "mp5"},
	{WEAPON_M249, "m249"},
	{WEAPON_M3, "m3"},
	{WEAPON_M4A1, "m4a1"},
	{WEAPON_TMP, "tmp"},
	{WEAPON_G3SG1, "g3sg1"},
	{WEAPON_DEAGLE, "deagle"},
	{WEAPON_SG552, "sg552"},
	{WEAPON_AK47, "ak47"},
	{WEAPON_P90, "p90"},
	{WEAPON_KNIFE, "knife"},
	{WEAPON_HEGRENADE, "hegrenade"},
	{WEAPON_SMOKEGRENADE, "smokegrenade"},
	{WEAPON_C4, "c4"},
	{WEAPON_FLASHBANG, "flashbang"},
};

std::string HPPv6__Utils__FormatString(const char* fmt, ...);
std::string HPPv6__Utils__GenRandomString();
int HPPv6__Game__GetWeaponIndex(std::string name);
void HPPv6__Utils__StringReplace(char* buf, const char* search, const char* replace);
double HPPv6__Math__Interp_F2(double s1, double s2, double s3, double f1, double f3);
double HPPv6__Math__Interp(double s1, double s2, double s3, double f1, double f3);