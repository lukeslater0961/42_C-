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

		float	operator*(const Fixed& other);
		float	operator/(const Fixed& other);
		float	operator-(const Fixed& other);
		float	operator+(const Fixed& other);

		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		static Fixed&		max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);
		static Fixed&		min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
	private:

		int					_FPValue;
		static const int	_numBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
