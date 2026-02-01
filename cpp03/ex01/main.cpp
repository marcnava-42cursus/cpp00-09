#include "ScavTrap.hpp"

int main()
{
	ScavTrap c;
	ScavTrap d("Savage");

	std::cout << "c gate status: " << (c.getGate() ? "ON" : "OFF") << std::endl;
	c.attack("CloneTrap");
	c.beRepaired(22);
	c.takeDamage(21);
	c.beRepaired(22);
	c.guardGate();
	std::cout << "c gate status: " << (c.getGate() ? "ON" : "OFF") << std::endl;
	c.setGate(false);
	std::cout << "c gate status: " << (c.getGate() ? "ON" : "OFF") << std::endl;
	c.guardGate();
	d.attack("Savage-clone");
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack("ScavTrap-clone");

	return (0);
}
