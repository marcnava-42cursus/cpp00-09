#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
}

AForm* Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &form_name, const std::string &target) const
{
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static FormCreator creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Intern couldn't create " << form_name
		<< " because this form does not exist." << std::endl;
	return NULL;
}
