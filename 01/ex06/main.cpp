/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:42:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 13:56:27 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl = Harl();

	if (ac != 2)
	{
		std::cout << "Incorrect amount of parametres" << "\n";
		return 1;
	}

	if (harl.complain(av[2]))
	{
		std::cout << "Incorrect amount of parametres" << "\n";
		return 1;
	}
}