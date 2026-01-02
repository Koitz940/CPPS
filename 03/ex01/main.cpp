/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:24:16 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/27 18:29:16 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap Paco;
	ScavTrap Jack("Jack");
	
	Paco.setName("Paco");
	std::cout << "\n---------- ClapTrap Jack ----------" << std::endl;
	std::cout << "Hitpoints: " << Jack.getHitPoints() << " ";
	std::cout << "Energy: " << Jack.getEnergyPoints() << " ";
	std::cout << "Attack Damage: " << Jack.getAttackDmg() << " ";
	std::cout << " Status: Active" << std::endl;

	std::cout << "\nStart attacking...\n" << std::endl;

	Jack.attack("Sharks");
	Jack.attack("Pirates");
	Jack.takeDamage(3);
	Jack.takeDamage(4);
	Jack.beRepaired(10);
	Jack.takeDamage(20);
	Jack.takeDamage(2);
	Jack.beRepaired(3);
	Jack.takeDamage(2);
	Jack.attack("Dragon");
	Jack.attack("Spirits");
	Jack.attack("Lions");
	Jack.attack("Kings");
	Jack.guardGate();
	Paco.attack("matrix of pass between basis");

	std::cout << "\nFights are over..." << std::endl;
}