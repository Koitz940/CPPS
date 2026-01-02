/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:33:42 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 19:40:59 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	const Fixed x;
	const Fixed y;

	public:
		Point();
		Point(const int x, const int y);
		Point(const float x, const float y);
		~Point();
		Point(const Point& other);
		Point& operator=(Point& other);
		const Point& operator=(const Point& other);
		
		static Fixed dotProd(const Point& a, const Point& b); 
		static Point crossProd(const Point& a, const Point& b);
		
		const Fixed getx() const;
		const Fixed gety() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream & o, Point const & input);
