#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed():_FPValue(0){std::cout << "default constructor called" << std::endl;};
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;};

Fixed::Fixed(const int value):_FPValue(value << _numBits){std::cout << "const int constructor called" << std::endl;};
Fixed::Fixed(const float value):_FPValue(static_cast<int>(roundf(value * (1 << _numBits)))){std::cout << "const float constructor called" << std::endl;};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" <<std::endl;
	if (this == &other)
		return (*this);
	this->_FPValue = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

float	Fixed::operator*(const Fixed& other)
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed& other)
{
	return (this->toFloat() / other.toFloat());
}

float	Fixed::operator+(const Fixed& other)
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed& other)
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->_FPValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->_FPValue--;
	return (*this);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1 > num2 ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return ((num1 > num2) ? num1 : num2);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return ((num1 < num2) ? num1 : num2);
}
int		Fixed::toInt(void) const{return (_FPValue >> _numBits);}
int		Fixed::getRawBits(void) const{return (_FPValue);}
void	Fixed::setRawBits(int const raw){this->_FPValue = raw;}
float	Fixed::toFloat(void) const{return (static_cast<float>(_FPValue) / (1 << _numBits));}
