#include <cstddef>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const std::size_t	animalCount = 4;
	AAnimal				*animals[animalCount];

	// Uncommenting the next line would fail to compile because AAnimal is abstract.
	// AAnimal			invalidAnimal;

	std::cout << "----- Creating animals -----" << std::endl;
	for (std::size_t i = 0; i < animalCount; i++)
	{
		if (i < animalCount / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "----- Making sounds -----" << std::endl;
	for (std::size_t i = 0; i < animalCount; i++)
		animals[i]->makeSound();

	std::cout << "----- Deep copy tests -----" << std::endl;
	Dog	basicDog;
	basicDog.setIdea(0, "Chase the mailman");
	Dog	copyDog(basicDog);
	copyDog.setIdea(0, "Sleep on the couch");
	std::cout << "basicDog idea[0]: " << basicDog.getIdea(0) << std::endl;
	std::cout << "copyDog idea[0]: " << copyDog.getIdea(0) << std::endl;

	Dog	assignedDog;
	assignedDog = basicDog;
	assignedDog.setIdea(1, "Eat all the treats");
	std::cout << "basicDog idea[1]: " << basicDog.getIdea(1) << std::endl;
	std::cout << "assignedDog idea[1]: " << assignedDog.getIdea(1) << std::endl;

	Cat	originalCat;
	originalCat.setIdea(2, "Climb the curtains");
	Cat	copiedCat(originalCat);
	copiedCat.setIdea(2, "Nap in the sun");
	std::cout << "originalCat idea[2]: " << originalCat.getIdea(2) << std::endl;
	std::cout << "copiedCat idea[2]: " << copiedCat.getIdea(2) << std::endl;

	std::cout << "----- Deleting animals -----" << std::endl;
	for (std::size_t i = 0; i < animalCount; i++)
		delete animals[i];
	return (0);
}
