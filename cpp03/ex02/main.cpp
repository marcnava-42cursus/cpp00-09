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
	std::cout << "f name: " << f.getName() << ", AD: " << f.getAd() << std::endl;
	f.setAd(100);
	std::cout << "f new AD: " << f.getAd() << std::endl;
	f.attack("some super random dude");
	f.setName("Omega");
	std::cout << "f new name: " << f.getName() << std::endl;

	return (0);
}
