#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
 private:
 public:
	class ThrowError : public std::exception {
		public:
			const char *what() const throw();
	};
	RPN();
	RPN(const RPN& obj);
	~RPN();
	RPN& operator=(const RPN& obj);

	int calculate(std::string data);
	bool isOperator(char c);
};

#endif
