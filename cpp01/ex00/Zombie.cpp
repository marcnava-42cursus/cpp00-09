#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->m_name = name;
	std::cout << "Zombie '" << name << "' created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie '" << m_name << "' destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
