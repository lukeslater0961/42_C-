/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:44 by lslater           #+#    #+#             */
/*   Updated: 2024/07/26 18:21:32 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _index(0){std::cout<<"PhoneBook created"<<std::endl;}
PhoneBook::~PhoneBook(){std::cout<<"PhoneBook destroyed"<<std::endl;}

void	do_phone_book(PhoneBook& phonebook)
{
	std::string	command;

	std::cout<<"enter a command: "<<std::endl;
	std::getline(std::cin, command);
	while(command.empty())
	{
		std::cout<<"enter a command: "<<std::endl;
		std::getline(std::cin, command);
	}
	check_for_commands(command, phonebook);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		std::cout<<"you only need 1 argument u dickhead"<<std::endl;
	else
	{
		PhoneBook phonebook;
		do_phone_book(phonebook);
	}
}
