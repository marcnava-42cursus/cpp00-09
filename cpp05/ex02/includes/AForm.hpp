#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string m_name;
		bool m_signed;
		const int m_sign_grade;
		const int m_exec_grade;

	protected:
		virtual void executeAction(void) const = 0;

	public:
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		std::string getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string m_message;

			public:
				GradeTooHighException(const std::string& message);
				virtual ~GradeTooHighException(void) throw();
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string m_message;

			public:
				GradeTooLowException(const std::string& message);
				virtual ~GradeTooLowException(void) throw();
				virtual const char* what(void) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			private:
				std::string m_message;

			public:
				FormNotSignedException(const std::string& message);
				virtual ~FormNotSignedException(void) throw();
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
