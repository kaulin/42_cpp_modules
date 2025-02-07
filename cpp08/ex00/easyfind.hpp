#pragma once

# include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& source, int target) {
	typename T::iterator result = std::find(source.begin(), source.end(), target);
	if (result == source.end())
		throw (std::out_of_range("I cannot provide what you desire"));
	return (result);
};