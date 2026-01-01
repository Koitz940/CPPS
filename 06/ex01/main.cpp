/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:50:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/01 18:50:54 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data* z = new Data;
	if (!z)
	{
		std::cout << "new failed........\n";
		return 1;
	}
	z->im = 0.5;
	z->re = 0.8660254037;

	uintptr_t n = Serializer::serialize(z);
	Data* p = Serializer::deserialize(n);

	std::cout << "Im: " << p->im << ", Re: " << p->re << "\n";
	std::cout << "Im: " << z->im << ", Re: " << z->re << "\n";
	delete z;
}