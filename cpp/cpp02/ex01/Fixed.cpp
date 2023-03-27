/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:18:04 by jaeywon           #+#    #+#             */
/*   Updated: 2023/03/27 17:23:28 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//--------CONSTRUCTOR--------
Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//bits 8만큼 num을 왼쪽으로 비트연산하여 8비트 고정소수점 기준 정수부로 밀어줌.
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << this->bits;
}

//float는 비트연산을 하지 못한다 따라서 8비트 만큼 왼쪽으로 비트연산 하는것과 같게 움지이도록 f에 256(2의 8승)
//을 곱해준다. 이때 연산중 값을 버려서 정확한 값이 나오지 않는 문제를 해결하기 위해 roundf로 반올림.
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * 256);
}

//---------DESTRUCTOR---------
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

//------METHOD---------

//고정 소수점을 정수로
//왼쪽우로 8비트 밀어준것을 다시 오른쪽으로 8비트 밀어 원래대로 돌리고 반환.
int Fixed::toInt(void) const{
	return (this->value >> this->bits);
}

//고정소수점을 실수로
//왼쪽으로 8비트 밀어준 것을 다시 오른쪽으로 8비트 밀어 원래대로 돌리고 반환.
float Fixed::toFloat(void) const {
	return ((float)this->value / (256));
}

//--------OVERLOAD---------
Fixed &Fixed::operator=(const Fixed& src){
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &src){
		this->setRawBits(src.getRawBits());
	}
	return (*this);
}
//고정 소수점 출력시 toFloat()을 적용해 부동소수점으로 값을 출력할 수 있도록 ostream클래스의 << 연산자를 오버로딩 해준다.
std::ostream& operator<<(std::ostream &out, const Fixed &fix){
	out << fix.toFloat();
	return (out);
}



//--------ACCESOR----------
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw){
	value = raw;
}