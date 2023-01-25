// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
// Only exposes x, y, z and w components
#define GLM_FORCE_XYZW_ONLY
// Force left handed coordinate system
#define GLM_FORCE_LEFT_HANDED

#include <windows.h>
#include <cstddef>
#include <Psapi.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <array>
#include <MinHook.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

std::byte* find_pattern(const wchar_t* mod_name, const char* pattern_str);

template <typename ret_ty = void, typename... args_ty>
ret_ty call_vfunc(void* class_ptr, const size_t offset, args_ty... args) noexcept
{
	return (*static_cast<ret_ty(__thiscall***)(void*, decltype(args)...)>(class_ptr))[offset](class_ptr, args...);
}

template <typename ptr_ty>
class ref_ptr_t
{
	ptr_ty** ptr{};

public:
	ref_ptr_t(ptr_ty** ptr_ptr) : ptr{ ptr_ptr } {};

	ptr_ty* operator->() { return *ptr; }
	bool operator==(void* cmp_ptr) { return *ptr == cmp_ptr; }
	bool operator!=(void* cmp_ptr) { return *ptr != cmp_ptr; }
};

#endif //PCH_H
