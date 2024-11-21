#include "WrongAnimal.hpp"

// Default Constructor
WrongAnimal::WrongAnimal () : _type("Undefined wrong animal") {
	std::cout << "WrongAnimal: Default constructor called." << std::endl;
}
// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal: Copy constructor called." << std::endl;
	_type = other._type;
}
// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: Destructor called." << std::endl;
}
// Copy Assignment Operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal: Copy assignment operator called." << std::endl;
	if (this == &other) return *this;
	_type = other._type;
	return *this;
}
// Getters
	const std::string& WrongAnimal::getType() const { return _type; }
// Setters
// Other
	void WrongAnimal::makeSound() const { std::cout << "Appropriate sound for an undefined wrong animal" << std::endl; }