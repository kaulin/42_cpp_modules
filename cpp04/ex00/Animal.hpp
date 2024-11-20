#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
protected:
	std::string	_type;
public:
	// Default Constructor
	Animal();
	// Parameterized Constructor
	Animal(const std::string& name);
	// Destructor
	~Animal();
	// Copy Constructor
	Animal(const Animal& other);
	// Copy Assignment Operator
	Animal& operator=(const Animal& other);

	// Getters
	std::string& getType();
	// Setters
	// Other
	virtual void makeSound();
};

#endif
