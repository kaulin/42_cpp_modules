#pragma once

#include <algorithm>
//#include <type_traits>

template <typename T>
typename T::iterator easyfind(T& source, int target) {
	// static_assert(std::is_integral<typename T::value_type>::value, "easyfind requires a container of integers");
	return std::find(source.begin(), source.end(), target);
};