#ifndef MAN_HH
#define MAN_HH

#include <string>

namespace my {
    using std::string;
    
    static int primary_key = 0;

    class Man {
        public:
            Man(string const & n, string const & s) :
                first_name(n), last_name(s), id(primary_key++) {};
        
        string to_string() const {
            return last_name + " " + first_name;
        }

        bool operator<(Man const & other) {
            return to_string() < other.to_string();
        }
        int get_id() const {
            return id;
        }
        private:
            string first_name;
            string last_name;
            int id;
    };

}

template <> 
struct std::hash<my::Man>
{
    typedef size_t result_type;
    typedef my::Man argument_type;
    result_type operator()(const argument_type & x) const
    {
        return static_cast<result_type>(x.get_id());
    }

};
#endif
