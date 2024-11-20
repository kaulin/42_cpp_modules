#include "Cat.hpp"

// Default Constructor
Cat::Cat () : _type("Undefined cat") {
	std::cout << "	Cat: Default constructor called." << std::endl;
}
// Parameterized Constructor
Cat::Cat (const std::string& name) : _type(name) {
	std::cout << "	Cat: Parameterized constructor called." << std::endl;
}
// Destructor
Cat::~Cat() {
	std::cout << "	Cat: Destructor called." << std::endl;
}
// Copy Constructor
Cat::Cat(const Cat& other) : _type(other._type) {
	std::cout << "	Cat: Copy constructor called." << std::endl;
}
// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other) {
	if (this == &other) return *this;
	_type = other._type;
	std::cout << "Cat: Copy assignment operator called." << std::endl;
	return *this;
}
// Getters
// Setters
// Other
	void Animal::makeSound(void) { std::cout << "Appropriate sound for an undefined cat" << std::endl; }