#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	else
		ScalarConverter::convert(argv[1]);
}
