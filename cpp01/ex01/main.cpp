#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int N = 5;

	horde = zombieHorde(N, "paquito");

	for (int i = 0; i < N; i++)
	{
		cout << "Zombie " << i << ": ";
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
