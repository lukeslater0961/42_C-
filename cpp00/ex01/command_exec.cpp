/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:02:15 by lslater           #+#    #+#             */
/*   Updated: 2024/10/14 15:29:18 by lslater          ###   ########.fr       */
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

void    Contacts::print_spaces(std::string text) const
{            
    for (long unsigned int i = 0; text.length() <= 10 &&  i < (10 - text.length()); i++) 
		std::cout <<" ";
	std::cout << "|";
}  

std::string	index_to_str(int index)
{
	std::stringstream ss;
	ss << index;
    	return ss.str();
}

void Contacts::get_info() const
{
	std::cout << "|     Index|First name|Last name | Nickname |  Number  | Secret   |" <<std::endl;
	std::cout<< "|";
	std::cout << _index + 1;
	print_spaces(index_to_str(_index));
	if (first_name.length() > 10)
		std::cout << first_name.substr(0, 9);
	else
	{
		std::cout << first_name;
		print_spaces(first_name);
	}
	if (last_name.length() > 10)
		std::cout << last_name.substr(0, 9);
	else
	{
		std::cout << last_name;
		print_spaces(last_name);
	}
	if (nickname.length() > 10)
		std::cout << nickname.substr(0, 9);
	else
	{
		std::cout << nickname;
		print_spaces(nickname);
	}
	if (number.length() > 10)
	{
		std::cout<< "number";
		print_spaces("number");
	}
	else
	{
		std::cout << number;
		print_spaces(number);
	}
	std::cout << "shhhh     ";
	std::cout<<"|" <<std::endl;
}

void Contacts::get_nolim_info() const
{
	std::cout << "|     Index|First name|Last name | Nickname |  Number  | Secret   |" <<std::endl;
	std::cout << "|";
	std::cout << _index + 1;
	print_spaces(index_to_str(_index));
	std::cout << first_name;
	print_spaces(first_name);
	std::cout << last_name;
	print_spaces(nickname);
	std::cout << nickname;
	print_spaces(nickname);
	std::cout << number;
	print_spaces(number);
	std::cout << darkest_secret <<std::endl;
}

void PhoneBook::displayContacts() const
{
	std::string     idx;

	if (contactCount <= 0)
	{
		std::cout << "No saved contacts found" << std::endl;
		return ;
	}
	for (int i = 0; i <= (contactCount - 1); i++)
		contacts[i].get_info();
	std::cout << "what contact do you want to look at ?"<< std::endl;
	std::getline(std::cin, idx);
    if (std::cin.eof())
        return ;
    while(idx.empty())
    {
		std::cout << "what contact do you want to look at ?"<< std::endl;
        std::getline(std::cin, idx);
	}
	int index;
    std::stringstream ss(idx);
    ss >> index;
	index--;
	if (index >= 0 && index <= 7)
		contacts[index].get_nolim_info();
	else
		std::cout << "invalid index"<< std::endl;
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
