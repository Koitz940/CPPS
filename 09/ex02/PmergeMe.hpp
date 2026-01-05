/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:06:33 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 20:06:33 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>

#define NS (1000000000.0)
#define US (1000000.0)

typedef long long num;

class PmergeMe {
	std::vector<num> vec;
	std::deque<num> deq;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(std::string& str);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		static void validate(const std::string& input);
		static void correct(std::string& str);
		void run();
	
	class Overflow: public std::exception {
		const char* msg;
		public:
			const char* what() const throw();
			Overflow(const char* msg);
	};
};

template <typename T>
void sortVec(std::vector<T>& vec);

template <typename T>
void sortDeq(std::deque<T>& vec);

template <typename T>
int locateVec(std::vector<T>& vec, T n);

template <typename T>
int locateDeq(std::deque<T>& deq, T n);

template<typename T>
void swap(T& a, T& b);

std::ostream& operator<<(std::ostream& out, const std::vector<num>& vec);
std::ostream& operator<<(std::ostream& out, const std::deque<num>& deq);