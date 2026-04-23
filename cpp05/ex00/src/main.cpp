#include "Bureaucrat.hpp"

static void	printTestResult(const std::string &name, bool ok)
{
	std::cout << (ok ? "[OK] " : "[KO] ") << name << std::endl;
}

int main(void)
{
	std::cout << "==== Bureaucrat exception tests ====" << std::endl;

	try
	{
		Bureaucrat a("Valid", 42);
		printTestResult("Constructor valid grade (42)", true);
		std::cout << a;
	}
	catch (const std::exception &e)
	{
		printTestResult("Constructor valid grade (42)", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat highCtor("CtorHigh", 0);
		(void)highCtor;
		printTestResult("Constructor grade too high (0)", false);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		printTestResult("Constructor grade too high (0)", true);
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		printTestResult("Constructor grade too high (0)", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat lowCtor("CtorLow", 151);
		(void)lowCtor;
		printTestResult("Constructor grade too low (151)", false);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		printTestResult("Constructor grade too low (151)", true);
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		printTestResult("Constructor grade too low (151)", false);
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat maxGrade("Max", 1);
	std::cout << "Before increment: " << maxGrade;
	try
	{
		maxGrade.incrementGrade();
		std::cout << "After increment: " << maxGrade;
		printTestResult("incrementGrade at 1", false);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		printTestResult("incrementGrade at 1", true);
		std::cout << e.what() << std::endl;
		std::cout << "After failed increment: " << maxGrade;
	}
	catch (const std::exception &e)
	{
		printTestResult("incrementGrade at 1", false);
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat minGrade("Min", 150);
	std::cout << "Before decrement: " << minGrade;
	try
	{
		minGrade.decrementGrade();
		std::cout << "After decrement: " << minGrade;
		printTestResult("decrementGrade at 150", false);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		printTestResult("decrementGrade at 150", true);
		std::cout << e.what() << std::endl;
		std::cout << "After failed decrement: " << minGrade;
	}
	catch (const std::exception &e)
	{
		printTestResult("decrementGrade at 150", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat up("Up", 2);
		std::cout << "Before increment: " << up;
		up.incrementGrade();
		printTestResult("incrementGrade normal (2 -> 1)", true);
		std::cout << "After increment: " << up;
	}
	catch (const std::exception &e)
	{
		printTestResult("incrementGrade normal (2 -> 1)", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat down("Down", 149);
		std::cout << "Before decrement: " << down;
		down.decrementGrade();
		printTestResult("decrementGrade normal (149 -> 150)", true);
		std::cout << "After decrement: " << down;
	}
	catch (const std::exception &e)
	{
		printTestResult("decrementGrade normal (149 -> 150)", false);
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
