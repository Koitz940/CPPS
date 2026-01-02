/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:20:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 17:35:24 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Fixed
{
	int val;
	static const int fract = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed(const int num);
		Fixed(const float num);
		Fixed& operator=(const Fixed& other);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream & o, Fixed const & input);
