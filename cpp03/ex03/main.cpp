#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("Giga Chadd");
	DiamondTrap c(a);

	a.whoAmI();
	a.attack("some super random dude");

	b.whoAmI();
	std::cout << "b diamond name: " << b.getName() << std::endl;
	std::cout << "b claptrap name: " << b.ClapTrap::getName() << std::endl;
	std::cout << "b stats => HP: " << b.getHp() << ", EP: " << b.getEp() << ", AD: " << b.getAd() << std::endl;
	b.attack("Chadd-clone");
	b.guardGate();
	std::cout << "b gate: " << (b.getGate() ? "ON" : "OFF") << std::endl;
	b.setName("Ultra Chadd");
	std::cout << "b new diamond name: " << b.getName() << std::endl;
	b.whoAmI();

	c.whoAmI();

	return (0);
}
