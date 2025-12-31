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
#include "Intern.hpp"

int main()
{
	Bureaucrat bossman("bossman", 1);
	Intern overworked = Intern();

	try
	{
		AForm* f = overworked.makeForm("ShrubberyCreationForm", "tree");
		f->beSigned(bossman);
		bossman.executeForm(*f);
		delete f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		AForm* f = overworked.makeForm("PresidentialPardonForm", "tree");
		f->beSigned(bossman);
		bossman.executeForm(*f);
		delete f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm* f = overworked.makeForm("RobotomyRequestForm", "tree");
		f->beSigned(bossman);
		bossman.executeForm(*f);
		delete f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm* f = overworked.makeForm("Form", "tree");
		f->beSigned(bossman);
		bossman.executeForm(*f);
		delete f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}