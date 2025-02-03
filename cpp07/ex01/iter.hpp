#pragma once

#include <iostream>

template <typename T> void iter(T* arr, int len, void (*f)(T)) {
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T> void iter(T* arr, int len, void (*f)(const T&)) {
	for (int i = 0; i < len; i++)
		f(arr[i]);
}