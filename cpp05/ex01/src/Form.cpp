#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : m_name("Default"), m_signed(false), m_sign_grade(150), m_exec_grade(150)
{
}

Form::Form(std::string name, int sign_grade, int exec_grade)
	: m_name(name), m_signed(false), m_sign_grade(sign_grade), m_exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1) throw GradeTooHighException("Grade too high");
	if (sign_grade > 150 || exec_grade > 150) throw GradeTooLowException("Grade too low");
}

Form::Form(const Form &other) : m_name(other.getName()), m_signed(other.isSigned()), m_sign_grade(other.getSignGrade()), m_exec_grade(other.getExecGrade())
{

}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		m_signed = other.m_signed;
	return *this;
}

Form::~Form(void)
{
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > m_sign_grade)
		throw GradeTooLowException("Grade too low");
	m_signed = true;
}

std::string Form::getName() const
{
	return this->m_name;
}

bool Form::isSigned() const
{
	return this->m_signed;
}

int Form::getSignGrade() const
{
	return this->m_sign_grade;
}

int Form::getExecGrade() const
{
	return this->m_exec_grade;
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "Form " << other.getName()
		<< ", signed: " << (other.isSigned() ? "yes" : "no")
		<< ", sign grade: " << other.getSignGrade()
		<< ", execute grade: " << other.getExecGrade();
	return (os);
}

Form::GradeTooHighException::GradeTooHighException(const std::string& message)
	: m_message(message)
{
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return m_message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message)
	: m_message(message)
{
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return m_message.c_str();
}
