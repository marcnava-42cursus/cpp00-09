#include "Dog.hpp"

Dog::Dog(void): AAnimal("Dog"), m_brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy): AAnimal(copy), m_brain(NULL)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
	delete this->m_brain;
}

Dog	&Dog::operator=(Dog const &copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		if (this->m_brain == NULL)
			this->m_brain = new Brain();
		*(this->m_brain) = *(copy.m_brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "BARK!!!!!" << std::endl;
}

void	Dog::setIdea(std::size_t index, std::string const &idea)
{
	if (this->m_brain != NULL)
		this->m_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(std::size_t index) const
{
	if (this->m_brain != NULL)
		return this->m_brain->getIdea(index);
	return "";
}

Brain const	*Dog::getBrain(void) const
{
	return this->m_brain;
}
