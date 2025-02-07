#include <random>
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
	int outcome = 0;
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
	try {
		outcome = *(::easyfind(source, target));
		if (!exists)
			std::cout << "Error: Target does not exists in container, yet this was found: " << outcome << "\n";
		else
			std::cout << "Found target in container: " << outcome << "\n";
	} catch (std::exception& e) {
		if (!exists)
			std::cout << "Target does not exist in container, caught exception:\n" << e.what() << "\n";
		else
			std::cout << "Error: Target exists in container, yet caught exception:\n" << e.what() << "\n";
	}
}

int main(void) {
	{
		std::cout << "Testing easyfind on int vector\n";
		std::vector<int> intVec;
		int len = 20;
		int target = 17;
		for (int i = 0; i < len; i++)
			intVec.push_back(i);
		::search("vector", intVec, target);
		std::cout << "Causing an exception:\n";
		::search("vector", intVec, 42);
	}
	{
		std::cout << "\nTesting easyfind on random size int list\n";
		std::vector<int> randomList;
		int len = rangen(1, 500);
		int target = rangen(0, 100);
		for (int i = 0; i < len; i++)
			randomList.push_back(rangen(0, 100));
		::search("vector", randomList, target);
	}
	{
		std::cout << "\nTesting easyfind on double vector\n";
		std::vector<double> doubleVec;
		int len = 20;
		int target = 17;
		for (int i = 0; i < len; i++)
			doubleVec.push_back(0.1 + i);
		::search("vector", doubleVec, target);
		for (int i = 0; i < len; i++)
			doubleVec.push_back(0.0 + i);
		::search("vector", doubleVec, target);
	}
	return 0;
}