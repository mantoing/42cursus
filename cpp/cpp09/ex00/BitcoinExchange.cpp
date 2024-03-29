/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:36:10 by jaeywon           #+#    #+#             */
/*   Updated: 2023/06/14 20:06:57 by jaeywon          ###   ########.fr       */
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

bool BitcoinExchange::isNumeric(const std::string& str) {
    for (std::size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]) && !std::isspace(str[i]) && str[i] != '-' && str[i] != '.') {
            return false;
        }
    }
    return true;
}

void BitcoinExchange::splitString(const std::string& str, char delimiter, std::string& t1, std::string& t2) {
	std::istringstream iss(str);
	std::getline(iss, t1, delimiter);
	std::getline(iss, t2, delimiter);
	t1.erase(std::remove_if(t1.begin(), t1.end(), ::isspace), t1.end());
	t2.erase(std::remove_if(t2.begin(), t2.end(), ::isspace), t2.end());
}

bool BitcoinExchange::isValidDate(const std::string& str) {
	if (str.length() != 10) 
		return (false);
	int year, month, day;
	std::istringstream iss(str);
    char dash1, dash2;
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
        return false;
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
    char* end = NULL;
    double value = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || *end != '\0') {
        return (false);
    }
	if (value == 0.0 && !std::isdigit(str[0])) {
		return (false);
	}
	if (*end && std::strcmp(end, "f")) {
		return (false);
	}
    if (value < 0.0) {
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
}

bool BitcoinExchange::checkInput(const char *filename) {
	std::ifstream file(filename);
	if (!file) {
		std::cout << "Failed to open file: " << filename << std::endl;
		return (false);
	}
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "File is empty : " << filename << std::endl;
		file.close();
		return (false);
	}
	std::string firstLine;
	std::getline(file, firstLine);
	std::stringstream ss(firstLine);
	std::string str_date, str_value;
	splitString(firstLine, '|', str_date, str_value);
	if (str_date != "date" || str_value != "value") {
		std::cout << "Invalid format in the first line: " << firstLine << std::endl;
		file.close();
		return (false);
	}
	std::string line;
	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}
		std::stringstream ss(line);
		std::string date, value;
		splitString(line, '|', date, value);
		if (!isNumeric(date) || !isNumeric(value)) {
			std::cout << "Invalid data in the file: " << line << std::endl;
			file.close();
			return (false);
		}
	}
	file.close();
	return (false);
}

int BitcoinExchange::stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int result;
    if (!(iss >> result))
		return false;
    return result;
}

float BitcoinExchange::match_DateValue(const std::string& date) {
	std::map<std::string, float>::iterator it = btcData.find(date);
	if (it != btcData.end()) {
		return (it->second);
	}
	else {
		std::map<std::string, float>::iterator lower = btcData.lower_bound(date);
		if (lower == btcData.begin()) {
			return (lower->second);
		}
		else if (lower == btcData.end()) {
			return ((--lower)->second);
		}
		else {
			std::map<std::string, float>::iterator prev = lower;
			--prev;
			return (prev->second);
			}
		}
}

void BitcoinExchange::match_cal(char *filename){
	std::ifstream file(filename);
	std::string firstline;

	std::getline(file, firstline);
	std::string line;
	while (std::getline(file, line)){
		if (line.empty()) {
			continue;
		}
		std::stringstream ss(line);
		std::string date, value;
		splitString(line, '|', date, value);
		float fvalue = std::strtod(value.c_str(), NULL);
		if (isValidDate(date) == false)
			std::cout << "Error: bad input => " << date << std::endl;
		if (!value.empty()) {
			if (value == " " || value == "NULL"){
				continue;
			}
			else {
				if (fvalue < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (isValidDate(date) == false)
					std::cout << "Error: bad input => " << date << std::endl;
				else if (isValidValue(value) == false)
					std::cout << "Error: bad input => " << value << std::endl;
				else if (!(stringToInt(value) == false)) {
					float exchangeRate = match_DateValue(date);
					float multiplevalue = fvalue * exchangeRate;
					std::cout << date << " => " << value << " = " << multiplevalue << std::endl;
				}
				else
					std::cout << "Error: too large a number" << std::endl;
			}
		}
	}
}

void BitcoinExchange::calculate(char *filename) {
	try {
		checkCsv();
		checkInput(filename);
	} catch (...) {
		return ;
	}
	match_cal(filename);
}

const char* BitcoinExchange::ThrowError::what() const throw() {
	return ("");
}