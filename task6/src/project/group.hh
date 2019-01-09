#ifndef GROUP_HH
#define GROUP_HH
#include <unordered_set>
#include <string>
#include "man.hh"
namespace my {

	using my::Man;
	using std::string;
	using std::unordered_set;
	static int group_key = 0;

	class Group {
	public:
		void add(Man const & person)
		{
			db.insert(person);
		}
		Group(string const & n) : group_name(n), id(group_key++) {};
		unordered_set<Man> data() const { return db; }
		string name() const { return group_name; }

	private:
		string group_name;
		int id;
		unordered_set<Man> db;
	};

}
#endif
