#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm{

	public:
		AForm(int gradeToExec, int gradeToSign);
		AForm(std::string name, int gradeToExec, int gradeToSign);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string	GetName(void) const;
		bool		GetIsSigned(void) const;
		int			GetGradeToExec(void) const;
		int			GetGradeToSign(void) const;
	
		void		BeSigned(const Bureaucrat& bureaucrat);

		class TooHighException
		{
			public:
				const char* what() const throw();
		};

		class TooLowException
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException
		{
			public:
				const char* what() const throw();
		};

		virtual void execute(Bureaucrat const & executor) const = 0;

	private:
		std::string const	_name;
		bool				_isSigned;
		int			const	_gradeToExec;
		int			const	_gradeToSign;
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
