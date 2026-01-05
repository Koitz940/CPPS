/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:31:05 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/03 15:55:57 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#define DINF ((double)1e308 + (double)1e308 + (double)1e308)
#define FINF ((float)2e38 + (float)2e38 + (float)2e38)
#define MAX 2147483647
#define MIN (-2147483647 - 1)

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& rSym);
	public:
		static void convert(const std::string &expression);
		~ScalarConverter();

	class Overflow: public std::exception
	{
		const char* msg;
		public:
			const char* what() const throw();
			Overflow(const char* msg);
	};
};