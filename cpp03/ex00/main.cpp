#include "ClapTrap.hpp"

void	alice_rundown(void)
{
	ClapTrap alice("Alice");

	std::cout << "Alice stats => HP: " << alice.getHp() << ", EP: " << alice.getEp() << ", AD: " << alice.getAd() << std::endl;
	alice.setAd(3);
	std::cout << "Alice new AD: " << alice.getAd() << std::endl;
	alice.setName("Alice_2");
	std::cout << "Alice new name: " << alice.getName() << std::endl;

	alice.attack("Bob");
	alice.attack("Chris");
	alice.attack("Diana");
	alice.attack("Elisa");
	alice.attack("Fred");
	alice.attack("Gemma");
	alice.attack("Henry");
	alice.attack("Isabella");
	alice.attack("Jack");
	alice.attack("Kevin");
	alice.attack("Laura");
	alice.attack("Mike");
}

void	bob_rundown(void)
{
	ClapTrap	bob("Bob");

	std::cout << "Bob stats => HP: " << bob.getHp() << ", EP: " << bob.getEp() << ", AD: " << bob.getAd() << std::endl;
	bob.setEp(3);
	std::cout << "Bob new EP: " << bob.getEp() << std::endl;
	bob.setName("Bobby");
	std::cout << "Bob new name: " << bob.getName() << std::endl;

	while (bob.getHp())
	{
		bob.takeDamage(2);
		bob.beRepaired(2);
	}
	bob.takeDamage(1);
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Alice's rundown..." << std::endl << std::endl;
	alice_rundown();
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}
