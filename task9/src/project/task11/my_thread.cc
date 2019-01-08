#include <project/my_thread.hh>

my::my_thread::my_thread(my::my_thread&& other) {
    swap(other);
}
my::my_thread::my_thread(int(*fun)(void*))
{
    this->_flags = CLONE_NEWUTS | CLONE_NEWUSER | SIGCHLD;
    _stack_size = 1024 * 1024 * 10;
    _stack = new char[_stack_size];

    _id = clone(fun, _stack+_stack_size, this->_flags, nullptr);
}

bool my::my_thread::joinable() const
{
    return _id != 0;
}

size_t my::my_thread::get_id() const
{
    return _id;
}

my::my_thread::~my_thread()
{
    if (_id != 0)
        kill(_id, SIGTERM);
    delete [] _stack;
};

void my::my_thread::join() const
{
    waitpid(_id, NULL, 0);
    kill(_id, SIGTERM);
    _id = 0;
}

void my::my_thread::swap(my_thread & other)
{
    std::swap(this->_id, other._id);
    std::swap(this->_flags, other._flags);
    std::swap(this->_stack, other._stack);
    std::swap(this->_stack_size, other._stack_size);
}
void my::swap(my_thread & left, my_thread & right)
{
    left.swap(right);
}
