/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:42:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 19:51:01 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point a;
	Point b(13.3f, 10.1f);
	Point c(0, 10);
	Point p(2, 5);
	Point q(-1, -1);

	std::cout << "point a = " << a << "\n";
	std::cout << "point b = " << b << "\n";
	std::cout << "point c = " << c << "\n";
	std::cout << "point p = " << p << "\n";
	std::cout << "point q = " << q << "\n";
	if (bsp(a, b, c, p))
		std::cout << "p is inside the triangle\n";
	else
		std::cout << "p is not inside the triangle\n";
	
	if (bsp(a, b, c, a))
		std::cout << "a is inside the triangle\n";
	else
		std::cout << "a is not inside the triangle\n";
	
	if (bsp(a, b, c, q))
		std::cout << "q is inside the triangle\n";
	else
		std::cout << "q is not inside the triangle\n";
	
	if (bsp(a, a, a, a))
		std::cout << "a is inside the triangle\n";
	else
		std::cout << "a is not inside the triangle\n";
	
	if (bsp(a, b, a, b))
		std::cout << "b is inside the triangle\n";
	else
		std::cout << "b is not inside the triangle\n";
	return (0);
}