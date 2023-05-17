#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <cstdlib>
# include <numeric>
# include <iterator>


class Span {
 private:
	std::vector<int> vec;
	unsigned int N;
 public:
	class FullVecException : public std::exception {
		public:
			const char* what() const throw();
	};
	class OnlyOneException : public std::exception {
		public:
			const char* what() const throw();
	};
	Span();
	Span(unsigned int N);
	Span(const Span& obj);
	~Span();

	Span& operator=(const Span& obj);

	void addNumber(int value);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	
	std::vector<int> getVector(void) const;
};

#endif