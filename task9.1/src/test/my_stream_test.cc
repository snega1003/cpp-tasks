#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include "project/my_stream.hh"
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
using namespace std;

TEST(NTH_ITERATOR, correctness)
{
    vector<int> data({1,2,3,4,5,6,7,8,9});
    ostringstream out;

    n_stream_iterator<int, 1> a(out, " ");
    copy(data.data(), data.data()+9, a);
    EXPECT_EQ(out.str(), "1 2 3 4 5 6 7 8 9");
    out.str("");

    n_stream_iterator<int, 2> a2(out, " ");
    copy(data.data(), data.data()+9, a2);
    EXPECT_EQ(out.str(), "2 4 6 8");
    out.str("");

    n_stream_iterator<int, 3> a3(out, " ");
    copy(data.data(), data.data()+9, a3);
    EXPECT_EQ(out.str(), "3 6 9");
}
