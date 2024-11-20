#include "ClapTrap.hpp"

int	main(void) {
	std::cout << "Clappers:" << std::endl;
	ClapTrap*		heapClapper = new ClapTrap;
	ClapTrap		stackClapper1("Clapperoni1");
	ClapTrap		stackClapper2("Clapperoni2");
	ClapTrap		cloneClapper(stackClapper1);
	ClapTrap		copyClapper1;
	ClapTrap		copyClapper2;

	std::cout << "\nTesting Clappers:" << std::endl;
	heapClapper->takeDamage(6);
	heapClapper->beRepaired(1);
	heapClapper->takeDamage(6);
	heapClapper->beRepaired(1);
	heapClapper->attack("The 42 Norm");
	for (int i = 0; i <= 10; i++) stackClapper1.attack("The 42 Norm");
	copyClapper1 = stackClapper1;
	copyClapper1.takeDamage(9);
	copyClapper1.beRepaired(10);
	copyClapper2 = stackClapper2;
	copyClapper2.takeDamage(9);
	copyClapper2.beRepaired(10);

	std::cout << "\nDeconstructing:" << std::endl;
	delete heapClapper;
	return 0;
}