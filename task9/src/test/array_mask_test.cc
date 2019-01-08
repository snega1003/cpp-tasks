#include <gtest/gtest.h>
#include "project/my_array.hh"
#include <iostream>

struct array_param
{
	my_array<bool> input;
	my_array<int> expected_output;
};

class array_mask_test : public ::testing::TestWithParam<array_param> {};

INSTANTIATE_TEST_CASE_P(
	_,
	array_mask_test,
	::testing::Values(
	array_param{
	my_array<bool>(std::vector<std::vector<bool> >({ { false, false, false }, { true, true, true } })),
	my_array<int>({ { 1, 2, 3 }, { 4, 4, 4 } })
},
array_param{
	my_array<bool>(std::vector<std::vector<bool> >({ { true, true, true }, { true, true, true } })),
	my_array<int>({ { 4, 4, 4 }, { 4, 4, 4 } })
},
array_param{
		my_array<bool>(std::vector<std::vector<bool> >({ { false, false, false }, { false, false, false } })),
		my_array<int>({ { 1, 2, 3 }, { 4, 5, 6 } })
	}
	)
		);

	TEST_P(array_mask_test, _)
	{
		array_param param = GetParam();
		my_array<bool> mask = param.input;
		my_array<int> out = param.expected_output;
		my_array<int> a(2, 3);
		a(0, 0) = 1;
		a(0, 1) = 2;
		a(0, 2) = 3;
		a(1, 0) = 4;
		a(1, 1) = 5;
		a(1, 2) = 6;
		my_array<int> b(a);

		a(mask) = 4;
		EXPECT_EQ(a, out);
	}
