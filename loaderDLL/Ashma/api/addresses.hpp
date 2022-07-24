#pragma once
#include <Windows.h>
#include <cstdint>
#define format3(address) (address - 0x00400000 + reinterpret_cast<uintptr_t>(GetModuleHandle(0)))

const std::uintptr_t current_module = reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL));

namespace func_defs
{
	using rbx_getscheduler_t = std::uintptr_t(__cdecl*)();
	using rbx_output_t = void(__fastcall*)(std::int16_t output_type, const char* str);
	using rbx_getstate_t = std::uintptr_t(__thiscall*)(std::uintptr_t SC, int* state_type);
	using rbx_pushvfstring_t = int(__cdecl*)(std::uintptr_t rl, const char* fmt, ...);
	using rbx_psuedo2adr_t = std::uintptr_t* (__fastcall*)(std::uintptr_t rl, int idx);
}

namespace addresses
{
	const std::uintptr_t rbx_getscheduler_addy = current_module + 0xE00F50;
	const std::uintptr_t rbx_output_addy = format3(0x18764B0);
	const std::uintptr_t rbx_getstate_addy = format3(0x871070);
	const std::uintptr_t rbx_pushvfstring_addy = format3(0x18764B0);; // LIMITED TO 512 CHARACTERS

	const std::uintptr_t spawn_func_addy = format3(0x892420);
	const std::uintptr_t deserializer_func_addy = format3(0x187A860);

	const std::uintptr_t pushcclosure_addy = current_module + 0x13683E0;
	const std::uintptr_t pushcclosure_exit_addy = current_module + 0x01368655;

	const std::uintptr_t setglobal_addy = current_module + 0x136A300;
	const std::uintptr_t setglobal_exit_addy = current_module + 0x0136BFC0;
	const std::uintptr_t setglobal_patch_1_addy = current_module + 0x0136A358;
	const std::uintptr_t setglobal_patch_2_addy = current_module + 0x0136A6E0;

	const std::uintptr_t psuedo2adr_addy = format3(0x1876670);

	const std::uintptr_t fake_ret_addy = current_module + 0x002357E9; // reg jmp

	const std::uintptr_t callcheck_addy_1 = current_module + 0x2C6B1F4; // data ptr
	const std::uintptr_t callcheck_addy_2 = current_module + 0x00232277; // code ptr
	const std::uintptr_t callcheck_addy_3 = current_module + 0x013C21C9; // VM callcheck

	const std::uintptr_t xor_const = current_module + 0x2A3FC40;
	static const std::uintptr_t* nilobject = reinterpret_cast<std::uintptr_t*>(format3(0x2622ED0)); // it doesn't like when i make it a pointer so it needs to be static, fucking C++
}

namespace offsets
{
	namespace scheduler
	{
		constexpr std::uintptr_t jobs_start = 0x134;
		constexpr std::uintptr_t jobs_end = 0x138;
		constexpr std::uintptr_t fps = 0x118;
	}

	namespace job
	{
		constexpr std::uintptr_t name = 0x10;
	}

	namespace waiting_scripts_job
	{
		constexpr std::uintptr_t datamodel = 0x28;
		constexpr std::uintptr_t script_context = 0x130;
	}

	namespace identity
	{
		constexpr std::uintptr_t extra_space = 72;
		constexpr std::uintptr_t identity = 24;
	}

	namespace luastate
	{
		constexpr std::uintptr_t top = 20;
		constexpr std::uintptr_t base = 0x10;
	}

	namespace luafunc
	{
		constexpr std::uintptr_t func = 16;
	}
}