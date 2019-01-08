#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>

#include <algorithm>
#include "man.h"
#include <unordered_map>
#include <unordered_set>
#include "project/trait.hh"

using namespace std;

int main()
{
	unordered_set<my::Man> days_off;
	unordered_map<my::Man, size_t> salary;
	
	my::Man m("bob", "bobich");
	cout << my::trait<my::Man>::size(m) << endl;

	my::Group g("nameofgroup");
	cout << my::trait<my::Group>::size(g) << endl;

	g.add(m);
	cout << my::trait<my::Group>::size(g) << endl;


	return 0;
}
