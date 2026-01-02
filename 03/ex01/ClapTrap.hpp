/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:55:04 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 13:24:48 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDmg;

	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap& operator=(const ClapTrap& other);
		ClapTrap(const ClapTrap& other);

		void attack(const std::string& target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDmg() const;
		std::string getName() const;

		void setName(const std::string& name);
		void setAttackDmg(unsigned int atk);
		void setEnenrgyPoints(unsigned int energy);
		void setHitPoints(unsigned int HitPoints);
};