#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string m_type;
	public:
		Animal(void);
		Animal(std::string);
		Animal(Animal const &);

		Animal	&operator=(Animal const &);

		virtual ~Animal(void);

		virtual void makeSound(void) const;

		std::string const &getType(void) const;
		void setType(std::string const &);
};

#endif
