/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:04:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 13:26:38 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	this->name = "";
	this->attackDmg = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap copy constructor called\n";
	*this = other;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap parameter constructor called\n";
	this->name = name;
	this->attackDmg = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assign constructor called\n";
	this->setAttackDmg(other.getAttackDmg());
	this->setName(other.getName());
	this->setEnenrgyPoints(other.getEnergyPoints());
	this->setHitPoints(other.getHitPoints());
	return (*this);
}

void ScavTrap::attack(const std::string& target) const
{
	std::cout << this->getName() << " took their anger out on " << target << " removing " << this->getAttackDmg() << "HP\n";
}

void ScavTrap::guardGate() const
{
	std::cout << this->getName() << " is now " << "keeping the gates\n";
}