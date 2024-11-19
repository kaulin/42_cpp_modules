#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap*		deleteMe = new ClapTrap;
	ClapTrap		stacked("Stan Stackowitch");
	ClapTrap	stable(stacked);
	deleteMe->takeDamage(6);
	deleteMe->beRepaired(1);
	deleteMe->takeDamage(6);
	deleteMe->beRepaired(1);
	deleteMe->attack("Stan");
	delete deleteMe;
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	stacked.attack("Stan Stackowitch Clone");
	stable.takeDamage(0);
	return 0;
}