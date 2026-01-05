/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:43:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 17:00:37 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <exception>
#define SIGN(c) ((c) == '*' || (c) == '/' || (c) == '+' || (c) == '-')

void validate(const std::string& input);
std::stack<int> gen_stack(const std::string& input);
int run(std::stack<int>& stuff);
std::string correct(char* str);

class RPNError: public std::exception {
	const char* msg;
	public:
		const char* what() const throw();
		RPNError(const char* msg);
};