#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
	std::string	_type;
public:
	// Default Constructor
	WrongAnimal();
	// Copy Constructor
	WrongAnimal(const WrongAnimal& other);
	// Destructor
	~WrongAnimal();
	// Copy Assignment Operator
	WrongAnimal& operator=(const WrongAnimal& other);

	// Getters
	const std::string& getType() const;
	// Setters
	// Other
	void makeSound() const;
};

#endif
