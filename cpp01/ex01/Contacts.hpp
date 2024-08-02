/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:32:36 by lslater           #+#    #+#             */
/*   Updated: 2024/07/31 00:13:12 by bananabread      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Contacts{

	public:
		Contacts();
		~Contacts();
		void setIndex(int idx);
		void 	setfirst_name();
		void	set_last();
		void	set_nick();
		void	set_number();
		void	set_secret();
		void	get_info() const;
		void	print_spaces(std::string text) const;
	private:
		int		_index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;
};
