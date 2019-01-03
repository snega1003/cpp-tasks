#define GROUP_HH
#include <unordered_set>
#include <string>
#include "man.hh"
namespace my {
    
    using my::Man;
    using std::string;
    using std::unordered_set;
    static int group_primary_key = 0;

    class Group {
        public:
            void add(Man const & person)
            {
                database.insert(person);
            }
            Group(string const & n) : first_name(n), id(group_primary_key++) {};
            

        private:
            string group_name;
            int id;
            unordered_set<Man> database;
    };

}
#endif
