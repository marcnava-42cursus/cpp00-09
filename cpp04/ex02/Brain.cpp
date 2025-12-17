#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain	&Brain::operator=(Brain const &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (std::size_t i = 0; i < 100; i++)
			this->m_ideas[i] = other.m_ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;
}

std::string const	&Brain::getIdea(std::size_t index) const
{
	static std::string	empty;

	if (index >= 100)
	{
		std::cout << "Idea index out of range" << std::endl;
		return (empty);
	}
	return (this->m_ideas[index]);
}

void	Brain::setIdea(std::size_t index, std::string const &idea)
{
	if (index >= 100)
	{
		std::cout << "Idea index out of range" << std::endl;
		return ;
	}
	this->m_ideas[index] = idea;
}
