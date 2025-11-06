#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

# define DEBUG "DEBUG"
# define INFO "INFO"
# define WARNING "WARNING"
# define ERROR "ERROR"

class Harl
{
	private:
		void m_debug( void );
		void m_info( void );
		void m_warning( void );
		void m_error( void );
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif