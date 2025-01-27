#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try{
		Bureaucrat john("doe", 1);
		std::cout << john << std::endl;
		john.DecrementGrade();
		john.IncrementGrade();
		john.IncrementGrade();
	}
	catch(Bureaucrat::TooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::TooHighException& e){
		std::cout << e.what() << std::endl;
	}
}
