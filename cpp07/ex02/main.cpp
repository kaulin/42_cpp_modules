#include "Array.hpp"

int main(void) {
	std::cout << "Testing empty int array:\n";
	Array<int> empty;
	empty.printItems();

	std::cout << "\nTesting array with ints:\n";
	Array<int> ints(4);
	ints[2] = 2;
	ints.printItems();
	
	std::cout << "\nTesting copy constructor with previous int array:\n";
	Array<int> intsCopy(ints);
	intsCopy[1] = 6;
	intsCopy.printItems();

	std::cout << "\nTesting array with chars:\n";
	Array<char> chars(12);
	chars[0] = 'H';
	chars[1] = 'E';
	chars[2] = 'L';
	chars[3] = 'L';
	chars[4] = 'O';
	chars[5] = ' ';
	chars[6] = 'W';
	chars[7] = 'O';
	chars[8] = 'R';
	chars[9] = 'L';
	chars[10] = 'D';
	chars[11] = '!';
	chars.printItems();

	std::cout << "\nTesting array with strings:\n";
	Array<std::string> strings(12);
	strings[0] = "All";
	strings[1] = "your";
	strings[2] = "base";
	strings[3] = "are";
	strings[4] = "belong";
	strings[5] = "to";
	strings[6] = "us";
	strings[11] = "!";
	strings.printItems();

	std::cout << "\nTesting array overflow:\n";
	Array<uint> uints(1);
	try {
		uints[0] = 3;
		uints[1] = 6;
		uints[2] = 9;
	} catch (std::exception& exception) {
		std::cout << "Caught exception '" << exception.what() << "'\n";
	}
	uints.printItems();

	return 0;
}