#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	static const int	_fracBits = 8;
	int					_value;
public:
	// Default Constructor
	Fixed();
	// Parametric Constructors
	Fixed(const int);
	Fixed(const float);
	// Destructor
	~Fixed();
	// Copy Constructor
	Fixed(const Fixed& other);

	// Copy Assignment Operator
	Fixed& operator=(const Fixed& other);

	// Comparison Operators
	bool	operator==(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;

	// Arithmetic Operators
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	// Increment Operators
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	// Getters
	int		getRawBits(void) const;
	// Setters
	void	setRawBits(int const raw);
	// Other
	float	toFloat(void) const;
	int		toInt(void)const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

// Insertion Operator
std::ostream& operator<< (std::ostream& os, const Fixed& fixed);

#endif
