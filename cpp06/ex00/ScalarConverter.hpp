#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdio>
#include <string>
#include <cstdlib>  
#include <cstring>  
#include <iostream> 
#include <errno.h>
#include <iomanip>
#include <climits>

class	ScalarConverter{
	public:

		static void	convert(std::string literal);
		static void	ConvertChar(std::string literal);
		static void	ConvertInt(std::string literal);
		static void	ConvertFloat(std::string literal);
		static void	ConvertDouble(std::string literal);


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

