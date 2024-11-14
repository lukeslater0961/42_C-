#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

# define ARG_ERROR "You've entered too many or not enough parameters"
# define INVALID_FILE "The filename you entered is invalid"
# define FILE_CANT_OPEN "Can't open given file"
# define EMPTY_ARG "one or several arguments is/are empty"
# define FILE_EMPTY "File is empty"

int				error_mngment(std::string errName);
int				parseArgs(char **argv);
int             CheckAndOpen(std::ifstream &inFile);
void			do_sed(std::ifstream& inFile, std::string filename, std::string tofind, std::string inputstring);

#endif
