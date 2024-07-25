/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:56 by lslater           #+#    #+#             */
/*   Updated: 2024/07/25 17:10:21 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>


//#include "Contacts.hpp"
//class PhoneBook
//{
//	private :
//		Contacts contacts[8];
//};


void	do_phone_book();
void	check_for_commands(std::string command);
void	get_and_check_input();

# define CTCT_NAME "whats the first name ? "
# define CTCT_LAST_NAME "whats the last name ? "
# define CTCT_NICKNAME "whats the nickname ? "
# define CTCT_NMBER "whats the number ? "
# define CTCT_D_SECRET "whats the darkest secret ? "

