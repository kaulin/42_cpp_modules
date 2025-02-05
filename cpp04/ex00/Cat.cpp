#include "Cat.hpp"

// Default Constructor
Cat::Cat () {
	std::cout << "Cat: Default constructor called." << std::endl;
	_type = "Cat";
}
// Copy Constructor
Cat::Cat(const Cat& other) {
	std::cout << "Cat: Copy constructor called." << std::endl;
	_type = other._type;
}
// Destructor
Cat::~Cat() {
	std::cout << "Cat: Destructor called." << std::endl;
}
// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	return *this;
}
// Getters
// Setters
// Other
	void Cat::makeSound() const { std::cout << "MEOW MEOW!!!" << std::endl; }