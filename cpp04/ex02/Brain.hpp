#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include "Animal.hpp"

class Brain {
private:
	std::string _ideas[100];
public:
	// Default Constructor
	Brain();
	// Destructor
	~Brain();
	// Copy Constructor
	Brain(const Brain& other);
	// Copy Assignment Operator
	Brain& operator=(const Brain& other);

	// Getters
	const std::string getIdea(const int n) const;
	// Setters
	// Other
	void	brainwash();
};

#endif
