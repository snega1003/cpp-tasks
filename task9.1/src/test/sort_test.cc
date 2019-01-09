#include "project/sort.hh"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>

TEST(Sort, merge)
{
    {
        std::vector<int> a = {1,4,2,3,4};
        std::vector<int> b = {1,2,3,4,4};
        mergeSortRecursive(a.begin(), a.end());
        EXPECT_EQ(a, b);
    }
    {
        std::vector<int> a = {1,2,3,4,5};
        std::vector<int> b = {1,2,3,4,5};
        mergeSortRecursive(a.begin(), a.end());
        EXPECT_EQ(a, b);
    }
    {
        std::vector<int> a = {9,8,7,6,1};
        std::vector<int> b = {1,6,7,8,9};
        mergeSortRecursive(a.begin(), a.end());
        EXPECT_EQ(a, b);
    }
    {
        std::vector<int> a = {1,2,3,4,5,6,7,8,9};
        std::vector<int> b = {1,2,3,4,5,6,7,8,9};
        for (int i = 0; i < 10; i++)
        {
            std::shuffle(a.begin(), a.end(), std::random_device());
            mergeSortRecursive(a.begin(), a.end());
            EXPECT_EQ(a, b);
        }
    }
    
}
