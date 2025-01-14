#include  "Array.hpp"


int main( void )
{
	try {
        Array<int> defaultArray;
        std::cout << "Default array size: " << defaultArray.size() << std::endl;
        Array<int> defaultArray2;
         defaultArray2 = defaultArray;
        std::cout << "assigning default arrays = default array2 size = " << defaultArray2.size()  <<std::endl;

        Array<int> arrayWithSize(5);
        std::cout << "Array with size 5 initialized." << std::endl;

        for (unsigned int i = 0; i < arrayWithSize.size(); ++i) {
            arrayWithSize[i] = i * 2; // Use subscript operator to set values
        }

        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < arrayWithSize.size(); ++i) {
            std::cout << arrayWithSize[i] << " "; // Use subscript operator to get values
        }
        std::cout << std::endl;

        Array<int> copiedArray(arrayWithSize);
        std::cout << "Copied array elements: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        copiedArray[0] = 100;
        std::cout << "Modified copied array first element: " << copiedArray[0] << std::endl;
        std::cout << "Original array first element after modification: " << arrayWithSize[0] << std::endl;

        std::cout << "Attempting out-of-bounds access..." << std::endl;
        std::cout << arrayWithSize[10] << std::endl; // This should throw an exception

    } catch (const Array<int>::OutofBoundException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";

        std::cout << "String array elements: ";
        for (unsigned int i = 0; i < stringArray.size(); ++i) {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Accessing out-of-bounds index in string array..." << std::endl;
        std::cout << stringArray[5] << std::endl;

    } catch (const Array<std::string>::OutofBoundException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Array<int> array1(5);
        for (unsigned int i = 0; i < array1.size(); ++i) {
            array1[i] = i * 2;
        }

        std::cout << "Array 1 elements: ";
        for (unsigned int i = 0; i < array1.size(); ++i) {
            std::cout << array1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> array2;
        array2 = array1;

        std::cout << "Array 2 (after assignment) elements: ";
        for (unsigned int i = 0; i < array2.size(); ++i) {
            std::cout << array2[i] << " ";
        }
        std::cout << std::endl;

        array2[0] = 100;
        std::cout << "Array 2 after modification: ";
        for (unsigned int i = 0; i < array2.size(); ++i) {
            std::cout << array2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Array 1 (should remain unchanged): ";
        for (unsigned int i = 0; i < array1.size(); ++i) {
            std::cout << array1[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Checking out of bounds..." << std::endl;
        std::cout << array1[13] << std::endl;
    } catch (const Array<int>::OutofBoundException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
