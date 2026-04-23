#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int sign_grade, int exec_grade)
	: m_name(name), m_signed(false), m_sign_grade(sign_grade), m_exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException("Grade too high");
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException("Grade too low");
}

AForm::AForm(const AForm &other)
	: m_name(other.getName()), m_signed(other.isSigned()),
		m_sign_grade(other.getSignGrade()), m_exec_grade(other.getExecGrade())
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		m_signed = other.m_signed;
	return *this;
}

AForm::~AForm(void)
{
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > m_sign_grade)
		throw GradeTooLowException("Grade too low to sign");
	m_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!m_signed)
		throw FormNotSignedException("Form is not signed");
	if (executor.getGrade() > m_exec_grade)
		throw GradeTooLowException("Grade too low to execute");
	executeAction();
}

std::string AForm::getName() const
{
	return this->m_name;
}

bool AForm::isSigned() const
{
	return this->m_signed;
}

int AForm::getSignGrade() const
{
	return this->m_sign_grade;
}

int AForm::getExecGrade() const
{
	return this->m_exec_grade;
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "AForm " << other.getName()
		<< ", signed: " << (other.isSigned() ? "yes" : "no")
		<< ", sign grade: " << other.getSignGrade()
		<< ", execute grade: " << other.getExecGrade();
	return (os);
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message)
	: m_message(message)
{
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return m_message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message)
	: m_message(message)
{
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return m_message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& message)
	: m_message(message)
{
}

AForm::FormNotSignedException::~FormNotSignedException(void) throw()
{
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return m_message.c_str();
}
