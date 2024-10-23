#include <iostream>

class	Fixed
{
	public:
		Fixed():_FPValue(0){};
		
		Fixed(const Fixed& other){std::cout << "copy constructor called" << std::endl;} //copy constructor

		Fixed& operator=(const Fixed& other)//copy assignment operator
		{
			std::cout << "copy assignment operator called" <<std::endl;
			if (this == &other)
				return (*this);
			return (*this);
		}

		~Fixed(){};

		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
	
	private:

		int					_FPValue;
		static const int	_numBits = 8;
};
