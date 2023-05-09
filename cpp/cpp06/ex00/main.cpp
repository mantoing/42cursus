#include "Convert.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Please, put in two arguments!" << std::endl;
		return 1;
	}

	Convert	converter(argv[1]);

	// converter.printvalue();

	converter.CheckChar();
	converter.CheckInt();
	converter.CheckFloat();
	converter.CheckDouble();
}