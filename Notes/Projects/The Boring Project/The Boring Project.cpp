// So yeah I am going to probably just trawl around a bunch and maybe copy paste some canonical parallel algorithms and linear algebra stuff in to this here file to gaze upon and half verify demonstrate some comprehension of like that corpus of the so called basics there to check that check box.

// OK so C++ Concurrency In Action Practical Multi Threading - Anthony Williams

// OK so the cover has a chick which is nice it must be important something about C++ and something about Concurrency.

/*
Table of Contents
Chapter One: Introduction
Chapter Two: Managing Threads
Chapter Three: Sharing Data
Chapter Four: Synchronizing Concurrent Operations
Chapter Five: The C++ Memory Model and Operations on Atomic Types
Chapter Six: Designing Data Structures for Concurrency I: Lock-based Data Structures
Chapter Seven: Designing Data Structures for Concurrency II: Lock-free Concurrent Data
Structures
Chapter Eight: Designing Concurrent Code
Chapter Nine: High Level Thread Management
Chapter Ten: Testing and Debugging Multi-threaded Applications
Appendix A: New Features of the C++ language used by the thread library
*/

// 1.4.1 Hello Concurrent World

#include <iostream>
int main()
{
	std::cout<<"Hello World\n";
}

// Listing 1.1: A Simple "Hello Concurrent World" Program

#include <iostream>
#include <thread> //#1
void hello() //#2
{
	std::cout<<"Hello Concurrent World\n";
}
int main()
{
	std::thread t(hello); //#3
	t.join(); //#4
}

// Cueballs In Code And Text

// 2

// Managing Threads

std::thread object:
	void do_some_work();
	std::thread my_thread(do_some_work);

// OK

class background_task
{
public:
	void operator()() const
	{
		do_something();
		do_something_else();
	}
};
background_task f;
std::thread my_thread(f);

// Listing 2.1: A Function That Returns Whilst A Thread Still Has Access To Local Variables

struct func
{
	int& i;
	func(int& i_):i(i_){}
	void operator()()
	{
		for(unsigned j=0;j<1000;++j)
		{
			do_something(i); #1
		}
	}
};
void oops()
{
	int some_local_state=0;
	std::thread my_thread(func(some_local_state));
}

// Cueballs In Code And Text

// Listing 2.2: Waiting For A Thread To Finish

struct func; //#A
void f()
{
	int some_local_state=0;
	std::thread t(func(some_local_state));
	try
	{
		do_something_in_current_thread();
	}
	catch(...)
	{
		t.join(); //#2
		throw;
	}
	t.join(); //#1
}

// Cueballs In Code And Text

// Listing 2.3: Using RAII To Wait For A Thread To Complete

class thread_guard
{
	std::thread& t;
public:
	explicit thread_guard(std::thread& t_):
		t(t_)
	{}
	~thread_guard()
	{
		if(t.joinable()) //#2
		{
			t.join(); //#3
		}
	}
	thread_guard(thread_guard const&)=delete;//#4
	thread_guard& operator=(
		thread_guard const&)=delete;
};

void func(int&);

void f()
{
	int some_local_state;
	std::thread t(func(some_local_state));
	thread_guard g(t);

	do_something_in_current_thread();
} //#1

// 2.1.3 Running Threads In The Background

std::thread t(do_background_work);
t.detach();
assert(!t.joinable());

// Listing 2.4: Detaching Thread To Handle Other Documents

void edit_document(std::string const& filename)
{
	open_document_and_display_gui(filename);
	while(!done_editing())
	{
		user_command cmd=get_user_input();
		if(cmd.type==open_new_document)
		{
			std::string const new_name=
				get_filename_from_user();
			std::thread t(edit_document, //#1
						new_name);
			t.detach(); //#2
		}
		else
		{
			process_user_input(cmd);
		}
	}
}

// 2.2 Passing Arguments To A Thread Function

void f(int i,std::string const& s);
std::thread t(f,3,”hello”);

// OK

void f(int i,std::string const& s);
void oops(int some_param)
{
	char buffer[1024]; //#1
	sprintf(buffer,”%i”,some_param);
	std::thread(f,3,buffer); //#2
}

// OK

void f(int i,std::string const& s);

void not_oops(int some_param)
{
	char buffer[1024];
	sprintf(buffer,”%i”,some_param);
	std::thread(f,3,std::string(buffer)); //#1
}
//#1 Convert to std::string explicitly to avoid dangling pointer

// OK

void update_data_for_widget(widget_id w,
	widget_data& data); //#1

void oops_again(widget_id w)
{
	widget_data data;
	std::thread t(update_data_for_widget,
		w,data); //#2
	display_status();
	t.join();
	process_widget_data(data); //#3
}

// OK

std::thread t(update_data_for_widget,
	w,std::ref(data));

// OK

class X
{
public:
	void do_lengthy_work();
};

X my_x;
std::thread t(&X::do_lengthy_work,&my_x); //#1

// OK

void process_big_object(
	std::unique_ptr<big_object>);

std::unique_ptr<big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object,std::move(p));

// OK

// 2.3 Transferring Ownership Of A Thread

void some_function();
void some_other_function();
std::thread t1(some_function); //#1
std::thread t2=std::move(t1); //#2
t1=std::thread(some_other_function); //#3
std::thread t3; //#4
t3=std::move(t2); //#5
t1=std::move(t3); //#6

// OK

// Listing 2.5: Returning A std::thread From A Function

std::thread f()
{
	void some_function();
	return std::thread(some_function);
}
std::thread g()
{
	void some_other_function(int);
	std::thread t(some_other_function,42);
	return t;
}

// Likewise, if ownership should be transferred into a function, it can just accept an instance of:

std::thread by value as one of the parameters, as shown here:
void f(std::thread t);
void g()
{
	void some_function();
	f(std::thread(some_function));
	std::thread t(some_function);
	f(std::move(t));
}

// OK

// Listing 2.6: scoped_thread And Example Usage

class scoped_thread
{
	std::thread t;
public:
	explicit scoped_thread(std::thread t_): //#4
		t(std::move(t_))
	{
		if(!t.joinable()) //#5
			throw std::logic_error(“No thread”);
	}
	~scoped_thread()
	{
		t.join(); //#3
	}
	scoped_thread(scoped_thread const&)=delete;
	scoped_thread& operator=(
		scoped_thread const&)=delete;
};

void func(int&);

void f()
{
	int some_local_state;
	scoped_thread t( //#1
		std::thread(func(some_local_state)));

	do_something_in_current_thread();
} //#2

// Listing 2.7: Spawn Some Threads And Wait For Them To Finish

void do_work(unsigned id);

void f()
{
	std::vector<std::thread> threads;
	for(unsigned i=0;i<20;++i)
	{
		threads.push_back(
		std::thread(do_work,i)); //#1
	}
	std::for_each(threads.begin(),threads.end(),
		std::mem_fn(&std::thread::join)); //#2
}

// OK

// Choosing The Number Of Threads At Runtime

// Listing 2.8: A Parallel Version Of std::accumulate

template<typename Iterator,typename T>
struct accumulate_block
{
	void operator()(Iterator first,Iterator last,T& result)
	{
		result=std::accumulate(first,last,result);
	}
};
template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
	unsigned long const length=std::distance(first,last);

	if(!length) //#1
		return init;

	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread; //#2

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads= //#3
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads; //#4

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads-1); //#5

	Iterator block_start=first;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		Iterator block_end=block_start;
		std::advance(block_end,block_size); //#6
		threads[i]=std::thread( //#7
			accumulate_block<Iterator,T>(),
			block_start,block_end,std::ref(results[i]));
		block_start=block_end; /#8
	}
	accumulate_block()(block_start,last,results[num_threads-1]); //#9

	std::for_each(threads.begin(),threads.end(),
		std::mem_fn(&std::thread::join)); //#10

return std::accumulate(results.begin(),results.end(),init); //#11

// OK

// 2.5 Identifying Threads

std::thread::id master_thread;
void some_core_part_of_algorithm()
{
	if(std::this_thread::get_id()==master_thread)
	{
		do_master_thread_work();
	}
	do_common_work();
}

// 2.6 Summary

// Chapter 3

// Sharing Data Between Threads

// 3.1 Problems with Sharing Data Between Threads

// 3.1.1 Race Conditions

// Maybe I should even go back and take some half impressive sounding Notes here to demonstrate that I really do Truly half care. This sorta kinda sounds extremely relevant in trading conditions and environments especially as a total outsider if I forgot some things but like how precisely the pings go down from the machine to the execution engine and if like we time at some point sub optimal after a competitor what precisely will go down and just how much of a Loss is it to be in Rank whatever when precisely, etc.

// 3.1.2 Avoiding Problematic Race Conditions

// 3.2 Protecting Shared Data With Mutexes, Mutual Exclusions

// 3.2.1 Using Mutexes In C++

// Listing 3.1: Protecting A List With A Mutex

#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list; //#1
std::mutex some_mutex; //#2
void add_to_list(int new_value)
{
	std::lock_guard<std::mutex> guard(some_mutex); //#3
	some_list.push_back(new_value);
}
bool list_contains(int value_to_find)
{
	std::lock_guard<std::mutex> guard(some_mutex); //#4
	return std::find(some_list.begin(),some_list.end(),value_to_find)
		!= some_list.end();
}

// OK

// 3.2.2 Structuring Code For Protecting Shared Data

// Listing 3.2: Accidentally Passing Out A Reference To Protected Data

class some_data
{
public:
	void do_something();
};

class data_wrapper
{
private:
	some_data data;
	std::mutex m;
public:
	template<typename Function>
	void process_data(Function func)
	{
		std::lock_guard<std::mutex> l(m);
		func(data); //#1
	}
};

some_data* unprotected;

void malicious_function(some_data& protected_data)
{
	unprotected=&protected_data;
}

data_wrapper x;

void foo()
{
	x.process_data(malicious_function); //#2
	unprotected->do_something(); //#3
}

// OK

//#1 Call to user-defined function passing protected data.
//#2 Pass our malicious function in to bypass the protection.
//#3 Unprotected access to the “protected” data.

// 3.2.3 Spotting Race Conditions Inherent In Interfaces

// Listing 3.3: The Interface To The std::stack Container Adapter

template<typename T,typename Container=std::deque<T> >
class stack
{
public:
	explicit stack(const Container&);
	explicit stack(Container&& = Container());
	template <class Alloc> explicit stack(const Alloc&);
	template <class Alloc> stack(const Container&, const Alloc&);
	template <class Alloc> stack(Container&&, const Alloc&);
	template <class Alloc> stack(stack&&, const Alloc&);

	bool empty() const;
	size_t size() const;
	T& top();
	T const& top() const;
	void push(T const&);
	void push(T&&);
	void pop();
	void swap(stack&&);
};

// OK

stack<int> s;
if(!s.empty()) //#1
{
	int const value=s.top(); //#2
	s.pop(); //#3
	do_something(value);
}

// OK

// Option 1: Pass In A Reference

std::vector<int> result;
some_stack.pop(result);

// Option 2: Require A No-Throw Copy Constructor Or Move Constructor

// Option 3: Return A Pointer To The Popped Item

// Option 4: Provide Both Options 1 And Either Option 2 Or 3

// Example Definition Of A Thread-Safe Stack

// Listing 3.4: A Class Definition For A Thread-Safe Stack

#include <exception>
struct empty_stack: std::exception
{
	const char* what() const throw();
};

template<typename T>
class thread_safe_stack
{
public:
	stack();
	stack(const stack&);
	stack& operator=(const stack&) = delete; //#1

	void push(T new_value);
	std::shared_ptr<T> pop();
	void pop(T& value);
	bool empty() const;
};

// Listing 3.5: A Class Definition For A Thread-Safe Stack

#include <exception>

struct empty_stack: std::exception
{
	const char* what() const throw();
};

template<typename T>
class thread_safe_stack
{
private:
	std::stack<T> data;
	mutable std::mutex m;
public:
	stack(){}
	stack(const stack& other)
	{
		std::lock_guard<std::mutex> lock(other.m);
		data=other.data; //#1
	}
	stack& operator=(const stack&) = delete;

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		data.push(new_value);
	}
	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lock(m);
		if(data.empty()) throw empty_stack(); //#2
		std::shared_ptr<T> const res(new T(data.top()); //#3
		data.pop();
		return res;
	}
	void pop(T& value)
	{
		std::lock_guard<std::mutex> lock(m);
		if(data.empty()) throw empty_stack();
		value=data.top();
 		data.pop();
 	}
	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m);
		return data.empty();
	}
};

// OK

//#1 We can't use the member initialiser list to copy the stack as we must lock the source object first.
//#2 Check for empty before trying to pop a value.
//#3 Allocate the return value before modifying the stack with pop()

// 3.2.4 Deadlock: The Problem And A Solution

// Listing 3.6: Locking Two Mutexes With std::lock() In A Comparison Operator

class some_big_object;
bool operator<(some_big_object& lhs,some_big_object& rhs);

class X
{
private:
	some_big_object some_detail;
	mutable std::mutex m;
public:
	X(some_big_object const& sd):some_detail(sd){}

	friend bool operator<(X const& lhs, X const& rhs)
	{
		if(&lhs==&rhs)
			return false;
		std::lock(lhs.m,rhs.m); #1
		std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock); #2
		std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock); #3
		return lhs.some_detail<rhs.some_detail;
	}
};

// OK

// 3.2.5 Further Guidelines For Avoiding Deadlock

// Avoid Nested Locks 

// Avoid Calling User-Supplied Code Whilst Holding A Lock

// Acquire Locks In A Fixed Order

// Use A Lock Hierarchy

// Listing 3.7: Using A Lock Hierarchy To Prevent Deadlock

hierarchical_mutex high_level_mutex(10000); //#4
hierarchical_mutex low_level_mutex(5000); //#7

int do_low_level_stuff();

int low_level_func()
{
	std::lock_guard<hierarchical_mutex> lk(low_level_mutex); //#6
	return do_low_level_stuff();
}

void high_level_stuff(int some_param);

void high_level_func()
{
	std::lock_guard<hierarchical_mutex> lk(high_level_mutex); //#3
	high_level_stuff(low_level_func()); //#5
}

void thread_a() //#1
{
	high_level_func();
}

hierarchical_mutex other_mutex(100); //#9
void do_other_stuff();

void other_stuff()
{
	high_level_func(); //#10
	do_other_stuff();
}

void thread_b() //#2
{
	std::lock_guard<hierarchical_mutex> lk(other_mutex); //#8
	other_stuff();
}

// Listing 3.8: A Simple Hierarchical Mutex

class hierarchical_mutex
{
	std::mutex internal_mutex;
	unsigned long const hierarchy_value;
	unsigned previous_hierarchy_value;
	static thread_local unsigned long this_thread_hierarchy_value; //#1

	void check_for_hierarchy_violation()
	{
		if(this_thread_hierarchy_value <= hierarchy_value) //#3
		{
			throw std::logic_error("mutex hierarchy violated");
		}
	}
	void update_hierarchy_value()
	{
		previous_hierarchy_value=this_thread_hierarchy_value; //#7
		this_thread_hierarchy_value=hierarchy_value;
	}
public:
	explicit hierarchical_mutex(unsigned long value):
		hierarchy_value(value),
		previous_hierarchy_value(0)
	{}
	void lock()
	{
		check_for_hierarchy_violation();
		internal_mutex.lock(); //#4
		update_hierarchy_value(); //#5
	}
	void unlock()
	{
		this_thread_hierarchy_value=previous_hierarchy_value; //#6
		internal_mutex.unlock();
	}
	bool try_lock()
	{
		check_for_hierarchy_violation();
		if(!internal_mutex.try_lock()) //#8
			return false;
		update_hierarchy_value();
		return true;
	}
};
thread_local unsigned long
	hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX); //#2

// Extending These Guidelines Beyond Locks

// 3.2.6 Flexible Locking With std::unique_lock

// Listing 3.9: Locking Two Mutexes With lock() In A Comparison Operator

class some_big_object;
bool operator<(some_big_object& lhs,some_big_object& rhs);
class X
{
private:
	some_big_object some_detail;
	mutable std::mutex m;
public:
	X(some_big_object const& sd):some_detail(sd){}

	friend bool operator<(X const& lhs, X const& rhs)
	{
		if(&lhs==&rhs)
			return false;
		std::unique_lock<std::mutex> lock_a(lhs.m,std::defer_lock); //#1
		std::unique_lock<std::mutex> lock_b(rhs.m,std::defer_lock); //#1
		std::lock(lock_a,lock_b); //#2
		return lhs.some_detail<rhs.some_detail;
	}
};

// OK

// 3.2.7 Transferring Mutex Ownership Between Scopes

std::unique_lock<std::mutex> get_lock()
{
	extern std::mutex some_mutex;
	std::unique_lock<std::mutex> lk(some_mutex);
	prepare_data();
	return lk; //#1
}
void process_data()
{
	std::unique_lock<std::mutex> lk(get_lock()); //#2
	do_something();
}

// 3.2.8 Locking At An Appropriate Granularity

void get_and_process_data()
{
	std::unique_lock<std::mutex> my_lock(the_mutex);
	some_class data_to_process=get_next_data_chunk();
	my_lock.unlock(); //#1
	result_type result=process(data_to_process);
	my_lock.lock(); //#2
	write_result(data_to_process,result);
}

//#1 We don't need the mutex locked across the call to process()
//#2 Lock the mutex again to write the result.

// Listing 3.10: Locking One Mutex At A Time In A Comparison Operator

class Y
{
private:
	int some_detail;
	mutable std::mutex m;

	int get_detail() const
	{
		std::lock_guard<std::mutex> lock_a(m); //#3
		return some_detail;
	}
public:
	Y(int sd):some_detail(sd){}

	friend bool operator==(Y const& lhs, Y const& rhs)
	{
		if(&lhs==&rhs)
			return true;
		int const lhs_value=lhs.get_detail(); //#1
		int const rhs_value=rhs.get_detail(); //#2
		return lhs_value==rhs_value; //#4
	}
};

// 3.3 Alternative Facilities For Protecting Shared Data

// 3.3.1 Protecting Shared Data During Initialisation

std::shared_ptr<some_resource> resource_ptr;
void foo()
{
	if(!resource_ptr)
	{
		resource_ptr.reset(new some_resource); //#1
	}
	resource_ptr->do_something();
}

