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
	return (false);
}

bool	ErrorCheck(std::string literal)
{
	if (literal.length() == 1 && std::isalpha(literal[0]))
		return (false);
	else if (literal.length() > 1 && std::isalpha(literal[0]))
		return (ErrorMngment(SYNTAX));
	char *ptr = NULL;
	std::strtol(literal.c_str(), &ptr, 10); 
	if (*ptr)
		return (ErrorMngment(SYNTAX));
	return (false);
}

bool	CheckSpecialFloat(std::string literal)
{
	if (std::strchr(literal.c_str(), '.') != NULL)
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
	if (literal.find("inf") != std::string::npos || literal.find("nan") != std::string::npos)
		return (CheckSpecialFloat(literal));
	else if (std::strchr(literal.c_str(), '.') != NULL)
		return(FDErrorCheck(literal));
	else
		return (ErrorCheck(literal));
}


void	ScalarConverter::convert(std::string literal)
{
	if (CheckForErrors(literal))
		return ;
}
