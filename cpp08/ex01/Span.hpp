#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
class Span{
    public:

        Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span& other);
        ~Span();

        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();

        class NOSPANEXCEPTION{
            public:
                const char *what() throw()
                {
                    return "No Span can be found" ;
                }
        };

        class STOREDELEMSEXCEPTION{
            public:
                const char *what() throw()
                {
                    return "There are already N elements stored";
                }
        };

    private:
        unsigned int _n;
        std::vector<int> _numList;

};

#endif