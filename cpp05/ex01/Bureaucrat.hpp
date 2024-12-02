#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class	Bureaucrat
{
	public:

		Bureaucrat();
		Bureaucrat(std::string const name, int	grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		void	IncrementGrade(void);
		void	DecrementGrade(void);
		
		std::string GetName(void) const;
		int			GetGrade(void) const;
	
		void	signForm(Form& form);

		class TooHighException
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too high");
				}
		};

		class TooLowException
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too low");
				}
		};

	private:

		std::string const _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
