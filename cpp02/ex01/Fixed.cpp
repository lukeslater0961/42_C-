#include "Fixed.hpp"
#include <cmath>
#include <locale>

Fixed::Fixed():_FPValue(0){std::cout << "default constructor called" << std::endl;};
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;};

Fixed::Fixed(const int value):_FPValue(value << _numBits){std::cout << "const int constructor called" << std::endl;};
Fixed::Fixed(const float value):_FPValue(static_cast<int>(roundf(value * (1 << _numBits)))){std::cout << "const float constructor called" << std::endl;};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
	this->_FPValue = other._FPValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" <<std::endl;
	if (this == &other)
		return (*this);
	this->_FPValue = other._FPValue;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

int		Fixed::getRawBits(void) const{return (_FPValue);}

void	Fixed::setRawBits(int const raw){this->_FPValue = raw;}


float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_FPValue) / (1 << _numBits));
}

int		Fixed::toInt(void) const
{
	return (_FPValue >> _numBits);
}
