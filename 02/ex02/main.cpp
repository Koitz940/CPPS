/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:42:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 18:29:19 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c(42.42f);
	
	std::cout << "a   = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a   = " << a << std::endl;
	
	std::cout << "max(a,b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a,b) = " << Fixed::min( a, b ) << std::endl;
	
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a   = " << a << std::endl;
	std::cout << "b   = " << b << std::endl;

	std::cout << "max(a,b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a,b) = " << Fixed::min( a, b ) << std::endl;
	
	std::cout << "c   = " << c << std::endl;
	std::cout << "c * 1.5f = " << c * 1.5f << std::endl;
	
	std::cout << "b / 2.2f = " << b / 2.2f << std::endl;
	a = 7.25f;
	std::cout << "a   = " << a << std::endl;
	std::cout << "a + 5.5f = " << a + 5.5f << std::endl;
	std::cout << "a - 5.5f = " << a - 5.5f << std::endl;
	return (0);
}