// Listing 3.11: Thread-Safe Lazy Initialisation Using A Mutex

std::shared_ptr<some_resource> resource_ptr;
std::mutex resource_mutex;
void foo()
{
	std::unique_lock<std::mutex> lk(resource_mutex); //#1
	if(!resource_ptr)
	{
		resource_ptr.reset(new some_resource); //#2
	}
	lk.unlock();
	resource_ptr->do_something();
}

//#1 All threads are serialized here
//#2 Only the initialization needs protection

void undefined_behaviour_with_double_checked_locking()
{
	if(!resource_ptr) //#1
	{
		std::lock_guard<std::mutex> lk(resource_mutex);
		if(!resource_ptr) //#2
		{
			resource_ptr.reset(new some_resource); //#3
		}
	}
	resource_ptr->do_something(); //#4
}

// OK

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;
void init_resource()
{
	resource_ptr.reset(new some_resource);
}
void foo()
{
	std::call_once(resource_flag,init_resource); //#1
	resource_ptr->do_something();
}

//#1 This initialization is called exactly once.

// Listing 3.12: Thread-Safe Lazy Initialisation Of A Class Member Using std::call_once

class X
{
private:
	connection_info connection_details;
	connection_handle connection;
	std::once_flag connection_init_flag;

	void open_connection()
	{
		connection=connection_manager.open(connection_details);
	}
public:
	X(connection_info const& connection_details_):
		connection_details(connection_details_)
	{}
	void send_data(data_packet const& data) //#1
	{
		std::call_once(connection_init_flag,&X::open_connection,this); //#3
		connection.send_data(data);
	}
	data_packet receive_data() //#2
	{
		std::call_once(connection_init_flag,&X::open_connection,this); //#3
		return connection.receive_data();
	}
};

// OK

class my_class;
my_class& get_my_class_instance()
{
	static my_class instance; //#1
	return instance;
}

//#1 Initialisation of instance is guaranteed to be thread-safe.

// 3.3.2 Protecting Rarely-Updated Data Structures

// Listing 3.13: Protecting A Data Structure With A boost::shared_mutex

#include <map>
#include <string>
#include <mutex>
#include <boost/thread/shared_mutex.hpp>

class dns_entry;

class dns_cache
{
	std::map<std::string,dns_entry> entries;
	boost::shared_mutex entry_mutex;
public:
	dns_entry find_entry(std::string const& domain)
	{
		boost::shared_lock<boost::shared_mutex> lk(entry_mutex); //#1
		std::map<std::string,dns_entry>::const_iterator const it=
			entries.find(domain);
		return (it==entries.end())?dns_entry():*it;
	}
	void update_or_add_entry(std::string const& domain, 
		dns_entry const& dns_details)
	{
		std::lock_guard<boost::shared_mutex> lk(entry_mutex); //#2
		entries[domain]=dns_details;
	}
};

// 3.4 Summary

// Problematic race conditions can be disastrous when sharing data between threads...

// Chapter 4

// Synchronising Concurrent Operations

// 4.1 Waiting For An Event Or Other Condition

// A second option is to have the waiting thread "sleep" for small periods between the checks using the std::this_thread::sleep() function: 

bool flag;
std::mutex m;

void wait_for_flag()
{
	std::unique_lock<std::mutex> lk(m);
	while(!flag)
	{
		lk.unlock(); //#1
		std::this_thread::sleep(std::chrono::milliseconds(100)); //#2
		lk.lock(); //#3
	}
}

// #1 Unlock the mutex whilst we sleep, so another thread can acquire it and set the flag.
// #2 Sleep for 100ms.
// #3 Lock the mutex again before we loop round to check the flag.

// 4.1.1 Waiting For A Condition With Condition Variables

// Listing 4.1: Waiting For Data To Process With A std::condition_variable

std::mutex mut;
std::queue<data_chunk> data_queue; //#1
std::condition_variable data_cond;

void data_preparation_thread()
{
	while(more_data_to_prepare())
	{
		data_chunk const data=prepare_data();
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(data); //#2
		data_cond.notify_one(); //#3
	}
}

void data_processing_thread()
{
	while(true)
	{
		std::unique_lock<std::mutex> lk(mut); //#4
		data_cond.wait(lk,[]{return !data_queue.empty();}); //#5
		data_chunk data=data_queue.front();
		data_queue.pop();
		lk.unlock(); //#6
		process(data);
		if(is_last_chunk(data))
			break;
	}
}

// 4.1.2 Building A Thread-Safe Queue With Condition Variables

// Listing 4.2: std::queue Interface

template <class T,class Container = std::deque<T>>
class queue {
public:
	explicit queue(const Container&);
	explicit queue(Container&& = Container());
	queue(queue&& q);

	template <class Alloc> explicit queue(const Alloc&);
	template <class Alloc> queue(const Container&, const Alloc&);
	template <class Alloc> queue(Container&&, const Alloc&);
	template <class Alloc> queue(queue&&, const Alloc&);

	queue& operator=(queue&& q);
	void swap(queue&& q);

	bool empty() const;
	size_type size() const;

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	void push(const T& x);
	void push(T&& x);
	void pop();
};

// Listing 4.3: The Interface Of Our Thread-Safe Queue

template<typename T>
class queue
{
public:
	queue();
	queue(const queue&);
	queue& operator=(const queue&) = delete; //#1

	void push(T new_value);

	bool try_pop(T& value); //#2
	std::shared_ptr<T> try_pop(); //#3

	void wait_and_pop(T& value);
	std::shared_ptr<T> wait_and_pop();

	bool empty() const;
};

//#1 Disallow assignment for simplicity.
//#3 Return NULL if there is no value to retrieve.

// Listing 4.4: Extracting push() And wait_and_pop() From Listing 4.1

template<typename T>
class queue
{
private:
	std::mutex mut;
	std::queue<T> data_queue;
	std::condition_variable data_cond;
public:
	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(data);
		data_cond.notify_one();
	}

	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();});
		value=data_queue.front();
		data_queue.pop();
	}
};

queue<data_chunk> data_queue; //#1

void data_preparation_thread()
{
	while(more_data_to_prepare())
	{
		data_chunk const data=prepare_data();
		data_queue.push(data); //#2
	}
}

void data_processing_thread()
{
	while(true)
	{
		data_chunk data;
		data_queue.wait_and_pop(data); //#3
		process(data);
		if(is_last_chunk(data))
			break;
	}
}

//#1 We only need our new queue now, as the mutex and condition variable are contained within.
//#2 No external synchronization required for push()
//#3 wait_and_pop() takes care of the condition variable wait.

// Listing 4.5: The Full Class Definition For A Thread-Safe queue Using Condition Variables

template<typename T>
class queue
{
private:
	mutable std::mutex mut; //#1
	std::queue<T> data_queue;
	std::condition_variable data_cond;
public:
	queue()
	{}
	queue(queue const& other)
	{
		std::lock_guard<std::mutex> lk(other.mut);
		data_queue=other.data_queue;
	}

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(data);
		data_cond.notify_one();
	}

	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();});
		value=data_queue.front();
		data_queue.pop();
	}

	std::shared_ptr<T> wait_and_pop()
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();});
		std::shared_ptr<T> res(new T(data_queue.front()));
		data_queue.pop();
		return res;
	}

	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if(data_queue.empty)
			return false;
		value=data_queue.front();
		data_queue.pop();
	}

	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if(data_queue.empty())
			return std::shared_ptr<T>();
		std::shared_ptr<T> res(new T(data_queue.front()));
		data_queue.pop();
		return res;
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
};

//#1 The mutex must be mutable so we can lock it in empty() and in the copy constructor

// 4.2 Waiting For One-Off Events With Futures

// Listing 4.6: Waiting For An Event With A std::unique_future

void wait_for_flight1(flight_number flight)
{
	std::shared_future<boarding_information> //#1
		boarding_info=get_boarding_info(flight);
	board_flight(boarding_info.get());
}

void wait_for_flight2(flight_number flight)
{
	std::shared_future<boarding_information> //#2
		boarding_info=get_boarding_info(flight);
	while(!boarding_info.is_ready()) //#4
	{
		eat_in_cafe(); //#3
		buy_duty_free_goods();
	}
	board_flight(boarding_info.get());
}

// Listing 4.7: Using std::unique_future To Transfer A Large Block Of Data

void process_remote_file(
	std::string const& filename)
{
	std::unique_future<
		file_contents> contents=
		server.download_file_in_background( //#1
			filename);
	while(!contents.is_ready()) //#2
	{
		process_gui_events(); //#3
	}
	file_contents file_data(contents.get()); //#4
	process_file(file_data); //#5
}

// Packaged Tasks

// Promises

// 4.2.1 Associating A Task With A Future

// Listing 4.8: Downloading A File From A Remote Server

file_contents download_file(std::string const& filename)
{
	Connection con(remote_server);
	con.send_file_request(filename);
	file_contents contents;
	while(!con.eof())
	{
		std::vector<unsigned char> chunk=
			con.receive_data_chunk();
		contents.append(chunk);
	}
	return contents;
}

// OK

std::unique_future<file_contents>
	download_file_in_background(
		std::string const& filename)
{ 
	std::packaged_task<file_contents()> //#1
		task(std::bind(download_file,filename)));
	std::unique_future<file_contents> //#2
		res(task.get_future());
	std::thread(std::move(task)); //#3
	return res; //#4
}

// 4.2.2 Making (std::) Promises

// Listing 4.9: Handling Multiple Connections From A Single Thread Using Promises

void process_connections(connection_set& connections)
{
	while(!done(connections)) //#1
	{
		for(connection_iterator //#2
			connection=connections.begin(),
			end=connections.end();
			connection!=end;++connection)
		{
			if(connection->has_incoming_data()) //#3
			{
				data_packet data=connection->incoming();
				std::promise<payload_type>& p=
					connection->get_promise(data.id); //#5
				p.set_value(data.payload);
			}
			if(connection->has_outgoing_data()) //#4
			{
				outgoing_packet data=
					connection->top_of_outgoing_queue();
				connection->send(data.payload);
				data.promise.set_value(true); //#6
			}
		}
	}
}

// 4.2.3 Saving An Exception For The Future

double square_root(double x)
{
	if(x<0)
	{
		throw std::out_of_range(“x<0”);
	}
	return sqrt(x);
}

// OK

// Now suppose that instead of just invoking square_root() from the current thread:

double y=square_root(-1);

// The call is packaged up and run on another thread:

std::packaged_task<double()>
	task(std::bind(square_root,-1));
std::unique_future<double> f=task.get_future();
std::thread task_thread(std::move(task));
double y=f.get();

// OK

extern std::promise<double> some_promise;

try
{
	some_promise.set_value(calculate_value());
}
catch(...)
{
	some_promise.set_exception(
		std::current_exception());
}

// 4.3 Using Synchronisation Of Operations To Simplify Code 

// 4.3.1 Functional Programming With Futures

// Listing 4.10: Parallel QuickSort Using Futures

std::list<T> parallel_quick_sort(std::list<T> input)
{
	if(input.empty())
	{
		return input;
	}
	std::list<T> result;
	result.splice(result.begin(),input,input.begin()); //#1
	T const& partition_val=*result.begin();

	typename std::list<T>::iterator divide_point= //#2
		std::partition(input.begin(),input.end(),
			[&](T const& t){return t<partition_val;}); //#3

	std::list<T> lower_part;
	lower_part.splice(lower_part.end(),input,input.begin(),
		divide_point); //#4

	std::unique_future<std::list<T> > new_lower( //#5
		spawn_task(&parallel_quick_sort<T>,std::move(lower_part)));

	std::list<T> new_higher(parallel_quick_sort(std::move(input))); //#6

	result.splice(result.end(),new_higher); //#7
	result.splice(result.begin(),new_lower.get()); //#8
	return result; //#9
}

// OK

// Listing 4.11: A Sample Implementation Of spawn_task

template<typename F,typename A>
std::unique_future<std::result_of<F(A&&)>::type>
	spawn_task(F&& f,A&& a)
{
	typedef std::result_of<F(A&&)>::type result_type;
	std::packaged_task<result_type(A&&)>
		task(std::move(f)));
	std::unique_future<result_type> res(task.get_future());
	std::thread(std::move(task),std::move(a));
	return res;
}

// 4.3.2 Synchronising Operations With Message Passing

// Listing 4.12: A Mail Order Business, And A Customer

class mail_order_business
{
public:
	void run_business();
};
class customer
{
public:
	void live_life();
};
mail_order_business widgets_inc; //#1
customer fred; //#2

std::thread business_thread( //#3
	&mail_order_business::run_business,
	&widgets_inc);

std::thread customer_thread( //#4
	&customer::live_life,&fred);

// #1 Our business object
// #2 Our customer object
// #3 Run the business on a thread
// #4 Start a thread for the customer to live his life

// Listing 4.13: Registering With The Messaging Subsystem

class mail_order_business
{
private:
	messaging::receiver_id id;
public:
	mail_order_business():
		id(messaging::register_receiver()) //#1
	{}
	messaging::receiver_id get_id() const
	{
		return id;
	}
	// As before.
	};

class customer
{
private:
	messaging::receiver_id id;
	messaging::receiver_id business_id;
public:
	explicit
	customer(message::receiver_id business_id_):
		id(messaging::register_receiver()), //#2
		business_id(business_id_)
	{}
	// As before.
};

mail_order_business widgets_inc;
customer fred(widgets_inc.get_id()); //#3

//#1 Register business with messaging subsystem.
//#2 Register customer with messaging subsystem.
//#3 Pass the business ID into the customer.

// Listing 4.14: Sending An Order For Widgets Through The Messaging Subsystem

void customer::live_life()
{
	// ...
	order_message order; //#1
	order.deliver_to=id; //#2
	order.order_widgets(3);

	messaging::send_message(business_id,order); //#3
	// ...
}

void mail_order_business::run_business()
{
	// ...
	if(messaging::incoming<order_message>(id)) //#4
	{
		order_message order=
			messaging::get<order_message>(id); //#5
		if(widgets_available()>=
			order.num_widgets())
		{
			delivery_message delivery;
			delivery.from=id;
			delivery.add_widgets(get_widgets(
				order.num_widgets()));
			messaging::send_message(
				order.deliver_to,delivery); //#6
		}
		else
		{
			add_to_pending_orders(order);
		}
	}
	// ...
}

//#1 Create an order
//#2 Identify the customer as the recipient
//#3 Send the order to the business
//#4 Check for an incoming order
//#5 Get the order
//#6 Send the delivery to the customer

// 4.4 Summary

// Synchronising operations between threads is an important part of writing an application that uses concurrency: if there is no synchronisation, the threads are essentially independent, and might as well be written as separate applications that are run as a group due to their related activities. In this chapter, we've covered various ways of synchronising operations from the basic condition variables, through futures, promises and packaged tasks. We've also discussed ways of approaching the synchronisation issues: functional style programming where each task produces a result entirely dependent on its input rather than on the external environment, and message passing where communication between threads is via asynchronous messages sent through a messaging subsystem that acts as an intermediary.

// Having discussed much of the high level facilities available in C++, it's now time to look at the low-level facilities that make it all work: the C++ memory model and atomic operations. 

// Chapter 5

// The C++ Memory Model And Operations On Atomic Types

// 5.1 C++ Memory Model Basics

// 5.1.1 Objects And Memory Locations

// There are four important things to take away from this:

// 5. Every variable is an object, including those that are members of other objects;
// 6. Every object comprises at least one memory location;
// 7. Variables of fundamental type such as int or char are exactly one memory location, whatever their size, even if they are adjacent, or part of an array;
// 8. Adjacent bitfields are part of the same memory location. I'm sure you're wondering what this has got do with concurrency, so let's take a look.

// 5.1.2 Objects, Memory Locations And Concurrency

// 5.2 Atomic Operations And Types In C++

// 5.2.1 The Standard Atomic Types

// 5.2.2 Operations On std::atomic_flag

f.clear(std::memory_order_release); #1
bool x=f.test_and_set(); #2

// #1 Clear the flag with release semantics.
// #2 Set the flag with the default (sequentially consistent) memory ordering, and retrieve the old value.

// Listing 5.14: Implementation Of A Spinlock Mutex Using std::atomic_flag

class spinlock_mutex
{
	std::atomic_flag flag;
public:
	spinlock_mutex():
		flag(ATOMIC_FLAG_INIT)
	{}
	void lock()
	{
		while(flag.test_and_set(std::memory_order_acquire));
	}
	void unlock()
	{
		flag.clear(std::memory_order_release);
	}
};

// 5.2.3 Operations On std::atomic_bool

std::atomic_bool b=true;
b=false;

// OK

std::atomic_bool b;
bool x=b.load(std::memory_order_acquire);
b.store(true);
x=b.exchange(false,std::memory_order_acq_rel);

// Storing A New Value [Or Not] Depending On The Current Value

bool expected=false;
extern atomic_bool b; // Set somewhere else.
while(!b.compare_exchange_weak(expected,true) && !expected);

// OK

std::atomic_bool b;
bool expected;
b.compare_exchange_weak(expected,true,
	memory_order_acq_rel,memory_order_acquire);
b.compare_exchange_weak(expected,true,memory_order_acq_rel);

// 5.2.4 Operations On std::atomic_address

char some_array[5];
std::atomic_address p(some_array);
void* x=p.fetch_add(2); //#1
assert(x==some_array);
assert(p.load()==&some_array[2]);
x=(p-=1); //#2
assert(x==&some_array[1]);
assert(p.load()==&some_array[1]);

// #1 Add two to p and return the old value.
// #2 Subtract one from p and return the new value.

std::string my_strings[23];
std::atomic_address ps(my_strings);
ps.fetch_add(5*sizeof(std::string));
assert(ps.load()==&my_strings[5]);

// OK

p.fetch_add(3,std::memory_order_release);

// 5.2.5 Operations On Standard Atomic Integral Types

// 5.2.6 The std::atomic Class Template

// 5.2.7 Free Functions For Atomic Operations

std::shared_ptr<my_data> p;
void process_global_data()
{
	std::shared_ptr<my_data> local=std::atomic_load(&p);
	process_data(local);
}
void update_global_data()
{
	std::shared_ptr<my_data> local(new my_data);
	std::atomic_store(&p,local);
}

// OK

// 5.3 Synchronising Operations And Enforcing Ordering With Atomic Types

// Listing 5.15: Reading And Writing Variables From Different Threads

