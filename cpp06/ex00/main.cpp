#include "ScalarConverter.hpp"

int main (int argc, char** argv) {
	std::string literal;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <literal>\n";
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}