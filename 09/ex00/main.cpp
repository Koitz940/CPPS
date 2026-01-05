/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:03:07 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 16:55:58 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << "Incorrect amount of inputs";
		return 1;
	}
	try {
		BitcoinExchange b = BitcoinExchange();
		b.run(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
}
