/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:42:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 13:45:43 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl = Harl();

	std::cout << "I will now debug\n";
	harl.complain("DEBUG");
	std::cout << "I will now info\n";
	harl.complain("INFO");
	std::cout << "I will now warning\n";
	harl.complain("WARNING");
	std::cout << "I will now error\n";
	harl.complain("ERROR");
}