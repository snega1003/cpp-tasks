#include "project/rotate.hh"
#include <iostream>
using namespace std;

int main() {
	vector<double> vector({ 10, 100 });
	int i;
	cout << "i is number of rotations.\n i must be one of [1, 2, 3, 4, -1, -2, -3, 0, -4]\n so, your i is ";
	cin >> i;
	cout << endl;
	my::rotate(vector, i);
	cout << "rotated vector:" << vector[0] << " " << vector[1] << endl;

}
