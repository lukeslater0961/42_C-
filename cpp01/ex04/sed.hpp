#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

# define ARG_ERROR "You've entered too many or not enough parameters"
# define INVALID_FILE "The filename you entered is invalid"
# define FILE_CANT_OPEN "Can't open given file"
int	error_mngment(std::string errName);
int     parseArgs(char **argv);
int     CheckAndOpen(char **argv);
#endif
