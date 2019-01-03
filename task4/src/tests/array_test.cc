#include <gtest/gtest.h>
#include "project/my_array.hh"
#include <iostream>

TEST(my_array, correctness)
{
	my_array<int> a(2, 3);
	my_array<int> b(2, 3);
	a(0, 0) = 1;
	a(0, 1) = 2;
	a(0, 2) = 3;
	a(1, 0) = 4;
	a(1, 1) = 5;
	a(1, 2) = 6;
	b(0, 0) = 1;
	b(0, 1) = 2;
	b(0, 2) = 3;
	b(1, 0) = 4;
	b(1, 1) = 5;
	b(1, 2) = 6;
	{
		auto c = a + b;
		EXPECT_EQ(c(0, 0), a(0, 0) + b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) + b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) + b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) + b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) + b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) + b(1, 2));
	}
	{
		auto c = a - b;
		EXPECT_EQ(c(0, 0), a(0, 0) - b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) - b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) - b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) - b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) - b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) - b(1, 2));
	}
	{
		auto c = a * b;
		EXPECT_EQ(c(0, 0), a(0, 0) * b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) * b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) * b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) * b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) * b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) * b(1, 2));
	}
	{
		auto c = a / b;
		EXPECT_EQ(c(0, 0), a(0, 0) / b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) / b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) / b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) / b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) / b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) / b(1, 2));
	}
	{
		auto c = a | b;
		EXPECT_EQ(c(0, 0), a(0, 0) | b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) | b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) | b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) | b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) | b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) | b(1, 2));
	}
	{
		auto c = a & b;
		EXPECT_EQ(c(0, 0), a(0, 0) & b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) & b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) & b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) & b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) & b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) & b(1, 2));
	}
	{
		auto c = a ^ b;
		EXPECT_EQ(c(0, 0), a(0, 0) ^ b(0, 0));
		EXPECT_EQ(c(0, 1), a(0, 1) ^ b(0, 1));
		EXPECT_EQ(c(0, 2), a(0, 2) ^ b(0, 2));
		EXPECT_EQ(c(1, 0), a(1, 0) ^ b(1, 0));
		EXPECT_EQ(c(1, 1), a(1, 1) ^ b(1, 1));
		EXPECT_EQ(c(1, 2), a(1, 2) ^ b(1, 2));
	}
	{
		auto c = !a;
		EXPECT_EQ(c(0, 0), !a(0, 0));
		EXPECT_EQ(c(0, 1), !a(0, 1));
		EXPECT_EQ(c(0, 2), !a(0, 2));
		EXPECT_EQ(c(1, 0), !a(1, 0));
		EXPECT_EQ(c(1, 1), !a(1, 1));
		EXPECT_EQ(c(1, 2), !a(1, 2));
	}
}
