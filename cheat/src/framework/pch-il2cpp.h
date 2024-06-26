// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_IL2CPP_H
#define PCH_IL2CPP_H

// add headers that you want to pre-compile here
#include "il2cpp-appdata.h"

#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <mutex>

#include <nlohmann/json.hpp>
#include <magic_enum.hpp>
#include <imgui.h>

#include <Utils.h>
#include <Memory.h>
#include <HookManager.h>

#endif //PCH_IL2CPP_H