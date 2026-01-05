/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:55:28 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/01/05 16:46:55 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include "Date.hpp"

class BitcoinExchange {
	std::map<Date, float> data;
	Date min;

	void MapInit();
	void MapInit(const char* filename);
	std::pair<Date, float> GetOne(std::string& line, bool mode) const;
	void DoOne(std::pair<Date, float> intel) const;
	void iterNext(std::string& line, std::string::iterator& it) const;
	void print(std::pair<Date, float> intel, float rate) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const char* filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void run(char* filename) const;
	
	class FileError: public std::exception {
		const char* msg;
		public:
			const char* what() const throw();
			FileError(const char* msg);
	};
};
