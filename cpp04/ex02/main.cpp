#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int ARRAY_SIZE = 10;
	const AAnimal* animals[ARRAY_SIZE];

    for (int k = 0; k < ARRAY_SIZE / 2; ++k) {
        animals[k] = new Dog();
    }
    for (int k = ARRAY_SIZE / 2; k < ARRAY_SIZE; ++k) {
        animals[k] = new Cat();
    }
    for (int k = 0; k < ARRAY_SIZE; ++k) {
        std::cout << animals[k]->getType() << " ";
        animals[k]->makeSound();
    }

    for (int k = 0; k < ARRAY_SIZE; ++k) {
        delete animals[k];
    }

    return 0;
}
