#pragma once

#include <il2cpp-appdata.h>

#include <Singleton.h>

namespace Cheat::Features
{
	class AntiCheatBypass : public Singleton<AntiCheatBypass>
	{
	public:
		AntiCheatBypass();

	private:
		static void UncheaterManager_UncheaterCallback_OnHackDetected_Hook(void* __this, uint32_t code, uint32_t wp, app::String* path, MethodInfo* method);
		static void UncheaterManager_UncheaterCallback_OnSend_Hook(app::UncheaterManager_UncheaterCallback* __this, app::Byte__Array* buffer, MethodInfo* method);
	};
}
