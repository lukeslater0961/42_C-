#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form{

	public:
		Form(int gradeToExec, int gradeToSign);
		Form(std::string name, int gradeToExec, int gradeToSign);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

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

	private:
		std::string const	_name;
		bool				_isSigned;
		int			const	_gradeToExec;
		int			const	_gradeToSign;
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
