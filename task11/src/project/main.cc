#include <iostream>
#include <chrono>
#include "my_thread.hh"
using namespace std;
 
int fun(void*) {
   cout << "Another thread" << endl;
    return 0;
}
 
int main() {
    
    my::my_thread t(fun);
    cout << "Before. Joinable: " << t.joinable() << '\n';
    t.join();
    cout << "After. Joinable: " << t.joinable() << '\n';
 
}
