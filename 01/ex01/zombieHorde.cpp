/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:25:58 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:36:45 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
		std::cout << "an empty or negative size horde makes no sense\n";

	Zombie* horde = new Zombie[N];

	if (!horde)
	{
		std::cout << "failed horde creation\n";
		return NULL;
	}
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return horde;
}