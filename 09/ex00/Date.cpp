/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:00:15 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/04 00:00:15 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(): year(0), month(1), day(1) {}

Date::~Date() {};

//It seems that since 1584, a year that is a multiple of 100 isn't a loop year if it isn't a mulitple of 400, just leart that because I googled the name loop year because I did not remember it in english and started scrolling wikipedia
int Date::MaxDay(int month, int year)
{
    switch (month)
    {
        case 1:  return 31;
        case 2:  return 28 + (!(year % 100) ? !(year % 400): !(year % 4)); 
        case 3:  return 31;
        case 4:  return 30;
        case 5:  return 31;
        case 6:  return 30;
        case 7:  return 31;
        case 8:  return 31;
        case 9:  return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: 
			throw (DateError("Date error: incorrect month"));
			return -1;
    }
}

Date::Date(int year, int month, int day) {
	if (year < 0)
		throw(DateError("Date error: negative year"));
	this->year = year;
	if (month <= 0 || month > 23)
		throw(DateError("Date error: incorrect month"));
	this->month = month;
	if (day <= 0 || day > MaxDay(month, year))
		throw(DateError("Date error: incorrect day"));
	this->day = day;
}

Date::Date(const Date& other) {*this = other;}

Date& Date::operator=(const Date& other) {
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	return *this;
}

const char* Date::DateError::what() const throw() {return this->msg;}
Date::DateError::DateError(const char* msg): msg(msg) {}

bool Date::operator==(const Date& other) {
	return (other.year == this->year && other.month == this->month && other.day == this->day);
}

bool Date::operator!=(const Date& other) {
	return !(*this == other);
}

bool Date::operator>=(const Date& other) {
	return (*this == other || *this > other);
}

bool Date::operator<=(const Date& other) {
	return (*this == other || *this < other);
}

bool Date::operator<(const Date& other) {
	if (this->year > other.year)
		return false;
	else if (this->year < other.year)
		return true;
	if (this->month > other.month)
		return false;
	else if (this->month < other.month)
		return true;
	if (this->day > other.day)
		return false;
	else if (this->day < other.day)
		return true;
	return false;
}

bool Date::operator>(const Date& other) {
	if (this->year < other.year)
		return false;
	else if (this->year > other.year)
		return true;
	if (this->month < other.month)
		return false;
	else if (this->month > other.month)
		return true;
	if (this->day < other.day)
		return false;
	else if (this->day > other.day)
		return true;
	return false;
}

Date& Date::operator++() {
	this->day++;
	if (!(this->day > MaxDay(this->month, this->year)))
		return (*this);
	this->day = 1;
	this->month++;
	if (!(this->day > 12))
		return (*this);
	this->month = 1;
	this->year++;
	if (this->year == MIN)
		throw (DateError("++ operator applied on INT_MAX/12/31, out of dates LOL"));
	return (*this);
}

Date Date::operator++(int) {
	Date temp(*this);
	++*this;
	return (temp);
}

Date& Date::operator--() {
	this->day--;
	if (this->day > 0)
		return (*this);
	this->month--;
	if (this->month > 0) {
		this->day = MaxDay(this->month, this->year);
		return (*this);
	}
	this->month = 12;
	this->day = 31;
	this->year--;
	if (this->year < 0)
		throw (DateError("-- operator applied on 0000/01/01"));
	return (*this);
}

Date Date::operator--(int) {
	Date temp(*this);
	--*this;
	return (temp);
}

bool Date::operator==(const Date& other) const {
	return (other.year == this->year && other.month == this->month && other.day == this->day);
}

bool Date::operator!=(const Date& other) const {
	return !(*this == other);
}

bool Date::operator>=(const Date& other) const {
	return (*this == other || *this > other);
}

bool Date::operator<=(const Date& other) const {
	return (*this == other || *this < other);
}

bool Date::operator<(const Date& other) const {
	if (this->year > other.year)
		return false;
	else if (this->year < other.year)
		return true;
	if (this->month > other.month)
		return false;
	else if (this->month < other.month)
		return true;
	if (this->day > other.day)
		return false;
	else if (this->day < other.day)
		return true;
	return false;
}

bool Date::operator>(const Date& other) const {
	if (this->year < other.year)
		return false;
	else if (this->year > other.year)
		return true;
	if (this->month < other.month)
		return false;
	else if (this->month > other.month)
		return true;
	if (this->day < other.day)
		return false;
	else if (this->day > other.day)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	out << date.year << "-";
	if (date.year < 1000) {
		out << "0";
	}
	if (date.year < 100) {
		out << "0";
	}
	if (date.year < 10) {
		out << "0";
	}
	out << date.year << "-";
	if (date.month < 10) {
		out << "0";
	}
	out << date.month << "-";
	if (date.day < 10) {
		out << "0";
	}
	out << date.day;
	return out;
}