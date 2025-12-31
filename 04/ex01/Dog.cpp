/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:19:20 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:19:20 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "./Dog default\n";
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Takeback (Dog): KeyboardInterrupt\n";
}

Dog::Dog(const Dog& other): Animal("Dog")
{
	*this = other;
	std::cout << "./Dog copy\n";
}

void Dog::makeSound(void) const
{
	std::cout << "woof\n";
}

Brain* Dog::getBrain() const
{
	return this->brain;
}

Animal& Dog::operator=(const Animal& other)
{
	if (this == &other)
		return *this;
	
	this->type = "Dog";
	*this->brain = *other.getBrain();
	return *this;
}