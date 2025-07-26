#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using namespace std;

class Zombie
{
	private:
		string name;
	public:
		Zombie();
		Zombie(string name);
		~Zombie();
		void announce(void);
};

Zombie* zombieHorde(int N, string name);

#endif