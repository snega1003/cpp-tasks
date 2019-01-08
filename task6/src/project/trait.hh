#ifndef SIZE_HH
#define SIZE_HH

#include "man.hh"
#include "group.hh"

namespace my{
    
    template <class T>
    struct trait;

    template <>
    struct trait<Man> {
        typedef size_t res_type;
        typedef Man arg_type;
        static res_type size(arg_type const & person) 
        {
            return person.to_string().size()*sizeof(char) + sizeof(int);
        } 
    };

    template <>
    struct trait<Group> {
        typedef size_t res_type;
        typedef Group arg_type;
        static res_type size(arg_type const & group) 
        {
            size_t sum;
            for (auto s : group.data())
            {
                sum += trait<Man>::size(s);
            }
            sum += sizeof(size_t) + sizeof(unordered_set<Man>) + group.name().size()*sizeof(char);
            return sum;
        } 
    };
}

#endif
