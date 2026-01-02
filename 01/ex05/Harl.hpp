/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:20:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 13:23:22 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Harl
{
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	public:
		Harl();
		~Harl();
		void complain( std::string level );
};