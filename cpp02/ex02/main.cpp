#include <iostream>
#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// #include <bitset>

// int main(int argc, char** argv) {
// 	if (argc == 1) {
// 		Fixed a;
// 		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 		std::cout << a << std::endl;
// 		std::cout << ++a << std::endl;
// 		std::cout << a << std::endl;
// 		std::cout << a++ << std::endl;
// 		std::cout << a << std::endl;
// 		std::cout << b << std::endl;
// 		std::cout << Fixed::max( a, b ) << std::endl;

// 		Fixed c;
// 		Fixed d( Fixed(8388607) + Fixed(1) );
// 		std::cout << c << std::endl;
// 		std::cout << --c << std::endl;
// 		std::cout << c << std::endl;
// 		std::cout << c-- << std::endl;
// 		std::cout << c << std::endl;
// 		std::cout << d << std::endl;
// 		std::cout << ++d << std::endl;
// 		std::cout << Fixed::max( c, d ) << std::endl;
// 		std::cout << d << std::endl;
// 		return 0;
// 	} else if (argc != 4) {
// 		std::cout << "I desire three arguments or none at all!" << std::endl;
// 		return 2;
// 	}
// 	std::string	numA(argv[1]);
// 	std::string	op(argv[2]);
// 	std::string	numB(argv[3]);
// 	Fixed	a(std::stof(numA));
// 	Fixed	b(std::stof(numB));
// 	Fixed	result;
// 	std::cout << "Num A:	" << a << " in bits: " << std::bitset<32>(a.getRawBits()) << std::endl;
// 	std::cout << "Operator:	" << op << std::endl;
// 	std::cout << "Num B:	" << b << " in bits: " << std::bitset<32>(b.getRawBits()) << std::endl;
// 	if (!op.compare("+")) result.setRawBits(Fixed(a + b).getRawBits());
// 	else if (!op.compare("-")) result.setRawBits(Fixed(a - b).getRawBits());
// 	else if (!op.compare("*")) result.setRawBits(Fixed(a * b).getRawBits());
// 	else if (!op.compare("/")) result.setRawBits(Fixed(a / b).getRawBits());
// 	else if (!op.compare("<")) (a < b) ? result.setRawBits(256) : result.setRawBits(0);
// 	else if (!op.compare(">")) (a > b) ? result.setRawBits(256) : result.setRawBits(0);
// 	else if (!op.compare("<=")) (a <= b) ? result.setRawBits(256) : result.setRawBits(0);
// 	else if (!op.compare(">=")) (a >= b) ? result.setRawBits(256) : result.setRawBits(0);
// 	else if (!op.compare("==")) (a == b) ? result.setRawBits(256) : result.setRawBits(0);
// 	else if (!op.compare("!=")) (a != b) ? result.setRawBits(256) : result.setRawBits(0);
// 	else if (!op.compare("min")) result.setRawBits(Fixed::min(a, b).getRawBits());
// 	else if (!op.compare("max")) result.setRawBits(Fixed::max(a, b).getRawBits());
// 	else {
// 		std::cout << "Unknown operator" << std::endl;
// 		return 2;
// 	}
// 	std::cout << "Result: " << result << " in bits: " << std::bitset<32>(result.getRawBits()) << std::endl;
// 	return 0;
// }