#include <iostream>

class	Fixed
{
	public:
		Fixed():_FPValue(0){};
		
		Fixed(const Fixed& other)
		{
			std::cout << "copy constructor called" << std::endl;
			this->_FPValue = other._FPValue;
		} //copy constructor

		Fixed& operator=(const Fixed& other)//copy assignment operator
		{
			std::cout << "copy assignment operator called" <<std::endl;
			if (this == &other)
				return (*this);
			this->_FPValue = other._FPValue;
			return (*this);
		}

		~Fixed(){};

		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
	
	private:

		int					_FPValue;
		static const int	_numBits = 8;
};
