#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap*		deleteMe = new ClapTrap;
	ClapTrap		stacked("Stan Stackowitch");

	ScavTrap* 		deleteMe2 = new ScavTrap;
	ScavTrap		stacked2("Ripperoni");
	ScavTrap		clone(stacked2);
	ScavTrap		copy;

	stacked2.guardGate();
	copy = stacked2;
	delete deleteMe;
	delete deleteMe2;
	// ClapTrap	stable(stacked);
	// deleteMe->takeDamage(6);
	// deleteMe->beRepaired(1);
	// deleteMe->takeDamage(6);
	// deleteMe->beRepaired(1);
	// deleteMe->attack("Stan");
	// delete deleteMe;
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	// stacked.attack("Stan Stackowitch Clone");
	// stable.takeDamage(0);
	return 0;
}