#include "PmergeMe.hpp"

static void isIntString(const std::string& string) {
	try {
		if (string.empty() || string.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument(string);
		std::stoi(string);
	} catch (const std::out_of_range& e) {
		throw std::invalid_argument(string);
	}
}

static bool validateArgs(int argc, char **argv) {
	try {
		for (int i = 1; i < argc; i++)
			isIntString(argv[i]);
		return true;
	} catch (const std::invalid_argument& e) {
		std::cout << "Error: Ivalid argument: " << e.what() << "\n";
		return false;
	}
}

static void printBefore(int argc, char** argv) {
	std::stringstream sstream;
	sstream << "Before: ";
	for (int i = 1; i < argc; i++)
		sstream << argv[i] << " ";
	std::cout << sstream.str() << "\n";
}

static void printAfter(std::vector<int> vec) {
	std::stringstream sstream;
	sstream << "After: ";
	for (int n : vec)
		sstream << n << " ";
	std::cout << sstream.str() << "\n";
}

static std::vector<int> argsToVector(int argc, char** argv) {
	std::vector<int> vec;
	vec.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
		vec.emplace_back(std::atoi(argv[i]));
	return vec;
}

static std::deque<int> argsToDeque(int argc, char** argv) {
	std::deque<int> deq;
	for (int i = 1; i < argc; i++)
		deq.emplace_back(std::atoi(argv[i]));
	return deq;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " positive_integer1 positive_integer2 [positive_integer3] ... [positive_integerN]\n";
		return 1;
	}
	if(!validateArgs(argc, argv))
		return 1;
	printBefore(argc, argv);

	// Vector implementation
	//start clock
	PmergeMe sorterVec;
	std::vector<int> vec = argsToVector(argc, argv);
	sorterVec.sortVector(vec);
	// stop clock
	
	// Deque implementation
	//start clock
	PmergeMe sorterDeq;
	std::deque<int> deq = argsToDeque(argc, argv);
	sorterDeq.sortDeque(deq);
	// stop clock

	// validate results

	printAfter(vec);

	// print vectime
	// print deqtime
	
	return 0;
}