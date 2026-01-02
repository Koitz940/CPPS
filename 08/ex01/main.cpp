/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:52:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 02:52:09 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main() {
	Span small(300);
	Span big(20000);

	for (int i = 0; i < 300; i++) {
		small.addNumber(rand());
	}
	std::vector<int> vec(20000, 1);
	for (int i = 0; i < 300; i++) {
		vec[i] = rand();
	}
	big.addNumber(vec.begin(), vec.end());

	std::cout << small.shortestSpan() << " " << small.longestSpan() << "\n";
	std::cout << big.shortestSpan() << " " << big.longestSpan() << "\n";
}