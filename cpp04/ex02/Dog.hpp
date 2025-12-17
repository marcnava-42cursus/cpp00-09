#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain	*m_brain;
	public:
		Dog(void);
		Dog(Dog const &other);

		Dog	&operator=(Dog const &other);

		~Dog(void);

		void	makeSound(void) const;

		void		setIdea(std::size_t index, std::string const &idea);
		std::string	getIdea(std::size_t index) const;
		Brain const	*getBrain(void) const;
};

#endif
