#include <iostream>
#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// Fixed	e(6.66f);
	// Fixed	f(42.42f);
	// Fixed	g(e);
	// Fixed	h(3.9980467557907104f);
	// std::cout << "g is " << g << std::endl;
	// g.setRawBits(f.getRawBits());
	// std::cout << "g is " << g << std::endl;
	// std::cout << "h is " << h.toFloat() << std::endl;
	return 0;
}