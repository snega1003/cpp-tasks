#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include "project/trait.hh"
#include "project/group.hh"
#include "project/man.hh"

TEST(Traits, size)
{
	using namespace my;

	Man m("bob", "bobich");
	EXPECT_EQ(trait<Man>::size(m), 14);

	Group g("nameofgroup");
	g.add(m);
	EXPECT_EQ(trait<Group>::size(g), 55);

	std::cout << trait<Group>::size(g) << std::endl;
	g.add(Man("bob", "bobich"));
	EXPECT_EQ(trait<Group>::size(g), 69);
}
