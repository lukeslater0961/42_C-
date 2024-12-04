#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdio>
#include <string>
#include <cstdlib>  
#include <cstring>  
#include <iostream> 
#include <errno.h>

class	ScalarConverter{
	public:

		static void	convert(std::string literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

#define EMPTY "Empty argument entered"
#define DOTS "Two or more dots were found"
#define	SYNTAX "Invalid syntax"

#endif

