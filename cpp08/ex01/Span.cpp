#include "Span.hpp"

Span::Span(unsigned int N){
    this->_n = N;
}

Span::Span(const Span& other){*this = other;}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
    this->_n = other._n;
    this->_numList = other._numList;
    return *this;
}

Span::~Span(){};


void Span::addNumber(int num)
{
    try{
        if (this->_numList.size() == this->_n)
            throw(STOREDELEMSEXCEPTION());
        this->_numList.push_back(num);
    }
    catch(STOREDELEMSEXCEPTION& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int Span::longestSpan(void)
{
    try{
        if (this->_numList.size() <= 1)
            throw(NOSPANEXCEPTION());

        std::vector<int>::iterator min  = std::min_element(this->_numList.begin(), this->_numList.end());
        std::vector<int>::iterator max = std::max_element(this->_numList.begin(), this->_numList.end());
        return *max - *min;
    }
    catch(NOSPANEXCEPTION& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 1;
}