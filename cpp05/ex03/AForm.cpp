#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(int gradeToSign, int gradeToExec): _name("NULL") ,_gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(TooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw(TooLowException());
	else
		this->_isSigned = false;
}

AForm::AForm(std::string name , int gradeToSign, int gradeToExec): _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(TooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw(TooLowException());
	else
		this->_isSigned = false;
}

AForm::AForm(const AForm& other): _gradeToExec(other.GetGradeToExec()), _gradeToSign(other.GetGradeToSign())
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << other.GetName() << ", Form has grade to exec :" << other.GetGradeToExec() << ", grade to sign : " << other.GetGradeToSign() << ", is signed : " << other.GetIsSigned() << std::endl;
	return (os);
}

AForm::~AForm(){}

bool AForm::GetIsSigned() const{return(this->_isSigned);}

std::string AForm::GetName() const{return(this->_name);}

int AForm::GetGradeToExec() const{return(this->_gradeToExec);}

int AForm::GetGradeToSign() const{return(this->_gradeToSign);}

void		AForm::BeSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.GetGrade() > this->_gradeToSign)
		throw(TooLowException());
	else
		this->_isSigned = true;
}


const char* AForm::TooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::TooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return " is not signed";
}
