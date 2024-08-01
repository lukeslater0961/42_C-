/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:02:15 by lslater           #+#    #+#             */
/*   Updated: 2024/07/31 00:29:32 by bananabread      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contacts::Contacts(){}
Contacts::~Contacts(){}

void	add_contact(PhoneBook& phonebook)
{
	Contacts newContact;
	
	phonebook.addContact(newContact);
	phonebook.getIndex();

	do_phone_book(phonebook);
}

void Contacts::get_info() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void PhoneBook::displayContacts() const
{
    for (int i = 0; i <= (contactCount - 1); i++)
        contacts[i].get_info();
}

void	check_for_commands(std::string command, PhoneBook& phonebook)
{
	if (command == "ADD")
		add_contact(phonebook);
	else if (command == "SEARCH")
	{
		phonebook.displayContacts();
		do_phone_book(phonebook);
	}
	else if (command == "EXIT")
		return ;
	else
	{
		std::cout<<"invalid command: please try again"<<std::endl;
		do_phone_book(phonebook);
	}
}
