#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	m_type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &copy);
		
		WrongAnimal const	&operator=(WrongAnimal const &copy);
		
		virtual ~WrongAnimal(void);

		std::string const	&getType(void) const;
		void				setType(std::string const &type);

			void	makeSound(void) const;
};

#endif
