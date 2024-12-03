#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	try{
		Bureaucrat john("ford", 1);
		AForm*	form = new RobotomyRequestForm("barnabebew");
		AForm*	form2 = new PresidentialPardonForm("luke");
		AForm*	form3 = new ShrubberyCreationForm("KNIGHTS OF NI");
		Intern	someRandomIntern;	
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "NI");
		
		if (rrf)
		{
			std::cout << *rrf;
			john.signForm(*rrf);
			john.executeForm(*rrf);
		}
		std::cout << *form3;
		john.executeForm(*form2);
		john.signForm(*form3);
		john.executeForm(*form3);
		john.signForm(*form);
		john.executeForm(*form);

		std::cout << *form3;
		std::cout << john << std::endl;

		delete(rrf);
		delete(form);
		delete(form2);
		delete(form3);
	}
	catch(Bureaucrat::TooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::TooHighException& e){
		std::cout << e.what() << std::endl;
	}
}
