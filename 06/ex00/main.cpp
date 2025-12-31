/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:59:55 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/31 18:59:55 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main()
{
	float x = 97.;

	std::cout << "Char: "<< static_cast<char>(x) << "\n";
	std::cout << "Int: "<< static_cast<int>(x) << "\n";
	std::cout << "Float: "<< x << "f\n";
	std::cout << "Double: "<< static_cast<double>(x) << "\n";
}