#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie '" << name << "' created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie '" << name << "' destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
