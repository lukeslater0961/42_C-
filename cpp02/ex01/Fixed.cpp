#include "Fixed.hpp"

int	Fixed::getRawBits(void) const{return (_FPValue);}

void	Fixed::setRawBits(int const raw){this->_FPValue = raw;}

