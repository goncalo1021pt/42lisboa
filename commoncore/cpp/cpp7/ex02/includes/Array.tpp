#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::~Array()  {
	delete []_array;
}

template <typename T>
Array<T>::Array(const Array &other) {
	if (this != &other)
		*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete []_array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int ctd = 0; ctd < _size; ctd++) 
			_array[ctd] = other._array[ctd];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw Array::IndexOutOfBoundException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw() {
	return "Index out of bound";
}