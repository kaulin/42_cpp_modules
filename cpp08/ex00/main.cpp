#include <random>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include "easyfind.hpp"

int rangen(int from, int to) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(from,to);
	return distribution(generator);
}

template <typename T>
void search(std::string type, T& source, int target) {
	bool exists = false;
	typename T::iterator outcome;
	std::cout << "Searching for [" << target << "] from " << type << " container with following elements:\n";
	for (typename T::iterator it = source.begin(); it != source.end(); ++it) {
		std::cout << "[";
		if (*it == target && !exists) {
			exists = true;
			std::cout << "TARGET!->";
		}
		std::cout << *it << "]";
	}
	std::cout << "\n";
	outcome = easyfind(source, target);
	if (!exists && outcome == source.end())
		std::cout << "OK: Target does not exist in container.\n";
	else if (!exists && outcome != source.end())
		std::cout << "KO: Target does not exists in container, yet this was found: " << *outcome << "\n";
	else if (exists && outcome == source.end())
		std::cout << "KO: Target exists in container, but was not found\n";
	else
		std::cout << "OK: Target exists in container and was found: " << *outcome << "\n";
}

int main(void) {
	{
		std::cout << "Testing easyfind on empty int vector\n";
		int len = 0;
		int target = rangen(0, 420000);
		std::vector<int> intVec;
		intVec.reserve(len);
		for (int i = 0; i < len; i++)
			intVec.emplace_back(i);
		search("vector", intVec, target);
		std::cout << "Target not in container:\n";
		search("vector", intVec, 42);
	}
	{
		std::cout << "Testing easyfind on int vector\n";
		int len = 20;
		int target = 17;
		std::vector<int> intVec;
		intVec.reserve(len);
		for (int i = 0; i < len; i++)
			intVec.emplace_back(i);
		search("vector", intVec, target);
		std::cout << "Target not in container:\n";
		search("vector", intVec, 42);
	}
	{
		std::cout << "\nTesting easyfind on random size int list\n";
		int len = rangen(1, 500);
		int target = rangen(0, 99);
		std::list<int> randomList;
		for (int i = 0; i < len; i++)
			randomList.emplace_back(rangen(0, 99));
		search("vector", randomList, target);
	}
	{
		std::cout << "\nTesting easyfind on random size int multiset\n";
		int len = rangen(1, 5000);
		int target = rangen(0, 99);
		std::multiset<int> randomSet;
		for (int i = 0; i < len; i++)
			randomSet.insert(rangen(0, 99));
		search("multiset", randomSet, target);
	}
	// {
	// 	std::cout << "\nTesting easyfind on double vector\n";
	// 	std::vector<double> doubleVec;
	// 	int len = 20;
	// 	int target = 17;
	// 	for (int i = 0; i < len; i++)
	// 		doubleVec.push_back(0.1 + i);
	// 	search("vector", doubleVec, target);
	// 	for (int i = 0; i < len; i++)
	// 		doubleVec.push_back(0.0 + i);
	// 	search("vector", doubleVec, target);
	// }
	return 0;
}