#include "Array.hpp"

void testWithArgs(int argc, char** argv) {
	std::cout << "Testing Array class on arg array: \n";
	Array<std::string> args(argc - 1);
	for (int i = 1; i < argc; i++)
		args[i - 1] = std::string(argv[i]);
	args.printItems();

	std::cout << "\nTesting copy constructor with arg array: \n";
	Array<std::string> argsCopy1(args);
	for (uint i = 0; i < argsCopy1.size(); i++)
		if (i % 2) argsCopy1[i] = "CAT";
	std::cout << "Original \n";
	args.printItems();
	std::cout << "Copy1\n";
	argsCopy1.printItems();

	std::cout << "\nTesting copy assignment operator with arg array copy: \n";
	Array<std::string> argsCopy2 = argsCopy1;
	for (uint i = 0; i < argsCopy2.size(); i++)
		if (i % 2 == 0) argsCopy2[i] = "MOUSE";
	std::cout << "Original \n";
	args.printItems();
	std::cout << "Copy1\n";
	argsCopy1.printItems();
	std::cout << "Copy2\n";
	argsCopy2.printItems();

	std::cout << "\nTesting array overflow with arg array:\n";
	try {
		args[argc] = "!?!?!";
	} catch (std::exception& exception) {
		std::cout << "Caught exception '" << exception.what() << "'\n";
	}
}

void testWithoutArgs() {
	std::cout << "Testing empty int array:\n";
	Array<int> empty;
	empty.printItems();

	std::cout << "\nTesting array of ints:\n";
	Array<int> ints(4);
	ints[2] = 2;
	ints.printItems();
	
	std::cout << "\nTesting copy constructor with previous int array:\n";
	Array<int> intsCopy(ints);
	intsCopy[1] = 6;
	ints[0] = 8;
	std::cout << "Copy:\n";
	intsCopy.printItems();
	std::cout << "Original:\n";
	ints.printItems();

	std::cout << "\nTesting array of chars:\n";
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

	std::cout << "\nTesting array of strings:\n";
	Array<std::string> strings(12);
	strings[0] = "All";
	strings[1] = "your";
	strings[2] = "base";
	strings[3] = "are";
	strings[4] = "belong";
	strings[5] = "to";
	strings[6] = "us";
	strings[7] = "!";
	strings.printItems();
	
	std::cout << "\nTesting assignment operator with previous string array:\n";
	Array<std::string> stringsCopy = strings;
	stringsCopy[7] = "?";
	stringsCopy[11] = "";
	strings[7] = "!";
	strings[8] = "!";
	strings[9] = "!";
	strings[10] = "!";
	strings[11] = "!";
	std::cout << "Copy:\n";
	stringsCopy.printItems();
	std::cout << "Original:\n";
	strings.printItems();

	std::cout << "\nTesting array overflow with previous string aray:\n";
	try {
		strings[12] = "!?!?!";
	} catch (std::exception& exception) {
		std::cout << "Caught exception '" << exception.what() << "'\n";
	}
}

int main(int argc, char **argv) {
	if (argc > 1)
		testWithArgs(argc, argv);
	else testWithoutArgs();
	return 0;
}