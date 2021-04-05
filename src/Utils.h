#pragma once
#include <string>

namespace util
{
	static bool stob(std::string& str)
	{
		if (str == std::string("true"))
			return true;
		return false;
	}
}

