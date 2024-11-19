#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	// Default Constructor
	ClapTrap();
	// Parameterized Constructor
	ClapTrap(std::string name);
	// Destructor
	~ClapTrap();
	// Copy Constructor
	ClapTrap(const ClapTrap& other);
	// Copy Assignment Operator
	ClapTrap& operator=(const ClapTrap& other);

	// Getters
	// Setters
	// Other
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
