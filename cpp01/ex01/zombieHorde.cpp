#include "Zombie.hpp"

Zombie* zombieHorde(int N, string name)
{
	Zombie *zhorde;

	zhorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zhorde[i] = Zombie(name);
	return zhorde;
}
