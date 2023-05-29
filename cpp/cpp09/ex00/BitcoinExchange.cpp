/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:36:10 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/29 22:46:05 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	this->btcData = obj.btcData;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	if (this != &obj)
		this->btcData = obj.btcData;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){

}

void BitcoinExchange::splitString(const std::string& str, char delimiter, std::string& t1, std::string& t2) {
	std::istringstream iss(str);
	std::getline(iss, t1, delimiter);
	std::getline(iss, t2, delimiter);
}

bool BitcoinExchange::isValidDate(const std::string& str) {
	if (str.length() != 10) 
		return (false);
	int year, month, day;
	if (sscanf(str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (false);
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	int maxDays = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		maxDays = 30;
	} else if (month == 2) {
		bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
		maxDays = (isLeapYear) ? 29 : 28;
	}

	if (day > maxDays)
		return (false);
	return (true);
}

bool BitcoinExchange::isValidValue(const std::string& str) {
    char* end;
    double value = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || *end != '\0') {
        return (false);
    }
    if (value < 0.0 || value > 1000.0) {
        return (false);
    }
    return (true);
}

void BitcoinExchange::checkCsv(void){
	std::ifstream csv("data.csv");
	if (!csv.is_open()) {
		std::cout << "Failed to open database file" << std::endl;
		throw ThrowError();
	}
	if (csv.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Database file is empty" << "\n";
		csv.close();
		throw ThrowError();
	}

	std::string line;
	while (std::getline(csv, line)) {
		if (line != "date,exchange_rate") {
			std::string date, value;
			splitString(line, ',', date, value);

			if (isValidDate(date) == false) {
				std::cout << "Invalid data found in the line: " << line << "\n";
				throw ThrowError();
			}
			if (isValidValue(value) == false) {
				std::cout << "Invalid data found in the line: " << line << "\n";
				throw ThrowError();
			}
			else {
				btcData[date] = std::strtod(value.c_str(), NULL);
			}
		}
	}
	csv.close();
	for (std::map<std::string, float>::const_iterator it = btcData.begin(); it != btcData.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << "\n";
    }

}

void BitcoinExchange::calculate(char *csv) {
	try {
		(void)csv;
		checkCsv();
	} catch (...) {
		return ;
	}
}

const char* BitcoinExchange::ThrowError::what() const throw() {
	return ("");
}