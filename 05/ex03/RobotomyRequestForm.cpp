/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 01:59:18 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 16:40:29 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("sus")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm parameter constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("RobotomyRequestForm", 72, 45), target(other.target)
{
	std::cout << "RobotomyRequestForm parameter constructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkConditions(executor);
	
	std::cout << "* Unbearable drilling noises *\n";
	if (rand() % 2)
		std::cout << this->target << " has been successfully robotomized\n";
	else
		std::cout << "The robotomy has failed\n";
}