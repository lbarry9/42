/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:09:40 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/16 18:20:53 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array<T> &copy);
		~Array(void);
		Array<T>		&operator=(const Array<T> &copy);
		T 				&operator[](unsigned int i);
		const T			&operator[](const unsigned int i) const;
		unsigned int	size() const;

	private:
		T				*_arr;
		unsigned int	_size;
};

template <typename T>
Array<T>::Array(void) : _arr(new T[0]()), _size(0)
{
	std::cout << "Array default constructor called" << std::endl;
}

//  Construction with an unsigned int n as a parameter:
// Creates an array of n elements initialized by default.
template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n)
{
	std::cout << "Array parametrised constructor called" << std::endl;
}

// copy constructor
template <typename T>
Array<T>::Array(const Array &copy) : _arr(new T[copy._size]()), _size(copy._size)
{
	std::cout << "Copy constructor called" << std::endl;
	if (copy._size == 0)
		return;
	for (unsigned int i = 0; i < copy._size; i++)
		_arr[i] = copy._arr[i];
}

// copy assignment operator overload
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
	std::cout << "Array copy assignment operator overload used" << std::endl;
	if (this != &copy && copy._size > 0)
	{
		delete[] _arr;
		_arr = new T[copy._size]();
		_size = copy._size;
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = copy._arr[i];
	}
	return (*this);
}

// destructor - delete (free) array
template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array destructor called" << std::endl;
	delete [] _arr;
}

// [] operator override
// returns reference to element at index and so works as a getter & setter, allowing value to be modified
template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size || i < 0)
		throw std::out_of_range("Index is out of bounds");
	return (_arr[i]);
}

// const [] operator override - readonly
template <typename T>
const T &Array<T>::operator[](const unsigned int i) const
{
	if (i >= _size || i < 0)
		throw std::out_of_range("Index is out of bounds");
	return (_arr[i]);
}

// size accessor
template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
