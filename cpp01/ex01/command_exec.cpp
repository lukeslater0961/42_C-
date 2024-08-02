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

void    Contacts::print_spaces(std::string text) const
{            
        for (long unsigned int i = 0; text.length() <= 10 &&  i < (10 - text.length()); i++) 
                std::cout <<" ";
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
	std::cout << _index;
	print_spaces(index_to_str(_index));
	std::cout<< "|";
	std::cout << first_name;
	print_spaces(first_name);
	std::cout << "|";
	std::cout << last_name;
	print_spaces(last_name);
	std::cout << "|";
	std::cout << nickname;
	print_spaces(nickname);
	std::cout << "|";
	std::cout << number;
	print_spaces(number);
	std::cout << "|";
	std::cout << "shhhh";
	print_spaces("shhhh");
	std::cout << "|" << std::endl;;
}

void PhoneBook::displayContacts() const
{
	std::string     index;
    
	for (int i = 0; i <= (contactCount - 1); i++)
		contacts[i].get_info();
	std::cout << "what contact do you want to look at ?"<< std::endl;
        std::getline(std::cin, index);
        if (std::cin.eof())
                return ;
        while(index.empty())
        {
		std::cout << "what contact do you want to look at ?"<< std::endl;
                std::getline(std::cin, index);
        }
	contacts[index].get_info();


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
