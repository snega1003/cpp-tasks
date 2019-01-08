#include <iostream>
#include <algorithm>
#include <project/line_number_buffer.hh>

int main()
{
    auto oldbuf = std::cout.rdbuf();

    line_number_buffer buf{oldbuf};
    std::cout.rdbuf(&buf);

    std::cout << std::cin.rdbuf() << std::endl;

    std::cout.rdbuf(oldbuf);
    return 0;
}
