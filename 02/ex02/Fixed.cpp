/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:23:24 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/04 01:17:32 by gcassi-d         ###   ########.fr       */
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
	//std::cout << "setRawBits member function called\n";
	this->val = raw;
}

Fixed::Fixed()
{
	//std::cout << "Default constructor callled\n";
	this->val = 0;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor callled\n";
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called\n";
	this->val = other.getRawBits();
}

Fixed::Fixed(const int num)
{
	//std::cout << "Integer constructor called\n";
	this->val = num << this->fract;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called\n";
	this->val = roundf(num * (float)(1 << this->fract));
}

Fixed& Fixed::operator=(Fixed const & input)
{
	//std::cout << "Copy assignment constructor called\n";
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

bool Fixed::operator==(const Fixed& other) const
{
	return this->val == other.val;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->val <= other.val;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->val >= other.val;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->val < other.val;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->val > other.val;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->val != other.val;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::min(Fixed& input1, Fixed& input2)
{
	if (input1 < input2)
		return input1;
	return input2;
}
Fixed const& Fixed::min(Fixed const& input1, Fixed const& input2)
{
	if (input1 < input2)
		return input1;
	return input2;
}

Fixed& Fixed::max(Fixed& input1, Fixed& input2)
{
	if (input1 > input2)
		return input1;
	return input2;
}

Fixed const& Fixed::max(Fixed const& input1, Fixed const& input2)
{
	if (input1 > input2)
		return input1;
	return input2;
}

Fixed& Fixed::operator++()
{
	++(this->val);
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}
Fixed& Fixed::operator--()
{
	--(this->val);
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}