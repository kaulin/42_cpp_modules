#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Default Constructor
	FragTrap();
	// Parameterized Constructor
	FragTrap(const std::string& name);
	// Destructor
	~FragTrap();
	// Copy Constructor
	FragTrap(const FragTrap& other);
	// Copy Assignment Operator
	FragTrap& operator=(const FragTrap& other);

	// Getters
	// Setters
	// Other
	void highFivesGuys(void);
};

#endif
