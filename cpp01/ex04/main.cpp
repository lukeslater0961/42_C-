#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (error_mngment(ARG_ERROR));
	else
	{
		if (parseArgs(argv))
			return (1);
		if (CheckAndOpen(argv))
			return (1);
	}
}
