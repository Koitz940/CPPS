/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:48:19 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 19:42:24 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}
Point::~Point() {}
Point::Point(const int x, const int y): x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)) {}

const Fixed Point::getx() const
{
	return this->x;
}

const Fixed Point::gety() const
{
	return this->y;
}

Point::Point(const Point& other): x(other.x), y(other.y) {}

Point& Point::operator=(Point& other)
{
	(void) other;
	return (*this);
}

const Point& Point::operator=(const Point& other)
{
	(void) other;
	return (*this);
}

bool bsp(Point const a, Point const b, Point const c, Point p) {
    const Fixed d1 = (b.getx() - a.getx()) * (p.gety() - a.gety()) - (b.gety() - a.gety()) * (p.getx() - a.getx());
    const Fixed d2 = (c.getx() - b.getx()) * (p.gety() - b.gety()) - (c.gety() - b.gety()) * (p.getx() - b.getx());
    const Fixed d3 = (a.getx() - c.getx()) * (p.gety() - c.gety()) - (a.gety() - c.gety()) * (p.getx() - c.getx());

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}

std::ostream& operator<<(std::ostream & o, Point const & input)
{
	o << "x: " << input.getx() << ", y: " << input.gety() << "\n";
	return o;
}