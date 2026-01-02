/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 23:05:58 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/01 23:05:58 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ostream>

template<typename T>
class Array {
	T* vec;
	size_t capacity;

	public:
		Array();
		Array(const unsigned int n);
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);

		T& operator[](size_t i);
		const T& operator[](size_t i) const;
		size_t size() const;

	class IndexOutOfBounds: public std::exception {
		const char* msg;
		public:
			const char* what() const throw();
			IndexOutOfBounds(const char* msg);
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr);

struct complex
{
	double re;
	double im;
};

complex from(double re, double im);

std::ostream& operator<<(std::ostream& out, const complex& arr);