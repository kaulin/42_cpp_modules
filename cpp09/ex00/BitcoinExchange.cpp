#include "BitcoinExchange.hpp"

// Default Constructor
BitcoinExchange::BitcoinExchange () {
	std::cout << "BitcoinExchange: Default constructor called.\n";
}
// Parameterized Constructor
BitcoinExchange::BitcoinExchange (const std::string& name) : _name(name) {
	std::cout << "BitcoinExchange: Parameterized constructor called.\n"
}
// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _name(other._name) {
	std::cout << "BitcoinExchange: Copy constructor called.\n";
}
// Destructor
BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange: Destructor called.\n";
}
// Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange: Copy assignment operator called.\n";
	if (this == &other) return *this;
	_name = other._name;
	return *this;
}
// Getters
const std::string&	BitcoinExchange::getName() const { return _name;}
// Setters
void	BitcoinExchange::setName(std::string name) { _name = name; }
// Other