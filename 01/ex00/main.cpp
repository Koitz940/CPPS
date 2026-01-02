/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:13:59 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:17:22 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie* zombie = newZombie("Antonio");
	
	randomChump("What is my purpose? to be deleted by the stack!!");
	zombie->announce();
	delete zombie;
}