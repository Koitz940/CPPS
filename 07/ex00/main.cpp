/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:31:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 17:02:54 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <ostream>

template<typename T>
T min(T& a, T& b)
{
	return (a < b ? a: b);
}

template<typename T>
T max(T& a, T& b)
{
	return (a > b ? a: b);
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

std::ostream& operator<<(std::ostream& out, const complex& z) {
	out << z.re << " + " << z.im << "i";
	return out;
}

int main()
{
	int a = 2;
	int b = 3;
	std::cout << a << " " << b << "\n";
	swap(a, b);
	std::cout << a << " " << b << "\n";

	int *q = &a;
	int *p = &b;
	std::cout << &a << " " << &b << " " << p << " " << q << "\n";
	swap(p, q);
	std::cout << &a << " " << &b << " " << p << " " << q << "\n";

	complex z;
	complex s;
	z.re = 0.0;
	z.im = 1.0;
	s.re = -1.0;
	s.im = 2.0;
	std::cout << z << "  " << s << "\n";
	swap(z, s);
	std::cout << z << "  " << s << "\n";

	std::cout << min(a, b) << " " << max(a, b) << "\n";
}