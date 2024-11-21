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
	// Copy Constructor
	Animal(const Animal& other);
	Animal(const std::string& name);
	// Destructor
	virtual ~Animal();
	// Copy Assignment Operator
	Animal& operator=(const Animal& other);

	// Getters
	virtual const std::string& getType() const;
	// Setters
	// Other
	virtual void makeSound() const;
};

#endif
