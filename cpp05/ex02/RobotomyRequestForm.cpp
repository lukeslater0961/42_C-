#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("NULL"){}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->GetIsSigned() != 1)
		throw(FormNotSignedException());
	else if (executor.GetGrade() > this->GetGradeToExec())
		throw(TooLowException());	
	else
	{
		std::cout << "*Drilling sounds*" << std::endl;
		srand(time(0));
        int isFailed = rand() % 2;
		if (!isFailed)
			std::cout << this->_target << " has been successfully Robotomyzed ! " << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
}
