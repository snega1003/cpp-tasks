#include <gtest/gtest.h>
#include "project/ostream_guard.hh"
#include <iostream>

using namespace std;

void print_hex(int i) {
	my_guard g(cout);
	cout << hex << i;
}

TEST(Guard, correctness)
{
	ios_base::fmtflags flags = cout.flags();
	{
		my_guard a(cout);
		cout.width(10);
		cout.fill('x');
		cout << hex;
		EXPECT_NE(flags, cout.flags());
	}
	EXPECT_EQ(flags, cout.flags());
}
