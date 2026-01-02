/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:20:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 16:58:35 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	int val;
	static const int fract = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};