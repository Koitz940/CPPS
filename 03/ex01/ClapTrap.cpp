/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:03:01 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 13:26:42 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called\n";
	this->name = "";
	this->attackDmg = 0;
	this->hitPoints = 10;
	this->energyPoints = 0;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called\n";
	*this = other;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap parametre constructor called\n";
	this->name = name;
	this->attackDmg = 0;
	this->hitPoints = 10;
	this->energyPoints = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assign constructor called\n";
	this->setAttackDmg(other.getAttackDmg());
	this->setName(other.getName());
	this->setEnenrgyPoints(other.getEnergyPoints());
	this->setHitPoints(other.getHitPoints());
	return (*this);
}

void ClapTrap::setName(const std::string& name)
{
	this->name = name;
}

void ClapTrap::setAttackDmg(unsigned int atk)
{
	this->attackDmg = atk;
}

void ClapTrap::setHitPoints(unsigned int hp)
{
	this->hitPoints = hp;
}

void ClapTrap::setEnenrgyPoints(unsigned int energy)
{
	this->energyPoints = energy;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDmg() const
{
	return (this->attackDmg);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	std::cout << this->getName() << " got repaired by " << amount << " points!\n";
}

void ClapTrap::attack(const std::string &target) const
{
	std::cout << this->getName() << " attacked " << target << " dealing " << this->getAttackDmg() << "dmg\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	switch (this->getHitPoints() <= amount)
	{
	case 1:
		this->setHitPoints(0);
		std::cout << this->name << " took " << amount << " dmg and died!\n";
		break;
	case 0:
		this->hitPoints -= amount;
		std::cout << this->name << " took " << amount << " dmg\n";
	}
}