#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string m_name;
		int m_hp;
		int m_ep;
		int m_ad;
	public:
		ClapTrap(void);

		ClapTrap(std::string);

		ClapTrap(ClapTrap const &);

		ClapTrap &operator=(ClapTrap const &);

		~ClapTrap(void);

		std::string const &getName() const;
		int const &getHp(void) const;
		int const &getEp(void) const;
		int const &getAd(void) const;

		void setName(const std::string &);
		void setHp(const int &);
		void setEp(const int &);
		void setAd(const int &);

		void attack(const std::string &);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);
};

#endif