#include <vector>
#include <cstdatomic>
#include <iostream>

std::vector<int> data;
std::atomic_bool data_ready(false);

void writer_thread()
{
	data.push_back(42); //#3
	data_ready=true; //#4
}
void reader_thread()
{
	while(!data_ready.load()) //#1
	{
		std::this_thread::sleep(
			std::milliseconds(1));
	}
	std::cout<<”The answer=”<<data[0]<<”\n”; //#2
}

// 5.3.1 The Synchronises-With Relation

// 5.3.2 The Happens-Before Relation

// Listing 5.16: The Order Of Evaluation Of Arguments To A Function Call Is Unspecified

#include <iostream>

void foo(int a,int b)
{
	std::cout<<a<<”,”<<b<<std::endl;
}

int get_num()
{
	static int i=0;
	return ++i;
}

int main()
{
	foo(get_num(),get_num()); //#1
}

// 5.3.3 Memory Ordering For Atomic Operations

// Sequentially-Consistent Ordering

// Listing 5.17: Sequential Consistency Implies A Total Ordering

#include <cstdatomic>
#include <thread>
#include <assert.h>

std::atomic_bool x,y;
std::atomic_int z;

void write_x()
{
	x.store(true,std::memory_order_seq_cst); //#2
}

void write_y()
{
	y.store(true,std::memory_order_seq_cst); //#3
}

void read_x_then_y()
{
	while(!x.load(std::memory_order_seq_cst));
	if(y.load(std::memory_order_seq_cst)) //#4
		++z;
}

void read_y_then_x()
{
	while(!y.load(std::memory_order_seq_cst));
	if(x.load(std::memory_order_seq_cst)) //#5
		++z;
}

int main()
{
	x=false;
	y=false;
	z=0;
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	assert(z.load()!=0); //#1
}

// Non-Sequentially-Consistent Memory Orderings

// Relaxed Ordering

// Listing 5.18: Relaxed Operations Have Very Little Ordering Requirements

#include <cstdatomic>
#include <thread>
#include <assert.h>

std::atomic_bool x,y;
std::atomic_int z;

void write_x_then_y()
{
	x.store(true,std::memory_order_relaxed); //#4
	y.store(true,std::memory_order_relaxed); //#5
}

void read_y_then_x()
{
	while(!y.load(std::memory_order_relaxed)); //#3
	if(x.load(std::memory_order_relaxed)) //#2
		++z;
}

int main()
{
	x=false;
	y=false;
	z=0;
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load()!=0); //#1
}

// Acquire-Release Ordering

// Listing 5.19: Acquire-Release Does Not Imply A Total Ordering

#include <cstdatomic>
#include <thread>
#include <assert.h>

std::atomic_bool x,y;
std::atomic_int z;

void write_x()
{
	x.store(true,std::memory_order_release);
}

void write_y()
{
	y.store(true,std::memory_order_release);
}

void read_x_then_y()
{
	while(!x.load(std::memory_order_acquire));
	if(y.load(std::memory_order_acquire)) //#3
		++z;
}

void read_y_then_x()
{
	while(!y.load(std::memory_order_acquire));
	if(x.load(std::memory_order_acquire)) //#2 
		++z;
}

int main()
{
	x=false;
	y=false;
	z=0;
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	assert(z.load()!=0); //#1
}

// Listing 5.20: Acquire-Release Operations Can Impose Ordering On Relaxed Operations

#include <cstdatomic>
#include <thread>
#include <assert.h>

std::atomic_bool x,y;
std::atomic_int z;

void write_x_then_y()
{
	x.store(true,std::memory_order_relaxed); //#3
	y.store(true,std::memory_order_release); //#2
}

void read_y_then_x()
{
	while(!y.load(std::memory_order_acquire)); //#1
	if(x.load(std::memory_order_relaxed)) //#4
		++z;
}

int main()
{
	x=false;
	y=false;
	z=0;
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load()!=0); //#5
}

// Transitive Synchronisation With Acquire-Release Ordering

// Listing 5.21: Transitive Synchronisation Using std::memory_order_acquire And std::memory_order_release

std::atomic<int> data[5];
std::atomic<bool> sync1(false),sync2(false);

void thread_1()
{
	data[0].store(42,std::memory_order_relaxed);
	data[1].store(97,std::memory_order_relaxed);
	data[2].store(17,std::memory_order_relaxed);
	data[3].store(-141,std::memory_order_relaxed);
	data[4].store(2003,std::memory_order_relaxed);
	sync1.store(true,std::memory_order_release); //#3
}

void thread_2()
{
	while(!sync1.load(std::memory_order_acquire)); //#1
	sync2.store(std::memory_order_release); //#2
}

void thread_3()
{
	while(!sync2.load(std::memory_order_acquire)); //#4
	assert(data[0].load(std::memory_order_relaxed)==42);
	assert(data[1].load(std::memory_order_relaxed)==97);
	assert(data[2].load(std::memory_order_relaxed)==17);
	assert(data[3].load(std::memory_order_relaxed)==-141);
	assert(data[4].load(std::memory_order_relaxed)==2003);
}

// OK

std::atomic<int> sync(0);
void thread_1()
{
	// ...
	sync.store(1,std::memory_order_release);
}

void thread_2()
{
	int expected=1;
	while(!sync.compare_exchange_strong(expected,2,
		std::memory_order_acq_rel))
	expected=1;
}

void thread_3()
{
	while(sync.load(std::memory_order_acquire)<2);
	// ...
}

// Data-Dependency With Acquire-Release Ordering And memory_order_consume

// Listing 5.22: Using std::memory_order_consume To Synchronise Data In A Dynamically Allocated Object

struct X
{
	int i;
	std::string s;
};

std::atomic<X*> p;
std::atomic_int a;

void create_x()
{
	X* x=new X;
	x->i=42;
	x->s=”hello”;
	a.store(99,std::memory_order_relaxed); //#1
	p.store(x,std::memory_order_release); //#2
}

void use_x()
{
	X* x;
	while(!(x=p.load(std::memory_order_consume))) //#3
		std::this_thread::sleep(std::chrono::microseconds(1));
	assert(x->i==42); //#4
	assert(x->s==”hello”); //#5
	assert(a.load(std::memory_order_relaxed)==99); //#6
}

int main()
{
	std::thread t1(create_x);
	std::thread t2(use_x);
	t1.join();
	t2.join();
}

// 5.3.4 Release Sequences And Synchronises-With

// Listing 5.23: Reading Values From A Queue With Atomics

#include <cstdatomic>
#include <thread>

std::vector<int> queue_data;
std::atomic_int count;

void populate_queue()
{
	unsigned const number_of_items=20;
	queue_data.clear();
	for(unsigned i=0;i<number_of_items;++i)
	{
		queue_data.push_back(i);
	}

	count.store(number_of_items,std::memory_order_release); //#1
}

void consume_queue_items()
{
	while(true)
	{
		int item_index; 
		if((item_index=count.fetch_sub(1,std::memory_order_acquire))<=0) //#2
		{
			wait_for_more_items(); //#4
			continue;
		}
		process(queue_data[item_index-1]); //#3
	}
}

int main()
{
	std::thread a(populate_queue);
	std::thread b(consume_queue_items);
	std::thread c(consume_queue_items);
	a.join();
	b.join();
	c.join();
}

// OK

// 5.3.5 Fences

// Listing 5.24: Relaxed Operations Can Be Ordered With Fences

#include <cstdatomic>
#include <thread>
#include <assert.h>

std::atomic_bool x,y;
std::atomic_int z;

void write_x_then_y()
{
	x.store(true,std::memory_order_relaxed); //#3
	std::atomic_thread_fence(std::memory_order_release); //#1
	y.store(true,std::memory_order_relaxed); //#4
}

void read_y_then_x()
{
	while(!y.load(std::memory_order_relaxed)); //#5
	std::atomic_thread_fence(std::memory_order_acquire); //#2
	if(x.load(std::memory_order_relaxed)) //#6
		++z;
}

int main()
{
	x=false;
	y=false;
	z=0;
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load()!=0); //#7
}

// OK

void write_x_then_y()
{
	std::atomic_thread_fence(std::memory_order_release);
	x.store(true,std::memory_order_relaxed); //#1
	y.store(true,std::memory_order_relaxed); //#2
}

// #1, #2 These two operations are no longer separated by the fence, and so are no longer ordered.

// 5.3.6 Ordering Non-Atomic Operations With Atomics

// Listing 5.25: Atomic Operations And Fences Can Enforce An Ordering On Non-Atomic Operations

#include <cstdatomic>
#include <thread>
#include <assert.h>

bool x=false; //#5
std::atomic_bool y;
std::atomic_int z;

void write_x_then_y()
{
	x=true; //#1
	std::atomic_thread_fence(std::memory_order_release);
	y.store(true,std::memory_order_relaxed); //#2
}

void read_y_then_x()
{
	while(!y.load(std::memory_order_relaxed)); //#3
	std::atomic_thread_fence(std::memory_order_acquire);
	if(x) //#4
		++z;
}

int main()
{
	x=false;
	y=false;
	z=0;
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load()!=0); //#6
}

// #5 x is a now plain non-atomic variable

// 5.4 Summary

/*
In this chapter we've covered the low level details of the C++0x memory model and the atomic operations that provide the basis for synchronisation between threads. This includes the basic atomic types and the generic std::atomic<> template, the operations on them, and the complex details of the various memory ordering options. We've also looked at fences, and how they can be paired with operations on atomic types to enforce an ordering. Finally, we've come back to the beginning with a look at how the atomic operations can be used to enforce an ordering between non-atomic operations on separate threads. In the next chapter we'll look at using the high level synchronisation facilities alongside atomic operations to design efficient containers for concurrent access, and write algorithms that process data in parallel. 
*/

// Chapter 6

// Designing Data Structures For Concurrency I: Lock-Based Data Structures

// 6.1 What Does It Mean For A Data Structure To Be Designed For Concurrency?

// 6.1.1 Guidelines For Designing Data Structures For Concurrency

// Ensure that no thread can see a state where the invariants of the data structure have been broken by the actions of another thread.

// Take care to avoid race conditions inherent in the interface to the data structure by providing functions for complete operations rather than for operation steps.

// Pay attention to how the data structure behaves in the presence of exceptions to ensure that the invariants are not broken.

// Minimise the opportunities for deadlock when using the data structure by restricting the scope of locks and avoiding nested locks where possible. 

// If one thread is accessing the data structure through a particular function, which functions are safe to call from other threads?

// Can the scope of locks be restricted to allow some parts of an operation to be performed outside the lock?

// Can different parts of the data structure be protected with different mutexes?

// Do all operations require the same level of protection?

// Can a simple change to the data structure improve the opportunities for concurrency without affecting the operational semantics?

// 6.2 Lock-Based Concurrent Data Structures

// 6.2.1 A Thread-Safe Stack Using Locks

// Listing 6.26: A Class Definition For A Thread-Safe Stack

#include <exception>

struct empty_stack: std::exception
{
	const char* what() const throw();
};

template<typename T>
class stack
{
private:
	std::stack<T> data;
	mutable std::mutex m;
public:
	stack(){}
	stack(const stack& other)
	{
		std::lock_guard<std::mutex> lock(other.m);
		data=other.data;
	}
	stack& operator=(const stack&) = delete;

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		data.push(new_value); //#1
	}
	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lock(m);
		if(data.empty()) throw empty_stack(); //#2
		std::shared_ptr<T> const res(new T(data.top())); //#3
		data.pop(); //#4
		return res;
	}
	void pop(T& value)
	{
		std::lock_guard<std::mutex> lock(m);
		if(data.empty()) throw empty_stack();
		value=data.top(); //#5
		data.pop(); //#6
	}
	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m);
		return data.empty();
	}
};

// 6.2.2 A Thread-Safe Queue Using Locks And Condition Variables

// Listing 6.27: The Full Class Definition For A Thread-Safe Queue Using Condition Variables

template<typename T>
class queue
{
private:
	mutable std::mutex mut;
	std::queue<T> data_queue;
	std::condition_variable data_cond;
public:
	queue()
	{}
	queue(queue const& other)
	{
		std::lock_guard<std::mutex> lk(other.mut); 
		data_queue=other.data_queue;
	}

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(data);
		data_cond.notify_one(); //#1
	}

	void wait_and_pop(T& value) //#2
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();});
		value=data_queue.front();
		data_queue.pop();
	}

	std::shared_ptr<T> wait_and_pop() //#3
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();}); //#5
		std::shared_ptr<T> res(new T(data_queue.front()));
		data_queue.pop();
		return res;
	} 

	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if(data_queue.empty())
			return false;
		value=data_queue.front();
		data_queue.pop();
	}

	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if(data_queue.empty())
			return std::shared_ptr<T>(); //#4
		std::shared_ptr<T> res(new T(data_queue.front()));
		data_queue.pop();
		return res;
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
};

// Listing 6.28: A Thread-Safe Queue Holding std::shared_ptr<> Instances For Exception-Safety

template<typename T>
class queue
{
private:
	mutable std::mutex mut;
	std::queue<std::shared_ptr<T> > data_queue;
	std::condition_variable data_cond;
public:
	queue()
	{}
	queue(queue const& other)
	{
		std::lock_guard<std::mutex> lk(other.mut);
		data_queue=other.data_queue;
	}

	void push(T new_value)
	{
		std::shared_ptr<T> data(new T(new_value)); //#5
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(data);
		data_cond.notify_one();
	}

	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();});
		value=*data_queue.front(); //#1
		data_queue.pop();
	}

	std::shared_ptr<T> wait_and_pop()
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk,[]{return !data_queue.empty();});
		std::shared_ptr<T> res=data_queue.front(); //#3
		data_queue.pop();
		return res;
	}

	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if(data_queue.empty())
			return false;
		value=*data_queue.front(); //#2
		data_queue.pop();
	}

	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if(data_queue.empty())
			return std::shared_ptr<T>();
		std::shared_ptr<T> res=data_queue.front(); //#4
		data_queue.pop();
		return res;
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
};

// 6.2.3 A Thread-Safe Queue Using Fine-Grained Locks And Condition Variables

// Listing 6.29: A Simple Queue Implementation

template<typename T>
class queue
{
private:
	struct node
	{
		T data;
		node* next;
		
		node(T data_):
			data(data_),next(0)
		{}
	};

	node* head; //#1
	node* tail; //#2

public:
	queue():
		head(0),tail(0)
	{}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;
	~queue()
	{
		while(head)
		{
			node* const old_head=head;
			head=old_head->next;
			delete old_head;
		}
	}

	std::shared_ptr<T> try_pop()
	{
		if(!head)
		{
			return std::shared_ptr<T>();
		}
		std::shared_ptr<T> const res(new T(head->data));
		node* const old_head=head;
		head=old_head->next; //#6
		delete old_head;
		return res;
	}

	void push(T new_value)
	{
		std::auto_ptr<node> p(new node(new_value));
		if(tail)
		{
			tail->next=p.get(); //#5
		}
		else
		{
			head=p.get(); //#3
		}
		tail=p.release(); //#4
	}
};

// Enabling Concurrency By Separating Data

// Listing 6.30: A Simple Queue With A Dummy Node

template<typename T>
class queue
{
private:
	struct node
	{
		std::shared_ptr<T> data; //#2
		node* next;
		node():
			next(0)
		{}
	};

	node* head;
	node* tail;

public:
	queue():
		head(new node),tail(head) //#7
	{}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;

	~queue()
	{
		while(head)
		{
			node* const old_head=head;
			head=old_head->next;
			delete old_head;
		}
	}

	std::shared_ptr<T> try_pop()
	{
		if(head==tail) //#1
		{
			return std::shared_ptr<T>();
		}
		std::shared_ptr<T> const res(head->data); //#3
		node* const old_head=head;
		head=old_head->next; //#8
		delete old_head; //#9
		return res;
	}

	void push(T new_value)
	{
		std::shared_ptr<T> new_data(new T(new_value)); //#4
		std::auto_ptr<node> p(new node); //#5
		tail->data=new_data; //#6
		tail->next=p.get();
		tail=p.release();
	}
};

// OK

// Listing 6.31: A Thread-Safe Queue With Fine-Grained Locking

template<typename T>
class queue
{
private:
	struct node
	{
		std::shared_ptr<T> data;
		node* next;

		node():
			next(NULL)
		{}
	};

	std::mutex head_mutex;
	node* head;
	std::mutex tail_mutex;
	node* tail;

	node* get_tail()
	{
		std::lock_guard<std::mutex> tail_lock(tail_mutex);
		return tail;
	}

	node* pop_head()
	{
		std::lock_guard<std::mutex> head_lock(head_mutex);
		if(head==get_tail())
		{
			return NULL;
		}
		node* const old_head=head;
		head=old_head->next;
		return old_head;
	}

public:
	queue():
		head(new node),tail(head)
	{}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;

	~queue()
	{
		while(head)
		{
			node* const old_head=head;
			head=old_head->next;
			delete old_head;
		}
	}

	std::shared_ptr<T> try_pop()
	{
		node* old_head=pop_head();
		if(!old_head)
		{
			return std::shared_ptr<T>();
		}

		std::shared_ptr<T> const res(old_head->data);
		delete old_head;
		return res;
	}

	void push(T new_value)
	{
		std::shared_ptr<T> new_data(new T(new_value));
		std::auto_ptr<node> p(new node);
		std::lock_guard<std::mutex> tail_lock(tail_mutex);
		tail->data=new_data;
		tail->next=p.get();
		tail=p.release();
	}
};

// OK

// tail->next==NULL
// tail->data==NULL
// head==tail implies an empty list
// A single element list has head->next==tail
// For each node x in the list, where x!=tail, x->data points to an instance of T, and x->next points to the next node in the list. x->next==tail implies x is the last node in the list.
// Following the next nodes from head will eventually yield tail. 

// OK

node* pop_head() //#A
{
	node* const old_tail=get_tail(); //#1
	std::lock_guard<std::mutex> head_lock(head_mutex);

	if(head==old_tail) //#2
	{
		return NULL;
	}
	node* const old_head=head;
	head=old_head->next; //#3
	return old_head;
}

//#1 Get the old tail value outside the lock on head_mutex
//#A This is a broken implementation.

// Waiting For An Item To Pop

// Listing 6.32: A Thread-Safe Queue With Fine-Grained Locking And Waiting

template<typename T>
class queue
{
private:
	struct node
	{
		std::shared_ptr<T> data;
		node* next;

