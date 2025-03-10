#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExchange bcx;
	bcx.calculateTotals(argv[1]);
	return 0;
}