/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:48:45 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 16:54:39 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	MapInit();
}

BitcoinExchange::BitcoinExchange(const char* filename) {
	MapInit(filename);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->data = other.data;
	this->min = other.min;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	this->data = other.data;
	this->min = other.min;
	return *this;
}

void BitcoinExchange::MapInit() {
	MapInit("data.csv");
}

void BitcoinExchange::MapInit(const char* filename) {
	std::ifstream fd(filename);
	std::string line;
	std::pair<Date, float> temp;

	this->min = Date(MAX, 12, 31);
	if (!fd) {
		throw (FileError("Database (default is 'data.csv') could not be opened"));
	}
	getline(fd, line);
	if (line != "date,exchange_rate") {
		throw (FileError("Database does not have the correct format"));
	}
	while (getline(fd, line)) {
		try {
			temp = this->GetOne(line, false);
			if (temp.first < this->min)
				this->min = temp.first;
			this->data[temp.first] = temp.second;
		} catch (std::exception& e) {
			std::cerr << e.what() << "\n";
			fd.close();
			return;
		}
	}

	fd.close();
}


BitcoinExchange::FileError::FileError(const char* msg): msg(msg) {}

const char* BitcoinExchange::FileError::what() const throw() {
	return this->msg;
}

void BitcoinExchange::iterNext(std::string& line, std::string::iterator& it) const {
	it++;
	if (it == line.end())
		throw (FileError("Database does not have the correct format: early line end"));
}

std::pair<Date, float> BitcoinExchange::GetOne(std::string& line, bool mode) const {
	std::string::iterator it = line.begin();
	std::string::iterator it_float = line.end() - 1;

	int year = 0;
	for (int i = 0; i < 4; i++) {
		if (!isdigit(*it))
			throw (FileError("Database does not have the correct format: Invalid year"));
		year = year * 10 + *it - '0';
		iterNext(line, it);
	}

	if (*it != '-')
		throw (FileError("Database does not have the correct format: Invalid year-month separation"));
	iterNext(line, it);

	int month = 0;
	for (int i = 0; i < 2; i++) {
		if (!isdigit(*it))
			throw (FileError("Database does not have the correct format: Invalid month"));
		month = month * 10 + *it - '0';
		iterNext(line, it);
	}

	if (*it != '-')
		throw (FileError("Database does not have the correct format: Invalid month-day separation"));
	iterNext(line, it);

	int day = 0;
	for (int i = 0; i < 2; i++) {
		if (!isdigit(*it))
			throw (FileError("Database does not have the correct format: Invalid day"));
		day = day * 10 + *it - '0';
		iterNext(line, it);
	}

	Date date(year, month, day);

	if (mode) {
		if (*it != ' ')
			throw (FileError("Database does not have the correct format: Invalid date-exhange rate separation (',' for .csv file and ' | ' for input file)"));
		iterNext(line, it);
		if (*it != '|')
			throw (FileError("Database does not have the correct format: Invalid date-exhange rate separation (',' for .csv file and ' | ' for input file)"));
		iterNext(line, it);
		if (*it != ' ')
			throw (FileError("Database does not have the correct format: Invalid date-exhange rate separation (',' for .csv file and ' | ' for input file)"));
		iterNext(line, it);
	}
	else {
		if (*it != ',')
			throw (FileError("Database does not have the correct format: Invalid date-exchange rate separation (',' for .csv file and ' | ' for input file)"));
		iterNext(line, it);
	}

	if (!isdigit(*it))
		throw (FileError("Database does not have the correct format: Invalid exchange rate"));

	float rate = (float)(*it - '0');

	it++;
	while (*it != '.' && it != line.end()) {
		if (!isdigit(*it))
			throw (FileError("Database does not have the correct format: Invalid exchange rate"));
		rate = rate * 10.0 + (float)(*it - '0');
		if (mode && rate > 1000.0) 
			throw (FileError("Rate overflow in input file"));
		it++;
	}

	if (it == line.end())
		return std::pair<Date, float>(date, rate);

	float decimal = 0.0;
	while (it_float != it) {
		if (!isdigit(*it_float))
			throw (FileError("Database does not have the correct format: Invalid exchange rate"));
		decimal = (decimal + (float)(*it_float - '0')) / 10.0;
		it_float--;
	}

	if (mode && rate + decimal > 1000.0)
		throw (FileError("Rate overflow in input file"));

	return std::pair<Date, float>(date, rate + decimal);
}

void BitcoinExchange::run(char* filename) const {
	std::ifstream fd(filename);
	std::string line;
	std::pair<Date, float> temp;

	if (!fd) {
		throw (FileError("input could not be opened"));
	}
	getline(fd, line);
	if (line != "date | value") {
		throw (FileError("input does not have the correct format"));
	}
	while (getline(fd, line)) {
		try {
			temp = this->GetOne(line, true);
			this->DoOne(temp);
		} catch (std::exception& e) {
			std::cerr << e.what() << "\n";
		}
	}
}

void BitcoinExchange::DoOne(std::pair<Date, float> intel) const {
	float rate;
	std::map<Date, float>::const_iterator it = this->data.find(intel.first);

	if (intel.first < this->min)
		throw(FileError("Given input date is earlier than any possible date"));

	if (it != this->data.end()) {
		rate = it->second;
		this->print(intel, rate);
		return ;
	}
	it = this->data.begin();

	Date min(0, 1, 1);
	while (it != this->data.end()) {
		if (it->first < intel.first && it->first > min) {
			min = it->first;
			rate = it->second;
		}
		it++;
	}
	this->print(intel, rate);
}

void BitcoinExchange::print(std::pair<Date, float> intel, float rate) const {
	std::cout << intel.first << " => " << intel.second << " = " << rate * intel.second << "\n";
}