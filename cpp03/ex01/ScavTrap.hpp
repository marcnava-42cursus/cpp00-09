#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

 #include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool m_gate;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		virtual ~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);

		void attack(const std::string &target);
		void guardGate(void);
};

#endif