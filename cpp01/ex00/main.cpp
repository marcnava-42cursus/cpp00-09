#include "Zombie.hpp"

int main(void)
{
	Zombie *zmb = newZombie("Zombie 1");
	zmb->announce();

	randomChump("Zombie 2");

	delete zmb;
	return 0;
}
