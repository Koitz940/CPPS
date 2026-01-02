/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:55:18 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 21:55:18 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <list>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& other) {*this = other;};
		MutantStack& operator=(const MutantStack& other) {
			std::stack<T, Container>::operator=(other);
			return *this;
		};

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin() {return this->c.begin();}
    	iterator end() {return this->c.end();}
		const_iterator end() const {return this->c.end();}
		const_iterator begin() const {return this->c.begin();}
};