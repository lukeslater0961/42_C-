#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t*	uintptr = reinterpret_cast<uintptr_t*>(&ptr);
	return (*uintptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* dataPtr = reinterpret_cast<Data*>(&raw);
	return (dataPtr);
}
