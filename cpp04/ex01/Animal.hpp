#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
protected:
	std::string	_type;
public:
	// Default Constructor
	Animal();
	// Copy Constructor
	Animal(const Animal& other);
	// Destructor
	virtual ~Animal();
	// Copy Assignment Operator
	Animal& operator=(const Animal& other);

	// Getters
	const std::string& getType() const;
	// Setters
	// Other
	virtual void makeSound() const;
};

#endif
