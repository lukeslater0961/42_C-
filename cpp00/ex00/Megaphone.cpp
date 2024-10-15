/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:02:41 by lslater           #+#    #+#             */
/*   Updated: 2024/10/15 12:36:26 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

void	to_upper(char **argv)
{
	std::string str;
	for (int i = 1; argv[i] != NULL; i++)
		str.append(argv[i]);
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (std::isalnum(*iter))
			*iter = std::toupper(*iter);
	}
	std::cout<<str<<std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
		to_upper(argv);
}

