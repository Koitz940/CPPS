/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:13:13 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 19:58:03 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}