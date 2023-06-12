#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN& obj) {
	*this = obj;
}

RPN::~RPN() {
}

RPN &RPN::operator=(const RPN& obj) {
	if (this != &obj)
	{
	}
	return *this;
}

const char* RPN::ThrowError::what() const throw() {
	return ("Error: Check Value");
}

bool RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::calculate(std::string data) {
	std::stack<int> stack;

	for (int i = 0; i < (int)data.size(); i++){
		if (data[i] == ' ')
			i++;
		if (isdigit(data[i]))
			stack.push(data[i] - 48);
		else if (isOperator(data[i])) {
			if (stack.size() < 2)
				throw ThrowError();
			int v1, v2;
			v2 = stack.top();
			stack.pop();
			v1 = stack.top();
			stack.pop();
			if (data[i] == '+')
				stack.push(v1 + v2);
			if (data[i] == '-')
				stack.push(v1 - v2);
			if (data[i] == '*')
				stack.push(v1 * v2);
			if (data[i] == '/')
				stack.push(v1 / v2);
		}
		else
			throw ThrowError();
	}
	if (stack.size() != 1)
		throw ThrowError();
	return (stack.top());
}