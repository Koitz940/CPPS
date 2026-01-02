/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:13:59 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:42:40 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	int N = 10;
	Zombie* horde = zombieHorde(N, "Antonio");
	std::cout << "Somos la humilde familia de Antonio, respétenos y halábenos\n";
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}