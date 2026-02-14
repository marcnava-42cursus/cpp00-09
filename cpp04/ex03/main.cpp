#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void	runExtraTests(void)
{
	std::cout << "----- extra tests -----" << std::endl;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character		alice("alice");
	Character		target("target");
	AMateria		*m0 = src->createMateria("ice");
	AMateria		*m1 = src->createMateria("cure");
	AMateria		*m2 = src->createMateria("ice");
	AMateria		*m3 = src->createMateria("cure");
	AMateria		*overflow = src->createMateria("ice");

	alice.equip(m0);
	alice.equip(m1);
	alice.equip(m2);
	alice.equip(m3);
	alice.equip(overflow);
	delete overflow;

	alice.use(-1, target);
	alice.use(4, target);
	alice.use(0, target);
	alice.use(1, target);

	alice.unequip(1);
	alice.use(1, target);
	delete m1;

	Character	copy(alice);
	alice.unequip(0);
	delete m0;
	copy.use(0, target);

	delete src;
	std::cout << "----- end extra tests -----" << std::endl;
}

int	main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter		*me = new Character("me");
	AMateria		*tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter		*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	runExtraTests();
	return (0);
}
