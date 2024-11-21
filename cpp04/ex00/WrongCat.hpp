#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	// Default Constructor
	WrongCat();
	// Parameterized Constructor
	WrongCat(const std::string& name) = delete;
	// Destructor
	~WrongCat();
	// Copy Constructor
	WrongCat(const WrongCat& other) = delete;
	// Copy Assignment Operator
	WrongCat& operator=(const WrongCat& other) = delete;

	// Getters
	// Setters
	// Other
	void makeSound(void) const;
};

#endif
