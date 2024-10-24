#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		
		Fixed(const Fixed& other);

		Fixed& operator=(const Fixed& other);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int					_FPValue;
		static const int	_numBits = 8;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
