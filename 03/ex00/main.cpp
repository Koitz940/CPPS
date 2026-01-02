/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:24:16 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/27 18:22:31 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap Paco;
	ClapTrap Jack("Jack");
	ClapTrap Jhon;
	
	Paco.setName("Paco");
	Jack.setAttackDmg(2);
	Jhon = Paco;

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
	Paco.attack("matrix of pass between basis");
	Jhon.attack("me");

	std::cout << "\nFights are over..." << std::endl;
}