/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:44:37 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 16:48:48 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

Intern::Intern(const Intern& other)
{
	(void) other;
	std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	std::cout << "Intern copy assign constructor called\n";
	return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string options[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm* (Intern::*funcs[3])(const std::string& target) const = {&Intern::createPres, &Intern::createRobot, &Intern::createSrhub};

	for (int i = 0; i < 3; i++)
	{
		if (options[i] == name)
		{
			std::cout << "Intern creates " << name << "\n";
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Form could not be created; Invalid Form name\n";
	throw(FormDoesNotExist());
}

AForm* Intern::createRobot(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createSrhub(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createPres(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

const char* Intern::FormDoesNotExist::what() const throw()
{
	return "Existing Forms: PresidentialPardonForm, ShrubberyCreationForm, RobotomyRequestForm";
}
