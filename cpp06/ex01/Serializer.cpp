#include "Serializer.hpp"

// Default Constructor
Serializer::Serializer () {}
// Copy Constructor
Serializer::Serializer(const Serializer& other) { (void)other; }
// Destructor
Serializer::~Serializer() {}
// Copy Assignment Operator
Serializer& Serializer::operator=(const Serializer& other) { 
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}