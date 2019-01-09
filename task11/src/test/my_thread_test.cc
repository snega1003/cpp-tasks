#include <gtest/gtest.h>
#include <thread>
#include <project/my_thread.hh>
using namespace std;

int my_thr(void*)
{
    cout << "Another thread" << endl;
    return 0;
}
int thr()
{
    cout << "Another thread" << endl;
    return 0;
}
TEST(my_thread, correctness)
{
    my::my_thread t_1(my_thr);
    thread t(thr);
    EXPECT_EQ(t_1.joinable(), t.joinable());
    t_1.join();
    t.join();
    EXPECT_EQ(t_1.joinable(), t.joinable());

}
