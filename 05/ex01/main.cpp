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
	Form f1 = Form("yes", 20, 140);
	Form f2 = Form("no", 10, 140);
	Form f3 = f1;
	Form f4(f2);;

	std::cout << f1 << "\n" << f2 << "\n" << f3 << "\n" << f4 << "\n";


	try
	{
		Form willBreak = Form("I am Error", 0, 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form willBreak = Form("I am Error", 0, 10);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form willBreak = Form("I am Error", 0, 151);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form willBreak = Form("I am Error", 10, 151);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form willBreak = Form("I am Error", 151, 151);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Jhon.signForm(f2);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Jhon.signForm(f1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Jhon.signForm(f1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}