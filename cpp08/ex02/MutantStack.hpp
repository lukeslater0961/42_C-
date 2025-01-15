#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

template <typename T>
class MutantStack{
    public:
        typedef typename    std::deque::iterator        const_iterator;
        typedef typename    std::deque::const_iterator  const_iterator; 

        MutantStack(){}

        MutantStack(cosnt MutantStack& other){stack(other.stack);}

        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                this->stack = other.stack
            return (*this);
        }

        ~MutantStack(){};

        void    push(const T& value){stack.push(value);}
        void    pop(){stack.pop();}
        T&      top(){return stack.top();}
        size_t  size(){return stack.size();}
        bool    empty(){return stack.empty();}

    private:
        std::stack <T> stack;

}

#endif 