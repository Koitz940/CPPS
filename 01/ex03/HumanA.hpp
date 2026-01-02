/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:08:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 19:14:02 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
};