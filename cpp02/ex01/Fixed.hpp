#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_bits = 8;
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
	// Other Operators
	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

	// Getters
	int		getRawBits(void) const;
	// Setters
	void	setRawBits(int const raw);
	// Other
	float	toFloat(void) const;
	int		toInt(void)const;
};

#endif
