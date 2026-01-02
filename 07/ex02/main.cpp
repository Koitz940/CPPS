/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:31:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 17:10:26 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define E 2.71828182845904523536

//There is no Array.cpp allowed, so uhm, yeah this is just ridiculous isn't it, I am just very sorry

template <typename T>
Array<T>::IndexOutOfBounds::IndexOutOfBounds(const char* msg): msg(msg) {}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw() {
	return this->msg;
}

template <typename T>
Array<T>::Array() {
	this->vec = new T[1];
	this->capacity = 1;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	if (!n)
		throw (Array<T>::IndexOutOfBounds("Cannot have an empty array"));
	this->capacity = n;
	this->vec = new T[n];
	for (size_t i = 0; i < this->capacity; ++i) {
		this->vec[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array<T>& other) {
	*this = other;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->vec;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this->vec)
		delete[] this->vec;
	this->vec = new T[other.size()];
	this->capacity = other.size();
	for (size_t i = 0; i < this->capacity; ++i) {
		this->vec[i] = other.vec[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t i) {
	if (i >= this->capacity)
		throw (Array<T>::IndexOutOfBounds("Cannot index a value outside of the array"));
	return (this->vec[i]);
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
	if (i >= this->capacity)
		throw (Array<T>::IndexOutOfBounds("Cannot index a value outside of the array"));
	T& x = this->vec[i];
	return (x);
}

template <typename T>
size_t Array<T>::size() const {
	return this->capacity;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    for (size_t i = 0; i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}

std::ostream& operator<<(std::ostream& out, const complex& z) {
	out << z.re << " + " << z.im << "i";
	return out;
}

complex from(double re, double im)
{
	complex z;
	z.re = re;
	z.im = im;
	return z;
}

int main()
{
	size_t n = 10;
	size_t m = 20;

	std::cout << "creating valid arrays\n";
	Array<complex> test;

	Array<int> ints(n);
	Array<complex> nums(m);

	std::cout << "creating empty string\n";
	try {
		Array<char> str(0);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "initializing int array values\n";
	try {
		for (size_t i = 0; i < ints.size(); i++) {
			ints[i] = (int)((i * (i + 1)) / 2);
		}
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "checking out of range of the int array\n";
	try {
		ints[234] = 3141592;
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "initializing complex array values\n";
	try {
		for (size_t i = 0; i < nums.size(); i++) {
			nums[i] = from( ((double)(i * i + 2 * i + 1) - (double)(i * i)) / 2.0, E * (double)i);
		}
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "checking out of range of the complex array\n";
	try {
		nums[234] = from(1729.0, -1.0);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << ints << "\n" << nums << "\n";
}