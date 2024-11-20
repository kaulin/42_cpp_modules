#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	std::cout << "Clappers:" << std::endl;
	ClapTrap*		heapClapper = new ClapTrap;
	ClapTrap		stackClapper1("Clapperoni1");
	ClapTrap		stackClapper2("Clapperoni2");
	ClapTrap		cloneClapper(stackClapper1);
	ClapTrap		copyClapper1;
	ClapTrap		copyClapper2;
	std::cout << "\nScavvers:" << std::endl;
	ScavTrap* 		heapScavver = new ScavTrap;
	ScavTrap		stackScavver1("Scavveroni1");
	ScavTrap		stackScavver2("Scavveroni2");
	ScavTrap		cloneScavver(stackScavver1);
	ScavTrap		copyScavver1;
	ScavTrap		copyScavver2;
	
	// std::cout << "\nTesting Clappers:" << std::endl;
	// heapClapper->takeDamage(6);
	// heapClapper->beRepaired(1);
	// heapClapper->takeDamage(6);
	// heapClapper->beRepaired(1);
	// heapClapper->attack("The 42 Norm");
	// for (int i = 0; i <= 10; i++) stackClapper1.attack("The 42 Norm");
	// copyClapper1 = stackClapper1;
	// copyClapper1.takeDamage(9);
	// copyClapper1.beRepaired(10);
	// copyClapper2 = stackClapper2;
	// copyClapper2.takeDamage(9);
	// copyClapper2.beRepaired(10);
	
	std::cout << "\nTesting Scavvers:" << std::endl;
	heapScavver->takeDamage(60);
	heapScavver->beRepaired(10);
	heapScavver->takeDamage(60);
	heapScavver->beRepaired(10);
	heapScavver->guardGate();
	heapScavver->attack("The 42 Norm");
	for (int i = 0; i <= 50; i++) stackScavver1.attack("The 42 Norm");
	copyScavver1 = stackScavver1;
	copyScavver1.takeDamage(9);
	copyScavver1.beRepaired(10);
	copyScavver1.guardGate();
	copyScavver2 = stackScavver2;
	copyScavver2.takeDamage(9);
	copyScavver2.beRepaired(10);
	cloneScavver.guardGate();

	std::cout << "\nDeconstructing:" << std::endl;
	delete heapClapper;
	delete heapScavver;
	return 0;
}