#pragma once
#include <unordered_map>
#include <vector>
#include <Windows.h>

#define AUTO_ASSEMBLE_TRAMPOLINE(ADDRESS, TRAMPOLINE_LENGTH, INSTRUCTIONS) \
do { \
auto allocMemory = Memory::AllocateNearbyMemory(ADDRESS, sizeof INSTRUCTIONS + 14); \
Memory::CreateTrampoline(ADDRESS, allocMemory, TRAMPOLINE_LENGTH); \
Memory::WriteInstructions(allocMemory, INSTRUCTIONS, sizeof INSTRUCTIONS, ADDRESS + TRAMPOLINE_LENGTH); \
} while (false)

class MemoryResolver;

class Memory
{
public:
	static void PatchBytes(void* address, const char* bytes, size_t len);
	static void PatchBytes(uintptr_t address, const char* bytes);
	template <size_t N>
	static void PatchBytes(uintptr_t address, const BYTE(&bytes)[N]);
	static void NopBytes(uintptr_t address, size_t len);
	static void RestoreBytes(uintptr_t address);
	static void RestoreBytes(std::initializer_list<uintptr_t> address);
	static uintptr_t PatternScan(uintptr_t module, const char* signature);
	static void* AllocateNearbyMemory(uintptr_t address, size_t size);
	static void CreateTrampoline(uintptr_t address, void* destination, size_t length);
	static void RemoveTrampoline(uintptr_t address);
	static void WriteInstructions(void* destination, const BYTE instructions[], size_t instructionLen, uintptr_t retAddress);
	static void RestoreAllPatches();

private:
	struct PatchInfo {
		void* address;
		std::vector<BYTE> originalBytes;
		bool hasTrampoline = false;
		void* trampolineDestination = nullptr;
	};

	static std::unordered_map<void*, PatchInfo> patches;
};

class MemoryResolver
{
public:
	MemoryResolver(uintptr_t addr) : address(addr) {}
	MemoryResolver(uintptr_t mod, uintptr_t addr) : module(mod), address(addr) {}

	uintptr_t GetAddress() const { return address; }

	uintptr_t RelativeJMP() const;
	uintptr_t RelativeMOV32() const;
	uintptr_t RelativeMOV() const;
	uintptr_t RelativeXMM128() const;
	uintptr_t JMP() const;
	uintptr_t MOV32() const;
	uintptr_t MOV() const;
	uintptr_t XMM128() const;

private:
	uintptr_t module;
	uintptr_t address;
};