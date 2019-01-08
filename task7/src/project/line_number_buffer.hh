#ifndef LINE_NUMBER_BUFFER_HH
#define LINE_NUMBER_BUFFER_HH

#include <streambuf>
#include <sstream>
#include <iomanip>

class line_number_buffer: public std::streambuf {
        std::streambuf* old; 
        std::string str;
        size_t num;
        bool flag;
    public:
    explicit line_number_buffer(std::streambuf* b): old(b), str(""), num(1), flag(true) {

    }
    protected:
        int_type overflow(int_type c) override
        { 
            if (flag)
            {
                std::stringstream s;
                s << std::setw(5)<< std::right << num++ << ".   ";
                old->sputn(s.str().c_str(), s.str().size());
                flag = false;
            }
            if (c == '\n')
                flag = true;
            return old->sputc(c);  
        }
        std::streamsize xsputn(const char* s, std::streamsize n) override
        {
            str.assign(s, n);
            str = std::to_string(num++) + str;
         	size_t p = str.find("\n");
        	while( p != std::string::npos)
        	{
                std::stringstream stream;
                stream << std::setw(5)<< std::right << num++ << ".   ";
		        str.replace(p, 1, std::string("\n") + stream.str());

	    	    p = str.find("\n", p + 1);
	        }
            return old->sputn(str.c_str(), str.size());
        }
};

#endif
