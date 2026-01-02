/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:51:33 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 15:20:22 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

std::string ask(std::string message)
{
	std::string answer = "";

	while (answer.length() == 0)
	{
		std::cout << message;
		getline(std::cin, answer);
	}
	return (answer);
}

void add(PhoneBook &phone)
{
	std::string n;
	std::string ln;
	std::string nn;

	n = ask("What is the user's name? ");
	ln = ask("What is the user's last name? ");
	nn = ask("What is the user's nickname? ");
	phone.add(n, ln, nn);
}

int getind()
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);
		if (input.length() != 1)
			return -1;
		return input[0] - '0';
	}
}


void search(PhoneBook &phone)
{
	int ind;
	int am;
	Contact contact;

	am = phone.contact_amount();
	phone.search();
	
	std::cout << "\n" << "Enter index of desired user: ";
	ind = getind();
	while (ind < 0 || ind >= am)
	{
		std::cout << "\n" << "That's not a valid index, try again: ";
		ind = getind();
	}
	contact = phone.contacts[(ind + phone.first()) % 8];
	std::cout << "Name: " << contact.name << "\n";
	std::cout << "Last name: " << contact.last << "\n";
	std::cout << "Nickname: " << contact.nick << "\n";
}

int main()
{
	std::string command;
	PhoneBook phone = PhoneBook();
	
	while (1)
	{
		command = ask("What do you want to do?\n[ADD] Add a new contact\n[SEARCH] Display all contacts\n[EXIT] Exit\n");
		if (command.compare("ADD") == 0)
			add(phone);
		else if (command.compare("SEARCH") == 0)
			search(phone);
		else if (command.compare("EXIT") == 0)
			return (0);
		std::cout << "\n";
	}
}