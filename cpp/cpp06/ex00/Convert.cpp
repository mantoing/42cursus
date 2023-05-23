/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:10:36 by jaeywon           #+#    #+#             */
/*   Updated: 2023/05/23 17:00:14 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Convert.hpp"

Convert::Convert() {

}

Convert::Convert(std::string value) : _value(value) {
	try{
		if (is_char(value))
			_double = static_cast<double>(value[0]);
		else
			_double = std::strtod(value.c_str(), NULL);
	} catch (const std::exception& e) {
		std::cerr << "Argument error" << std::endl;
	}
}

Convert::Convert(const Convert& obj) {
	*this = obj;
}

Convert::~Convert() {

}

bool Convert::is_char(std::string value) const{
	if (value.length() == 1 && !std::isdigit(value[0]))
		return (true);
	return (false);
}

void Convert::CheckInt() const {
	int d = static_cast<int>(_double);

	if ((_double >= std::numeric_limits<int>::min() + 1.0 \
		&& _double <= std::numeric_limits<int>::max() - 1.0)) 
	{
		std::cout << "Int : " << d << std::endl;
		return ;
	}
	else 
	std::cout << "Int :";
	std::cout << "Impossible" << std::endl;
}

void Convert::CheckChar() const {
	char c = static_cast<char>(_double);
	
	if (std::isprint(_double))
	{
		std::cout << "Char :" << "'" << c << "'" << std::endl;
		return ;
	}
	else if (c > std::numeric_limits<char>::min() - 1.0 \
		&& c < std::numeric_limits<char>::max() + 1.0)
	{
		std::cout << "Char : Impossible" << std::endl;
		return ;
	}
	std::cout << " Char :";
	std::cout << "Non displayable" << std::endl; 
}

void Convert::CheckDouble() const {
	if (_double != _double)
	{
		std::cout << "Double : " << "nan" << std::endl;
		return ;
	}
	if (_double == std::numeric_limits<double>::infinity()) 
	{
		std::cout << "Double : " << "inf" << std::endl;
		return ;
	}
	if (_double == -std::numeric_limits<double>::infinity()) 
	{
		std::cout << "Double : " << "-inf" << std::endl;
		return ;
	}
	std::cout << "Double : ";
	std::cout << std::fixed << std::setprecision(1) << _double << std::endl;
}

void Convert::CheckFloat() const {
	float f = static_cast<float>(_double);
	
	if (_double != _double)
	{
		std::cout << "Float : " << "nanf" << std::endl;
		return ;
	}
	if (_double == std::numeric_limits<float>::infinity())
	{
		std::cout << "Float : " << "inff" << std::endl;
		return ;
	}
	if (_double == -std::numeric_limits<float>::infinity())
	{
		std::cout << "Float : " << "-inff" << std::endl;
		return ;
	}
	if (_double < std::numeric_limits<float>::min() \
		&& _double > std::numeric_limits<float>::max())
	{
		std::cout << "Float : ";
		std::cout << "Impossible" << std::endl;
		return ;
	}
	std::cout << "Float : ";
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

Convert &Convert::operator=(const Convert& obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}