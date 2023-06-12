#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>


class BitcoinExchange {
 private:
	std::map<std::string, float> btcData;
	
	void splitString(const std::string& str, char delimiter, std::string& t1, std::string& t2);
	bool isValidDate(const std::string& str);
	bool isValidValue(const std::string& str);
	void checkCsv(void);
	bool isNumeric(const std::string& str);
	bool checkInput(const char* filename);
	void match_cal(char *filename);
	float match_DateValue(const std::string& date);
	int stringToInt(const std::string& str);
 public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj);

	void calculate(char *filename);
	
	class ThrowError : public std::exception {
		public :
			const char* what() const throw();
	};
};

#endif
