#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
            MutantStack()
            {
                std::stack<T>(); 
            };

            MutantStack(const MutantStack<T>& other)
            {
                std::stack<T> stack(other);
            }

            MutantStack& operator=(const MutantStack<T>& other)
            {
                if (this != &other)
                {
                    std::stack<T> stack(other);
                }

                return (*this);
            }

            ~MutantStack(){};

            typedef typename std::stack<T>::container_type::iterator iterator;
            iterator begin(void){return this->c.begin();};
            iterator end(void){return this->c.end();};

            typedef typename std::stack<T>::container_type::const_iterator const_iterator;
            iterator begin(void) const {return this->c.begin();};
            iterator end(void) const {return this->c.end();};

            typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
            iterator rbegin(void){return this->c.rbegin();};
            iterator rend(void){return this->c.rend();};

            typedef typename std::stack<T>::container_type::const_reverse_iterator reverse_const_iterator;
            iterator rbegin(void) const {return this->c.rbegin();};
            iterator rend(void) const {return this->c.rend();};
};

#endif
