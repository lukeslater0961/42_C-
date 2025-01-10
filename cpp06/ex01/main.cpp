#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <cassert>

int main()
{
    Data* hello = new Data;
	hello->num = 42;     
    uintptr_t serialized = Serializer::serialize(hello);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer address: " << deserialized << std::endl;
    
    // Test 1: Ensure the deserialized pointer matches the original pointer.
    assert(deserialized == hello);  
	std::cout << "Test 1 passed: Deserialized pointer matches original pointer." << std::endl;

    // Test 2: Verify the object data is not changed after serialization and deserialization.
    assert(deserialized->num == hello->num);  // Ensure the value has not been modified.
    std::cout << "Test 2 passed: Object data is preserved." << std::endl;
	
	Data* nullData = NULL;
    uintptr_t nullSerialized = Serializer::serialize(nullData);
    Data* nullDeserialized = Serializer::deserialize(nullSerialized);
    
    // Test 3: Ensure the deserialized null pointer is still null.
    assert(nullDeserialized == NULL);
    std::cout << "Test 3 passed: Null pointer serialization and deserialization work." << std::endl;

	delete hello;
}
