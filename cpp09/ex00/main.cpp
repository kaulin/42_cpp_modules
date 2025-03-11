#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExchange bcx;
	try {
		bcx.initDatabase(DATABASE);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	try {
		bcx.calculateTotals(argv[1]);
	} catch (std::exception& e) {
	std::cout << e.what() << "\n";
	}
	return 0;
}