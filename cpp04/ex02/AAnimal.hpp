#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string m_type;
	public:
		AAnimal(void);
		AAnimal(std::string);
		AAnimal(AAnimal const &);

		AAnimal	&operator=(AAnimal const &);

		virtual ~AAnimal(void);

		virtual void makeSound(void) const = 0;

		std::string const &getType(void) const;
		void setType(std::string const &);
};

#endif
