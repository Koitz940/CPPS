/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:14:41 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/01 19:14:41 by gcassi-d         ###   ########.fr       */
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
}