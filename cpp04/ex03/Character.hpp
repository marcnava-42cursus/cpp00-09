#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
	private:
		static int const	kInventorySize = 4;

		std::string	m_name;
		AMateria	*m_inventory[kInventorySize];

	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &other);
		Character	&operator=(Character const &other);
		virtual ~Character(void);

		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
};

#endif
