/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:44 by lslater           #+#    #+#             */
/*   Updated: 2024/07/25 17:18:55 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	get_and_check_input()
{
	std::string	command;

	std::getline(std::cin, command);
	while(command.empty())
	{
		std::cout<<"enter a command: "<<std::endl;
		std::getline(std::cin, command);
	}
	check_for_commands(command);
}

void	do_phone_book()
{
	std::cout<<"enter a command: "<<std::endl;
	get_and_check_input();
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		std::cout<<"you need 1 argument u dickhead"<<std::endl;
	else
		do_phone_book();
}
