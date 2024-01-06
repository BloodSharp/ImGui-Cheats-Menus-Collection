#pragma once

#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../imgui/backends/imgui_impl_sdl2.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include <cstdio>
#include <string>
#include <vector>

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

#include "IGCMC-ImageLoader.h"

#include "IGCMC-Interface.h"
#include "IGCMC-Aimware.h"
#include "IGCMC-NeverLose.h"
#include "IGCMC-Pivoborn.h"
#include "IGCMC-HPPv6.h"
