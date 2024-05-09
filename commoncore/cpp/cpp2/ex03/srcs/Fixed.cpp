#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int value) {
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &other) {
	_value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const {
	return _value > other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _value >= other._value;
}

bool Fixed::operator<(const Fixed &other) const {
	return _value < other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return _value == other._value;
}

Fixed Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	_value++;
	return tmp;
}

Fixed Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	_value--;
	return tmp;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &x, Fixed &y) {
	return x < y ? x : y;
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y) {
	return x < y ? x : y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y) {
	return x > y ? x : y;
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y) {
	return x > y ? x : y;
}