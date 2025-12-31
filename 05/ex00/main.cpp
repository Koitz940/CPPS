/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:54:42 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 22:54:42 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat S;
	Bureaucrat Jhon = Bureaucrat("Jhon", 20);
	Bureaucrat test(Jhon);
	Bureaucrat some = Bureaucrat("aba", 140);
	S = some;

	std::cout << Jhon << "\n" << S << "\n" << test << "\n" << some << "\n";

	try
	{
		Bureaucrat willBreak = Bureaucrat("I am Error", 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat willBreakAgain = Bureaucrat("I am Error", 213);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << S << "; adding 1\n";
		S.gradeUp();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << S << "; removing 5\n";
		S.gradeDown(5);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << Jhon << "; adding 1\n";
		Jhon.gradeUp();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << Jhon << "; adding 19\n";
		Jhon.gradeUp(19);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << Jhon << "; adding 20\n";
		Jhon.gradeUp(20);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << Jhon << "; adding 18\n";
		Jhon.gradeUp(18);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << Jhon << "; adding 1\n";
		Jhon.gradeUp();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; removing 1\n";
		some.gradeDown();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; adding 1\n";
		some.gradeUp();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; adding 145\n";
		some.gradeUp(145);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; removing 1\n";
		some.gradeDown();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; removing 15\n";
		some.gradeDown(15);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; removing 9\n";
		some.gradeDown(9);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << some << "; removing 1\n";
		some.gradeDown();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}