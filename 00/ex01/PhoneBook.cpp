/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:41:44 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 15:27:26 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
	i = 0;
	for (int k = 0; k < 8; k++)
	{
		contacts[k] = Contact();
	}
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add(std::string s, std::string ls, std::string ns)
{
	contacts[i % 8] = Contact(s, ls, ns);
	i++;
}

int PhoneBook::contact_amount()
{
	return i >= 8? 8: i;
}

int PhoneBook::first()
{
	return i >= 8? i % 8: 0;
}

void PhoneBook::search()
{
	int amount = (*this).contact_amount();
	int k;
	std::string n;
	std::string ln;
	std::string nn;

	std::cout << right << setw(10) << "Index" << setw(3) << " | " << setw(10) << "Name" << setw(3) << " | " << setw(10) << "Last name" << setw(3) << " | " << setw(10) << "Nickname" << "\n";
	for (int j = 0; j < amount; j++)
	{
		k = (j + (*this).first()) % 8;
		if ((*this).contacts[k].name.length() > 10)
		{
			n = (*this).contacts[k].name.substr(0, 9);
			n += ".";	
		}
		else
			n += (*this).contacts[k].name;
		if ((*this).contacts[k].last.length() > 10)
		{
			ln = (*this).contacts[k].last.substr(0, 9);
			ln += ".";	
		}
		else
			ln += (*this).contacts[k].last;
		if ((*this).contacts[k].nick.length() > 10)
		{
			nn = (*this).contacts[k].nick.substr(0, 9);
			nn += ".";	
		}
		else
			nn += (*this).contacts[k].nick;
		std::cout << right << setw(10) << j << setw(3) << " | " << setw(10) << n << setw(3) << " | " << setw(10) << ln << setw(3) << " | " << setw(10) << nn << "\n";
		n.clear();
		ln.clear();
		nn.clear();
	}
}