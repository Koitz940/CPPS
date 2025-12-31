/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:37:01 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/31 18:37:01 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rSym){
	return *this;
}

void ScalarConverter::converter(std::string &expression)
{

}

static void fromFloat(const float x)
{

}

static void fromDouble(const double x)
{
	
}

static void fromInt(const int n)
{
	if (n == 127 || (n < 32 && n >= 0))
		std::cout << "Char: Non displayable\n";
	else if (n < 0 || n > 127)
		std::cout << "Char: Impossible\n";
	else
		std::cout << "Char: "<< static_cast<char>(n) << "\n";
	std::cout << "int: "<< n << "\n";
	std::cout << "Float: " << static_cast<float>(n) << "\n";
	std::cout << "Double: " << static_cast<double>(n) << "\n";
}

static void fromChar(const char c)
{
	
}