		node():
			next(NULL)
		{}
	};

	std::mutex head_mutex;
	node* head;
	std::mutex tail_mutex;
	node* tail;
	std::condition_variable data_cond;

	node* get_tail()
	{
		std::lock_guard<std::mutex> tail_lock(tail_mutex);
		return tail;
	}

	node* pop_head() //#1
	{
		node* const old_head=head;
		head=old_head->next;
		return old_head;
	}

	node* try_pop_head()
	{
		std::lock_guard<std::mutex> head_lock(head_mutex);

		if(head==get_tail())
		{
			return NULL;
		}
		return pop_head();
	}

	node* try_pop_head(T& value)
	{
		std::lock_guard<std::mutex> head_lock(head_mutex);

		if(head==get_tail())
		{
			return NULL;
		}
		value=*head->data;
		return pop_head();
	}

	std::unique_lock<std::mutex> wait_for_data() //#2
	{
		std::unique_lock<std::mutex> head_lock(head_mutex);
		data_cond.wait(head_lock,[&]{return head!=get_tail();});
		return head_lock; //#3
	}

	node* wait_pop_head()
	{
		std::unique_lock<std::mutex> head_lock(wait_for_data()); //#4
		return pop_head();
	}

	node* wait_pop_head(T& value)
	{
		std::unique_lock<std::mutex> head_lock(wait_for_data()); //#5
		value=*head->data;
		return pop_head();
	}

public:
	queue():
		head(new node),tail(head)
	{}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;

	~queue()
	{
		while(head)
		{
			node* const old_head=head;
			head=old_head->next;
			delete old_head;
		}
	}

	std::shared_ptr<T> try_pop()
	{
		node* const old_head=try_pop_head();
		if(!old_head)
		{
			return std::shared_ptr<T>();
		}

		std::shared_ptr<T> const res(old_head->data);
		delete old_head;
		return res;
	}

	bool try_pop(T& value)
	{
		node* const old_head=try_pop_head(value);
		if(!old_head)
		{
			return false;
		}
		delete old_head;
		return true;
	}

	std::shared_ptr<T> wait_and_pop()
	{
		node* const old_head=wait_pop_head();
		std::shared_ptr<T> const res(old_head->data);
		delete old_head;
		return res;
	}

	void wait_and_pop(T& value)
	{
		node* const old_head=wait_pop_head(value);
		delete old_head;
	}

	void push(T new_value)
	{
		std::shared_ptr<T> new_data(new T(new_value));
		std::auto_ptr<node> p(new node);
		{
			std::lock_guard<std::mutex> tail_lock(tail_mutex);
			tail->data=new_data;
			tail->next=p.get();
			tail=p.release();
		}
		data_cond.notify_one();
	}

	void empty()
	{
		std::lock_guard<std::mutex> head_lock(head_mutex);
		return (head==get_tail());
	}
};

// OK

// 6.3 Designing More Complex Lock-Based Data Structures

// 6.3.1 Writing A Thread-Safe Lookup Table Using Locks

// Add a new key/value pair;
// Change the value associated with a given key;
// Remove a key and its associated value; and
// Obtain the value associated with a given key if any.

// Designing A Map Data Structure For Fine-Grained Locking

// A binary tree, such as a red-black tree;
// A sorted array; and
// A hash table.

// Listing 6.33: A Thread-Safe Lookup Table

template<typename Key,typename Value,typename Hash=std::hash<Key> >
class lookup_table
{
private:
	typedef std::pair<Key,Value> bucket_value;
	typedef std::list<bucket_value> bucket_data;
	typedef typename bucket_data::iterator bucket_iterator;

	struct bucket_type
	{
		bucket_data data;
		boost::shared_mutex mutex; //#2

		bucket_iterator find_entry_for(Key const& key) //#10
		{
			return std::find_if(data.begin(),data.end(),
				[&](bucket_value const& item)
				{return item.first==key;});
		}
	};

	std::vector<bucket_type*> buckets; //#1
	Hash hasher;

	bucket_type& get_bucket(Key const& key) const //#3
	{
		std::size_t const bucket_index=hasher(key)%buckets.size();
		return *buckets[bucket_index];
	}

public:
	typedef Key key_type;
	typedef Value mapped_type;
	typedef Hash hash_type;

	lookup_table(unsigned num_buckets=19, Hash const& hasher_=Hash()):
		buckets(num_buckets),hasher(hasher_)
	{
		for(unsigned i=0;i<num_buckets;++i)
		{
			buckets[i]=new bucket_type;
		}
	}

	lookup_table(lookup_table const& other)=delete;
	lookup_table& operator=(lookup_table const& other)=delete;

	~lookup_table()
	{
		for(unsigned i=0;i<buckets.size();++i)
		{
			delete buckets[i];
		}
	}

	Value value_for(Key const& key,
		Value const& default_value=Value()) const
	{
		bucket_type& bucket=get_bucket(key); //#4
		boost::shared_lock<boost::shared_mutex> lock(bucket.mutex); //#7
		bucket_iterator const found_entry=bucket.find_entry_for(key);
		return (found_entry==bucket.data.end())?
		default_value : found_entry->second;
	}

	void add_or_update_mapping(Key const& key,Value const& value)
	{
		bucket_type& bucket=get_bucket(key); //#5
		std::unique_lock<boost::shared_mutex> lock(bucket.mutex); //#8
		bucket_iterator const found_entry=bucket.find_entry_for(key);
		if(found_entry==bucket.data.end())
		{
			bucket.data.push_back(bucket_value(key,value));
		}
		else
		{
			found_entry->second=value;
		}
	}

	void remove_mapping(Key const& key)
	{
		bucket_type& bucket=get_bucket(key); //#6
		std::unique_lock<boost::shared_mutex> lock(bucket.mutex); //#9
		bucket_iterator const found_entry=bucket.find_entry_for(key);
		if(found_entry!=bucket.data.end())
		{
			bucket.data.erase(found_entry);
		}
	}
};

// OK

// Listing 6.34: Obtaining The Contents Of A lookup_table As A std::map<>

std::map<Key,Value> lookup_table::get_map() const
{
	std::vector<std::unique_lock<boost::shared_mutex> > locks;
	for(unsigned i=0;i<buckets.size();++i)
	{
		locks.push_back(
		std::unique_lock<boost::shared_mutex>(buckets[i].mutex));
	}
	std::map<Key,Value> res;
	for(unsigned i=0;i<buckets.size();++i)
	{
		for(bucket_iterator it=buckets[i].data.begin();
			it!=buckets[i].data.end();
			++it)
		{
			res.insert(*it);
		}
	}
	return res;
}

// OK

// 6.3.2 Writing A Thread-Safe List Using Locks

// add an item to the list;
// remove an item from the list if it meets a certain condition;
// find an item in the list that meets a certain condition;
// update an item that meets a certain condition;
// copy each item in the list to another container.

// Listing 6.35: A Thread-Safe List With Iteration Support

template<typename T>
class concurrent_list
{
	struct node //#1
	{
		std::mutex m;
		std::shared_ptr<T> data;
		node* next;

		node(): //#2
			next(NULL)
		{}

		node(T const& value): //#4
			data(new T(value))
		{}
	};

	node head;

public:
	concurrent_list()
	{}

	concurrent_list(concurrent_list const& other)=delete;
	concurrent_list& operator=(concurrent_list const& other)=delete;

	~concurrent_list()
	{
		remove_if([](T const&){return true;});
	}

	void push_front(T const& value)
	{
		std::auto_ptr<node> new_node(new node(value)); //#3
		std::lock_guard<std::mutex> lk(head.m);
		new_node->next=head.next; //#5
		head.next=new_node.release(); //#6
	}

	template<typename Function>
	void for_each(Function f) //#7
	{
		node* current=&head;

		std::unique_lock<std::mutex> lk(head.m); //#8
		while(node* const next=current->next) //#9
		{
			std::unique_lock<std::mutex> next_lk(next->m); //#10
			lk.unlock(); //#11
			f(*next->data); //#12
			current=next;
			lk=std::move(next_lk); //#13
		}
	}

	template<typename Predicate>
	std::shared_ptr<T> find_first_if(Predicate p) //#14
	{
		node* current=&head;
		std::unique_lock<std::mutex> lk(head.m);
		while(node* const next=current->next)
		{
			std::unique_lock<std::mutex> next_lk(next->m);
			lk.unlock();
			if(p(*next->data)) //#15
			{
				return next->data; //#16
			}
			current=next;
			lk=std::move(next_lk);
		}
		return std::shared_ptr<T>();
	} 

	template<typename Predicate>
	void remove_if(Predicate p) //#17
	{
		node* current=&head;
		std::unique_lock<std::mutex> lk(head.m);
		while(node* const next=current->next)
		{
			std::unique_lock<std::mutex> next_lk(next->m);
			if(p(*next->data)) //#18
			{
				current->next=next->next; //#19
				next_lk.unlock();
				delete next; //#20
			}
			else
			{
				lk.unlock(); //#21
				current=next;
				lk=std::move(next_lk);
			}
		}
	}
};

// OK

// 6.4 Summary

// This chapter started by looking at what it meant to design a data structure for concurrency, and some guidelines for doing so. We've then worked through several common data structures [stack, queue, hash map and linked list] looking at how to apply those guidelines to implement them in a way designed for concurrent access, using locks to protect the data and prevent data races. You should now be able to look at the design of your own data structures to see where the opportunities for concurrency lie, and where there is potential for race conditions. In chapter 7 we'll look at ways of avoiding locks entirely, using the low-level atomic operations to provide the necessary ordering constraints, whilst sticking to the same set of guidelines.

// Chapter 7

// Designing Data Structures For Concurrency II: Lock-Free Concurrent Data Structures

// 7.1 The Pros And Cons Of Lock-Free Data Structures

// 7.2 Worked Examples Of Lock-Free Data Structures

// 7.2.1 Writing A Thread-Safe Stack Without Locks

// 9. Create a new node,
// 10. set its next pointer to the current head node, and
// 11. set the head node to point to it.

// Listing 7.36: Implementing push() Without Locks

template<typename T>
class stack
{
private:
	struct node
	{
		T data;
		node* next;

		node(T const& data_): //#4
			data(data_)
		{}
	};

	std::atomic<node*> head;
public:
	void push(T const& data)
	{
		node* const new_node=new node(data); //#1
		new_node->next=head.load(); //#2
		while(!head.compare_exchange_weak(new_node->next,new_node)); //#3
	}
};

// OK

// 12. Read the current value of head;
// 13. Read head->next;
// 14. Set head to head->next;
// 15. Return the data from the retrieved node;
// 16. Delete the retrieved node

template<typename T>
class stack
{
public:
	void pop(T& result)
	{
		node* old_head=head.load();
		while(!head.compare_exchange_weak(old_head,old_head->next));
		result=old_head->data;
	}
};

// OK

// Listing 7.37: A Lock-Free Stack That Leaks Nodes

template<typename T>
class stack
{
private:
	struct node
	{
		std::shared_ptr<T> data; //#1
		node* next;

		node(T const& data_):
			data(new T(data_)) //#2
		{}
	}; 

	std::atomic<node*> head;
public:
	void push(T const& data)
	{
		node* const new_node=new node(data);
		new_node->next=head.load();
		while(!head.compare_exchange_weak(new_node->next,new_node));
	}
	std::shared_ptr<T> pop()
	{
		node* old_head=head.load();
		while(old_head && //#3
			!head.compare_exchange_weak(old_head,old_head->next));
		return old_head ? old_head->data : std::shared_ptr<T>(); //#4
	}
};

// OK

// 7.2.2 Stopping Those Pesky Leaks: Managing Memory In Lock-Free Data Structures

// Listing 7.38: Reclaiming Nodes When No Threads Are In pop()

template<typename T>
class stack
{
private:
	std::atomic<unsigned> threads_in_pop; //#1
	std::atomic<node*> to_be_deleted;

	static void delete_nodes(node* nodes) //#7
	{
		while(nodes)
		{
			node* next=nodes->next;
			delete nodes;
			nodes=next;
		}
	}
public:
	std::shared_ptr<T> pop()
	{
		++threads_in_pop; //#2
		node* old_head=head.load();
		while(old_head &&
			!head.compare_exchange_weak(old_head,old_head->next));
		std::shared_ptr<T> res;
		if(old_head)
		{
			res.swap(old_head->data);
		}
		node* nodes_to_delete=to_be_deleted.load(); //#5
		if(!--threads_in_pop) //#3
		{
			if(to_be_deleted.compare_exchange_strong( //#6
				nodes_to_delete,NULL))
			{
				delete_nodes(nodes_to_delete);
			}
			delete old_head; //#4
		}
		else if(old_head) //#8
		{
			old_head->next=nodes_to_delete; //#9
			while(!to_be_deleted.compare_exchange_weak( //#10
				old_head->next,old_head));
		}
		return res;
	}
};

// OK

// 7.2.3 Detecting Nodes That Can't Be Reclaimed Using Hazard Pointers

std::shared_ptr<T> pop()
{
	std::atomic_address& hp=get_hazard_pointer_for_current_thread();
	node* old_head=head.load(); //#1
	node* temp;
	do
	{
		temp=old_head;
		hp.store(old_head); //#2
		old_head=head.load();
	} while(old_head!=temp); //#3
	// ...
}

// OK

// Listing 7.39: An Implementation Of pop() Using Hazard Pointers

std::shared_ptr<T> pop()
{
	std::atomic_address& hp=get_hazard_pointer_for_current_thread();
	node* old_head=head.load();
	do
	{
		node* temp;
		do 
		{
			temp=old_head;
			hp.store(old_head);
			old_head=head.load();
		} while(old_head!=temp);
	}
	while(old_head &&
		!head.compare_exchange_strong(old_head,old_head->next));
	hp.store(NULL); //#2
	std::shared_ptr<T> res;
	if(old_head)
	{
		res.swap(old_head->data);
		if(outstanding_hazard_pointers_for(old_head)) //#3
		{
			reclaim_later(old_head); //#4
		}
		else
		{
			delete old_head; //#5
		}
		delete_nodes_with_no_hazards(); //#6
	}
	return res;
}

// OK

// Listing 7.40: A Simple Implementation Of get_hazard_pointer_for_current_thread()

unsigned const max_hazard_pointers=100;
struct hazard_pointer
{
	std::atomic<std::thread::id> id;
	std::atomic_address pointer;
};
hazard_pointer hazard_pointers[max_hazard_pointers];

class hp_owner
{
	hazard_pointer* hp;

public:
	hp_owner(hp_owner const&)=delete;
	hp_owner operator=(hp_owner const&)=delete;

	hp_owner(): //#4
		hp(NULL)
	{
		for(unsigned i=0;i<max_hazard_pointers;++i)
		{
			std::thread::id old_id;
			if(hazard_pointers[i].id.compare_exchange_strong( //#5
				old_id,std::this_thread::get_id()))
			{
				hp=&hazard_pointers[i]; //#6
				break;
			}
		}
		if(!hp) //#7
		{
			throw std::runtime_error("No hazard pointers available");
		} 
	}
	
	std::atomic_address& get_pointer()
	{
		return hp->pointer;
	}

	~hp_owner() //#8
	{
		hp->pointer.store(NULL);
		hp->id.store(std::thread::id());
	}
};

std::atomic_address& get_hazard_pointer_for_current_thread() //#1
{
	thread_local static hp_owner hazard; //#2
	return hazard.get_pointer(); //#3
}

// OK

rough the hazard pointer table looking for entries.
bool outstanding_hazard_pointers_for(void* p)
{
	for(unsigned i=0;i<max_hazard_pointers;++i)
	{
		if(hazard_pointers[i].pointer.load()==p)
		{
			return true;
		}
	}
	return false;
}

// Listing 7.41: A Simple Implementation Of reclaim_later() And delete_nodes_with_no_hazards()

template<typename T>
void do_delete(void* p)
{
	delete static_cast<T*>(p);
}

struct data_to_reclaim
{
	void* data;
	std::function<void(void*)> deleter;
	data_to_reclaim* next;

	template<typename T>
	data_to_reclaim(T* p): //#4
		data(p),
		deleter(&do_delete<T>),
		next(0)
	{}

	~data_to_reclaim()
	{
		deleter(data); //#5
	}
};

std::atomic<data_to_reclaim*> nodes_to_reclaim;

void add_to_reclaim_list(data_to_reclaim* node) //#3
{
	node->next=nodes_to_reclaim.load();
	while(!nodes_to_reclaim.compate_exchange_weak(node->next,node));
}

template<typename T>
void reclaim_later(T* data) //#1
{
	add_to_reclaim_list(new data_to_reclaim(data)); //#2
}

void delete_nodes_with_no_hazards()
{
	data_to_reclaim* current=nodes_to_reclaim.exchange(NULL); //#6
	while(current)
	{
		data_to_reclaim* const next=current->next;
		if(!outstanding_hazard_pointers_for(current->data)) //#7
		{
			delete current; //#8
		}
		else
		{
			add_to_reclaim_list(current); //#9
		}
		current=next;
	}
}

// OK

// OKOKOK solid day of following some code logique and argumentation maybe walk through this book again multiple times and add a massive multiline comment up front with some thoughts and commentaries on algorithms or pass through again for Round 2 afterwards with more thoughts.

// Better Reclamation Strategies Using Hazard Pointers

// 7.2.4 Detecting Nodes In Use With Reference Counting

// Listing 7.42: A Lock-Free Stack Using A Lock-Free std::shared_ptr<> Implementation

class stack
{
private:
	struct node
	{
		std::shared_ptr<T> data;
		std::shared_ptr<node> next;

		node(T const& data_):
			data(new T(data_))
		{}
	};

	std::shared_ptr<node> head;
public:
	void push(T const& data)
	{
		std::shared_ptr<node> const new_node=new node(data);
		new_node->next=head.load();
		while(!std::atomic_compare_exchange_weak(&head,
			&new_node->next,new_node));
	}
	std::shared_ptr<T> pop()
	{
		std::shared_ptr<node> old_head=std::atomic_load(&head);
		while(old_head && !std::atomic_compare_exchange_weak(&head,
			&old_head,old_head->next));
		return old_head ? old_head->data : std::shared_ptr<T>();
	}
};

// OK

// Listing 7.43: A Lock-Free Stack Using Split Reference Counts

template<typename T>
class stack
{
private:
	struct node;

