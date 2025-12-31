/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:31:30 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 21:31:30 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "./AAnimal default\n";
	this->type = "";
}

AAnimal::~AAnimal()
{
	std::cout << "Takeback (AAnimal): KeyboardInterrupt\n";
}

AAnimal::AAnimal(std::string type)
{

	std::cout << "./AAnimal parametrised\n";
	this->type = type;
}

AAnimal::AAnimal(const AAnimal& other)
{

	std::cout << "./AAnimal copy\n";
	this->type = other.getType();
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "./AAnimal copy assign\n";
	this->type = other.getType();
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->type);
}

void AAnimal::setType(std::string type)
{
	this->type = type;
}