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

	// Getters
	int		getRawBits(void) const;
	// Setters
	void	setRawBits(int const raw);
	// Other
	float	toFloat(void) const;
	int		toInt(void)const;
};

// Other Operators
std::ostream& operator<< (std::ostream& os, const Fixed& fixed);

#endif
