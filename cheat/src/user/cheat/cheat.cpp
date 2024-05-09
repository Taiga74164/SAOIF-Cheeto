#include <pch-il2cpp.h>
#include "cheat.h"

#include "features/AntiCheatBypass.h"

using namespace Cheat::Features;

void init_cheat()
{
#define INIT_FEATURE(feature) feature::GetInstance()
	INIT_FEATURE(AntiCheatBypass);
#undef INIT_FEATURE
}