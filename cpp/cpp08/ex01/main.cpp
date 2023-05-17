#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(10);
// 	sp.addNumber(2);
// 	sp.addNumber(2);
// 	sp.addNumber(51);
// 	sp.addNumber(1235);
// 	sp.addNumber(10);
// 	sp.addNumber(1123);
// 	sp.addNumber(1);
// 	sp.addNumber(112);
// 	sp.addNumber(114443);
// 	sp.addNumber(552);
	
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
	
// 	std::cout << "---addNumber test---" << std::endl;

// 	try
// 	{
// 		Span					sp(0);
// 		sp.addNumber(0);
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	try
// 	{
// 		Span					sp(1);
// 		sp.addNumber(3);
// 		sp.addNumber(5);
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
	
// 	std::cout << "---short_long exception test---" << std::endl;
	
// 	try
// 	{
// 		Span					sp(0);
// 		std::cout << sp.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	try
// 	{
// 		Span					sp(0);
// 		std::cout << sp.longestSpan() << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	std::cout << "---max test---" << std::endl;
	
// 	Span						sp1 = Span(10000);

// 	for (int i = -5000; i <= 4999; i++)
// 		sp1.addNumber(i);
// 	std::cout << sp1.shortestSpan() << std::endl;
// 	std::cout << sp1.longestSpan() << std::endl;

// 	return 0;
// }

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(10);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}