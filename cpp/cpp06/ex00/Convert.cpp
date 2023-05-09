# include "Convert.hpp"

Convert::Convert() {

}

Convert::Convert(std::string value) : _value(value)
		, _double(std::strtod(value.c_str(), NULL))
		, _char(static_cast<char>(_double))
		, _int(static_cast<int>(_double))
		, _float(static_cast<float>(_double)) {
}

Convert::Convert(const Convert& obj) :_value(obj._value)
		, _double(obj._double)
		, _char(obj._char)
		, _int(obj._int)
		, _float(obj._float) {
}

Convert::~Convert() {

}

void Convert::CheckInt() const {
	if (_double > std::numeric_limits<int>::min() - 1.0 \
		&& _double < std::numeric_limits<int>::max() + 1.0) 
	{
		std::cout << "Int : " << _int << std::endl;
		return ;
	}
	std::cout << "Int :";
	std::cout << "Impossible" << std::endl;
}

void Convert::CheckChar() const {
	if (std::isprint(_double))
	{
		std::cout << "Cahr :" << "'" << _char << "'" << std::endl;
		return ;
	}
	if (_double > std::numeric_limits<char>::min() - 1.0 \
		&& _double < std::numeric_limits<char>::max() + 1.0)
	{
		std::cout << "Char : " << "Non displayable" << std::endl;
		return ;
	}
	std::cout << " Char :";
	std::cout << "Impossible" << std::endl; 
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
	std::cout << std::fixed << std::setprecision(1) << _float  << "f" << std::endl;
}

void Convert::PrintValue() const {
	std::cout << "**********************" << std::endl;
	std::cout << "char: "  << _char << std::endl;
	std::cout << "int: "  << _int << std::endl;
	std::cout << "float: "  << _float << std::endl;
	std::cout << "double: "  << _double << std::endl;
	std::cout << "**********************" << std::endl;
}

Convert &Convert::operator=(const Convert& obj) {
	if (this == &obj)
		return (*this);
	return (*this);
}