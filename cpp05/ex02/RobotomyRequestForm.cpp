#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(72, 45), _target("NULL"){}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(72, 45), _target(target){}

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

}
