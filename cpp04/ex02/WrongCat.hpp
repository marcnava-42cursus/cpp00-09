#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(std::string const &type);
		WrongCat(WrongCat const &copy);
		
		WrongCat const &operator=(WrongCat const &copy);
		
		~WrongCat(void);
		
		std::string const &getType(void) const;
		void setType(std::string const &type);

		void makeSound(void) const;
};

#endif
