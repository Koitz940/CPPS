/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:04:20 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 19:53:02 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::~Weapon() {}

const std::string Weapon::getType()
{
	return (const std::string)type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}