#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
	std::string	_type;
public:
	// Default Constructor
	WrongAnimal();
	// Parameterized Constructor
	WrongAnimal(const std::string& name) = delete;
	// Destructor
	~WrongAnimal();
	// Copy Constructor
	WrongAnimal(const WrongAnimal& other) = delete;
	// Copy Assignment Operator
	WrongAnimal& operator=(const WrongAnimal& other) = delete;

	// Getters
	const std::string& getType() const;
	// Setters
	// Other
	void makeSound() const;
};

#endif
