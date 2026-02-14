#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	m_type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		AMateria	&operator=(AMateria const &other);
		virtual ~AMateria(void);

		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
