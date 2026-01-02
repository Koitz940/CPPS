/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:25:22 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 22:25:22 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	std::cout << "Mutanstack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "List:" << std::endl;
	std::list<int> lis;
	lis.push_back(5);
	lis.push_back(17);
	std::cout << lis.back() << std::endl;
	lis.pop_back();
	std::cout << lis.size() << std::endl;
	lis.push_back(3);
	lis.push_back(5);
	lis.push_back(737);
	lis.push_back(0);
	std::list<int>::iterator itl = lis.begin();
	std::list<int>::iterator itle = lis.end();
	++itl;
	--itl;
	while (itl != itle) {
		std::cout << *itl << std::endl;
		++itl;
	}
}