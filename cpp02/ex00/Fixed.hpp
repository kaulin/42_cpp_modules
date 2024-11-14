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
};

#endif
