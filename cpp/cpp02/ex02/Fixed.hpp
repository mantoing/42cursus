#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed {
 private:
	int	value;
	static const int	bits = 8;
 public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator=(const Fixed& src);
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	bool operator>(const Fixed &fix) const;
	bool operator<(const Fixed &fix) const;
	bool operator>=(const Fixed &fix) const;
	bool operator<=(const Fixed &fix) const;
	bool operator==(const Fixed &fix) const;
	bool operator!=(const Fixed &fix) const;
	Fixed operator++(int);
	Fixed& operator++();
	Fixed operator--(int);
	Fixed& operator--();
	Fixed operator+(Fixed const &fix);
	Fixed operator/(Fixed const &fix);
	Fixed operator*(Fixed const &fix);
	Fixed operator-(Fixed const &fix);
	static Fixed& min(Fixed &fix1, Fixed &fix2);
	static const Fixed& min(const Fixed &fix1, const Fixed &fix2);
	static Fixed& max(Fixed &fix1, Fixed &fix2);
	static const Fixed& max(const Fixed &fix1, const Fixed &fix2);
};
std::ostream& operator<<(std::ostream &out, const Fixed &fix);

#endif
