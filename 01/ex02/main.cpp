/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:44:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:51:00 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string hi = "HI THIS IS BRAIN";
	std::string* stringPTR = &hi; 
	std::string &stringREF = hi;
	
	std::cout << "Memory adress of hi: " << &hi << "\n";
	std::cout << "Memory adress helf by stringPTR: " << stringPTR << "\n";
	std::cout << "Memory adress held by stringREF " << &stringREF << "\n";

	std::cout << "Contents of hi: " << hi << "\n";
	std::cout << "What stringPTR poinys to: " << *stringPTR << "\n";
	std::cout << "what stringREF referencees: " << stringREF << "\n";
}