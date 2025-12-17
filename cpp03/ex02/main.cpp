#include "FragTrap.hpp"

int main()
{
	FragTrap e;
	FragTrap f("Chadd");

	e.highFiveGuys();
	e.attack("some random dude");
	e.takeDamage(101);
	e.takeDamage(1);
	e.attack("some random dude");
	f.highFiveGuys();

	return (0);
}
