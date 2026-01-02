/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:31:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 17:06:34 by gcassi-d         ###   ########.fr       */
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

template<typename T>
void x2(T& x) {
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

	float* b = new float[len];
	for (size_t i = 0; i < len; i++) {
		b[i] = (float)i + 1.5;
	}
	iter(b, len, x2);
	for (size_t i = 0; i < len; i++) {
		std::cout << b[i] << "\n";
	}
	delete[] b;
}