#include "Span.hpp"


int main(void)
{
	Span sp = Span(8);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Spans before______________" <<std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Spans after______________" <<std::endl;
    std::vector<int> numbers(3);
    numbers[0] = 60;
    numbers[1] = 70;
    numbers[2] = 80;
	sp.addMultipleNumbers(numbers.begin(), numbers.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
