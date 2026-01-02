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

#include "whatever.hpp"
#include <iostream>

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

int main()
{
	int a[2] = {3, 4};
	int b[2] = {1, 2};
	swap(a, b);
	std::cout << a << " " << b << "\n";
}