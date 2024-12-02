#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(145, 135), _target("NULL"){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(145, 135), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.GetGrade() > this->GetGradeToExec())
	{
		throw(TooLowException());	
	}
	else
	{
		std::cout << "                     .o00o"<< std::endl;
		std::cout << "                   o0NI000oo"<< std::endl;
		std::cout << "                  000000NI0000o" << std::endl;
		std::cout << "                 000000000NI0000" << std::endl;
		std::cout << "              oooooo  00000000  o88o" << std::endl;
		std::cout << "           ooOOOOOOOoo  ```''  888888" << std::endl;
		std::cout << "         OOOOONIOOOOO'.qQQQQq. `8888'" << std::endl;
		std::cout << "        NIOOOOOONIO'.QNIQNIQQQQ/.88'" << std::endl;
		std::cout << "        OOOONIOOOO'.NIQQNIQQQQ/ /q" << std::endl;
		std::cout << "         ONIOONIOO QQQQQQQNIQ/ /QQ" << std::endl;
		std::cout << "           OOOOOOOOO `NIQQNI/ /QQ'" << std::endl;
		std::cout << "             OO:F_P:O `QQQ/  /Q'" << std::endl;
		std::cout << "                \\. \ |  // |" << std::endl;
		std::cout << "                d\ \\\|_////" << std::endl;
		std::cout << "                qP| \\ _' `|Ob" << std::endl;
		std::cout << "                   \  / \  \Op" << std::endl;
		std::cout << "                   |  | O| |" << std::endl;
		std::cout << "           _       /\. \_/ /\"" << std::endl;
		std::cout << "           `---__/|_\\   //|" << std::endl;
		std::cout << "                  `-'  `-'`-'-'" << std::endl;

	}
}
