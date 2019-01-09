#ifndef MY_THREAD_HH
#define MY_THREAD_HH
#include <cstddef>
#include <utility>
#include <signal.h>
#include <sched.h> 
#include <sys/wait.h> 

namespace my{

	enum {
		stack_size = 1024 * 1024 * 10
	};

	class my_thread {
	public:
		my_thread() = default;
		my_thread(my_thread&& other);
		my_thread(int(*fun)(void*));
		~my_thread();

		bool joinable() { return id != 0; };
		int get_id() { return id; }
		void join();
		void swap(my_thread & other);

	private:
		int id = NULL;
		int flags = CLONE_VM | SIGCHLD;
		char * stack = nullptr;
		//size_t _stack_size;
	};

	my_thread::my_thread(my_thread&& other) {
		swap(other);
	}

	void my_thread::swap(my_thread & other) {
		std::swap(this->id, other.id);
		std::swap(this->flags, other.flags);
		std::swap(this->stack, other.stack);
	}


	my_thread::my_thread(int(*f) (void*)) {
		this->flags = CLONE_VM | SIGCHLD;
		stack = new char[stack_size];
		id = clone(f, stack + stack_size, this->flags, nullptr);
	}

	my_thread::~my_thread() {
		if (id != NULL) {
			kill(id, SIGTERM); 
		}
		delete[] stack;
	};

	void my_thread::join() {
		waitpid(id, NULL, 0);
		kill(id, SIGTERM);
		id = NULL;
	}


}
#endif
