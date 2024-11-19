#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap () :
	_name("INSERT BORING PLACEHOLDER NAME HERE"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(10) {
	std::cout << "	Default constructor called on ClapTrap" << std::endl;
}
// Parameterized Constructor
ClapTrap::ClapTrap (std::string name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(10) {
	std::cout << "	Parameterized constructor called for ClapTrap " << _name << std::endl;
}
// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "	Destructor called on ClapTrap " << _name << std::endl;
}
// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other._name + " Clone"),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
	std::cout << "	Copy constructor called for ClapTrap " << _name << std::endl;
}
// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) return *this;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "	Copy assignment operator called on  ClapTrap " << _name << std::endl;
	return *this;
}
// Getters
// Setters
// Other
void ClapTrap::attack(const std::string& target) {
	if (!_hitPoints) std::cout << "ClapTrap " << _name << " is out of hit points and can't attack!" << std::endl;
	else if (!_energyPoints)  std::cout << "ClapTrap " << _name << " is out of energy points and can't attack!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount) {
	( _hitPoints > amount) ? _hitPoints -= amount : _hitPoints = 0;
	std::cout << "ClapTrap " << _name << " took " << amount << " damage and has " << _hitPoints << " hit points left!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (!_hitPoints) std::cout << "ClapTrap " << _name << " is out of hit points and can't repair!" << std::endl;
	else if (!_energyPoints)  std::cout << "ClapTrap " << _name << " is out of energy points and can't repair!" << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired " << amount << " hit points and now has " << _hitPoints << " left!" << std::endl;
	}

}