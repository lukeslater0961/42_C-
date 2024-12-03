#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("NULL"){}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->GetIsSigned() != 1)
		throw(FormNotSignedException());
	else if (executor.GetGrade() > this->GetGradeToExec())
		throw(TooLowException());	
	else
		std::cout << this->_target << "has been pardonned by Zaphod Beeblebrox" << std::endl;
}
