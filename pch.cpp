// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.

std::byte* find_pattern(const wchar_t* mod_name, const char* pattern_str)
{
	if (const HMODULE mod = GetModuleHandle(mod_name))
	{
		MODULEINFO mod_info{};
		GetModuleInformation(GetCurrentProcess(), mod, &mod_info, sizeof(MODULEINFO));

		std::vector<std::pair<std::byte, bool>> pattern{};

		std::stringstream sstream{ pattern_str };
		std::string s{};

		while (sstream >> s)
		{
			if (s.find_first_not_of('?') == std::string::npos)
			{
				pattern.emplace_back(std::byte{}, true);
			}
			else if (s.length() == 2 && std::isxdigit(s.at(0)) && std::isxdigit(s.at(1)))
			{
				pattern.emplace_back(static_cast<std::byte>(std::stoul(s, nullptr, 16)), false);
			}
		}

		const auto start = static_cast<std::byte*>(mod_info.lpBaseOfDll);
		std::byte* end = start + mod_info.SizeOfImage;

		std::byte* result = std::search(start, end, std::default_searcher(pattern.begin(), pattern.end(), [](const std::byte a, const std::pair<std::byte, bool> b)
			{
				return a == b.first || b.second;
			}));

		if (result != end)
		{
			return result;
		}
	}

	return nullptr;
}