	struct counted_node_ptr //#1
	{
		int external_count;
		node* ptr;
	};

	struct node
	{
		std::shared_ptr<T> data;
		std::atomic_int internal_count; //#3
		counted_node_ptr next; //#2

		node(T const& data_):
			data(new T(data_)),
			internal_count(0)
		{}
	};

	std::atomic<counted_node_ptr> head; //#4

	void increase_head_count(counted_node_ptr& old_counter)
	{
		counted_node_ptr new_counter;

		do
		{
			new_counter=old_counter;
			++new_counter.external_count;
		}
		while(!head.compare_exchange_strong(old_counter,new_counter)); //#7
		old_counter.external_count=new_counter.external_count;
	}

public:
	~stack()
	{
		while(pop());
	}

	void push(T const& data) //#5
	{
		counted_node_ptr new_node;
		new_node.ptr=new node(data);
		new_node.external_count=1;
		new_node.ptr->next=head.load();
		while(!head.compare_exchange_weak(new_node.ptr->next,new_node));
	} 

	std::shared_ptr<T> pop() //#6
	{
		counted_node_ptr old_head=head.load();
		for(;;)
		{
			increase_head_count(old_head);
			node* const ptr=old_head.ptr; //#8
			if(!ptr)
			{
				return std::shared_ptr<T>();
			}
			if(head.compare_exchange_strong(old_head,ptr->next)) //#9
			{
				std::shared_ptr<T> res;
				res.swap(ptr->data); //#10
			
				int const count_increase=old_head.external_count-2; //#12

				if(ptr->internal_count.fetch_add(count_increase)== //#11
					-count_increase)
				{
					delete ptr;
				}

				return res; //#13
			}
			else if(ptr->internal_count.fetch_add(-1)==1)
			{
				delete ptr; //#14
			}
		}
	} 
};

 // OK

 // 7.2.5 Applying The Memory Model To Our Lock-Free Stack

void push(T const& data)
{
	counted_node_ptr new_node;
	new_node.ptr=new node(data);
	new_node.external_count=1;
	new_node.ptr->next=head.load();
	while(!head.compare_exchange_weak(new_node.ptr->next,new_node,
		std::memory_order_release,std::memory_order_relaxed));
}

// OK

// OK

void increase_head_count(counted_node_ptr& old_counter)
{
	counted_node_ptr new_counter;

	do
	{
		new_counter=old_counter;
		++new_counter.external_count;
	}
	while(!head.compare_exchange_strong(old_counter,new_counter,
		std::memory_order_acquire,std::memory_order_relaxed));

	old_counter.external_count=new_counter.external_count;
}

// Listing 7.44: A Lock-Free Stack With Reference Counting And Relaxed Atomic Operations

template<typename T>
class stack
{
private:
	struct node;


	struct counted_node_ptr
	{
		int external_count;
		node* ptr;
	};

	struct node
	{
		std::shared_ptr<T> data;
		std::atomic_int internal_count;
		counted_node_ptr next;
		node(T const& data_):
			data(new T(data_)),
			internal_count(0)
		{}
	};

	std::atomic<counted_node_ptr> head;

	void increase_head_count(counted_node_ptr& old_counter)
	{
		counted_node_ptr new_counter;

		do
		{
			new_counter=old_counter;
			++new_counter.external_count;
		}
		while(!head.compare_exchange_strong(old_counter,new_counter,
			std::memory_order_acquire,
			std::memory_order_relaxed));

		old_counter.external_count=new_counter.external_count;
	}

public:
	~stack()
	{
		while(pop());
	}

	void push(T const& data)
	{
		counted_node_ptr new_node;
		new_node.ptr=new node(data);
		new_node.external_count=1;
		new_node.ptr->next=head.load();
		while(!head.compare_exchange_weak(new_node.ptr->next,new_node,
			std::memory_order_release,
			std::memory_order_relaxed));
	}
	std::shared_ptr<T> pop()
	{
		counted_node_ptr old_head=
			head.load(std::memory_order_relaxed);
		for(;;)
		{
			increase_head_count(old_head);
			node* const ptr=old_head.ptr;
			if(!ptr)
			{
				return std::shared_ptr<T>();
			}
			if(head.compare_exchange_strong(old_head,ptr->next,
				std::memory_order_relaxed))
			{
				std::shared_ptr<T> res;
				res.swap(ptr->data);

				int const count_increase=old_head.external_count-2;

				if(ptr->internal_count.fetch_add(count_increase,
					std::memory_order_release)==-count_increase)
				{
					delete ptr;
				}

				return res;
			}
			else if(ptr->internal_count.fetch_add(-1,
				std::memory_order_relaxed)==1)
			{
				ptr->internal_count.load(std::memory_order_acquire);
				delete ptr;
			}
		}
	}
};

// OK

// 7.2.6 Writing A Thread-Safe Queue Without Locks

// Listing 7.45: A First Attempt At A Lock-Free Queue

template<typename T>
class queue
{
private:
	struct node
	{
		std::shared_ptr<T> data;
		node* next;

		node():
			next(NULL)
		{}
	};

	std::atomic<node*> head;
	std::atomic<node*> tail;

	node* pop_head()
	{
		node* const old_head=head.load();
		if(old_head==tail.load()) //#2
		{
			return NULL;
		}
		head.store(old_head->next);
		return old_head;
	}

public:
	queue():
		head(new node),tail(head.load())
	{}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;

	~queue()
	{
		while(node* const old_head=head.load())
		{
			head.store(old_head->next);
			delete old_head;
		}
	}
	std::shared_ptr<T> pop()
	{
		node* old_head=pop_head();
		if(!old_head)
		{
			return std::shared_ptr<T>();
		}

		std::shared_ptr<T> const res(old_head->data); //#4
		delete old_head;
		return res;
	}

	void push(T new_value)
	{
		std::shared_ptr<T> new_data(new T(new_value));
		node* p=new node; //#5
		node* const old_tail=tail.load() //#6
		old_tail->data.swap(new_data); //#3
		old_tail->next=p; //#7
		tail.store(p); //#1
	}
};

// OK

// Handling Multiple Threads In push()

// Listing 7.46: A First Attempt At Revising push()

void push(T new_value)
{
	std::unique_ptr<T> new_data(new T(new_value));
	counted_node_ptr new_next;
	new_next.ptr=new node;
	new_next.external_count=1;
	for(;;)
	{
		node* const old_tail=tail.load(); //#1
		T* old_data=NULL;
		if(old_tail->data.compare_exchange_strong(
			old_data,new_data.get())) //#2
		{
			old_tail->next=new_next;
			tail.store(new_next.ptr); //#3
			new_data.release();
			break;
		}
	}
}

// OK

// Listing 7.47: A Lock-Free Queue With A Reference-Counted Tail

template<typename T>
class queue
{
private:
	struct node;

	struct counted_node_ptr
	{
		int external_count;
		node* ptr;
	};

	struct node_counter
	{
		int internal_count:30;
		unsigned external_counters:2; //#3
	};

	struct node
	{
		std::atomic<T*> data;
		std::atomic<node_counter> count; //#2
		counted_node_ptr next;
		
		node()
		{
			node_counter new_count;
			new_count.internal_count=0;
			new_count.external_counters=2; //#4
			count.store(new_count);

			next.ptr=NULL;
			next.external_count=0;
		}

		void release_ref() //#8
		{
			node_counter old_counter=
				count.load(std::memory_order_relaxed);
			node_counter new_counter;
			do
			{
				new_counter=old_counter;
				--new_counter.internal_count;
			}
			while(!count.compare_exchange_strong(
				old_counter,new_counter,
				std::memory_order_acquire,std::memory_order_relaxed));

				if(!new_counter.internal_count &&
					!new_counter.external_counters)
				{
					delete this;
				}
		}

};

std::atomic<counted_node_ptr> head;
std::atomic<counted_node_ptr> tail; //#1

static void increase_external_count( //#5
	std::atomic<counted_node_ptr>& counter,
	counted_node_ptr& old_counter)
{
	counted_node_ptr new_counter;

	do
	{
		new_counter=old_counter;
		++new_counter.external_count;
	}
	while(!counter.compare_exchange_strong(
		old_counter,new_counter,
		std::memory_order_acquire,std::memory_order_relaxed));

	old_counter.external_count=new_counter.external_count;
}

static void free_external_counter(counted_node_ptr &old_node_ptr) //#6
{
	node* const ptr=old_node_ptr.ptr;
	int const count_increase=old_node_ptr.external_count-2;

	node_counter old_counter=
		ptr->count.load(std::memory_order_relaxed);
	node_counter new_counter;
	do
	{
		new_counter=old_counter;
		--new_counter.external_counters;
		new_counter.internal_count+=count_increase;
	}
	while(!ptr->count.compare_exchange_strong( //#7
		old_counter,new_counter,
		std::memory_order_acquire,std::memory_order_relaxed));

	if(!new_counter.internal_count &&
		!new_counter.external_counters)
	{
		delete ptr;
	}
}

public:
	queue()
	{
		counted_node_ptr new_node;
		new_node.external_count=1;
		new_node.ptr=new node;

		head.store(new_node);
		tail.store(new_node);
	}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;

	~queue()
	{
		while(pop());
		delete head.load().ptr;
	}
	std::unique_ptr<T> pop()
	{
		counted_node_ptr old_head=head.load(std::memory_order_relaxed);
		for(;;)
		{
			increase_external_count(head,old_head);
			node* const ptr=old_head.ptr;
			if(ptr==tail.load().ptr)
			{
				return std::unique_ptr<T>();
			}
			if(head.compare_exchange_strong(old_head,ptr->next))
			{
				T* const res=ptr->data.exchange(NULL);
				free_external_counter(old_head);
				return std::unique_ptr<T>(res);
			}
			ptr->release_ref();
		}
	}

	void push(T new_value)
	{
		std::unique_ptr<T> new_data(new T(new_value));
		counted_node_ptr new_next;
		new_next.ptr=new node;
		new_next.external_count=1; 
		counted_node_ptr old_tail=tail.load();

		for(;;)
		{
			increase_external_count(tail,old_tail);

			T* old_data=NULL;
			if(old_tail.ptr->data.compare_exchange_strong( //#9
				old_data,new_data.get()))
			{
				old_tail.ptr->next=new_next;
				old_tail=tail.exchange(new_next);
				free_external_counter(old_tail);
				new_data.release();
				break;
			}
			old_tail.ptr->release_ref();
		}
	}
};

// OK

// Helping Out Another Thread

// Listing 7.48: A Lock-Free Queue With Helping

template<typename T>
class queue
{
private:
	struct node;

	struct counted_node_ptr
	{
		int external_count;
		node* ptr;
	};

	struct node_counter
	{
		int internal_count:30;
		unsigned external_counters:2;
	};

	struct node
	{
		std::atomic<T*> data;
		std::atomic<node_counter> count;
		std::atomic<counted_node_ptr> next; //#1

		node()
		{
			node_counter new_count;
			new_count.internal_count=0;
			new_count.external_counters=2;
			count.store(new_count);

			counted_node_ptr next_node={0};
			next.store(next_node);
		}

		void release_ref()
		{
			node_counter old_counter=
				count.load(std::memory_order_relaxed);
			node_counter new_counter;
			do
			{
				new_counter=old_counter;
				--new_counter.internal_count;
			}
			while(!count.compare_exchange_strong(
				old_counter,new_counter,
				std::memory_order_acquire,std::memory_order_relaxed));

			if(!new_counter.internal_count &&
				!new_counter.external_counters)
			{
				delete this;
			}
		}

	};

	std::atomic<counted_node_ptr> head;
	std::atomic<counted_node_ptr> tail;

	static void increase_external_count(
		std::atomic<counted_node_ptr>& counter,
		counted_node_ptr& old_counter)
	{
		counted_node_ptr new_counter;

		do
		{
			new_counter=old_counter;
			++new_counter.external_count;
		}
		while(!counter.compare_exchange_strong(
			old_counter,new_counter,
			std::memory_order_acquire,
			std::memory_order_relaxed));

		old_counter.external_count=new_counter.external_count;
	}

	void set_new_tail(counted_node_ptr &old_tail, //#6
		counted_node_ptr const &new_tail)
	{
		node* const current_tail_ptr=old_tail.ptr;
		while(!tail.compare_exchange_weak(old_tail,new_tail) && //#7
			old_tail.ptr==current_tail_ptr);
		if(old_tail.ptr==current_tail_ptr) //#8
		{
			free_external_counter(old_tail); //#9
		}
		else
		{
			current_tail_ptr->release_ref(); //#10
		}
	}

	static void free_external_counter(counted_node_ptr &old_node_ptr)
	{
		node* const ptr=old_node_ptr.ptr;
		int const count_increase=old_node_ptr.external_count-2;

		node_counter old_counter=
			ptr->count.load(std::memory_order_relaxed);
		node_counter new_counter;
		do
		{
			new_counter=old_counter;
			--new_counter.external_counters;
			new_counter.internal_count+=count_increase;
		}
		while(!ptr->count.compare_exchange_strong(
			old_counter,new_counter,
			std::memory_order_acquire,std::memory_order_relaxed)); 
		if(!new_counter.internal_count &&
			!new_counter.external_counters)
		{
			delete ptr;
		}
	}

public:
	queue()
	{
		counted_node_ptr new_node;
		new_node.external_count=1;
		new_node.ptr=new node;

		head.store(new_node);
		tail.store(new_node);
	}

	queue(const queue& other)=delete;
	queue& operator=(const queue& other)=delete;

	~queue()
	{
		while(pop());
		delete head.load().ptr;
	}
	std::unique_ptr<T> pop() 
	{
		counted_node_ptr old_head=head.load(std::memory_order_relaxed);
		for(;;)
		{
			increase_external_count(head,old_head);
			node* const ptr=old_head.ptr;
			if(ptr==tail.load().ptr)
			{
				return std::unique_ptr<T>();
			}
			counted_node_ptr next=ptr->next.load(); //#2
			if(head.compare_exchange_strong(old_head,next))
			{
				T* const res=ptr->data.exchange(NULL);
				free_external_counter(old_head);
				return std::unique_ptr<T>(res);
			}
			ptr->release_ref();
		}
	}

	void push(T new_value)
	{ 
		std::unique_ptr<T> new_data(new T(new_value));
		counted_node_ptr new_next;
		new_next.ptr=new node;
		new_next.external_count=1;
		counted_node_ptr old_tail=tail.load();

		for(;;)
		{
			increase_external_count(tail,old_tail);
			T* old_data=NULL;
			if(old_tail.ptr->data.compare_exchange_strong(
				old_data,new_data.get()))
			{
				counted_node_ptr old_next={0};
				if(!old_tail.ptr->next.compare_exchange_strong( //#3
					old_next,new_next))
				{
					delete new_next.ptr; //#4
					new_next=old_next; //#5
				}
				set_new_tail(old_tail, new_next);
				new_data.release();
				break;
			}
			else
			{
				counted_node_ptr old_next={0};
				if(old_tail.ptr->next.compare_exchange_strong( //#11
					old_next,new_next))
				{
					old_next=new_next; //#12
					new_next.ptr=new node; //#13
				}
				set_new_tail(old_tail, old_next); //#14
			}
		}
	}
};

//#1 next pointer is now atomic
//#2 We must explicitly load() the next pointer

// OK

// 7.3 Guidelines For Writing Lock-Free Data Structures

// 7.3.1 Guideline: Use std::memory_order_seq_cst For Prototyping

// 7.3.2 Guideline: Use A Lock-Free Memory Reclamation Scheme

// Waiting until no threads are accessing the data structure and deleting all objects that are pending deletion then;

// Using hazard pointers to identify that a thread is accessing a particular object; and

// Reference counting the objects so that they aren't deleted until there are no outstanding references.

// 7.3.3 Guideline: Identify Busy-Wait Loops And “help” The Other Thread

// 7.4 Summary

// Chapter 8

// Designing Concurrent Code

// 8.1 Techniques for Dividing Work Between Threads

// 8.1.1 Dividing Data Between Threads Before Processing Begins

// 8.1.2 Dividing Data Recursively

// Listing 8.49: Parallel Quick Sort Using A Stack Of Pending Chunks To Sort

template<typename T>
struct sorter //#2
{
	struct chunk_to_sort
	{
		std::list<T> data;
		bool end_of_data;
		std::promise<std::list<T> > promise;

		chunk_to_sort(bool done=false):
			end_of_data(done)
		{}

	};

	thread_safe_stack<chunk_to_sort> chunks; //#3
	std::vector<std::thread> threads; //#4
	unsigned const max_thread_count;

	sorter():
		max_thread_count(std::thread::hardware_concurrency()-1)
	{}

	~sorter() //#16
	{
		for(unsigned i=0;i<threads.size();++i)
		{
			chunks.push(std::move(chunk_to_sort(true))); //#18
		}

		for(unsigned i=0;i<threads.size();++i)
		{
			threads[i].join(); //#19
		}
	}

	bool try_sort_chunk()
	{
		boost::shared_ptr<chunk_to_sort > chunk=chunks.pop(); //#11
		if(chunk)
		{
			if(chunk->end_of_data) //#20
			{
				return false;
			}
			sort_chunk(chunk); //#12
		}
		return true;
	}

	std::list<T> do_sort(std::list<T>& chunk_data) //#5
	{
		if(chunk_data.empty())
		{
			return chunk_data;
		}

		std::list<T> result;
		result.splice(result.begin(),chunk_data,chunk_data.begin());
		T const& partition_val=*result.begin();

		typename std::list<T>::iterator divide_point= //#6
			std::partition(chunk_data.begin(),chunk_data.end(),
				less_than<T>(partition_val));

		chunk_to_sort new_lower_chunk;
		new_lower_chunk.data.splice(new_lower_chunk.data.end(),
			chunk_data,chunk_data.begin(),
			divide_point);

		std::unique_future<std::list<T> > new_lower=
			new_lower_chunk.promise.get_future();
		chunks.push(std::move(new_lower_chunk)); //#7
		if(threads.size()<max_thread_count) //#8
		{
			threads.push_back(std::thread(&sorter<T>::sort_thread,this));
		}

		std::list<T> new_higher(do_sort(chunk_data));

		result.splice(result.end(),new_higher);
		while(!new_lower.is_ready()) //#9
		{
			try_sort_chunk(); //#10
		}

		result.splice(result.begin(),new_lower.get());
		return result;
	}

