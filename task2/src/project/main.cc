#include "my_vector.hh"
#include <fstream>
#include <algorithm>
#include <random>
#include <iostream>

int main()
{
	my_vector::vector<std::ofstream> a;
	a.push_back(std::ofstream("a"));
	a.push_back(std::ofstream("b"));
	a.push_back(std::ofstream("c"));
	std::shuffle(a.begin(), a.end(), std::random_device());
	my_vector::vector<std::ofstream> b;
	a[0] << 1;
	a[1] << 2;
	a[2] << 3;
	a.swap(b);
	std::cout << b.size();
}
