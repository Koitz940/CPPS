/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:20:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/04 01:17:23 by gcassi-d         ###   ########.fr       */
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
		
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& input1, Fixed& input2);
		static Fixed const& min(Fixed const& input1, Fixed const& input2);
		static Fixed& max(Fixed& input1, Fixed& input2);
		static Fixed const& max(Fixed const& input1, Fixed const& input2);
			
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream & o, Fixed const & input);
