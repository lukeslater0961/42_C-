#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (error_mngment(ARG_ERROR));
	else
	{
		if (parseArgs(argv))
			return (1);
		std::ifstream* inFile = CheckAndOpen(argv);
		if (inFile)
			do_sed(inFile, argv[1], argv[2], argv[3]);
		delete(inFile);
	}
}
