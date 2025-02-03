#include "Serializer.hpp"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <name for data packet>\n";
		return 1;
	}
	Data data;
	uintptr_t serialized_ptr;
	Data* deserialized_ptr;

	data.name = argv[1];

	std::cout <<  "TESTING pointer serialization!\n";
	std::cout << "  Pointer ["<< &data << "] contains data with name: " << data.name << "\n";
	serialized_ptr = Serializer::serialize(&data);
	std::cout << "  Serialized pointer ["<< serialized_ptr << "]\n";
	deserialized_ptr = Serializer::deserialize(serialized_ptr);
	std::cout << "  Deserialized pointer to data packet ["<< deserialized_ptr << "]\n";
	std::cout << "OUTCOME: " << ((&data == deserialized_ptr) ? "OK - pointers match\n" : "KO - pointers don't match\n");
	return 0;
}