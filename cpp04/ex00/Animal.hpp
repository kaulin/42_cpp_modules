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
	Animal(const std::string& name) = delete;
	// Destructor
	virtual ~Animal();
	// Copy Constructor
	Animal(const Animal& other) = delete;
	// Copy Assignment Operator
	Animal& operator=(const Animal& other) = delete;

	// Getters
	virtual const std::string& getType() const;
	// Setters
	// Other
	virtual void makeSound() const;
};

#endif
