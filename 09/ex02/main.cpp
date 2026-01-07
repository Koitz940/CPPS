/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:45:42 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/07 17:32:42 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static std::string join(char **arr)
{
    std::string result;
    for (int i = 0; arr[i]; i++) {
        if (i > 0) result += ' ';
        result += arr[i];
    }
    return result;
}

int	main(int ac, char **av) {
	if (ac < 2)
		return std::cerr << "Error: no arguments\n", 1;
	
	std::clock_t start = clock();
	
	std::string expr = join(av + 1);

	try {
		PmergeMe::correct(expr);
		PmergeMe::validate(expr);
		PmergeMe instance(expr, clock() - start);
		instance.run();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
}
