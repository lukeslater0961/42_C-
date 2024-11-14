#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (error_mngment(ARG_ERROR));
	else
	{
		if (parseArgs(argv))
			return (1);
		std::ifstream inFile(argv[1], std::ios::in);
		if (CheckAndOpen(inFile))
			return (1);
		if (inFile)
			do_sed(inFile, argv[1], argv[2], argv[3]);
		inFile.close();
	}
}
