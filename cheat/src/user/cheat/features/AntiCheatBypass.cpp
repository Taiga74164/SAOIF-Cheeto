#include <pch-il2cpp.h>
#include "AntiCheatBypass.h"

#include <helpers.h>

namespace Cheat::Features
{
	AntiCheatBypass::AntiCheatBypass()
	{
		HookManager::install(app::UncheaterManager_UncheaterCallback_OnHackDetected, UncheaterManager_UncheaterCallback_OnHackDetected_Hook);
		// HookManager::install(app::UncheaterManager_UncheaterCallback_OnSend, UncheaterManager_UncheaterCallback_OnSend_Hook);
	}

	void AntiCheatBypass::UncheaterManager_UncheaterCallback_OnHackDetected_Hook(void* __this, uint32_t code, uint32_t wp, app::String* path, MethodInfo* method)
	{
		LOG_INFO("UncheaterCallback.OnHackDetected called. Client was trying to quit the game!");
		auto um = GET_STATIC_FIELDS(UncheaterManager);
		um->isQuit = false;
	}

	void AntiCheatBypass::UncheaterManager_UncheaterCallback_OnSend_Hook(app::UncheaterManager_UncheaterCallback* __this, app::Byte__Array* buffer, MethodInfo* method)
	{
		auto encoding = app::Encoding_get_UTF8(nullptr);
		auto buf = app::Encoding_GetString(encoding, buffer, *app::Encoding_GetString__MethodInfo);
		auto bufStr = il2cppi_to_string(buf);
		auto replaceAll = [](std::string& str, const std::string& oldValue, const std::string& newValue) {
			if (oldValue.empty())
				return;

			size_t startPos = 0;
			while ((startPos = str.find(oldValue, startPos)) != std::string::npos)
			{
				str.replace(startPos, oldValue.length(), newValue);
				startPos += newValue.length();
			}
		};

		auto bufNew = bufStr;
		replaceAll(bufNew, "\\u0000", "");


		LOG_INFO("UncheaterCallback.OnSend called.");
		LOG_INFO("Buffer %s", bufNew.c_str());

		CALL_ORIGIN(UncheaterManager_UncheaterCallback_OnSend_Hook, __this, buffer, method);
	}
}
