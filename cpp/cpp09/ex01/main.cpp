#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error: Argument error" << std::endl;
	else {
		try {
			RPN rpn;
			std::cout << rpn.calculate(av[1]) << std::endl;		
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		} 
	}
	return (0);
}
