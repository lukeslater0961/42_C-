#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

# define ARG_ERROR "You've entered too many or not enough parameters"
# define INVALID_FILE "The filename you entered is invalid"
# define FILE_CANT_OPEN "Can't open given file"
# define EMPTY_ARG "one or several arguments is/are empty"

int				error_mngment(std::string errName);
int				parseArgs(char **argv);
std::ifstream*	CheckAndOpen(char **argv);
void	do_sed(std::ifstream *inFile, std::string filename);
#endif
