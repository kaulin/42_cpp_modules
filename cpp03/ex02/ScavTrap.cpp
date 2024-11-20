#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap () {
	std::cout << "	Default constructor called on ScavTrap" << std::endl;
	_name = "Scavvy";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
// Parameterized Constructor
ScavTrap::ScavTrap(const std::string& name) {
	std::cout << "	Parameterized constructor called for ScavTrap " << _name << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "	Destructor called on ScavTrap " << _name << std::endl;
}
// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "	Copy constructor called for ScavTrap " << _name << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}
// Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "	Copy assignment operator called on ScavTrap " << _name << std::endl;
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
void ScavTrap::attack(const std::string& target) {
	if (!_hitPoints) std::cout << "	ScavTrap " << _name << " is out of hit points and can't attack!" << std::endl;
	else if (!_energyPoints)  std::cout << "	ScavTrap " << _name << " is out of energy points and can't attack!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "	ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
}
void ScavTrap::guardGate() {
	if (!_hitPoints) std::cout << "	ScavTrap " << _name << " is out of hit points and can't gatekeep!" << std::endl;
	else if (!_energyPoints)  std::cout << "	ScavTrap " << _name << " is out of energy points and can't gatekeep!" << std::endl;
	else std::cout << "	ScavTrap " << _name << " is gatekeeping!" << std::endl;
}