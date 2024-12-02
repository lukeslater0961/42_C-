#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	try{
		Bureaucrat john("ford", 150);
		Form	Johnny("johnson", 150, 150);
		std::cout << john << std::endl;
		std::cout << Johnny << std::endl;
		john.signForm(Johnny);
		std::cout << Johnny << std::endl;
	}
	catch(Bureaucrat::TooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::TooHighException& e){
		std::cout << e.what() << std::endl;
	}
}
