#include "Cat.hpp"

// Default Constructor
Cat::Cat () {
	std::cout << "Cat: Default constructor called." << std::endl;
	_type = "Cat";
}
// Destructor
Cat::~Cat() {
	std::cout << "Cat: Destructor called." << std::endl;
}
// Getters
// Setters
// Other
	void Cat::makeSound(void) const { std::cout << "MEOW MEOW" << std::endl; }