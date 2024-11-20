#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap () {
	std::cout << "	Default constructor called on FragTrap" << std::endl;
	_name = "Fraggy";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
// Parameterized Constructor
FragTrap::FragTrap(const std::string& name) {
	std::cout << "	Parameterized constructor called for FragTrap " << _name << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
// Destructor
FragTrap::~FragTrap() {
	std::cout << "	Destructor called on FragTrap " << _name << std::endl;
}
// Copy Constructor
FragTrap::FragTrap(const FragTrap& other) {
	std::cout << "	Copy constructor called for FragTrap " << _name << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}
// Copy Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "	Copy assignment operator called on FragTrap " << _name << std::endl;
	if (this == &other) return *this;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}
// Getters
// Setters
// Other
void FragTrap::highFivesGuys(void) {
	if (!_hitPoints) std::cout << "	FragTrap " << _name << " is out of hit points and can't high five!" << std::endl;
	else if (!_energyPoints)  std::cout << "	FragTrap " << _name << " is out of energy points and can't high five!" << std::endl;
	else std::cout << "	FragTrap " << _name << " is requesting a high five from the evaluator for a job well done!" << std::endl;
}