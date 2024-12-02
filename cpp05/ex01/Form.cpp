#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(int gradeToSign, int gradeToExec): _name("NULL") ,_gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(TooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw(TooLowException());
	else
		this->_isSigned = false;
}

Form::Form(std::string name , int gradeToSign, int gradeToExec): _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(TooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw(TooLowException());
	else
		this->_isSigned = false;
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << other.GetName() << ", Form has grade to exec :" << other.GetGradeToExec() << ", grade to sign : " << other.GetGradeToSign() << ", is signed : " << other.GetIsSigned() << std::endl;
	return (os);
}

Form::~Form(){}

bool Form::GetIsSigned() const{return(this->_isSigned);}

std::string Form::GetName() const{return(this->_name);}

int Form::GetGradeToExec() const{return(this->_gradeToExec);}

int Form::GetGradeToSign() const{return(this->_gradeToSign);}

void		Form::BeSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.GetGrade() > this->_gradeToSign)
		throw(TooLowException());
	else
		this->_isSigned = true;
}


const char* Form::TooLowException::what() const throw() {
    return "Grade is too low";
}

const char* Form::TooHighException::what() const throw() {
    return "Grade is too high";
}
