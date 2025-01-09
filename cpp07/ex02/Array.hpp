#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <class T>
class Array{
	public:
	
		Array():_array(NULL),  _size(0){};
		Array(unsigned int n)
		{
			_array = new T[n];
			this->SetSize(n);	
		}

		Array (const Array &other): _size(other._size)
		{
			if (_size > 0)
			{
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
		}

		class OutofBoundException
		{
			public:
				const char* what() const throw()
				{
					return ("Index is out of bounds");
				}
		};

		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw(OutofBoundException());
			return this->_array[index] ;
		}

		~Array()
		{
			if (this->_array != NULL)
				delete[] _array;
		}

		unsigned int size(){return _size;};
		void SetSize(unsigned int n){this->_size = n;};

	private:

		T				*_array;
		unsigned int	_size;

};

#endif
