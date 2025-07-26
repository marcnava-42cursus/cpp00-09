#include "Zombie.hpp"

Zombie::Zombie(void) { }

Zombie::Zombie(string name)
{
	this->name = name;
	cout << "Zombie '" << name << "' created" << endl;
}

Zombie::~Zombie(void)
{
	cout << "Zombie '" << name << "' destroyed" << endl;
}

void Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}