	void sort_chunk(boost::shared_ptr<chunk_to_sort > const& chunk)
	{
		chunk->promise.set_value(do_sort(chunk->data)); //#13
	}

	void sort_thread()
	{
		while(try_sort_chunk()) //#21
		{
			std::this_thread::yield();
		}
	}
};

template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input) //#1
{
	if(input.empty())
	{
		return input;
	}
	sorter<T> s;

	return s.do_sort(input); //#17
}

// OK

// 8.1.3 Dividing Work By Task Type

// Dividing Work By Task Type To Separate Concerns

// Dividing A Sequence Of Tasks Between Threads

// 8.2 Factors Affecting The Performance Of Concurrent Code

// 8.2.1 How Many Processors?

// 8.2.2 Data Contention And Cache Ping Pong

std::atomic<unsigned long> counter(0);
void processing_loop()
{
	while(counter.fetch_add(1,std::memory_order_relaxed)<100000000)
	{
		do_something();
	}
}

// OK

std::mutex m;
my_data data;
void processing_loop_with_mutex()
{
	while(true)
	{
		std::lock_guard<std::mutex> lk(m);
		if(done_processing(data)) break;
	}
}

// OK

// 8.2.3 False Sharing

// 8.2.4 How Close Is My Data?

// 8.2.5 Over-Subscription And Excessive Task Switching

// 8.3 Designing Data Structures For Multithreaded Performance

// 8.3.1 Dividing Array Elements For Complex Operations

// 8.3.2 Data Access Patterns In Other Data Structures

// try to adjust the data distribution between threads so that data that is close together is worked on by the same thread,

// try to minimize the data required by any given thread, and

// try to ensure that data accessed by separate threads is sufficiently far apart to avoid false sharing.

// One way to test whether this kind of false sharing is a problem is to add huge blocks of padding between the data elements that can be concurrently accessed by different threads. e.g.

struct protected_data
{
	std::mutex m;
	char padding[65536];
	my_data data_to_protect;
};

// to test the mutex contention issue, or

struct my_data
{
	data_item1 d1;
	data_item2 d2;
	char padding[65536];
};
my_data some_array[256];

// 8.4 Additional Considerations When Designing Code For Concurrency

// 8.4.1 Exception Safety In Parallel Algorithms

// Listing 8.50: A Parallel Version Of std::accumulate

template<typename Iterator,typename T>
struct accumulate_block
{
	void operator()(Iterator first,Iterator last,T& result)
	{
		result=std::accumulate(first,last,result); //#10
	}
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
	unsigned long const length=std::distance(first,last); //#1

	if(!length)
		return init;

	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread;

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads=
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads;
	
	std::vector<T> results(num_threads); //#2
	std::vector<std::thread> threads(num_threads-1); //#3

	Iterator block_start=first; //#4
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		Iterator block_end=block_start; //#5
		std::advance(block_end,block_size);
		threads[i]=std::thread( //#6
			accumulate_block<Iterator,T>(),
			block_start,block_end,std::ref(results[i]));
		block_start=block_end; //#7
	}
	accumulate_block()(block_start,last,results[num_threads-1]); //#8

	std::for_each(threads.begin(),threads.end(),
		std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(),results.end(),init); //#9
}

// OK

// Adding Exception Safety

// Listing 8.51: A Parallel Version Of std::accumulate Using std::packaged_task

template<typename Iterator,typename T>
struct accumulate_block
{
	T operator()(Iterator first,Iterator last) //#1
	{
		return std::accumulate(first,last,T()); //#2
	}
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
	unsigned long const length=std::distance(first,last);

	if(!length)
		return init;

	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread;

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads=
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads;

	std::vector<std::unique_future<T> > futures(num_threads-1); //#3
	std::vector<std::thread> threads(num_threads-1);

	Iterator block_start=first;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		Iterator block_end=block_start;
		std::advance(block_end,block_size);
		std::packaged_task<T(Iterator,Iterator)> task( //#4
			accumulate_block<Iterator,T>());
		futures[i]=std::move(task.get_future()); //#5
		threads[i]=std::thread(std::move(task),block_start,block_end); //#6
		block_start=block_end;
	}
	T last_result=accumulate_block()(block_start,last); //#7

	std::for_each(threads.begin(),threads.end(),
		std::mem_fn(&std::thread::join));

	T result=init; //#8
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		result+=futures[i].get(); //#9
	}
	result += last_result; //#10
	return result;
}

// OK

try
{
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		// ... as before
	}
	T last_result=accumulate_block()(block_start,last);

	std::for_each(threads.begin(),threads.end(),
		std::mem_fn(&std::thread::join));
}

catch(...)
{
	for(unsigned long i=0;i<(num_thread-1);++i)
	{
		if(threads[i].joinable())
		thread[i].join();
	}
	throw;
}

// OK

class join_threads
{
	std::vector<std::thread>& threads;
public:
	explicit join_threads(std::vector<std::thread>& threads_):
		threads(threads_)
	{}
	~join_threads()
	{
		for(unsigned long i=0;i<threads.size();++i)
		{
			if(threads[i].joinable())
				threads[i].join();
		}
	}
};

// OK

// Listing 8.52: An Exception-Safe Parallel Version Of std::accumulate

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
	unsigned long const length=std::distance(first,last);

	if(!length)
		return init;

	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread;

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads=
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads;

	std::vector<std::unique_future<T> > futures(num_threads-1);
	std::vector<std::thread> threads(num_threads-1);
	join_threads joiner(threads); //#1

	Iterator block_start=first;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{ 
		Iterator block_end=block_start;
		std::advance(block_end,block_size);
		std::packaged_task<T(Iterator,Iterator)> task(
			accumulate_block<Iterator,T>());
		futures[i]=std::move(task.get_future());
		threads[i]=std::thread(std::move(task),block_start,block_end);
		block_start=block_end;
	}
	T last_result=accumulate_block()(block_start,last);
	T result=init;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		result+=futures[i].get(); //#2
	}
	result += last_result;
	return result;
}

// OK

// 8.4.2 Scalability And Amdahl's Law

// 8.4.3 Hiding Latency With Multiple Threads

// 8.4.4 Improving Responsiveness With Concurrency

while(true)
{
	event_data event=get_event();
	if(event.type==quit)
		break;
	process(event);
}

// Listing 8.53: Separating GUI Thread From Task Thread

std::thread task_thread;
std::atomic<bool> task_cancelled(false);

void gui_thread()
{
	while(true)
	{
		event_data event=get_event();
		if(event.type==quit)
			break;
		process(event);
	}
}

void task()
{
	while(!task_complete() && !task_cancelled)
	{
		do_next_operation();
	}
	if(task_cancelled)
	{
		perform_cleanup();
	}
	else
	{
		post_gui_event(task_complete);
	}
}

void process(event_data const& event)
{
	switch(event.type)
	{
	case start_task:
		task_cancelled=false;
		task_thread=std::thread(task);
		break;
	case stop_task:
		task_cancelled=true;
		task_thread.join();
		break;
	case task_complete:
		task_thread.join();
		display_results();
		break;
	default:
		// ...
	}
}

// OK

// 8.5 Designing Concurrent Code In Practice

// 8.5.1 A Parallel Implementation Of std::for_each

// Listing 8.54: A Parallel Version Of std::for_each

template<typename Iterator,typename Func>
void parallel_for_each(Iterator first,Iterator last,Func f)
{
	unsigned long const length=std::distance(first,last);
	if(!length)
		return;

	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread;

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads=
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads;

	std::vector<std::unique_future<void>> futures(num_threads-1); //#1
	std::vector<std::thread> threads(num_threads-1);
	join_threads joiner(threads);

	Iterator block_start=first;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		Iterator block_end=block_start;
		std::advance(block_end,block_size);
		std::packaged_task<void(void)> task( //#2
			[=]()
			{ 
				std::for_each(block_start,block_end,f);
			});
		futures[i]=std::move(task.get_future());
		threads[i]=std::thread(std::move(task)); //#3
		block_start=block_end;
	}
	std::for_each(block_start,last,f);
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		futures[i].get(); //#4
	}
}

// OK

// 8.5.2 A Parallel Implementation Of std::find

// Listing 8.55: An Implementation Of A Parallel Find Algorithm

template<typename Iterator,typename MatchType>
Iterator parallel_find(Iterator first,Iterator last,MatchType match)
{
	struct find_element //#1
	{
		void operator()(Iterator begin,Iterator end,
			MatchType match,
			std::promise<Iterator>* result,
			std::atomic<bool>* done_flag)
		{
			try
			{
				for(;(begin!=end) && !done_flag->load();++begin) //#2
				{
					if(*begin==match)
					{
						result->set_value(begin); //#3
						done_flag->store(true); //#4
						return;
					}
				}
			}
			catch(...) //#5
			{
				try
				{
					result->set_exception(std::current_exception()); //#6
					done_flag->store(true);
				}
				catch(...) //#7
				{}
			}
		}
	}; 

	unsigned long const length=std::distance(first,last);
	
	if(!length)
		return last;

	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread;

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads=
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads;

	std::promise<Iterator> result; //#8
	std::atomic<bool> done_flag(false); //#9
	std::vector<std::thread> threads(num_threads-1); 
	{ //#12
		join_threads joiner(threads);

		Iterator block_start=first;
		for(unsigned long i=0;i<(num_threads-1);++i)
		{
			Iterator block_end=block_start;
			std::advance(block_end,block_size);
			threads[i]=std::thread(find_element(), //#10
				block_start,block_end,match,
				&result,&done_flag);
			block_start=block_end;
		}
		find_element()(block_start,last,match,&result,&done_flag); //#11
	}
	if(!done_flag.load()) //#13
	{
		return last;
	}
	return result.get_future().get(); //#14
}

// OK

// 8.5.3 A Parallel Implementation Of std::partial_sum

// Listing 8.56: Calculating Partial Sums In Parallel By Dividing The Problem

template<typename Iterator>
void parallel_partial_sum(Iterator first,Iterator last)
{
	typedef typename Iterator::value_type value_type;

	struct process_chunk //#12
	{
		void operator()(Iterator begin,Iterator last,
			std::unique_future<value_type>*
			previous_end_value,
			std::promise<value_type>* end_value)
		{
			try
			{
				Iterator end=last;
				++end;
				std::partial_sum(begin,end); //#13
				if(previous_end_value) //#14
				{
					value_type& addend=previous_end_value->get(); //#15
					*last+=addend; //#16
					if(end_value)
					{
						end_value->set_value(*last); //#17
					}
					std::for_each(begin,last,[addend](value_type& item) //#18
					{
						item+=addend;
					});
				}
				else if(end_value)
				{
					end_value->set_value(*last); //#19
				}
			} 
			catch(...) //#20
			{
				if(end_value)
				{
					end_value->set_exception(std::current_exception()); //#21
				}
				else
				{
					throw; //#22
				}
			}
		}
	};

	unsigned long const length=std::distance(first,last);

	if(!length)
		return last;

	unsigned long const min_per_thread=25; //#1
	unsigned long const max_threads= 
		(length+min_per_thread-1)/min_per_thread;

	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();

	unsigned long const num_threads=
		std::min(hardware_threads!=0?hardware_threads:2,max_threads);

	unsigned long const block_size=length/num_threads;

	typedef typename Iterator::value_type value_type;

	std::vector<std::thread> threads(num_threads-1); //#2
	std::vector<std::promise<value_type>> end_values(num_threads-1); //#3
	std::vector<std::unique_future<value_type>> previous_end_values; //#4
	previous_end_values.reserve(num_threads-1); //#5
	join_threads joiner(threads);

	Iterator block_start=first;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		Iterator block_last=block_start;
		std::advance(block_last,block_size-1); //#6
		threads[i]=std::thread(process_chunk(), //#7
			block_start,block_last,
			(i!=0)?&previous_end_values[i-1]:0,
			&end_values[i]);
		block_start=block_last;
		++block_start; //#8
		previous_end_values.push_back(end_values[i].get_future()); //#9
	}
	Iterator final_element=block_start;
	std::advance(final_element,std::distance(block_start,last)-1); //#10
	process_chunk()(block_start,final_element, //#11
		(num_threads>1)?&previous_end_values.back():0,
		0);
}

// OK

// Implementing The Incremental Pairwise Algorithm For Partial Sums

// Listing 8.57: A Really Simple Barrier Class

class barrier
{
	unsigned const count;
	std::atomic<unsigned> spaces;
	std::atomic<unsigned> generation;
public:
	explicit barrier(unsigned count_): //#1
		count(count_),spaces(count),generation(0)
	{}
	void wait()
	{
		unsigned const my_generation=generation; //#6
		if(!--spaces) //#2
		{
			spaces=count; //#3
			++generation; //#4
		}
		else
		{
			while(generation==my_generation) //#5
			std::this_thread::yield(); //#7
		}
	}
};

// OK

void done_waiting()
{
	--count; //#1
	if(!--spaces) //#2
	{
		spaces=count.load(); //#3
		++generation;
	}
}

// OK

// Listing 8.58: A Parallel Implementation Of partial_sum By Pairwise Updates

struct barrier
{
	std::atomic<unsigned> count;
	std::atomic<unsigned> spaces;
	std::atomic<unsigned> generation;

	barrier(unsigned count_):
		count(count_),spaces(count_),generation(0)
	{}

	void wait()
	{
		unsigned const gen=generation.load();
		if(!--spaces)
		{
			spaces=count.load();
			++generation;
		}
		else
		{
			while(generation.load()==gen)
			{
				std::this_thread::yield();
			}
		}
	}

	void done_waiting()
	{
		--count;
		if(!--spaces)
		{
			spaces=count.load();
			++generation;
		}
	}
};

template<typename Iterator>
void parallel_partial_sum(Iterator first,Iterator last)
{
	typedef typename Iterator::value_type value_type;

	struct process_element //#1
	{
		void operator()(Iterator first,Iterator last,
			std::vector<value_type>& buffer,
			unsigned i,barrier& b)
		{
			value_type& ith_element=*(first+i);
			bool update_source=false;

			for(unsigned step=0,stride=1;stride<=i;++step,stride*=2)
			{
				value_type const& source=(step%2)? //#5
					buffer[i]:ith_element;
				value_type& dest=(step%2)?
					ith_element:buffer[i];
				value_type const& addend=(step%2)? //#6
					buffer[i-stride]:*(first+i-stride);

				dest=source+addend; //#7
				update_source=!(step%2);
				b.wait(); //#8
			}

			if(update_source) //#9
			{
				ith_element=buffer[i];
			}
			b.done_waiting(); //#10
		}
	};

	unsigned long const length=std::distance(first,last);

	if(length<=1)
		return;

	std::vector<value_type> buffer(length);
	barrier b(length);

	std::vector<std::thread> threads(length-1); //#3
	join_threads joiner(threads);

	Iterator block_start=first;
	for(unsigned long i=0;i<(length-1);++i)
	{
		threads[i]=std::thread(process_element(),first,last, //#2
		std::ref(buffer),i,std::ref(b));
	}
	process_element()(first,last,buffer,length-1,b); //#4
}

// OK

// 8.6 Summary

// We've covered quite a lot of ground in this chapter. We started with various techniques for dividing work between threads such as dividing the data beforehand, or using a number of threads to form a pipeline. We then looked at the issues surrounding the performance of multi-threaded code from a low-level perspective, with a look at false sharing and data contention before moving on to how the patterns of data access can affect the performance of a bit of code. We then looked at additional considerations in the design of concurrent code, such as exception safety and scalability. Finally, we've ended with a number of examples of parallel algorithm implementations, each of which have highlighted particular issues that can occur when designing multi-threaded code. One item that has cropped up a couple of times in this chapter is the idea of a "thread pool" - a preconfigured group of threads which run tasks assigned to the pool. There is quite a lot of thought that goes into the design of a good thread pool, so we'll look at some of the issues in the next chapter, along with other aspects of advanced thread management.

// Chapter 9

// Advanced Thread Management

// OKOKOK oh goodie me there we go we shall see the so called Advanced thread management so there you go there you have it will be advanced one hopes you know beauty, Truth, wise dom, knawledge brah like Institute For Advanced Study is uh errm advanced righto merely the simplest of simple widdle logique poems if you follow each argument, puzzle, and structure quite closely, clearly, technically, and precisely with thine own noodle noddle noggin.

// In earlier chapters, we've been explicitly managing our threads by creating std::thread objects for each and every thread. In a couple of places we've seen how this can be undesirable, as we then have to manage the lifetime of the thread objects, determine the number of threads appropriate to the problem and to the current hardware, and so forth. The ideal scenario would be that we could just divide the code up into the smallest pieces that can be executed concurrently, pass them over to the compiler and library and say "parallelise this for optimal performance". Another recurring theme in several of the examples is that you might use several threads to solve a problem, but require that they finish early if some condition is met. This might be because the result has already been determined, or because an error has occurred, or even because the user has explicitly requested that the operation be aborted. Whatever the reason, the threads need to be sent a "please stop" request so that they can give up on the task they were given, tidy up, and finish as soon as possible. In this chapter, we're going to look at mechanisms for both of these, starting with the automatic management of the number of threads, and the division of tasks between them. 

// 9.1 Thread Pools

// 9.1.1 The Simplest Possible Thread Pool

// Listing 9.59: Simple Thread Pool

class thread_pool
{
	std::atomic_bool done;
	thread_safe_queue<std::function<void()>> work_queue; //#2
	std::vector<std::thread> threads; //#1
	join_threads joiner; //#7

	void worker_thread()
	{
		while(!done) //#9
		{
			std::function<void()> task;
			if(work_queue.try_pop(task)) //#10
			{
				task(); //#11
			}
			else
			{
				std::this_thread::yield(); //#12
			}
		}
	}

public:
	thread_pool():
		joiner(threads),done(false)
	{
		unsigned const thread_count=std::thread::hardware_concurrency(); //#4
		
		try
		{
			for(unsigned i=0;i<thread_count;++i)
			{
				threads.push_back(
				std::thread(&thread_pool::worker_thread,this)); //#5
			}
		}
		catch(...)
		{
			done=true; //#6
			throw;
		}
	}

	~thread_pool()
	{
		done=true;
	}

	template<typename FunctionType>
	void submit(FunctionType f)
	{
		work_queue.push(std::function<void()>(f)); //#3
	}
};

// OK

// 9.1.2 Waiting For Tasks Submitted To A Thread Pool

