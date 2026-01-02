/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:58:44 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 19:52:55 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
	std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string getType();
		void setType(std::string type);
};