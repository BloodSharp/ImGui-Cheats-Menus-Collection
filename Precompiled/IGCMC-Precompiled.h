#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../imgui/backends/imgui_impl_sdl2.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <map>
#include <functional>
#include <algorithm>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../imgui/examples/libs/emscripten/emscripten_mainloop_stub.h"
#elif defined(_WIN32)
#include <shellapi.h>
#endif

#if defined(_WIN32)
#define BASE_FONT_DIR "C:\\Windows\\Fonts\\"
#elif defined(__EMSCRIPTEN__)
#define BASE_FONT_DIR "/FileSystem/Fonts/"
#endif

#include "../ImGui-Cheats-Menus-Collection/IGCMC-ImageLoader.h"

#include "../ImGui-Cheats-Menus-Collection/IGCMC-Interface.h"
#include "../ImGui-Cheats-Menus-Collection/IGCMC-Aimware.h"
#include "../ImGui-Cheats-Menus-Collection/IGCMC-NeverLose.h"
#include "../ImGui-Cheats-Menus-Collection/IGCMC-HPPv6.h"

// HPP v6 Assets
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/background_title.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_rage_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_legit_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_visuals_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_kreedz_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_misc_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_configs_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/tab_console_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/wpn_pistols_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/wpn_rifles_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/wpn_snipers_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/wpn_shotguns_icon.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/menu/wpn_smgs_icon.h"

#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_ak47.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_aug.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_awp.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_c4.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_deagle.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_elite.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_famas.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_fiveseven.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_flashbang.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_g3sg1.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_galil.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_glock18.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_hegrenade.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_knife.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_m249.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_m4a1.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_m3.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_mac10.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_mp5.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_p228.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_p90.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_scout.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_sg550.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_sg552.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_smokegrenade.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_tmp.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_ump45.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_usp.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/weapons/weapon_xm1014.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/images/defuser/defuser.h"

#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Utils.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Cvars.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Notifications.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Custom-ImGui.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Renderer.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Fade-Background.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Themes.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Menu-Settings-List.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Hotkeys.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Modal.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Menu-Gui.h"
#include "../ImGui-Cheats-Menus-Collection/HPPv6/HPPv6-Menu.h"