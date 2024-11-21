#include "Animal.hpp"

// Default Constructor
Animal::Animal () : _type("Undefined animal") {
	std::cout << "Animal: Default constructor called." << std::endl;
}
// Copy Constructor
Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal: Copy constructor called." << std::endl;
}
// Destructor
Animal::~Animal() {
	std::cout << "Animal: Destructor called." << std::endl;
}
// Copy Assignment Operator
Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	return *this;
}
// Getters
	const std::string& Animal::getType() const { return _type; }
// Setters
// Other
	void Animal::makeSound() const { std::cout << "APPROPRIATE SOUND FOR AN UNDEFINED ANIMAL!!!" << std::endl; }