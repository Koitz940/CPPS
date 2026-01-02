/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:58:51 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:36:55 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
	std::string name;
	public:
		Zombie();
		~Zombie();
		void announce( void );
		void set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif