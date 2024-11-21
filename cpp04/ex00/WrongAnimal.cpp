#include "WrongAnimal.hpp"

// Default Constructor
WrongAnimal::WrongAnimal () : _type("Undefined wrong animal") {
	std::cout << "WrongAnimal: Default constructor called." << std::endl;
}
// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: Destructor called." << std::endl;
}
// Getters
	const std::string& WrongAnimal::getType() const { return _type; }
// Setters
// Other
	void WrongAnimal::makeSound() const { std::cout << "Appropriate sound for an undefined wrong animal" << std::endl; }