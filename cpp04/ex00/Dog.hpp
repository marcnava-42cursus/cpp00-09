#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	private:
		std::string	m_type;
	public:
		Dog(void);
		Dog(std::string const &type);
		Dog(Dog const &other);

		Dog	&operator=(Dog const &other);

		~Dog(void);

		void	makeSound(void) const;

		std::string const &getType(void) const;
		void	setType(std::string const &type);
};

#endif