// Listing 9.60: A Thread Pool With Waitable Tasks

class thread_pool
{
public:
	template<typename ResultType>
	using task_handle=std::unique_future<ResultType>; //#1

	template<typename FunctionType>
	task_handle<std::result_of<FunctionType()>::type> //#2
		submit(FunctionType f)
	{
		typedef std::result_of<FunctionType()>::type result_type; //#3

		std::packaged_task<result_type()> task(f); //#4
		task_handle<result_type> res(task.get_future()); //#5
		work_queue.push(std::move(task)); //#6
		return res; //#7
	}
	// The rest as before.
};

// Listing 9.61: parallel_accumulate Using A Thread Pool With Waitable Tasks

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
	unsigned long const length=std::distance(first,last);

	if(!length)
		return init;

	unsigned long const block_size=25;
	unsigned long const num_blocks=(length+block_size-1)/block_size; //#1

	std::vector<thread_pool::task_handle<T>> futures(num_blocks-1);
	thread_pool pool;

	Iterator block_start=first;
	for(unsigned long i=0;i<(num_threads-1);++i)
	{
		Iterator block_end=block_start;
		std::advance(block_end,block_size);
		futures[i]=pool.submit(accumulate_block<Iterator,T>()); //#2
		block_start=block_end;
	}
	T last_result=accumulate_block()(block_start,last);
	T result=init;
	for(unsigned long i=0;i<(num_blocks-1);++i)
	{
		result+=futures[i].get();
	}
	result += last_result;
	return result;
}

// 9.1.3 Tasks That Wait For Other Tasks

// Listing 9.62: An Implementation Of run_pending_task()

void thread_pool::run_pending_task()
{
	std::function<void()> task;
	if(work_queue.try_pop(task))
	{
		task();
	}
	else
	{
		std::this_thread::yield();
	}
}

// Listing 9.63: A Thread-Pool Based Implementation Of Quick Sort

template<typename T>

struct sorter //#1
{
	thread_pool pool; //#2

	std::list<T> do_sort(std::list<T>& chunk_data)
	{
		if(chunk_data.empty())
		{
			return chunk_data;
		}

		std::list<T> result;
		result.splice(result.begin(),chunk_data,chunk_data.begin());
		T const& partition_val=*result.begin();

		typename std::list<T>::iterator divide_point=
			std::partition(chunk_data.begin(),chunk_data.end(),
				less_than<T>(partition_val));

		std::list<T> new_lower_chunk;
		new_lower_chunk.splice(new_lower_chunk.end(),
			chunk_data,chunk_data.begin(),
			divide_point);

		thread_pool::task_handle<std::list<T>> new_lower= //#3
			pool.submit(std::bind(&sorter::do_sort,this,
				std::move(new_lower_chunk)));

		std::list<T> new_higher(do_sort(chunk_data));

		result.splice(result.end(),new_higher);
		while(!new_lower.is_ready())
		{
			pool.run_pending_task(); //#4
		}

		result.splice(result.begin(),new_lower.get());
		return result;
	}
};

template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
	if(input.empty())
	{
		return input;
	}
	sorter<T> s;
	return s.do_sort(input);
}

// OK

// 9.1.4 Avoiding Contention On The Work Queue

// Listing 9.64: A Thread-Pool With Thread-Local Work Queues

class thread_pool
{
	thread_safe_queue<std::function<void()> > pool_work_queue;
	typedef std::queue<std::function<void()> > local_queue_type; //#6
	static thread_local std::unique_ptr<local_queue_type>
		local_work_queue; //#1

	void worker_thread()
	{
		local_work_queue.reset(new local_queue_type); //#2

		while(!done)
		{
			run_pending_task();
		}
	}

public:
	template<typename FunctionType>
	task_handle<std::result_of<FunctionType()>::type>
		submit(FunctionType f)
	{
		typedef std::result_of<FunctionType()>::type result_type;

		std::packaged_task<result_type()> task(f);
		task_handle<result_type> res(task.get_future());
		if(local_work_queue) //#3
		{
			local_work_queue->push(std::move(task));
		}
		else
		{
			pool_work_queue.push(std::move(task)); //#4
		}
		return res;
	}

	void run_pending_task()
	{
		std::function<void()> task;
		if(local_work_queue && !local_work_queue->empty()) //#5
		{
			task=std::move(local_work_queue->front());
			local_work_queue->pop();
			task();
		}
		else if(pool_work_queue.try_pop(task)) //#7
		{
			task();
		}
		else
		{
			std::this_thread::yield();
		}
	}
	// The rest as before.
};

// OK

// 9.1.5 Work-Stealing

// Listing 9.65: Lock-Based Queue For Work-Stealing

class work_stealing_queue
{
private:
	typedef std::function<void()> data_type;
	std::deque<data_type> the_queue; //#1
	mutable std::mutex the_mutex;

public:
	work_stealing_queue()
	{}

	work_stealing_queue(const work_stealing_queue& other)=delete;
	work_stealing_queue& operator=(
		const work_stealing_queue& other)=delete;

	void push(data_type const& data) //#2
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		the_queue.push_front(data);
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		return the_queue.empty();
	}

	bool try_pop(data_type& res) //#3
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		if(the_queue.empty())
		{
			return false;
		}

		res=std::move(the_queue.front());
		the_queue.pop_front();
		return true;
	} 

	bool try_steal(data_type& res) //#4
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		if(the_queue.empty())
		{
			return false;
		} 
		res=std::move(the_queue.back());
		the_queue.pop_back();
		return true;
	}
};

// OK

// Listing 9.66: A Thread Pool That Uses Work Stealing

class thread_pool
{
	typedef std::function<void()> task_type;

	std::atomic_bool done;
	thread_safe_queue<task_type> pool_work_queue;
	std::vector<std::unique_ptr<work_stealing_queue> > queues; //#3
	std::vector<std::thread> threads;
	join_threads joiner;

	static thread_local work_stealing_queue* local_work_queue; //#1
	static thread_local unsigned my_index;

	void worker_thread(unsigned my_index_)
	{
		my_index=my_index_;
		local_work_queue=queues[my_index].get(); //#4
		while(!done)
		{
			run_pending_task();
		}
	}

	bool pop_task_from_local_queue(task_type& task)
	{
		return local_work_queue && local_work_queue->try_pop(task);
	}

	bool pop_task_from_pool_queue(task_type& task)
	{
		return pool_work_queue.try_pop(task);
	}

	bool pop_task_from_other_thread_queue(task_type& task) //#8
	{
		for(unsigned i=0;i<queues.size();++i)
		{
			unsigned const index=(my_index+i+1)%queues.size(); //#9
			if(queues[index]->try_steal(task))
			{
				return true;
			}
		}

		return false;
	}

public:
	thread_pool():
		joiner(threads),done(false)
	{
		unsigned const thread_count=std::thread::hardware_concurrency();

		try
		{
			for(unsigned i=0;i<thread_count;++i)
			{
				queues.push_back(std::unique_ptr<work_stealing_queue>( //#2
					new work_stealing_queue));
				threads.push_back(
					std::thread(&thread_pool::worker_thread,this,i));
			}
		}
		catch(...)
		{
			done=true;
			throw; 

		}
	}

	~thread_pool()
	{
		done=true;
	}

	template<typename ResultType>
	using task_handle=std::unique_future<ResultType>;

	template<typename FunctionType>
	task_handle<std::result_of<FunctionType()>::type> submit(
		FunctionType f)
	{
		typedef std::result_of<FunctionType()>::type result_type;

		std::packaged_task<result_type()> task(f);
		task_handle<result_type> res(task.get_future());
		if(local_work_queue)
		{
			local_work_queue->push(std::move(task));
		}
		else
		{
			pool_work_queue.push(std::move(task));
		}
		return res;
	}

	void run_pending_task()
	{
		task_type task;
		if(pop_task_from_local_queue(task) || //#5
			pop_task_from_pool_queue(task) || //#6
			pop_task_from_other_thread_queue(task)) //#7
		{
			task();
		}
		else
		{
			std::this_thread::yield();
		}
	}
};

// OK

// 9.2 Interrupting Threads

// 9.2.1 Launching And Interrupting Another Thread

class interruptible_thread
{
public:
	template<typename FunctionType>
	interruptible_thread(FunctionType f);
	void join();
	void detach();
	bool joinable() const;
	void interrupt();
};

// OK

// Listing 9.67: Basic Implementation Of interruptible_thread

class interrupt_flag
{
public:
	void set();
	bool is_set() const;
};
thread_local interrupt_flag this_thread_interrupt_flag;

class interruptible_thread
{
	std::thread internal_thread;
	interrupt_flag* flag;
public:
	template<typename FunctionType>
	interruptible_thread(FunctionType f)
	{
		struct wrapper
		{
			FunctionType m_f;
			
			wrapper(FunctionType& f_):
				m_f(f_)
			{}

			void operator()(interrupt_flag** flag_ptr,
				std::mutex* m,std::condition_variable* c)
			{
				{
					std::lock_guard<std::mutex> lk(m);
					*flag_ptr=&this_thread_interrupt_flag;
				}
				c.notify_one();

				m_f();
			}
		};

		std::mutex flag_mutex;
		std::condition_variable flag_condition;
		flag=0;
		internal_thread=std::thread(wrapper(f),&flag,
			&flag_mutex,&flag_condition);
		std::unique_lock ul(flag_mutex);
		while(!flag)
		{
			flag_condition.wait(ul);
		}
	}

	void interrupt()
	{
		if(flag)
		{
			flag->set();
		}
	}
};

// OK

// 9.2.2 Detecting That A Thread Has Been Interrupted

void interruption_point()
{
	if(this_thread_interrupt_flag.is_set())
	{
		throw thread_interrupted();
	}
}

// OK

void foo()
{
	while(!done)
	{
		interruption_point();
		process_next_item();
	}
}

// 9.2.3 Interrupting A Condition Variable Wait

// Listing 9.68: A Broken Implementation Of interruptible_wait For std::condition_variable

void interruptible_wait(std::condition_variable& cv,
	std::unique_lock<std::mutex>& lk)
{
	interruption_point();
	this_thread_interrupt_flag.set_condition_variable(cv); //#1
	cv.wait(lk); //#2
	this_thread_interrupt_flag.clear_condition_variable(); //#3
	interruption_point();
}

// OK

// Listing 9.69: An Implementation Of interruptible_wait For std::condition_variable Using A Timeout

class interrupt_flag
{
	std::atomic<bool> flag;
	std::condition_variable* thread_cond;
	std::mutex set_clear_mutex;

public:
	interrupt_flag():
		thread_cond(0)
	{}

	void set()
	{
		flag.store(true,std::memory_order_relaxed);
		std::lock_guard<std::mutex> lk(set_clear_mutex);
		if(thread_cond)
		{
			thread_cond->notify_all();
		}
	}

	bool is_set() const
	{
		return flag.load(std::memory_order_relaxed);
	}

	void set_condition_variable(std::condition_variable& cv)
	{
		std::lock_guard<std::mutex> lk(set_clear_mutex);
		thread_cond=&cv;
	}

	void clear_condition_variable()
	{
		std::lock_guard<std::mutex> lk(set_clear_mutex);
		thread_cond=0;
	}

	struct clear_cv_on_destruct
	{
		~clear_cv_on_destruct()
		{
			this_thread_interrupt_flag.clear_condition_variable();
		}
	};

};

void interruptible_wait(std::condition_variable& cv,
	std::unique_lock<std::mutex>& lk)
{
	interruption_point();
	this_thread_interrupt_flag.set_condition_variable(cv);
	interrupt_flag::clear_cv_on_destruct guard;
	interruption_point();
	cv.wait_for(lk,std::chrono::milliseconds(1));
	interruption_point();
}

// Of course, if we have the predicate that's being waited for then the 1ms timeout can be completely hidden inside the predicate loop:

template<typename Predicate>
void interruptible_wait(std::condition_variable& cv,
	std::unique_lock<std::mutex>& lk,
	Predicate pred)
{
	interruption_point();
	this_thread_interrupt_flag.set_condition_variable(cv);
	interrupt_flag::clear_cv_on_destruct guard;
	while(!this_thread_interrupt_flag.is_set() && !pred())
	{
		cv.wait_for(lk,std::chrono::milliseconds(1));
	}
	interruption_point();
}

// 9.2.4 Interrupting A Wait On std::condition_variable_any

// 9.2.4 Interrupting A Wait On std::condition_variable_any

// Listing 9.70: An Implementation Of interruptible_wait For std::condition_variable_any Using A Custom Lock Type

class interrupt_flag
{
	std::atomic<bool> flag;
	std::condition_variable* thread_cond;
	std::condition_variable_any* thread_cond_any;
	std::mutex set_clear_mutex;

public:
	interrupt_flag():
		thread_cond(0),thread_cond_any(0)
	{}

	void set()
	{
		flag.store(true,std::memory_order_relaxed);
		std::lock_guard<std::mutex> lk(set_clear_mutex);
		if(thread_cond)
		{
			thread_cond->notify_all();
		}
		else if(thread_cond_any)
		{
			thread_cond_any->notify_all();
		}
	}

	template<typename Lockable>
	void wait(std::condition_variable_any& cv,Lockable& lk)
	{
		struct custom_lock
		{
			interrupt_flag* self;
			Lockable& lk;

			custom_lock(interrupt_flag* self_,
					std::condition_variable_any& cond,
					Lockable& lk_):
				self(self_),lk(lk_)
			{
				self->set_clear_mutex.lock();
				self->thread_cond_any=&cond;
			}

			void unlock()
			{
				lk.unlock();
				self->set_clear_mutex.unlock();
			}

			void lock()
			{
				self->set_clear_mutex.lock();
				lk.lock();
			}

			~custom_lock()
			{
				self->thread_cond_any=0;
				self->set_clear_mutex.unlock();
			}
		};
		custom_lock cl(this,cv,lk);
		interruption_point();
		cv.wait(cl);
		interruption_point();
	}

	// The rest as before.
};

template<typename Lockable>
void interruptible_wait(std::condition_variable_any& cv,
	Lockable& lk)
{
	this_thread_interrupt_flag.wait(cv,lk);
}

// OK

// 9.2.5 Interrupting Other Blocking Calls

template<typename T>
void interruptible_wait(std::unique_future<T>& uf)
{
	while(!this_thread_interrupt_flag.is_set() && !uf.is_ready())
	{
		uf.wait_for(lk,std::chrono::milliseconds(1));
	}
	interruption_point();
}

// 9.2.6 Handling Interruptions

try
{
	do_something();
}
catch(thread_interrupted&)
{
	handle_interruption();
}

// OK

void interruptible_thread::wrapper::operator()(
	interrupt_flag** flag_ptr,
	std::mutex* m,std::condition_variable* c)
{
	{
		std::lock_guard<std::mutex> lk(m);
		*flag_ptr=&this_thread_interrupt_flag;
	}
	c.notify_one();
	try
	{
		m_f();
	}
	catch(thread_interrupted&)
	{}
}

// OK

// 9.2.7 Interrupting Background Tasks On Application Exit

// Listing 9.71: Monitouring The File System In The Background

std::mutex config_mutex;
std::vector<interruptible_thread> background_threads;
void background_thread(int disk_id)
{
	while(true)
	{
		interruption_point(); //#7
		fs_change fsc=get_fs_changes(disk_id); //#5
		if(fsc.has_changes())
		{
			update_index(fsc); //#6
		}
	}
}
void start_background_processing()
{
	background_threads.push_back(
	interruptible_thread(background_thread,disk_1));
	background_threads.push_back(
	interruptible_thread(background_thread,disk_2));
}
int main()
{
	start_background_processing(); //#1
	process_gui_until_exit(); //#2
	std::unique_lock<std::mutex> lk(config_mutex);
	for(unsigned i=0;i<background_threads.size();++i)
	{
		background_threads[i].interrupt(); //#3
	}
	for(unsigned i=0;i<background_threads.size();++i)
	{
		background_threads[i].join(); //#4
	}
} 

// OK

// 9.3 Summary

// In this chapter, we've looked at various "advanced" thread management techniques: thread pools, and interrupting threads. We've seen how the use of local work queues and work stealing can reduce the synchronisation overhead and potentially improve the throughput of the thread pool, and how running other tasks from the queue whilst waiting for a sub-task to complete can eliminate the potential for deadlock. We've also looked at various ways of allowing one thread to interrupt the processing of another, such as the use of specific interruption points and functions that perform what would otherwise be a blocking wait in a way that can be interrupted. 

// Chapter 10

// Testing And Debugging Multithreaded Applications

// 10.1 Types Of Concurrency-Related Bugs

// Unwanted blocking and
// Race Conditions

// 10.1.1 Unwanted Blocking

// Deadlock. As we saw in chapter 3, in the case of deadlock one thread is waiting for another, which is in turn waiting for the first. If your threads deadlock then the tasks they are doing will not get done. In the most visible cases, one of the threads involved is the thread responsible for the user interface, in which case the interface will cease to respond. In other cases the interface will remain responsive, but some required task won't complete, such as a search not returning, or a document not printing.

// Livelock. Livelock is similar to deadlock in that one thread is waiting for another, which is in turn waiting for the first. The key difference here is that the wait is not a blocking wait, but an active checking loop, such as a spin-lock. In serious cases, the symptoms are the same as deadlock (app doesn't make any progress), except that the CPU usage is high because threads are still running, but blocking each other. In not-so-serious cases, the livelock will eventually resolve due to the random scheduling, but there will be a long delay in the task that got live-locked, with a high CPU usage during that delay.

// Blocking on Input/Output or other external input. If your thread is blocked waiting for external input then it cannot proceed, even if the waited-for input is never going to come. It is therefore undesirable to block on external input from a thread that also performs tasks that other threads may be waiting for.

// 10.1.2 Race Conditions

// Data races. A data race is the specific type of race condition that results in undefined behaviour due to unsynchronised concurrent access to a shared memory location. We introduced data races in chapter 5 when we looked at the C++ memory model. Data races usually occur through incorrect usage of atomic operations to synchronise threads, or through access to shared data without locking the appropriate mutex.

// Broken invariants. This can manifest as dangling pointers (other thread deleted data being accessed), random memory corruption (read inconsistent values due to partial updates), double-free (two threads pop the same value from a queue) amongst others.

