/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:02:15 by lslater           #+#    #+#             */
/*   Updated: 2024/07/26 18:21:34 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Contacts::Contacts(){std::cout<<"Contact was created"<<std::endl;} */

std::string	get_first(std::string first_name)
{
	std::cout<<CTCT_NAME<<std::endl;
	getline(std::cin, first_name);
	while (first_name.empty())
		getline(std::cin, first_name);
	return (first_name);
}

std::string	get_last(std::string last_name)
{
	std::cout<<CTCT_LAST_NAME<<std::endl;
	getline(std::cin, last_name);
	while (last_name.empty())
		getline(std::cin, last_name);
	return (last_name);
}

std::string	get_nick(std::string nick_name)
{
	std::cout<<CTCT_NICKNAME<<std::endl;
	getline(std::cin, nick_name);
	while (nick_name.empty())
		getline(std::cin, nick_name);
	return (nick_name);
}

std::string	get_number(std::string number)
{
	std::cout<<CTCT_NMBER<<std::endl;
	getline(std::cin, number);
	while (number.empty())
		getline(std::cin, number);
	return (number);
}

std::string	get_secret(std::string secret)
{
	std::cout<<CTCT_D_SECRET<<std::endl;
	getline(std::cin, secret);
	while (secret.empty())
		getline(std::cin, secret);
	return (secret);
}


void	add_contact(PhoneBook phonebook)
{
	std::string drkst_scrt;
	std::string	frst_nme;
	std::string lst_nme;
	std::string ncknme;
	std::string	nmber;
	
	frst_nme = get_first(frst_nme);
	lst_nme =  get_last(lst_nme);
	ncknme = get_nick(ncknme);
	nmber = get_number(nmber);
	drkst_scrt = get_secret(drkst_scrt);
	phonebook._index++;

	std::cout<<frst_nme<<std::endl;//toberemoved
	std::cout<<lst_nme<<std::endl;//toberemoved
	std::cout<<ncknme<<std::endl;//toberemoved
	std::cout<<nmber<<std::endl;//toberemoved
	std::cout<<drkst_scrt<<std::endl;//toberemoved
	std::cout<<phonebook._index<<std::endl;//toberemoved

	std::cout<<"enter a command: "<<std::endl;
	get_and_check_input(phonebook);
}

void	check_for_commands(std::string command, PhoneBook phonebook)
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
		get_and_check_input(phonebook);
	}
}
