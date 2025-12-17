#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		std::string	m_type;
	public:
		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &copy);

		Cat	&operator=(Cat const &copy);
		
		~Cat(void);

		void	makeSound(void) const;
		
		std::string const &getType(void) const;
		void setType(std::string const &type);
};

#endif
