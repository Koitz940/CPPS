/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:21:53 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:21:53 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "./WrongAnimal default\n";
	this->type = "";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Takeback (WrongAnimal): KeyboardInterrupt\n";
}

WrongAnimal::WrongAnimal(std::string type)
{

	std::cout << "./WrongAnimal parametrised\n";
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{

	std::cout << "./WrongAnimal copy\n";
	this->type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "./WrongAnimal copy assign\n";
	this->type = other.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Error 404, sound not found\n";
}