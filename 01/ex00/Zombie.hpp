/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:58:51 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/22 18:15:50 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie
{
	std::string name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif