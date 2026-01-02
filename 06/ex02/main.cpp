/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:14:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 16:54:47 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main()
{
	Base* b = generate();
	identify(b);
	Base& ref = *b;
	identify(ref);
	if (!b)
		std::cout << "new failed...\n";
	else
		delete b;

	Base* c = generate();
	identify(c);
	Base& ref1 = *c;
	identify(ref1);
	if (!c)
		std::cout << "new failed...\n";
	else
		delete c;


	Base* a = generate();
	identify(a);
	Base& ref2 = *a;
	identify(ref2);
	if (!a)
		std::cout << "new failed...\n";
	else
		delete a;
	
	Base* d = generate();
	identify(d);
	Base& ref3 = *d;
	identify(ref3);
	if (!d)
		std::cout << "new failed...\n";
	else
		delete d;
}