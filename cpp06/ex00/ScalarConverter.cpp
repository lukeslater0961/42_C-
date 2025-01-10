#include "ScalarConverter.hpp"
#include <cctype>
#include <cstring>


bool	ErrorMngment(std::string errorType)
{
	std::cout << errorType << std::endl;
	return (true);
}

bool	FDErrorCheck(std::string literal)
{
	const char *dotPos = std::strchr(literal.c_str(), '.') + 1;
	char *ptr = NULL;

	if (literal.length() > 0 && literal[literal.length() - 1] == 'f')
		literal[literal.length() - 1] = '\0'; 
	if (literal[0] == '.' || ((literal[0] ==  '+' || literal[0] == '-') && literal[1] == '.'))
		return (ErrorMngment(SYNTAX));
	else if (std::strchr(dotPos, '.') != NULL)
		return (ErrorMngment(DOTS));
    std::strtod(literal.c_str(), &ptr);
	if (*ptr)
		return (ErrorMngment(SYNTAX));
	else if (!(dotPos[0] >= '0' && dotPos[0] <= '9'))
		return (ErrorMngment(SYNTAX));
	return (false);
}

bool	ErrorCheck(std::string literal)
{
	if (literal.length() == 1 && (std::isalpha(literal[0]) || std::isprint(literal[0])))
		return (false);
	else if (literal.length() > 1 && std::isalpha(literal[0]))
		return (ErrorMngment(SYNTAX));
	char *ptr = NULL;
	std::strtol(literal.c_str(), &ptr, 10); 
	if (*ptr)
		return (ErrorMngment(SYNTAX));
	return (false);
}

bool CheckSpecialCases(std::string literal)
{
	if (literal == "inf" || 
			literal == "inff"||
			literal == "nan" ||
			literal == "nanf" ||
			literal == "-inf" || 
			literal == "-inff"||
			literal == "-nan")
		return (true);
	return (false);
}

bool	CheckSpecialFloat(std::string literal)
{
	char *ptr = NULL;
	if (std::strchr(literal.c_str(), '.') != NULL)
		return (ErrorMngment(SYNTAX));
	std::strtof(literal.c_str(), &ptr);
	std::cout << ptr;
	if (CheckSpecialCases(literal))
        return (false);
	else if (*ptr)
		return (ErrorMngment(SYNTAX));
	return (false);
}

bool	CheckForErrors(std::string literal)
{
	size_t startIndex = 0;

	if (literal.empty())
		return (ErrorMngment(EMPTY));
	if (literal[startIndex] == '+' || literal[startIndex] == '-')
		startIndex = 1; 
	if (startIndex < literal.length() && (literal[startIndex] == '+' || literal[startIndex] == '-'))
		return (ErrorMngment(SYNTAX));
	if (startIndex == 1)
		literal.erase(0, 1);
	if (literal.find("inf") != std::string::npos || literal.find("nan") != std::string::npos)
		return (CheckSpecialFloat(literal));
	else if (std::strchr(literal.c_str(), '.') != NULL)
		return(FDErrorCheck(literal));
	else
		return (ErrorCheck(literal));
}

void	DoNan(std::string literal)
{
	double value = std::strtod(literal.c_str(), NULL); 
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal != "-inf" && 
			literal != "-inff" &&
			literal != "-nan")
	{
		std::cout  << "float: " << std::fixed<< std::setprecision(1)<< "+" << static_cast<float>(value) << "f" <<std::endl;
		std::cout  << "double: "<< std::fixed<< std::setprecision(1) << "+" << static_cast<double>(value);
	}
	else
	{
		std::cout  << "float: " << std::fixed<< std::setprecision(1)<< static_cast<float>(value) << "f" <<std::endl;
		std::cout  << "double: "<< std::fixed<< std::setprecision(1) << static_cast<double>(value);
	}

}

void	ScalarConverter::ConvertDouble(std::string literal)
{
	if (literal.length() == 1 && (std::isalpha(literal[0]) || isprint(literal[0])))
		std::cout << "double: " << std::fixed << std::setprecision(1)<< static_cast<double>(literal[0]) <<std::endl;
	else
	{

		double value = std::strtod(literal.c_str(), NULL);
		std::cout << "double: " << std::fixed << std::setprecision(1)<< static_cast<double>(value) <<std::endl;
	}
}

void	ScalarConverter::ConvertFloat(std::string literal)
{
	if (literal.length() == 1 && (std::isalpha(literal[0]) || isprint(literal[0])))
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(literal[0]) << "f" <<std::endl;
	else
	{

		double value = std::strtod(literal.c_str(), NULL);
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(value) << "f" <<std::endl;
	}
}

void	ScalarConverter::ConvertInt(std::string literal)
{
	if (literal.length() == 1 && (std::isalpha(literal[0]) || isprint(literal[0])))
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	else
	{

		double value = std::strtod(literal.c_str(), NULL);
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void	ScalarConverter::ConvertChar(std::string literal)
{
	if (literal.length() == 1 && (std::isalpha(literal[0]) || isprint(literal[0])))
		std::cout << "char:" << static_cast<char>(literal[0]) << std::endl;
	else
	{
		double value = std::strtod(literal.c_str(), NULL);
		if (!isprint(static_cast<char>(value)))
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(value) << std::endl;
	}
}


void	TypeConvert(std::string literal)
{
	if (CheckSpecialCases(literal))
		DoNan(literal);
	else
	{
		double value = std::strtod(literal.c_str(), NULL); 
		if (literal.length() > 10 && (value >= 2147483647 || value <= -2147483648))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: "<< std::fixed<< std::setprecision(1) << static_cast<double>(value);
		}
		else
		{
			ScalarConverter::ConvertChar(literal);
			ScalarConverter::ConvertInt(literal);
			ScalarConverter::ConvertFloat(literal);
			ScalarConverter::ConvertDouble(literal);
		}
	}
}

void	ScalarConverter::convert(std::string literal)
{
	if (CheckForErrors(literal))
		return ;
	else
		TypeConvert(literal);
}
