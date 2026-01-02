/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:31:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/01 20:31:41 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void iter(T *adress, int lenght, void (*fct)(T& var)) {
	for (int i = 0; i < lenght; i++) {
		fct(adress[i]);
	}
}

void x2(int& x) {
	x *= 2;
}

int main()
{
	size_t len = 10;
	int* const a = new int[len];
	for (size_t i = 0; i < len; i++) {
		a[i] = (int)i + 1;
	}
	iter(a, len, x2);
	for (size_t i = 0; i < len; i++) {
		std::cout << a[i] << "\n";
	}
	delete[] a;

	int* b = new int[len];
	for (size_t i = 0; i < len; i++) {
		b[i] = (int)i + 1;
	}
	iter(b, len, x2);
	for (size_t i = 0; i < len; i++) {
		std::cout << b[i] << "\n";
	}
	delete[] b;
}