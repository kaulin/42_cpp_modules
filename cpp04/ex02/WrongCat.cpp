#include "WrongCat.hpp"

// Default Constructor
WrongCat::WrongCat () {
	_type = "WrongCat";
	std::cout << "WrongCat: Default constructor called." << std::endl;
}
// Copy Constructor
WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "WrongCat: Copy constructor called." << std::endl;
	_type = other._type;
}
// Destructor
WrongCat::~WrongCat() {
	std::cout << "WrongCat: Destructor called." << std::endl;
}
// Copy Assignment Operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	return *this;
}
// Getters
// Setters
// Other
	void WrongCat::makeSound(void) const { std::cout << "MEOW MEOW!!!" << std::endl; }