/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:13:16 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:13:16 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "./Cat default\n";
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Takeback (Cat): KeyboardInterrupt\n";
}

Cat::Cat(const Cat& other): Animal("Cat")
{
	*this = other;
	std::cout << "./Cat copy\n";
}

void Cat::makeSound(void) const
{
	std::cout << "meow\n";
}

Brain* Cat::getBrain() const
{
	return this->brain;
}

Animal& Cat::operator=(const Animal& other)
{
	if (this == &other)
		return *this;
	
	this->type = "Cat";
	*this->brain = *other.getBrain();
	return *this;
}