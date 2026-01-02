/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:23:04 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 20:09:41 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{
	std::string name;
	Weapon *weapon;
	char hasWeapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};