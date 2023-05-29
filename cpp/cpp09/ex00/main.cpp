#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: btc <filename>\n";
		return (1);
	}
	BitcoinExchange btc;
	btc.calculate(av[1]);
}