// Lifetime issues. Though you could bundle these problems in with the broken invariants, this really is a separate category. The basic problem with bugs in this category is that the thread outlives the data that it accesses, so it is accessing data that has been deleted or otherwise destroyed, and potentially even has had the storage reused for another object. You typically get lifetime issues where a thread references local variables which go out of scope before the thread function has completed, but it is not limited to that scenario. Whenever the lifetime of the thread and the data it operates on are not tied together in some way there is the potential for the data to be destroyed before the thread has finished, and for the thread function to have the rug pulled out from under its feet. If you manually call join() in order to wait for the thread to complete, you need to ensure that the call to join() cannot be skipped due to an exception being thrown. This is just basic exception safety applied to threads.

// 10.2 Techniques For Locating Concurrency-Related Bugs

// 10.2.1 Reviewing Code To Locate Potential Bugs

// Questions To Think About When Reviewing Multithreaded Code

// Which data needs to be protected from concurrent access?

// How do you ensure that the data is protected?

// Where in the code could other threads be at this time?

// Which mutexes does this thread hold?

// Which mutexes might other threads hold?

// Is the data loaded by this thread still valid? Could it have been modified by other threads?

// If we assume that another thread could be modifying the data, what would that mean and how could we ensure that this never happened?

// 10.2.2 Locating Concurrency-Related Bugs By Testing

/*

One thread calling push() or pop() on its own to verify that the queue does work at a basic level;

One thread calling push() on an empty queue whilst another thread calls pop();

Multiple threads calling push() on an empty queue;

Multiple threads calling push() on a full queue;

Multiple threads calling pop() on an empty queue;

Multiple threads calling pop() on a full queue;

Multiple threads calling pop() on a partially-full queue with insufficient items for all threads;

Multiple threads calling push() whilst one thread calls pop() on an empty queue;

Multiple threads calling push() whilst one thread calls pop() on a full queue;

Multiple threads calling push() whilst multiple threads call pop() on an empty
queue;

Multiple threads calling push() whilst multiple threads call pop() on a full queue;

what we mean by “multiple threads” in each case (3, 4, 1024?);

whether or not there are enough processing cores in the system for each thread to run on its own core;

which processor architectures the tests should be run on; and

how we ensure suitable scheduling for the “whilst” parts of our tests

*/

// 10.2.3 Designing For Testability

/*

the responsibilities of each function and class are clear;

the functions are short and to-the-point;

your tests can take complete control of the environment surrounding the code being tested;

the code that performs the particular operation being tested is close together rather than spread throughout the system; and

you thought about how to test the code before you wrote it

*/

// 10.2.4 Multi-Threaded Testing Techniques

// Brute Force Testing

// Combination Simulation Testing

// Detecting Problems Exposed By Tests With A Special Library

// 10.2.5 Testing The Performance Of Multithreaded Code

// 10.3 Summary

// In this chapter we've looked at various types of concurrency-related bugs that you might encounter, from deadlocks and livelocks to data races and other problematic race conditions. We've then followed that up with techniques for locating bugs. These included issues to think about during code reviews, and guidelines for writing testable code, and how to structure tests for concurrent code. Finally, we've looked at some utility components that can help with testing.

// Appendix A

// Overview Of New C++0x Language Features

// A.1 Rvalue References

int var=42;
int& ref=var; //#1
ref=99;
assert(var==99); //#2

// #1 create a reference to var
// #2 original updated due to assignment to reference

int& i=42; //#1
// #1 Will not compile

int const& i=42;

// OK

void print(std::string const& s);
print(“hello”); //#1
// #1 create temporary std::string object

int&& i=42;
int j=42;
int&& k=j; //#1
//#1 Will not compile

// A.1.1 Move Semantics

void process_copy(std::vector<int> const& vec_)
{
	std::vector<int> vec(vec_);
	vec.push_back(42);
}

// OK

void process_copy(std::vector<int> && vec)
{
	vec.push_back(42);
}

// Listing A.72: A class With A Move Constructor

class X
{
private:
	int* data;
public:
	X():
		data(new int[1000000])
	{}
	~X()
	{
		delete data;
	}
	X(const X& other): //#1
		data(new int[1000000])
	{
		std::copy(other.data,other.data+1000000,data);
	}
	X(X&& other): //#2
		data(other.data)
	{
		other.data=0;
	}
};

// OK

X x1;
X x2=std::move(x1);
X x3=static_cast<X&&>(x2);

// OK

void do_stuff(X&& x_)
{
	X a(x_); //#1
	X b(std::move(x_)); //#2
}
do_stuff(X()); //#3
X x;
do_stuff(x); //#4

/*
#1 copies
#2 moves
#3 OK, rvalue binds to rvalue reference
#4 Error, lvalue cannot bind to rvalue reference
*/

// A.1.2 Rvalue References And Function Templates

template<typename T>
void foo(T&& t)
{}

// OK

foo(42); //#1
foo(3.14159); //#2
foo(std::string()); //#3

/*
#1 Calls foo<int>(42)
#2 Calls foo<double>(3.14159)
#3 Calls foo<std::string>(std::string())
*/

int i=42;
foo(i); //#1
#1 Calls foo<int&>(i)

// A.2 Deleted Functions

class no_copies
{
public:
	no_copies(){}
private:
	no_copies(no_copies const&); //#1
	no_copies& operator=(no_copies const&); //#1
};
no_copies a;
no_copies b(a); //#2

/*
#1 No implementation.
#2 Won't compile.
*/

class no_copies
{
public:
	no_copies(){}
	no_copies(no_copies const&) = delete;
	no_copies& operator=(no_copies const&) = delete;
};

// OK

// Listing A.73: A Simple Move-Only Type

class move_only
{
	std::unique_ptr<my_class> data;
public:
	move_only(const move_only&) = delete;
	move_only(move_only&& other):
		data(std::move(other.data))
	{}
	move_only& operator=(const move_only&) = delete;
	move_only& operator=(move_only&& other)
	{
		data=std::move(other.data);
		return *this;
	}
};

move_only m1;
move_only m2(m1); //#1
move_only m3(std::move(m1)); //#2

/*
#1 Error, copy constructor is declared deleted.
#2 OK, move constructor found.
*/

void foo(short);
void foo(int) = delete;

foo(42); //#1
foo((short)42); //#2

/*
#1 Error, int overload declared deleted.
#2 OK
*/

// A.3 Defaulted Functions

/*
In order to change the accessibility of the function. By default, the compiler generated functions are public. If you wish to make them protected or even private then you must write them yourself. By declaring them as defaulted you can get the compiler to write the function and change the access level.

As documentation - if the compiler-generated version is sufficient, then it might be worth explicitly declaring it as such so that when you or someone else looks at the code later it is clear that this was intended. 

In order to force the compiler to generate the function when it would not otherwise have done. This is typically done with default constructors, which are only normally compiler-generated if there are no user-defined constructors. If you need to define a custom copy constructor (for example), you can still get a compiler-generated default constructor by declaring it as defaulted.

In order to make a destructor virtual whilst leaving it as compiler-generated.

To force a particular declaration of the copy constructor, such as having it take the source parameter by a non-const reference rather than by a const reference.

To take advantage of the special properties of the compiler-generated function which are lost if you provide an implementation. More on this in a moment.
*/

class Y
{
private:
	Y() = default; //#1
public:
	Y(Y&) = default; //#2
	T& operator=(const Y&) = default; //#3
protected:
	virtual ~Y() = default; //#4
};

/*
#1 Change access of default constructor to private.
#2 Change copy constructor to accept a non-const reference.
#3 Explicitly declare the copy-assignment operator defaulted with the default declaration and access.
#4 Change the destructor to be protected and virtual but still compiler-generated.
*/

/*
objects with trivial copy constructors, trivial copy assignment operators and trivial destructors can be copied with memcpy or memmove;

literal types used for constexpr functions (see section A.4) must have a trivial constructor, copy constructor and destructor;

classes with a trivial default constructor, copy constructor, copy assignment operator and destructor can be used in a union with a user-defined constructor and destructor;

classes with trivial copy assignment operators can be used with the std::atomic<> class template (see section 5.2.6) in order to provide a value of that type with atomic operations
*/

struct aggregate
{
	aggregate() = default;
	aggregate(aggregate const&) = default;
	int a;
	double b;
};
aggregate x={42,3.141};

// OK

struct X
{
	int a;
};

// OK

X x1; //#1
// #1 x1.a has undefined value

X x2=X(); //#1
#1 x1.a==0

// OK

X::X():a(){} #1
X::X():a(42){} #2
X::X(){} #3

/*
#1 a==0 always
#2 a==42 always
#3 a uninitialized for non-static instances of X, a==0 for static instances of X
*/

X::X() = default; //#1
// #1 default initialization rules for a apply

// A.4 constexpr Functions

const int i=23;
const int two_i=i*2;
const int four=4;
const int forty_two=two_i-four;

// specify the bounds of an array

int bounds=99;
int array[bounds]; //#1
const int bounds2=99;
int array2[bounds2]; //#2

/*
#1 Error bounds is not a constant expression.
#2 OK, bounds2 is a constant expression.
*/

// specify the value of a non-type template parameter:

template<unsigned size>
struct test
{};
test<bounds> ia; //#1
test<bounds2> ia2; //#2

/*
#1 Error bounds is not a constant expression.
#2 OK, bounds2 is a constant expression.
*/

// provide an initializer for a static const class data member of integral type in the class definition:

class X
{
	static const int the_answer=forty_two;
};

// provide an initialiser for a built-in type or aggregate that can be used for static initialisation:

struct my_aggregate
{
	int a;
	int b;
};
static my_aggregate ma1={forty_two,123}; //#1
int dummy=257;
static my_aggregate ma2={dummy,dummy}; //#2

/*
#1 static initialisation.
#2 dynamic initialisation.
*/

// Static initialisation like this can be used to avoid order-of-initialisation problems and race conditions.

constexpr int square(int x)
{
	return x*x;
}
int array[square(5)];

// OK

int dummy=4;
int array[square(dummy)]; //#1

// #1 error, dummy is not a constant expression.

// A.4.1 constexpr And User-Defined Types

/*
it must have a trivial copy constructor,

it must have a trivial destructor,

all non-static data members and base classes must be trivial types, and

it must have either a trivial default constructor or a constexpr constructor other than the copy constructor.
*/

// Listing A.74: A Class With A Trivial Default Constructor

class CX
{
private:
	int a;
	int b;
public:
	CX() = default; //#1
	CX(int a_, int b_): //#2
		a(a_),b(b_)
	{}
	int get_a() const
	{
		return a;
	}
	int get_b() const
	{
		return b;
	}
	int foo() const
	{
		return a+b;
	}
};

// OK

constexpr CX create_cx()
{
	return CX();
}

// OK

constexpr CX clone(CX val)
{
	return val;
}

// OK

class CX
{
private:
	int a;
	int b;
public:
	CX() = default;
	constexpr CX(int a_, int b_):
		a(a_),b(b_)
	{}
	constexpr int get_a() const //#1
	{
		return a;
	}
	constexpr int get_b() //#2
	{
		return b;
	}
	constexpr int foo()
	{
		return a+b;
	}
};

// OK

constexpr CX make_cx(int a)
{
	return CX(a,1);
}
constexpr CX half_double(CX old)
{
	return CX(old.get_a()/2,old.get_b()*2);
}
constexpr int foo_squared(CX val)
{
	return square(val.foo());
}
int array[foo_squared(half_double(make_cx(10)))]; //#1
// #1 49 elements

CX si=half_double(CX(42,19)); //#1
//#1 statically initialized

// A.4.2 constexpr Objects

constexpr int i=45; //#1
constexpr std::string s("hello"); //#2
int foo();
constexpr int j=foo(); //#3

/*
#1 OK
#2 Error, std::string is not a literal type
#3 Error, foo() is not declared constexpr
*/

// A.4.3 constexpr Function Requirements

/*
all parameters must be of a literal type;

the return type must be a literal type;

the function body must consist of a single return statement;

the expression in the return statement must qualify as a constant expression; and

any constructor or conversion operator used to construct the return value from the expression must be constexpr.

constexpr member functions cannot be virtual; and

the class for which the function is a member must be a literal type

the constructor body must be empty;

every base class must be initialized;

every non-static data member must be initialized;

any expressions used in the member initialization list must qualify as a constant expression;

the constructors chosen for the initialization of the data members and base classes must be constexpr constructors; and

any constructor or conversion operator used to construct the data members and base classes from their corresponding initialization expression must be constexpr.

*/

// A.4.4 constexpr And Templates

template<typename T>
constexpr T sum(T a,T b)
{
	return a+b;
}
constexpr int i=sum(3,42); //#1
std::string s=sum(std::string(“hello”),std::string(" world")); //#2

/*
#1 OK, sum<int> is constexpr
#2 Also OK, but sum<std::string> is not constexpr
*/

// A.5 Lambda Functions

[]{ //#1
	do_stuff();
	do_more_stuff();
}(); //#2

/*
#1 Start the lambda expression with []
#2 Finish the lambda expression, and call it with no parameters
*/

std::vector<int> data=make_data();
std::for_each(data.begin(),data.end(),[](int i){std::cout<<i<<”\n”;});

// Listing A.75: A Simple Lambda With A Deduced Return Type

std::condition_variable cond;
bool data_ready;
std::mutex m;
void wait_for_data()
{
	std::unique_lock<std::mutex> lk(m);
	cond.wait(lk,[]{return data_ready;}); //#1
}

// OK

cond.wait(lk,[]()->bool{return data_ready;});

// OK

cond.wait(lk,[]()->bool{
	if(data_ready)
	{
		std::cout<<”Data ready”<<std::endl;
		return true;
	}
	else
	{
		std::cout<<”Data not ready, resuming wait”<<std::endl;
		return false;
	}
});

// A.5.1 Lambda Functions That Reference Local Variables

std::function<int(int)> make_offseter(int offset)
{
	return [=](int j){return offset+j;};
}

// OK

int main()
{
	std::function<int(int)> offset_42=make_offseter(42);
	std::function<int(int)> offset_123=make_offseter(123);
	std::cout<<offset_42(12)<<”,“<<offset_123(12)<<std::endl;
	std::cout<<offset_42(12)<<”,“<<offset_123(12)<<std::endl;
}

// OK

int main()
{
	int offset=42; //#2
	std::function<int(int)> offset_a=[&](int j){return offset+j;}; //#1
	offset=123; //#3
	std::function<int(int)> offset_b=[&](int j){return offset+j;}; //#4
	std::cout<<offset_a(12)<<”,”<<offset_b(12)<<std::endl; //#5
	offset=99; //#7
	std::cout<<offset_a(12)<<”,”<<offset_b(12)<<std::endl; //#6
}

// OK

int main()
{
	int i=1234,j=5678,k=9;
	std::function<int()> f=[=,&j,&k]{return i+j+k;};
	i=1;
	j=2;
	k=3;
	std::cout<<f()<<std::endl;
}

// OK

int main()
{
	int i=1234,j=5678,k=9;
	std::function<int()> f=[&,j,k]{return i+j+k;};
	i=1;
	j=2;
	k=3;
	std::cout<<f()<<std::endl;
}

// OK

int main()
{
	int i=1234,j=5678,k=9;
	std::function<int()> f=[&i,j,&k]{return i+j+k;};
	i=1;
	j=2;
	k=3;
	std::cout<<f()<<std::endl;
}

// OK

struct X
{
	int some_data;
	void foo(std::vector<int>& vec)
	{
		std::for_each(vec.begin(),vec.end(),
			[this](int& i){i+=some_data;});
	}
};

// A.6 Variadic Templates

template<typename ... ParameterPack>
class my_template
{};

template<typename FunctionType>
class packaged_task;

template<typename ReturnType,typename ... Args>
class packaged_task<ReturnType(Args...)>;

// A.6.1 Expanding The Parameter Pack

template<typename ... Params>
struct dummy
{
	std::tuple<Params...> data;
};

// OK

template<typename ... Params>
struct dummy2
{
	std::tuple<std::string,Params...> data;
};

// OK

template<typename ... Params>
struct dummy3
{
	std::tuple<Params* ...> pointers;
	std::tuple<std::unique_ptr<Params> ...> unique_pointers;
};

// OK

// The expansion of:

std::tuple<std::pair<std::unique_ptr<Params>,double> ... > // is
std::tuple<std::pair<std::unique_ptr<int>,double>,
std::pair<std::unique_ptr<int>,double>,
std::pair<std::unique_ptr<char>,double> >

// OK

template<typename ... Types>
struct dummy4
{
	std::pair<Types...> data;
};
dummy4<int,char> a; //#1
dummy4<int> b; //#2
dummy4<int,int,int> c; //#3

/*
#1 OK, data is std::pair<int,char>
#2 Error, std::pair<int> is lacking a second type
#3 Error, std::pair<int,int,int> has too many types
*/

template<typename ... Args>
void foo(Args ... args);

// OK

template<typename CallableType,typename ... Args>
thread::thread(CallableType&& func,Args&& ... args);

// OK

template<typename ... ArgTypes>
void bar(ArgTypes&& ... args)
{
	foo(std::forward<ArgTypes>(args)...);
}

// OK

int i;
bar(i,3.141,std::string("hello"));

// OK

template<>
void bar<int&,double,std::string>(
	int& args_1,
	double&& args_2,
	std::string&& args_3)
{
	foo(std::forward<int&>(args_1),
		std::forward<double>(args_2),
		std::forward<std::string>(args_3));
}

// OK

template<typename ... Args>
unsigned count_args(Args ... args)
{
	return sizeof... (Args);
}

// A.7 Summary

/*
This appendix has only scratched the surface of the new language features introduced with the C++0x standard, as we've only looked at those features that actively affect the usage of the thread library. Other new language features include automatic variable type deduction, static assertions, strongly-typed enumerations, delegating constructors, Unicode support, template aliases, and a new uniform initialization sequence, along with a host of smaller changes. Describing all the new features in detail is outside the scope of this book - it would probably require a book in itself. The best overview of the entire standard is probably Bjarne Stroustrup's C++0x FAQ [Stroustup2009]. Hopefully the brief introduction to the new features covered in this appendix has provided enough depth to show how they relate to the thread library, and to enable you to write and understand multithreaded code that uses these new features. Though this appendix should provide enough depth for simple uses of the features covered, this is still only a brief introduction and not a complete reference or tutorial for the use of these features. If you intend to make extensive use of them then I would recommend acquiring such a reference or tutorial in order to gain the most benefit from them.
*/