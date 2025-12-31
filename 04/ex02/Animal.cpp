/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:31:30 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 21:31:30 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "./Animal default\n";
	this->type = "";
}

Animal::~Animal()
{
	std::cout << "Takeback (Animal): KeyboardInterrupt\n";
}

Animal::Animal(std::string type)
{

	std::cout << "./Animal parametrised\n";
	this->type = type;
}

Animal::Animal(const Animal& other)
{

	std::cout << "./Animal copy\n";
	this->type = other.getType();
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "./Animal copy assign\n";
	this->type = other.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::setType(std::string type)
{
	this->type = type;
}