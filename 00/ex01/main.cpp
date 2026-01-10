/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:51:33 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/03 18:20:56 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

std::string ask(const std::string& message)
{
	std::string answer = "";

	while (answer.empty())
	{
		std::cout << message;
		if (!getline(std::cin, answer))
			exit(0);
	}
	return (answer);
}

bool isnumber(std::string& msg) {
	if (msg.length() == 0)
		return true;
	for (size_t i = 0; i < msg.length(); i++) {
		if (!isdigit(msg[i]))
			return true;
	}
	return false;
}


std::string asknum(const std::string& message)
{
	std::string answer = "";

	while (answer.length() != 9 || isnumber(answer))
	{
		std::cout << message;
		if (!getline(std::cin, answer))
			exit(0);
	}
	return (answer);
}

void add(PhoneBook &phone)
{
	std::string n;
	std::string ln;
	std::string nn;
	std::string secret;
	std::string number;

	n = ask("What is the contact's name? ");
	ln = ask("What is the contact's last name? ");
	nn = ask("What is the contact's nickname? ");
	number = asknum("What is the contact's number? ");
	secret = ask("What is the contact's secret? ");
	phone.add(n, ln, nn, number, secret);
}

int getind()
{
    std::string input;

    while (true)
    {
        if (!getline(std::cin, input))
			exit(0);
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
	if (am == 0)
	{
		std::cout << "\n" << "There are no contacts to search for\n";
		return;
	}
	
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
	std::cout << "Number: " << contact.number << "\n";
	std::cout << "Darkest Secret: " << contact.secret << "\n";
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