/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:46:44 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 20:09:45 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	this->hasWeapon = 0;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	this->hasWeapon = 1;
}

void HumanB::attack()
{
	if (!this->hasWeapon)
		std::cout << this->name << " does not have a weapon to attack with\n";
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}