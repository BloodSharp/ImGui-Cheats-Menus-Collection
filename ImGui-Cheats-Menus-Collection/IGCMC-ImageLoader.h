#pragma once

#include "IGCMC-Precompiled.h"

namespace IGCMC
{
	namespace Utils
	{
		bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
		bool LoadTextureFromMemory(const unsigned char* buffer, int buffer_length, GLuint* out_texture, int* out_width, int* out_height);
	}
}