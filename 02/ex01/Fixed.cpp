/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:23:24 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 17:36:56 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called\n";
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

Fixed::Fixed(const int num)
{
	std::cout << "Integer constructor called\n";
	this->val = num << this->fract;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->val = roundf(num * (float)(1 << this->fract));
}

Fixed & Fixed::operator=(Fixed const & input)
{
	std::cout << "Copy assignment constructor called\n";
	this->val = input.getRawBits();
	return (*this);
}

int Fixed::toInt() const
{
	return this->getRawBits() >> this->fract;
}

float Fixed::toFloat() const
{
	return (float)(this->getRawBits()) / (float)(1 << this->fract);
}

std::ostream& operator<<(std::ostream& o, Fixed const& input)
{
	o << input.toFloat();
	return o;
}