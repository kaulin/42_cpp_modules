#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " positive_integer1 positive_integer2 [positive_integer3] ... [positive_integerN]\n";
		return 1;
	}
	try {
		long result = rpn.process(argv[1]);
		std::cout << result << "\n";
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
	return 0;
}