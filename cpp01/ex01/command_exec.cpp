/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:02:15 by lslater           #+#    #+#             */
/*   Updated: 2024/07/29 13:31:34 by bananabread      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contacts::Contacts(){}
Contacts::~Contacts(){}

std::string	get_first()
{
	std::string first_name;

	std::cout<<CTCT_NAME<<std::endl;
	getline(std::cin, first_name);
	while (first_name.empty())
		getline(std::cin, first_name);
	return (first_name);
}

void	add_contact(PhoneBook& phonebook)
{
	Contacts newContact;
	
	phonebook.addContact(newContact);
	phonebook.getIndex();

	do_phone_book(phonebook);
}

void	check_for_commands(std::string command, PhoneBook& phonebook)
{
	if (command == "ADD")
		add_contact(phonebook);
	else if (command == "SEARCH")
		std::cout<<"search"<<std::endl;
	else if (command == "EXIT")
		return ;
	else
	{
		std::cout<<"invalid command: please try again"<<std::endl;
		do_phone_book(phonebook);
	}
}
