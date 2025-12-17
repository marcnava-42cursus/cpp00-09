#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*m_brain;
	public:
		Cat(void);
		Cat(Cat const &copy);

		Cat	&operator=(Cat const &copy);
		
		~Cat(void);

		void	makeSound(void) const;
		
		void		setIdea(std::size_t index, std::string const &idea);
		std::string	getIdea(std::size_t index) const;
		Brain const	*getBrain(void) const;
};

#endif
