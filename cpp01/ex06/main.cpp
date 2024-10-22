
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout <<"you need 1 argument" << std::endl;
	else
	{
		Harl	harl;
		harl.complain(argv[1]);
	}
}
