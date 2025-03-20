#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <RPN expression>\n";
		return 1;
	}
	RPN rpn;
	try {
		long result = rpn.process(argv[1]);
		std::cout << result << "\n";
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
	return 0;
}