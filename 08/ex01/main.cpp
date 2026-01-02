/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:52:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 17:46:52 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main() {
	unsigned int n = 300;
	unsigned int m = 20000;
	Span small(n);
	Span big(m);

	try {
		Span dumb(0);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	for (unsigned int i = 0; i < n; i++) {
		small.addNumber(rand());
	}

	try {
		small.addNumber(rand());
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	
	std::vector<int> vec(m, 1);
	for (unsigned int i = 0; i < m; i++) {
		vec[i] = rand();
	}
	std::cout << small.size() << " " << big.size() << "\n";
	big.addNumber(vec.begin(), vec.end());
	std::cout << small.shortestSpan() << " " << small.longestSpan() << "\n";
	std::cout << big.shortestSpan() << " " << big.longestSpan() << "\n";

	Span dumb1(3);
	
	try {
		dumb1.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	try {
		dumb1.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	dumb1.addNumber(1);

	try {
		dumb1.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		dumb1.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	dumb1.addNumber(3);
	dumb1.addNumber(1);

	try {
		std::cout << dumb1.shortestSpan() << " " << dumb1.longestSpan() << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

}