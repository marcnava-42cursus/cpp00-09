#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		typedef AForm* (*FormCreator)(const std::string &target);

		static AForm* createShrubbery(const std::string &target);
		static AForm* createRobotomy(const std::string &target);
		static AForm* createPresidential(const std::string &target);

	public:
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);

		AForm* makeForm(const std::string &form_name, const std::string &target) const;
};

#endif
