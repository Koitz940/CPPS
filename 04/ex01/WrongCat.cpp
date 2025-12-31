/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 22:22:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/28 22:22:54 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "./WrongCat default\n";
}

WrongCat::~WrongCat()
{
	std::cout << "Takeback (WrongCat): KeyboardInterrupt\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal("WrongCat")
{
	*this = other;
	std::cout << "./WrongCat copy\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "meow\n";
}