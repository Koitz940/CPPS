/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:23:24 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 17:11:55 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->val);
}

void Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}

Fixed::Fixed()
{
	std::cout << "Default constructor callled\n";
	this->val = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor callled\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->val = other.getRawBits();
}

Fixed & Fixed::operator=(Fixed const & input)
{
	std::cout << "Copy assignment constructor called\n";
	this->val = input.getRawBits();
	return (*this);
}