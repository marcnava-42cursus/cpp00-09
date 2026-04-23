#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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

	std::cout << std::endl << "==== Form tests ====" << std::endl;

	try
	{
		Form validForm("ValidForm", 42, 21);
		printTestResult("Form constructor valid grades", true);
		std::cout << validForm << std::endl;
	}
	catch (const std::exception &e)
	{
		printTestResult("Form constructor valid grades", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form badHigh("BadHigh", 0, 21);
		(void)badHigh;
		printTestResult("Form constructor too high grade (0)", false);
	}
	catch (const Form::GradeTooHighException &e)
	{
		printTestResult("Form constructor too high grade (0)", true);
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		printTestResult("Form constructor too high grade (0)", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form badLow("BadLow", 42, 151);
		(void)badLow;
		printTestResult("Form constructor too low grade (151)", false);
	}
	catch (const Form::GradeTooLowException &e)
	{
		printTestResult("Form constructor too low grade (151)", true);
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		printTestResult("Form constructor too low grade (151)", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat signer("Signer", 10);
		Form signable("Signable", 50, 20);
		signer.signForm(signable);
		printTestResult("beSigned success", signable.isSigned());
	}
	catch (const std::exception &e)
	{
		printTestResult("beSigned success", false);
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat lowSigner("LowSigner", 100);
		Form protectedForm("ProtectedForm", 50, 20);
		lowSigner.signForm(protectedForm);
		printTestResult("beSigned low grade remains unsigned", !protectedForm.isSigned());
	}
	catch (const std::exception &e)
	{
		printTestResult("beSigned low grade remains unsigned", false);
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
