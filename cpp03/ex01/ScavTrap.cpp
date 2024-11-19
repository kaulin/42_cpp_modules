#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap () {
	_name = "INSERT LESS BORING PLACEHOLDER NAME HERE";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "	Default constructor called on ScavTrap" << std::endl;
}
// Parameterized Constructor
ScavTrap::ScavTrap (std::string name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "	Parameterized constructor called for ScavTrap " << _name << std::endl;
}
// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "	Destructor called on ScavTrap " << _name << std::endl;
}
// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) {
	_name = other._name + " Clone";
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "	Copy constructor called for  ClapTrap " << _name << std::endl;
}
// Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other) return *this;
	_name = other._name + " Copy";
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "	Copy assignment operator called on  ClapTrap " << _name << std::endl;
	return *this;
}
// Getters
// Setters
// Other
void ScavTrap::attack(const std::string& target) {
	if (!_hitPoints) std::cout << "ScavTrap " << _name << " is out of hit points and can't attack!" << std::endl;
	else if (!_energyPoints)  std::cout << "ScavTrap " << _name << " is out of energy points and can't attack!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
}
void ScavTrap::takeDamage(unsigned int amount) {
	( _hitPoints > amount) ? _hitPoints -= amount : _hitPoints = 0;
	std::cout << "ScavTrap " << _name << " took " << amount << " damage and has " << _hitPoints << " hit points left!" << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount) {
	if (!_hitPoints) std::cout << "ScavTrap " << _name << " is out of hit points and can't repair!" << std::endl;
	else if (!_energyPoints)  std::cout << "ScavTrap " << _name << " is out of energy points and can't repair!" << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ScavTrap " << _name << " repaired " << amount << " hit points and now has " << _hitPoints << " left!" << std::endl;
	}

}
void ScavTrap::guardGate() {
	if (!_hitPoints) std::cout << "ScavTrap " << _name << " is out of hit points and can't enter Gate keeper mode!" << std::endl;
	else if (!_energyPoints)  std::cout << "ScavTrap " << _name << " is out of energy points and can't enter Gate keeper mode!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " entered Gate keeper mode!" << std::endl;
	}
}