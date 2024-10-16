/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:42:08 by lslater           #+#    #+#             */
/*   Updated: 2024/10/16 09:49:40 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::getIndex() const {
    return _index;
}

void PhoneBook::incrementIndex() {
    _index++;
}

void PhoneBook::addContact(const Contacts& contact)
{
	if (_index == 8)
		_index = 0;
    contacts[_index] = contact;
    contacts[_index].setIndex(_index);
    contacts[_index].setfirst_name();
	contacts[_index].set_last();
	contacts[_index].set_nick();
	contacts[_index].set_number();
	contacts[_index].set_secret();
	if (contactCount < 8)
		contactCount++;
    _index++;
}

void Contacts::set_last()
{
    std::string lst_name;

	std::cout<<CTCT_LAST_NAME<<std::endl;
	getline(std::cin, lst_name);
	if (std::cin.eof())
		return ;
	while (lst_name.empty())
	{
		getline(std::cin, lst_name);
		if (std::cin.eof())
			return ;
	}
    last_name = lst_name;
}

void Contacts::set_secret()
{
    std::string scrt;

	std::cout<<CTCT_D_SECRET<<std::endl;
	getline(std::cin, scrt);
	if (std::cin.eof())
		return ;
	while (scrt.empty())
	{
		getline(std::cin, scrt);
		if (std::cin.eof())
			return ;
	}
    darkest_secret = scrt;
}

void Contacts::set_number()
{
    std::string nmber;

	std::cout<<CTCT_NMBER<<std::endl;
	getline(std::cin, nmber);
	if (std::cin.eof())
		return ;
	while (nmber.empty())
	{
		getline(std::cin, nmber);
		if (std::cin.eof())
			return ;
	}
    number = nmber;
}

void Contacts::set_nick()
{
    std::string nick;

	std::cout<<CTCT_NICKNAME<<std::endl;
	getline(std::cin, nick);
	if (std::cin.eof())
		return ;
	while (nick.empty())
	{	
		getline(std::cin, nick);
		if (std::cin.eof())
			return ;
	}
    nickname = nick;
}

void Contacts::setfirst_name()
{
    std::string frst_name;

	std::cout<<CTCT_NAME<<std::endl;
	getline(std::cin, frst_name);
	if (std::cin.eof())
		return ;
	while (frst_name.empty())
	{
		getline(std::cin, frst_name);
		if (std::cin.eof())
			return ;
	}
    first_name = frst_name;
}


void Contacts::setIndex(int idx)
{
    _index = idx;
}
                         
