/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:12:54 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/02 17:03:21 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>

template<typename T>
void swap(T& a, T& b);

template<typename T>
T min(T& a, T& b);

template<typename T>
T max(T& a, T& b);

struct complex
{
	double re;
	double im;
};

complex from(double re, double im);

std::ostream& operator<<(std::ostream& out, const complex& arr);