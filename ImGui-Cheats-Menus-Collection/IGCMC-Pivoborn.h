#pragma once

#include "IGCMC-Precompiled.h"

namespace IGCMC
{
	namespace Interfaces
	{
		namespace Cheats
		{
			namespace Pivoborn
			{
				void Setup(bool* pbIsInitialized);
				void Destroy(bool* pbIsInitialized);
				void Render(bool* pbMustOpenThisMenu);
			}
		}
	}
}