/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:32:36 by lslater           #+#    #+#             */
/*   Updated: 2024/07/26 17:40:59 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Contacts{

	public:
		Contacts();
		~Contacts();

	private:
		int		index;
		char	*first_name;
		char	*last_name;
		char	*nickname;
		char	*darkest_secret;
};
