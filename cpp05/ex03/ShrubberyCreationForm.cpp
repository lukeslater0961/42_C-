#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 135), _target("NULL"){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 135), _target(target){}

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

void	CopyShrubbery(std::ofstream& outputFile)
{
		outputFile << "                     .o00o" << std::endl;
		outputFile << "                   o0NI000oo" << std::endl;
		outputFile << "                  000000NI0000o" << std::endl;
		outputFile << "                 000000000NI0000" << std::endl;
		outputFile << "              oooooo  00000000  o88o" << std::endl;
		outputFile << "           ooOOOOOOOoo  ```''  888888" << std::endl;
		outputFile << "         OOOOONIOOOOO'.qQQQQq. `8888'" << std::endl;
		outputFile << "        NIOOOOOONIO'.QNIQNIQQQQ/.88'" << std::endl;
		outputFile << "        OOOONIOOOO'.NIQQNIQQQQ/ /q" << std::endl;
		outputFile << "         ONIOONIOO QQQQQQQNIQ/ /QQ" << std::endl;
		outputFile << "           OOOOOOOOO `NIQQNI/ /QQ'" << std::endl;
		outputFile << "             OO:F_P:O `QQQ/  /Q'" << std::endl;
		outputFile << "                \\. \\ |  // |" << std::endl;
		outputFile << "                d\\ \\\\|_////" << std::endl; 
		outputFile << "                qP| \\ _' `|Ob" << std::endl;
		outputFile << "                   \\  / \\  \\Op" << std::endl;
		outputFile << "                   |  | O| |" << std::endl;
		outputFile << "           _       /\\. \\_/ /\"" << std::endl;
		outputFile << "           `---__/|_\\   //|" << std::endl;
		outputFile << "                  `-'  `-'`-'-'" << std::endl;
}
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->GetIsSigned() != 1)
		throw(FormNotSignedException());
	else if (executor.GetGrade() > this->GetGradeToExec())
		throw(TooLowException());	
	else
	{
		std::string filename = this->_target +"_shrubbery";
		std::ofstream outputFile(filename.c_str());
		if (!outputFile)
		{
			std::cout << "can't open file"<< std::endl;
			return ;
		}
		CopyShrubbery(outputFile);
		outputFile.close();
	}
}

