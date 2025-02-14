/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:44 by lslater           #+#    #+#             */
/*   Updated: 2024/10/21 07:31:20 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <csignal>
#include <limits>

PhoneBook::PhoneBook(): _index(0), contactCount(0){std::cout<<"PhoneBook created"<<std::endl;}
PhoneBook::~PhoneBook(){std::cout<<"PhoneBook destroyed"<<std::endl;}

void	do_phone_book(PhoneBook& phonebook)
{
	std::string	command;

	std::cout<<"enter a command: "<<std::endl;
	std::getline(std::cin, command);
	if (std::cin.eof())
		return ;
	while(command.empty())
	{
		std::cout<<"enter a command: "<<std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return ;
	}
	check_for_commands(command, phonebook);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		std::cout<<"you only need 1 argument"<<std::endl;
	else
	{
		PhoneBook phonebook;
		do_phone_book(phonebook);
	}
}
