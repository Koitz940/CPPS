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
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
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
	if (f == 1 && dots == 0)
		throw (ScalarConverter::Overflow("Incorrect character found, not a valid number"));
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

static int ft_atoi(const std::string expression) {
	long long n = 0;
	long long sign = 1;
	size_t start = 0;

	switch (expression[start]) {
		case '+':
			start++;
			break;
		case '-':
			sign = -1;
			start++;
			break;
		default:
			break;
	};

	for (size_t i = start; i < expression.length(); i++) {
		n = 10 * n + (expression[i] - '0');
		switch (sign) {
			case 1:
				if (n > INT_MAX) {
					throw(ScalarConverter::Overflow("Given int overflows int max"));
				}
				break;
			case -1:
				if (sign * n < INT_MIN) {
					throw(ScalarConverter::Overflow("Given int underflows int min"));
				}
				break;
		}
	}
	return (int)(sign * n);
}

static float ft_atof(const std::string expression) {
	float x = 0.0;
	float decimal = 0.0;
	long sign = 1;
	size_t start = 0;

	switch (expression[start]) {
		case '+':
			start++;
			break;
		case '-':
			sign = -1;
			start++;
			break;
		default:
			break;
	};

	for (size_t i = start; expression[i] != '.'; i++) {
		x = 10.0 * x + expression[i] - '0';
		if (x == FINF) {
			switch (sign) {
				case 1:
					throw(ScalarConverter::Overflow("Given float overflows float max"));
					break;
				case 2:
					throw(ScalarConverter::Overflow("Given float underflows float min"));
					break;
			}
		}
	}

	for (size_t i = expression.length() - 2; expression[i] != '.'; i--) {
		decimal = decimal / 10.0 + expression[i] - '0';
		if (x + decimal / 10.0 == FINF) {
			switch (sign) {
				case 1:
					throw(ScalarConverter::Overflow("Given float overflows float max"));
					break;
				case 2:
					throw(ScalarConverter::Overflow("Given float underflows float min"));
					break;
			}
		}
	}
	return (float)sign * (x + decimal / 10.0);
}

static double ft_atod(const std::string expression) {
	double x = 0.0;
	double decimal = 0.0;
	long sign = 1;
	size_t start = 0;

	switch (expression[start]) {
		case '+':
			start++;
			break;
		case '-':
			sign = -1;
			start++;
			break;
		default:
			break;
	};

	for (size_t i = start; expression[i] != '.'; i++) {
		start = i;
		x = 10.0 * x + expression[i] - '0';
		if (x == DINF) {
			switch (sign) {
				case 1:
					throw(ScalarConverter::Overflow("Given double overflows double max"));
					break;
				case 2:
					throw(ScalarConverter::Overflow("Given double underflows double min"));
					break;
			}
		}
	}

	for (size_t i = expression.length() - 1; expression[i] != '.'; i--) {
		decimal = decimal / 10.0 + expression[i] - '0';
		if (x + decimal / 10.0 == DINF) {
			switch (sign) {
				case 1:
					throw(ScalarConverter::Overflow("Given double overflows double max"));
					break;
				case 2:
					throw(ScalarConverter::Overflow("Given double underflows double min"));
					break;
			}
		}
	}
	return (double)sign * (x + decimal / 10.0);
}

void ScalarConverter::convert(const std::string &expression)
{
	int floatFlag;
	int n = 0;
	float x = 0.0;
	double y = 0.0;

	if (expression.length() == 0) {
		std::cout << "Cannot transform an empty string\n";
		return;
	}
	if (expression == "-." || expression == "-.f" || expression == ".f") {
		std::cout << "Invalid float, either side must have a 0 at least\n";
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
		return;
	}
	switch (floatFlag) {
	case 0:
		try {
			n = ft_atoi(expression);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
			return;
		}
		print(n);
		break;
	case 1:
		try {
			x = ft_atof(expression);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
			return;
		}
		print(x);
		break;
	case 2:
		try {
			y = ft_atod(expression);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
			return;
		}
		print(y);
		break;
	default:
		break;
	}
}
