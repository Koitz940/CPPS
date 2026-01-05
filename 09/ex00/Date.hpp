/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:59:14 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 16:48:27 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ostream>
#define MIN (-2147483647 - 1)
#define MAX 2147483647

class Date {
	int MaxDay(int month, int year);

	public:
		Date();
		~Date();
		Date(int year, int month, int day);
		Date(const Date& other);
		Date& operator=(const Date& other);

		int year;
		int month;
		int day;

		bool operator==(const Date& other);
		bool operator!=(const Date& other);
		bool operator>=(const Date& other);
		bool operator<=(const Date& other);
		bool operator<(const Date& other);
		bool operator>(const Date& other);

		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
		bool operator>=(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;

		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);

	
	class DateError: public std::exception {
		const char* msg;
		public:
			const char* what() const throw();
			DateError(const char* msg);
	};
};

std::ostream& operator<<(std::ostream& out, const Date& date);