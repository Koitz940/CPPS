/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:44:17 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:44:17 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain start defualt\n";
	this->size = 0;
}

Brain::~Brain()
{
	std::cout << "Stopped thinking\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain start copy\n";
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain start copy\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	this->size = other.size;
	return (*this);
}

void Brain::addIdea(std::string idea)
{
	if (size == 100)
		return ;
	this->ideas[size++] = idea;
}

const std::string& Brain::getIdea(unsigned int i) const
{
	return this->ideas[i];
}
