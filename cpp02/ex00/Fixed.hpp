#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

class Fixed {
private:
	static const int	_fracBits = 8;
	int					_value;
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
	void	setRawBits(const int raw);
	// Other
};

#endif
