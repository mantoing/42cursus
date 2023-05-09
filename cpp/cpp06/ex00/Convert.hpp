#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <limits>
# include <iomanip>

class Convert {
 private:
	const std::string _value;
	double _double;
	char _char;
	int	_int;
	float _float;
 public:
	Convert();
	Convert(std::string _value);
	Convert(const Convert& obj);
	~Convert();
	Convert& operator=(const Convert& obj);

	void CheckInt() const;
	void CheckChar() const;
	void CheckDouble() const;
	void CheckFloat() const;
	void PrintValue() const;
};

#endif
