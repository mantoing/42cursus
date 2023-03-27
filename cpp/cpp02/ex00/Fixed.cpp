#include "Fixed.hpp"

//CONSTRUCTOR

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//DESTRUCTOR
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

//OVERLOAD
Fixed &Fixed::operator=(const Fixed& src){
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &src){
		this->setRawBits(src.getRawBits());
	}
	return (*this);
}

//ACCESOR

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw){
	value = raw;
}