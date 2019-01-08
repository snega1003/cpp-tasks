#ifndef MY_THREAD_HH
#define MY_THREAD_HH
#include <cstddef>
#include <utility>
#include <sched.h> 
#include <signal.h>
#include <sys/wait.h> 

namespace my{
    class my_thread {
    public:
        my_thread() = default;    
        my_thread(my_thread&& other);    
        my_thread(int(*fun)(void*));
        my_thread(const my_thread & other) = delete;    
        ~my_thread();
        bool joinable() const;
        size_t get_id() const;
        void join() const;
        void swap(my_thread & other);
    private:
        mutable pid_t _id = 0;
        int    _flags;
        char * _stack = nullptr;
        size_t _stack_size;
    };

    void swap(my_thread & left, my_thread & right);
}

#endif
