/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:36:33 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 14:47:54 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
	public:
		Contact(std::string name, std::string fname, std::string nickname);
		Contact();
		~Contact();
		
		std::string name;
		std::string last;
		std::string nick;
};

#endif