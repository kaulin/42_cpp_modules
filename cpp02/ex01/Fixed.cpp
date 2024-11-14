#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}
// Parametric constructors
Fixed::Fixed(const int value) : _value(value) {
	std::cout << "Int constructor called" << std::endl;

}
Fixed::Fixed(const float value) : _value(value) {
	std::cout << "Float constructor called" << std::endl;

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
	if (this == &other) return *this;
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}
std::ostream& Fixed::operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
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
float	Fixed::toFloat() const {
}
int	Fixed::toInt() const {
	return _value
}
