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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm s("trees");
	PresidentialPardonForm p("None");
	RobotomyRequestForm r("some");
	Bureaucrat bossman("bossman", 1);
	Bureaucrat useless("useless", 150);
	Bureaucrat average("average", 72);

	try
	{
		bossman.executeForm(p);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		bossman.executeForm(s);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		bossman.executeForm(s);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	bossman.SignForm(p);
	bossman.SignForm(s);
	bossman.SignForm(r);

	try
	{
		useless.executeForm(p);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		average.executeForm(s);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		bossman.executeForm(p);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		bossman.executeForm(r);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}