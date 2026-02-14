#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static int const	kStorageSize = 4;
		AMateria			*m_storage[kStorageSize];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);
		virtual ~MateriaSource(void);

		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(std::string const &type);
};

#endif
