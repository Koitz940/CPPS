/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:02:37 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:21:35 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie() 
{
	std::cout << name << ": Bye... I'll be back for moar brainzzzzzzzzzzzz\n";
}

void Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}