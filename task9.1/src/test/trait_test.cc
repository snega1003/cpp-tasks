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
    
    Man m("aaa", "bbb");
    EXPECT_EQ(trait<Man>::size(m), 11);

    Group g("NAME");
    g.add(m);
    EXPECT_EQ(trait<Group>::size(g), 79);

    std::cout << trait<Group>::size(g) << std::endl;    
    g.add(Man("aaa", "bbb"));
    EXPECT_EQ(trait<Group>::size(g), 90);
}
