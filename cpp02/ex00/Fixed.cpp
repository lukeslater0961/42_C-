#include "Fixed.hpp"

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;};

Fixed::Fixed():_FPValue(0){std::cout << "default constructor called" << std::endl;};

int	Fixed::getRawBits(void) const{return (_FPValue);}

void	Fixed::setRawBits(int const raw){this->_FPValue = raw;}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" <<std::endl;
	if (this == &other)
		return (*this);
	this->_FPValue = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}
