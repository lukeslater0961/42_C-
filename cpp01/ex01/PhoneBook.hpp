
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:45:56 by lslater           #+#    #+#             */
/*   Updated: 2024/07/26 17:04:39 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include "Contacts.hpp"
#include <sstream> 
class PhoneBook
{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(const Contacts& contact);
		void	incrementIndex();
		int		getIndex() const;
		void	displayContacts() const;
		void	get_contacts();

	private:
		Contacts	contacts[8];
		int			_index;
		int			contactCount;
};

void	do_phone_book(PhoneBook& phonebook);
void	check_for_commands(std::string command, PhoneBook& phonebook);
// void	get_and_check_input(PhoneBook& phonebook);

# define CTCT_NAME "whats the first name ? "
# define CTCT_LAST_NAME "whats the last name ? "
# define CTCT_NICKNAME "whats the nickname ? "
# define CTCT_NMBER "whats the number ? "
# define CTCT_D_SECRET "whats the darkest secret ? "

