#include <iostream>

#ifndef FIXED_H
#define FIXED_H

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);

		Fixed& operator=(const Fixed& other);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
	
	private:

		int					_FPValue;
		static const int	_numBits = 8;
};

#endif
