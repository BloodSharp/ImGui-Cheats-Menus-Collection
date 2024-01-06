#pragma once

#include "IGCMC-Precompiled.h"

namespace IGCMC
{
	namespace Interfaces
	{
		namespace Cheats
		{
			namespace NeverLoseV2
			{
				void Setup(bool* pbIsInitialized);
				void Destroy(bool* pbIsInitialized);
				void Render(bool* pbMustOpenThisMenu);
			}
		}
	}
}