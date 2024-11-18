#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

// Parametric constructors
Fixed::Fixed(const int value) : _value(value) {
	std::cout << "Int constructor called" << std::endl;
	_value = (_value << Fixed::_fracBits);
}
Fixed::Fixed(const float value) : _value(value) {
	std::cout << "Float constructor called" << std::endl;
	_value = (int)roundf(value * (1 << Fixed::_fracBits));
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) return *this;
	_value = other._value;
	return *this;
}

// Comparison Operators
bool	Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool	Fixed::operator>(const Fixed& other) const { return other < *this; }
bool	Fixed::operator>=(const Fixed& other) const { return !(*this < other); }
bool	Fixed::operator<=(const Fixed& other) const { return !(*this > other); }
bool	Fixed::operator==(const Fixed& other) const {return _value == other._value; }
bool	Fixed::operator!=(const Fixed& other) const {return !(*this == other); }

// Arithmetic Operators
Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	result;

	result.setRawBits(_value + other._value);
	return result;
}
Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	result;

	result.setRawBits(_value - other._value);
	return result;
}
Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;

	result.setRawBits((_value * other._value) >> Fixed::_fracBits);
	return result;
}
Fixed	Fixed::operator/(const Fixed& other) const {
	return Fixed(Fixed(toFloat() / other.toFloat()));
}

// Increment Operators
Fixed&	Fixed::operator++() {
	_value++;
	return *this;
}
Fixed	Fixed::operator++(int) {
	Fixed	pre(*this);

	_value++;
	return pre;
}
Fixed&	Fixed::operator--() {
	_value--;
	return *this;
}
Fixed	Fixed::operator--(int) {
	Fixed	pre(*this);

	_value--;
	return pre;
}

// Getters
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

// Setters
void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

// Other
int	Fixed::toInt() const {
	return (_value >> Fixed::_fracBits); 
}
float	Fixed::toFloat() const {
	return ((float)_value / (float)(1 << Fixed::_fracBits));
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// Insertion Operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}