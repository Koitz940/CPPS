/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:09:14 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/01 19:09:14 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base* generate(void)
{
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	std::cout << "Type " << c << " created\n";
	switch (c)
	{
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
	}
	return NULL;
}

void identify(Base *p)
{
	bool correct;

	if (!p)
	{
		std::cout << "either Null was given on purpose or a new failed\n";
		return;
	}
	std::cout << "Argument points to ";

	correct = dynamic_cast<A *>(p);
	if (correct)
	{
		std::cout << "A\n";
		return ;
	}
	correct = dynamic_cast<B *>(p);
	if (correct)
	{
		std::cout << "B\n";
		return ;
	}
	correct = dynamic_cast<C *>(p);
	if (correct)
	{
		std::cout << "C\n";
		return ;
	}
	if (!correct)
		std::cout << "something that isn't A, B, or C\n";
}

void identify(Base& p)
{
	std::cout << "Argument is a reference to ";

	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
	}
	catch (const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "something that isn't A, B, or C\n";
			}
		}
	}
}