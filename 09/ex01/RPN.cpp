/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:25:25 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 13:25:25 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPNError::RPNError(const char* msg): msg(msg) {}
const char* RPNError::what() const throw() {return this->msg;}

void validate(const std::string& input) {
	int stack_size = 0;

	if (input.length() == 0)
		throw(RPNError("Error: Empty input"));
	for (std::string::const_iterator it = input.begin();;) {
		if (!isdigit(*it) && !SIGN(*it))
			throw(RPNError("Error: Invalid character"));
		stack_size++;
		if (SIGN(*it)) {
			stack_size -= 2;
			if ((*it == '-' || *it == '+') && it + 1 != input.end() && isdigit(*(it + 1))) {
				stack_size += 2;
				it++;
			}
		}
		if (stack_size <= 0)
			throw(RPNError("Error: Invalid Reversed Polish expression"));
		it++;
		if (it == input.end()) {
			if (stack_size != 1)
				throw(RPNError("Error: Invalid Reversed Polish expression"));
			return ;
		}
		if (*it != ' ')
			throw(RPNError("Error: Invalid character"));
		it++;
		if (it == input.end())
			throw(RPNError("Error: Stop on space"));
	}
}

std::stack<int> gen_stack(const std::string& input) {
	std::stack<int> stk;

	for (std::string::const_iterator it = input.begin();;it++) {
		if (isdigit(*it))
			stk.push(*it - '0');
		else {
			switch (*it) {
				case '+':
					if (it + 1 != input.end() && isdigit(*(it + 1))) {
						stk.push(*(it + 1) - '0');
						it++;
					}
					else
						stk.push(10);
					break;
				case '-':
					if (it + 1 != input.end() && isdigit(*(it + 1))) {
						stk.push(-*(it + 1) + '0');
						it++;
					}
					else
						stk.push(11);
					break;
				case '*':
					stk.push(12);
					break;
				case '/':
					stk.push(13);
					break;
			}
		}
		it++;
		if (it == input.end())
			return stk;
	}
}

int run(std::stack<int>& stuff) {
	int num = stuff.top();
	int first;
	int second;

	stuff.pop();
	if (num < 10)
		return num;
	
	second = run(stuff);
	first = run(stuff);
	switch (num) {
		case 10: return first + second;
		case 11: return first - second;
		case 12: return first * second;
		case 13: return first / second;
	}
	return 98324623;
}