#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class	Intern
{
	public:

		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		class FormDoesntExist{
			const char* what() const throw();
		};

		AForm*	makeForm(std::string formName, std::string target);
};

#endif
