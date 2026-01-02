/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:39:18 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 13:27:54 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap& other);
		ScavTrap(const ScavTrap& other);

		void attack(const std::string& target) const;
		void guardGate() const;
};