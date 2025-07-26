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
		Zombie(string name);
		~Zombie();
		void announce(void);
};

void randomChump(string name);
Zombie *newZombie(string name);

#endif