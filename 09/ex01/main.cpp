/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:05:49 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/04 23:05:49 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
	std::stack<int> stuff;

	if (ac != 2) {
		std::cerr << "Wrong amount of arguments\n";
		return 1;
	}

	try {
		validate(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
	stuff = gen_stack(av[1]);
	std::cout << run(stuff) << "\n";
}