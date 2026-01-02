/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:31:50 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 14:48:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP
# include "Contact.hpp"
using namespace std;

class PhoneBook
{
	int i;
	
	public:
		PhoneBook();
		~PhoneBook();

		Contact contacts[8];

		void add(std::string s, std::string ls, std::string ns);
		void search();
		int contact_amount();
		int first();
};

#endif