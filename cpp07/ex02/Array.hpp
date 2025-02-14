#pragma once

#include <iostream>
#include <iomanip>

template <typename T>
class Array {
	private:
		unsigned int _size;
		T* _array;
	public:
		// Default Constructor
		Array () : _size(0), _array(new T[0]) {};

		// Param Constructor
		Array(unsigned int n) : _size(n), _array(new T[n]) {};

		// Copy Constructor
		Array(const Array& other) : _size(other._size), _array(new T[other._size]) { 
			for (unsigned int i = 0; i < _size; i++)
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
			if (this == &other)
				return *this;
			delete[] _array;
			_size = other._size;
			_array = new T[_size]; 
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i]; 
			return *this;
		};

		// Bracket Operator
		T& operator[](unsigned int i) {
			if (i >= _size)
				throw Array<T>::OutOfBoundsException();
			return _array[i];
		};

		// Size function
		unsigned int size(void) const {return _size; };

		// Print function
		void printItems(void) const {
			for (unsigned int i = 0; i < _size; i++)
				std::cout << "[" << std::setw(2) << i << "] " << _array[i] << "\n";
		}
};