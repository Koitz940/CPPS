/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:56:10 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 17:39:47 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::NoMoreSpace::NoMoreSpace(const char* msg): msg(msg) {}
const char* Span::NoMoreSpace::what() const throw() {
	return (this->msg);
}

Span::Span(): N(1), len(0) {
	this->vec = new int[1];
}

Span::Span(unsigned int n): N(n), len(0) {
	if (n == 0)
		throw(Span::NoMoreSpace("an empty array doesn't make sense"));
	this->vec = new int[n];
}

Span::~Span() {
	delete[] this->vec;
}

Span::Span(const Span& other): N(other.capacity()), len(other.len) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this->vec)
		delete[] this->vec;
	
	this->vec = new int[other.capacity()];
	this->N = other.N;
	for (unsigned int i = 0; i < other.len; i++) {
		this->vec[i] = other.vec[i];
	}
	this->len = other.len;
	return *this;
}

void Span::addNumber(int n) {
	if (this->len == this->N) {
		throw (Span::NoMoreSpace("Out of Space"));
	}
	this->vec[this->len] = n;
	this->len++;
}

void Span::addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd) {
	for (std::vector<int>::const_iterator it = itBegin; it != itEnd; it++) {
		try {
			addNumber(*it);
		} catch (std::exception& e) {
			return ;
		}
	}
}

static long abs(long n) {
	return n < 0 ? -n: n;
}

unsigned int Span::shortestSpan() const {
	if (this->len < 2)
		throw (Span::NoMoreSpace("No span of a list of len 0 or 1"));
	int *copy = new int[this->len];
	if (!copy) {
		std::cout << "allocation failed\n";
		return 0;
	}
	for (unsigned int i = 0; i < len; i++) {
		copy[i] = this->vec[i];
	}
	std::sort(copy, copy + this->len);
	unsigned int min = (unsigned int)abs(((long)copy[0] - (long)copy[1]));
	unsigned int tmp;
	for (unsigned int i = 1; i + 1 < this->len; i++) {
		tmp = (unsigned int)abs(((long)copy[i] - (long)copy[i + 1]));
		if (tmp < min)
			min = tmp;
	}
	delete[] copy;
	return min;
}

unsigned int Span::longestSpan() const {
	if (this->len < 2)
		throw (Span::NoMoreSpace("No span of a list of len 0 or 1"));
	int max = this->vec[0];
	int min = this->vec[0];
	for (unsigned int i = 0; i < this->len; i++) {
		if (this->vec[i] > max)
			max = this->vec[i];
		if (this->vec[i] < min)
			min = this->vec[i];
	}
	return (unsigned int)((long)max - (long)min);
}
unsigned int Span::capacity() const {
	return this->N;
}
unsigned int Span::size() const {
	return this->len;
}