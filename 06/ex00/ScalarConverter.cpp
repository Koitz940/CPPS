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
#include <sstream>

ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	(void)other;
	return *this;
}

ScalarConverter::Overflow::Overflow(const char* msg): msg(msg) {}

const char* ScalarConverter::Overflow::what() const throw()
{
	return (this->msg);
}

static void printChar(const char c)
{
	if (c == 127 || c < 32)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: '"<< c << "'\n";
}

static void printInt(const int n)
{
	std::cout << "Int: "<< n << "\n";
}

static void printFloat(const float x)
{
	std::cout << "Float: " << x;
	if (x - static_cast<int>(x) == 0)
		std::cout << ".0";
	std::cout << "f\n";
}

static void printDouble(const double x)
{
	std::cout << "Double: " << x;
	if (x - static_cast<int>(x) == 0)
		std::cout << ".0";
	std::cout << "\n";
}

template <typename T>
static void print(const T x)
{
	printChar(static_cast<char>(x));
	printInt(static_cast<int>(x));
	printFloat(static_cast<float>(x));
	printDouble(static_cast<double>(x));
}

static void specialFloat(const std::string& special)
{
	std::cout << "Char: Impossible\n";
	std::cout << "Int: Impossible\n";
	std::cout << "Float: " << special << "\n";
	std::cout << "Double: " << special.substr(0, special.length() - 1) << "\n";
}

static void specialDouble(const std::string& special)
{
	std::cout << "Char: Impossible\n";
	std::cout << "Int: Impossible\n";
	std::cout << "Float: " << special << "f\n";
	std::cout << "Double: " << special << "\n";
}

static int isANum(const std::string &str)
{
	size_t start = 0;
	int dots = 0;
	int f = 0;

	if (str[0] == '-' || str[0] == '+') {
		start++;
		if (str.length() == 1)
			throw (ScalarConverter::Overflow("Expression is just a sign, there is no number"));
	}
    for (size_t i = start; i < str.length(); i++) {
		if (str[i] == '.')
			dots += 1;
		else if (str[i] == 'f') {
			if (f == 1)
				throw (ScalarConverter::Overflow("multiple fs found, not a valid number"));
			f++;
		}
		else if (!isdigit(str[i]))
			throw (ScalarConverter::Overflow("Incorrect character found, not a valid number"));
	}
	if (dots == 0)
		return 0;
	if (dots > 1)
		throw (ScalarConverter::Overflow("multiple dots found, not a valid number"));
	if (f == 0)
		return 2;
	if (str[str.length() - 1] != 'f')
		throw (ScalarConverter::Overflow("Incorrect character found, not a valid number (f of float not at the end of the string)"));
	return 1;
}

void ScalarConverter::convert(const std::string &expression)
{
	int floatFlag;
	std::istringstream iss(expression);
	int n = 0;
	float x = 0.0;
	double y = 0.0;

	if (expression.length() == 0) {
		std::cout << "Cannot transform an empty string\n";
		return;
	}
	if (expression == "nanf" || expression == "+inff" || expression == "-inff"){
		specialFloat(expression);
		return;
	}
	if (expression == "nan" || expression == "+inf" || expression == "-inf") {
		specialDouble(expression);
		return;
	}
	if (expression.length() == 1 && !isdigit(expression[0])) {
		print(expression[0]);
		return;
	}
	try {
		floatFlag = isANum(expression);
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	switch (floatFlag) {
	case 0:
		iss >> n;
		print(n);
		break;
	case 1:
		iss >> x;
		print(x);
		break;
	case 2:
		iss >> y;
		print(y);
		break;
	default:
		break;
	}
}
