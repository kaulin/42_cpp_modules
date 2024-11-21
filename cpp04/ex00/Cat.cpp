#include "Cat.hpp"

// Default Constructor
Cat::Cat () {
	std::cout << "Cat: Default constructor called." << std::endl;
	std::cout << "Cat: type before: " << _type << std::endl;
	_type = "Cat";
	std::cout << "Cat: type after: " << _type << std::endl;
}
// Destructor
Cat::~Cat() {
	std::cout << "Cat: Destructor called." << std::endl;
}
// Getters
// Setters
// Other
	void Cat::makeSound(void) const { std::cout << "MEOW MEOW" << std::endl; }