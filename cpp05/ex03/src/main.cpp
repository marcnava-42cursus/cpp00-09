#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

static void	printSeparator(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n" << std::endl;
}

static void	testFormLifecycle(const std::string &label, AForm *form)
{
	Bureaucrat low("Low", 150);
	Bureaucrat boss("Boss", 1);

	printSeparator(label);
	if (!form)
	{
		std::cout << "[KO] form pointer is NULL" << std::endl;
		return;
	}
	boss.executeForm(*form);
	low.signForm(*form);
	boss.signForm(*form);
	low.executeForm(*form);
	boss.executeForm(*form);
}

int main(void)
{
	Intern someRandomIntern;
	AForm *forms[4];

	std::remove("home_shrubbery");
	forms[0] = someRandomIntern.makeForm("shrubbery creation", "home");
	forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
	forms[2] = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	forms[3] = someRandomIntern.makeForm("coffee request", "office");

	testFormLifecycle("Shrubbery from Intern", forms[0]);
	testFormLifecycle("Robotomy from Intern", forms[1]);
	testFormLifecycle("Presidential from Intern", forms[2]);

	printSeparator("Invalid form name");
	if (forms[3] == NULL)
		std::cout << "[OK] invalid form returned NULL" << std::endl;
	else
		std::cout << "[KO] invalid form should have returned NULL" << std::endl;

	printSeparator("Extra robotomy runs (50% behavior)");
	if (forms[1])
	{
		Bureaucrat boss("Boss", 1);
		for (int i = 0; i < 5; i++)
			boss.executeForm(*forms[1]);
	}

	printSeparator("Shrubbery file check");
	{
		std::ifstream createdFile("home_shrubbery");
		if (createdFile)
			std::cout << "[OK] home_shrubbery created" << std::endl;
		else
			std::cout << "[KO] home_shrubbery missing" << std::endl;
	}

	for (int i = 0; i < 4; i++)
		delete forms[i];
	return 0;
}
