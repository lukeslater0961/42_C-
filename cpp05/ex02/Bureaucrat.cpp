#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string const name, int	grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw(TooHighException());
	else if (grade > 150)
		throw(TooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& other){
    os << other.GetName() << ", Bureaucrat grade " << other.GetGrade() << ".";
    return os;
}

Bureaucrat::~Bureaucrat(){}

int Bureaucrat::GetGrade(void) const
{
	return this->_grade;
}

std::string Bureaucrat::GetName(void) const
{
	return this->_name;
}

void	Bureaucrat::DecrementGrade(void)
{
	int grade = GetGrade();
	if (++grade > 150)
		throw(TooLowException());
	else
		this->_grade++;
}

void	Bureaucrat::IncrementGrade(void)
{
	int grade = GetGrade();
	if (--grade < 1)
		throw(TooHighException());
	else
		this->_grade--;
}


void	Bureaucrat::signForm(AForm& form)
{
   try {
        form.BeSigned(*this);
        std::cout << this->GetName() << " signed " << form.GetName() << std::endl;
    } 
   catch (const AForm::TooLowException& e) {
        std::cout << this->GetName() << " couldn't sign " << form.GetName() << " because: " << e.what() << std::endl;
    }
}
