/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:02:15 by lslater           #+#    #+#             */
/*   Updated: 2024/07/25 17:18:17 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	add_contact()
{
	std::string	name;

	std::cout<<CTCT_NAME<<std::endl;
	getline(std::cin, name);
	while (name.empty())
		getline(std::cin, name);
	std::cout<<name<<std::endl;
}

void	check_for_commands(std::string command)
{
	if (command == "ADD")
		add_contact();
	else if (command == "SEARCH")
		std::cout<<"search"<<std::endl;
	else if (command == "EXIT")
		return ;
	else
	{
		std::cout<<"invalid command: please try again"<<std::endl;
		get_and_check_input();
	}
}
