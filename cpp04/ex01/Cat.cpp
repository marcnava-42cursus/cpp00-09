#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), m_brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy): Animal(copy), m_brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
	delete this->m_brain;
}

Cat	&Cat::operator=(Cat const &copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		if (this->m_brain == NULL)
			this->m_brain = new Brain();
		*(this->m_brain) = *(copy.m_brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOW!!!!!" << std::endl;
}

void	Cat::setIdea(std::size_t index, std::string const &idea)
{
	if (this->m_brain != NULL)
		this->m_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(std::size_t index) const
{
	if (this->m_brain != NULL)
		return this->m_brain->getIdea(index);
	return "";
}

Brain const	*Cat::getBrain(void) const
{
	return this->m_brain;
}
