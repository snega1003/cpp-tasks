#ifndef MY_ITERATOR
#define MY_ITERATOR

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

template <class T, unsigned int N = 1>
class n_stream_iterator : public std::iterator<std::input_iterator_tag, T>
{
    public:
        n_stream_iterator & operator++()
        {
            return *this;
        }
        n_stream_iterator & operator++(int)
        {
            return *this;
        }
        n_stream_iterator & operator*()
        {
            return *this;    
        }
        n_stream_iterator & operator=(T const &val)
        {
            if ( ( i + 1 ) % N == 0) 
            {
                if (!first)
                    (*stream) << separator;
                else 
                    first = !first;
                (*stream) << val;
            }
            i++;
            return *this;
        }
    n_stream_iterator(std::ostream & str, std::string sep = " ")
        : stream(&str), separator(sep), i(0) {}

    private:
        bool first = true;
        std::ostream* stream;
        std::string separator;
        unsigned int i;
};

#endif
