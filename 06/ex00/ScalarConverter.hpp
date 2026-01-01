/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:31:05 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/31 18:31:05 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

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