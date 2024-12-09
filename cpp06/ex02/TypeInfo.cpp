#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>


Base* generate(void)
{
	srand(time(0));
	int	value = rand() % 3;
	switch (value) {
		case 0:
			return new A();
		break;
		case 1:
			return new B();
		break;
		case 2:
			return new C();
		default:
			break;
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
}

void	identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "Type is C" << std::endl;

}

int	main()
{
	Base* base = generate();

	identify(base);
	identify(*base);
}
