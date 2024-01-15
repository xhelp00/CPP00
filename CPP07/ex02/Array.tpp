#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_ptr = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	_ptr = new T[size];
	_size = size;
}

template <typename T>
Array<T>::Array(Array const &other)
{
	_ptr = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		_ptr[i] = other._ptr[i];
	_size = other.size();
}

template <typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
	if (this != *other)
	{
		_ptr = new T[other.size()];
		for (int i = 0; i < other.size(); i++)
			_ptr[i] = other[i];
		_size = other.size();
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _ptr;
}


template <typename T>
std::size_t Array<T>::size() const
{
	return this->_size;
}

template <typename T>
T& Array<T>::operator[](std::size_t index)
{
	if (index < 0 || index >= this->_size)
		throw InvalidIndexException();
	return _ptr[index];
}