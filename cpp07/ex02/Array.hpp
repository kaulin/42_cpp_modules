#pragma once

#include <iostream>

template <typename T>
class Array {
	private:
		uint _size;
		T* _array;
	public:
		// Default Constructor
		Array () : _size(0), _array(nullptr) {};

		// Param Constructor
		Array(uint n) : _size(n), _array(new T[n]) {};

		// Copy Constructor
		Array(const Array& other) : _size(other._size), _array(new T[_size]) { 
			for (uint i = 0; i < _size; i++)
				_array[i] = other._array[i]; 
		};

		// Destructor
		~Array() { delete[] _array; }

		// Exception
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return "Index out of range";
				}
		};

		// Copy Assignment Operator
		Array& operator=(const Array& other) {
			if (this == other)
				return *this;
			delete[] _array;
			_size = other._size;
			_array = new T[_size]; 
			for (uint i = 0; i < _size; i++)
				_array[i] = other._array[i]; 
			return *this;
		};

		// Bracket Operator
		T& operator[](uint i) {
			if (i >= _size)
				throw Array<T>::OutOfBoundsException();
			return _array[i];
		};

		// Size function
		uint size(void) const {return _size; };

		// Print function
		void printItems(void) const {
			for (uint i = 0; i < _size; i++)
				std::cout << _array[i] << "\n";
		}
};