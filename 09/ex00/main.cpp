/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:03:07 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/03 22:03:07 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
int main(int ac, char** av)
{
	try {
		BitcoinExchange b = BitcoinExchange();

		if (ac != 2) {
			std::cerr << "Incorrect amount of inputs";
			return 1;
		}

		b.run(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
}
