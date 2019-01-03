#include <gtest/gtest.h>
#include <sstream>
#include "message.h"

TEST(Message, correctness)
{
	std::stringstream str;
	mess::message(str, "Hello, %", "world!");
	EXPECT_EQ(str.str(), "Hello, world!");
	str.str("");
	mess::message(str, "Hello, %%%%%%", "w", "o", "r", "l", "d", "!");
	EXPECT_STREQ(str.str().c_str(), "Hello, world!");
	str.str("");
	mess::message(str, "Hello, %%%%%%%%", "w", "o", "r", "l", "d", "!");
	EXPECT_STREQ(str.str().c_str(), "Hello, world!%%");
	str.str("");
	mess::message(str, "Hello, %%", "w", "o", "r", "l", "d", "!");
	EXPECT_STREQ(str.str().c_str(), "Hello, wo");
}
