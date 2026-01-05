/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:05:49 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 17:30:06 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
	std::stack<int> stuff;
	std::string expression;

	if (ac != 2) {
		std::cerr << "Wrong amount of arguments\n";
		return 1;
	}

	try {
		expression = correct(av[1]);
		validate(expression);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
	stuff = gen_stack(expression);
	std::cout << run(stuff) << "\n";
}
