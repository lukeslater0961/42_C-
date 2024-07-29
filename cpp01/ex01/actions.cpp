/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:42:08 by lslater           #+#    #+#             */
/*   Updated: 2024/07/29 13:48:02 by bananabread      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::getIndex() const {
    return _index;
}

void PhoneBook::incrementIndex() {
    _index++;
}

void PhoneBook::addContact(const Contacts& contact) {
    contacts[_index] = contact;
    contacts[_index].setIndex(_index);
    contacts[_index].setfirst_name();
	contacts[_index].set_last();
	contacts[_index].set_nick();
	contacts[_index].set_number();
	contacts[_index].set_secret();
    _index++;
}

void Contacts::set_last()
{
    std::string lst_name;

	std::cout<<CTCT_LAST_NAME<<std::endl;
	getline(std::cin, lst_name);
	while (lst_name.empty())
		getline(std::cin, lst_name);
    last_name = lst_name;
}

void Contacts::set_secret()
{
    std::string scrt;

	std::cout<<CTCT_D_SECRET<<std::endl;
	getline(std::cin, scrt);
	while (scrt.empty())
		getline(std::cin, scrt);
    darkest_secret = scrt;
}

void Contacts::set_number()
{
    std::string nmber;

	std::cout<<CTCT_NMBER<<std::endl;
	getline(std::cin, nmber);
	while (nmber.empty())
		getline(std::cin, nmber);
    number = nmber;
}

void Contacts::set_nick()
{
    std::string nick;

	std::cout<<CTCT_NICKNAME<<std::endl;
	getline(std::cin, nick);
	while (nick.empty())
		getline(std::cin, nick);
    nickname = nick;
}

void Contacts::setfirst_name()
{
    std::string frst_name;

	std::cout<<CTCT_NAME<<std::endl;
	getline(std::cin, frst_name);
	while (frst_name.empty())
		getline(std::cin, frst_name);
    first_name = frst_name;
}


void Contacts::setIndex(int idx)
{
    _index = idx;
}
                         