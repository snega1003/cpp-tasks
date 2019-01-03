#include <iostream>
#include "ostream_guard.h"
#include "my_array.h"

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
