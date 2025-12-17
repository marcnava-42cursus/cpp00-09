#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <cstddef>
# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	m_ideas[100];
	public:
		Brain(void);
		Brain(Brain const &other);

		Brain	&operator=(Brain const &other);

		~Brain(void);

		std::string const	&getIdea(std::size_t index) const;
		void				setIdea(std::size_t index, std::string const &idea);
};

#endif
