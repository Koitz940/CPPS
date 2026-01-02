/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:27:16 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/29 13:28:31 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"

class FragTrap: public ScavTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys(void);
};