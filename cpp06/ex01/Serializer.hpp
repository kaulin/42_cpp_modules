#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer {
	private:
		// Default Constructor
		Serializer();
		// Copy Constructor
		Serializer(const Serializer& other);
		// Destructor
		~Serializer();
		// Copy Assignment Operator
		Serializer& operator=(const Serializer& other);
	public:
		static unsigned intptr_t serialize(Data* ptr);
		static Data* deserialize(unsigned intptr_t raw);
};