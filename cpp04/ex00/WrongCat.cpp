#include "WrongCat.hpp"

// Default Constructor
WrongCat::WrongCat () {
	_type = "WrongCat";
	std::cout << "WrongCat: Default constructor called." << std::endl;
}
// Destructor
WrongCat::~WrongCat() {
	std::cout << "WrongCat: Destructor called." << std::endl;
}
// Getters
// Setters
// Other
	void WrongCat::makeSound(void) const { std::cout << "MEOW MEOW" << std::endl; }