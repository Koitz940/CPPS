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

Cat::Cat(): AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout << "./Cat default\n";
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Takeback (Cat): KeyboardInterrupt\n";
}

Cat::Cat(const Cat& other): AAnimal("Cat")
{
	*this = other;
	this->brain = new Brain(*other.brain);
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

AAnimal& Cat::operator=(const AAnimal& other)
{
	if (this == &other)
		return *this;
	
	this->type = "Cat";
	*this->brain = *other.getBrain();
	return *this;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	
	this->type = "Cat";
	if (this->brain)
		delete brain;
	if (!other.brain)
		this->brain = new Brain();
	else
		this->brain = new Brain(*other.getBrain());
	return *this;
}