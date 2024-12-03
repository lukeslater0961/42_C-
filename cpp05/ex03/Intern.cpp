#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>
#include <cstring>

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	 *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

Intern::~Intern(){}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	AForm	*makeFormForm = NULL;
	unsigned long		i;

	std::string forms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	for (i = 0; i < sizeof(forms)/sizeof(forms[0]); i++)
	{
		std::cout << forms[i] << formName<< std::endl;
		if (!std::strcmp(forms[i].c_str(), formName.c_str()))
			break ;		
	}
	switch (i)
	{
		case 0:
			makeFormForm = new RobotomyRequestForm(target);
			break;
		case 1:
			makeFormForm = new ShrubberyCreationForm(target);
			break;
		case 2:
			makeFormForm = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Form name doesn't exist" << std::endl;
	}
	return (makeFormForm);
}
