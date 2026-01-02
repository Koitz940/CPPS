/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:29:50 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 13:29:41 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ScavTrap()
{
	std::cout << "FragTrap default constructor called\n";
	this->name = "";
	this->attackDmg = 30;
	this->hitPoints = 100;
	this->energyPoints =100;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap parameter constructor called\n";
	this->name = name;
	this->attackDmg = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assign constructor called\n";
	this->setAttackDmg(other.getAttackDmg());
	this->setName(other.getName());
	this->setEnenrgyPoints(other.getEnergyPoints());
	this->setHitPoints(other.getHitPoints());
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Can I get a high five guys? let's goooo\n";
}