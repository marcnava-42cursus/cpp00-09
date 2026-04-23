#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

static void	printSeparator(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n" << std::endl;
}

static void	testBureaucratLimits(void)
{
	printSeparator("Bureaucrat limits");

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		(void)tooHigh;
	}
	catch (const std::exception &e)
	{
		std::cout << "[OK] grade 0 throws: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("TooLow", 151);
		(void)tooLow;
	}
	catch (const std::exception &e)
	{
		std::cout << "[OK] grade 151 throws: " << e.what() << std::endl;
	}
	{
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);

		try
		{
			top.incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cout << "[OK] increment at grade 1 throws: " << e.what() << std::endl;
		}
		try
		{
			bottom.decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cout << "[OK] decrement at grade 150 throws: " << e.what() << std::endl;
		}
	}
}

static void	testShrubberyForm(void)
{
	printSeparator("ShrubberyCreationForm");
	{
		ShrubberyCreationForm shrub("home");
		Bureaucrat signLow("SignLow", 150);
		Bureaucrat signOk("SignOk", 145);
		Bureaucrat execLow("ExecLow", 138);
		Bureaucrat execOk("ExecOk", 137);

		std::remove("home_shrubbery");

		execOk.executeForm(shrub);
		signLow.signForm(shrub);
		signOk.signForm(shrub);
		execLow.executeForm(shrub);
		execOk.executeForm(shrub);

		std::ifstream createdFile("home_shrubbery");
		if (!createdFile)
			std::cout << "[KO] home_shrubbery missing" << std::endl;
		else
		{
			std::string line;
			std::getline(createdFile, line);
			std::cout << "[OK] home_shrubbery created, first line length: "
				<< line.length() << std::endl;
		}
	}
}

static void	testRobotomyForm(void)
{
	printSeparator("RobotomyRequestForm");
	{
		RobotomyRequestForm robot("Bender");
		Bureaucrat signLow("SignLow", 73);
		Bureaucrat signOk("SignOk", 72);
		Bureaucrat execLow("ExecLow", 46);
		Bureaucrat execOk("ExecOk", 45);

		execOk.executeForm(robot);
		signLow.signForm(robot);
		signOk.signForm(robot);
		execLow.executeForm(robot);
		for (int i = 0; i < 6; i++)
			execOk.executeForm(robot);
	}
}

static void	testPresidentialForm(void)
{
	printSeparator("PresidentialPardonForm");
	{
		PresidentialPardonForm pardon("Arthur Dent");
		Bureaucrat signLow("SignLow", 26);
		Bureaucrat signOk("SignOk", 25);
		Bureaucrat execLow("ExecLow", 6);
		Bureaucrat execOk("ExecOk", 5);

		execOk.executeForm(pardon);
		signLow.signForm(pardon);
		signOk.signForm(pardon);
		execLow.executeForm(pardon);
		execOk.executeForm(pardon);
	}
}

int main(void)
{
	testBureaucratLimits();
	testShrubberyForm();
	testRobotomyForm();
	testPresidentialForm();

	return 0;
}
