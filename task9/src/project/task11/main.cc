#include <iostream>
#include <chrono>
#include <project/my_thread.hh>
using namespace std;
 
int fun(void*) {
   cout << "Another thread" << endl;
    return 0;
}
 
int main() {
    
    my::my_thread t(fun);
    cout << "Before starting, joinable: " << t.joinable() << '\n';
    t.join();
    cout << "After starting, joinable: " << t.joinable() << '\n';
 
}
