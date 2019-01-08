#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include "project/my_stream.hh"
#include <algorithm>
using namespace std;

int main()
{
    istringstream str("0.1 0.2 0.3 0.4");
    partial_sum(istream_iterator<double>(str),
                      istream_iterator<double>(),
                      my_stream_iterator<double, 3>(cout, " "));
    return 0;
}
