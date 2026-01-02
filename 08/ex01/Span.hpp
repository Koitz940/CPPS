/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:40:06 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 01:40:06 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ostream>
#include <vector>

class Span {
	int* vec;
	unsigned int N;
	unsigned int len;

	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int n);
		void addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		unsigned int capacity() const;
		unsigned int size() const;

	class NoMoreSpace: public std::exception {
		const char* msg;
		public:
			const char* what() const throw();
			NoMoreSpace(const char* msg);
	};
};

std::ostream& operator<<(std::ostream& out, const Span& arr);
