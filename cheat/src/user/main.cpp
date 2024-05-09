#include <pch-il2cpp.h>
#include "main.h"

#include <helpers.h>
#include <il2cpp-init.h>
#include <cheat/cheat.h>


void Run(HMODULE hModule)
{
	il2cppi_new_console();

	while (!GetModuleHandleA("GameAssembly.dll") && !FindWindowA("UnityWndClass", nullptr))
	{
#ifdef _DEBUG
		LOG_DEBUG("Game not fully loaded yet, waiting...");
#endif
		Sleep(3000);
	}

	Utils::SetCurrentPath(Utils::GetModulePath(hModule));

	init_il2cpp();
	init_cheat();
	
}