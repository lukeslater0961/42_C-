#ifndef	WHATEVER_HPP
#define WHATEVER_HPP

#include <utility>

template <typename T>
void swap(T &num1, T &num2)
{
	std::swap(num1, num2);
}

template <typename T>
T	min(T num1, T num2)
{
	return ((num1 > num2) ? num2: num1);
}

template <typename T>
T	max(T num1, T num2)
{
	return ((num1 > num2) ? num1: num2);
}

#endif
