#include <iostream>
#include "project/ostream_guard.hh"
//#include "my_array.hh"
using namespace std;

void print_hex(int i) {
	my_guard g(cout);
	cout << hex << i;
}
int main(){
	print_hex(16);
	cout << endl << 16 << endl;
	return 0;
}
