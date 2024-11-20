#include "Animal.hpp"

// Default Constructor
Animal::Animal () : _type("Undefined animal") {
	std::cout << "	Animal: Default constructor called." << std::endl;
}
// Parameterized Constructor
Animal::Animal (const std::string& name) : _type(name) {
	std::cout << "	Animal: Parameterized constructor called." << std::endl;
}
// Destructor
Animal::~Animal() {
	std::cout << "	Animal: Destructor called." << std::endl;
}
// Copy Constructor
Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "	Animal: Copy constructor called." << std::endl;
}
// Copy Assignment Operator
Animal& Animal::operator=(const Animal& other) {
	if (this == &other) return *this;
	_type = other._type;
	std::cout << "Animal: Copy assignment operator called." << std::endl;
	return *this;
}
// Getters
	std::string& Animal::getType() { return _type; }
// Setters
// Other
	void Animal::makeSound() { std::cout << "Appropriate sound for an undefined animal" << std::endl; }