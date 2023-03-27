#include "Fixed.hpp"
#include <cmath>

//--------CONSTRUCTOR--------
Fixed::Fixed(){
	value = 0;
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::Fixed(const int n) {
	this->value = n << this->bits;
}

Fixed::Fixed(const float f) {
	this->value = roundf(f * 256);
}

//---------DESTRUCTOR---------
Fixed::~Fixed(){

}

//------METHOD---------

int Fixed::toInt(void) const{
	return (this->value >> this->bits);
}

float Fixed::toFloat(void) const {
	return ((float)this->value / (256));
}

//--------OVERLOAD---------
Fixed &Fixed::operator=(const Fixed& src){
	if (this != &src){
		this->setRawBits(src.getRawBits());
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fix){
	out << fix.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &fix) const{
	if (this->value > fix.value)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &fix) const{
	if (this->value < fix.value)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &fix) const{
	if (this->value >= fix.value)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &fix) const{
	if (this->value <= fix.value)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &fix) const{
	if (this->value == fix.value)
		return (true);
	return (false);
}

//전위증가이기 때문에 값을 증가시켜 반환
Fixed& Fixed::operator++() {
	this->value++;
	return *this;
}
//후위증가 이기때문에 출력이후에 ++이 되어야한다.
//this->value++로 인해 값이 증가되었지만, 출력할때의 리턴은 a이므로 출력할때는 증가되지않는 값이 출력되지만,
//이후에 this에서 증가되어 a도 증가된 값을 가지게 된다.
Fixed Fixed::operator++(int) {
	Fixed a(*this);

	this->value++;
	return a;
}

Fixed& Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed a(*this);

	this->value--;
	return a;
}

Fixed Fixed::operator+(Fixed const &fix){
	Fixed a(this->toFloat() + fix.toFloat());
	return (a);
}

Fixed Fixed::operator/(Fixed const &fix){
	Fixed a(this->toFloat() / fix.toFloat());
	return (a);
}

Fixed Fixed::operator*(Fixed const &fix){
	Fixed a(this->toFloat() * fix.toFloat());
	return (a);
}

Fixed Fixed::operator-(Fixed const &fix){
	Fixed a(this->toFloat() - fix.toFloat());
	return (a);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2){
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

// const를 넣으면 좀더 안정감있는 함수가 완선된다.
const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2){
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2){
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

const Fixed& Fixed::max(const Fixed &fix1, const Fixed &fix2){
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

//--------ACCESOR----------
int Fixed::getRawBits(void) const{
	return (value);
}

void Fixed::setRawBits(int const raw){
	value = raw;
}