#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	// Default Constructor
	ScavTrap();
	// Parameterized Constructor
	ScavTrap(std::string name);
	// Destructor
	~ScavTrap();
	// Copy Constructor
	ScavTrap(const ScavTrap& other);
	// Copy Assignment Operator
	ScavTrap& operator=(const ScavTrap& other);

	// Getters
	// Setters
	// Other
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
};

#endif
