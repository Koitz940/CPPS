/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:23:24 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 14:13:46 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "Am I working? I think I am\n";
}

void Harl::info()
{
	std::cout << "I know the first 10 pages of the Bible by heart\n";
}

void Harl::warning()
{
	std::cout << "I am getting mad, don't piss me off again, or else... (points gun)\n";
}

void Harl::error()
{
	std::cout << "I AM ERROR\n";
}

bool Harl::complain(std::string level)
{
	void (Harl::*funcPtrs[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complaints[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (level != complaints[i] && i < 4)
		i++;
	switch (i)
	{
		case 0:
			(this->*funcPtrs[0])();
			(this->*funcPtrs[1])();
			(this->*funcPtrs[2])();
			(this->*funcPtrs[3])();
			break;
		case 1:
			(this->*funcPtrs[1])();
			(this->*funcPtrs[2])();
			(this->*funcPtrs[3])();
			break;
		case 2:
			(this->*funcPtrs[2])();
			(this->*funcPtrs[3])();
			break;
		case 3:
			(this->*funcPtrs[3])();
			break;
		default:
			return true;
	}
	return false;
}