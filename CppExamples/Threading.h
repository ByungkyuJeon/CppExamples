#pragma once

#include <Thread>
#include <mutex>

// Threading with no param
void operationWithNoParam()
{
	std::cout << "operation with no param called" << std::endl;
}

// Threading with param
void operationWithParams(int num, std::string& str)
{
	std::cout << num << " " + str << std::endl;
}

void operationWithRefReturn(int& num)
{
	num = 3;
}

int operationWithLambdaReturn()
{
	return 3;
}

void operationWithMutex(int& num, std::mutex& mutex)
{
	for (int count = 0; count < 10000; count++)
	{
		mutex.lock();
		num++; // locking critical section
		mutex.unlock();
	}
}

void executeThreading()
{
	// Threading with no param
	std::cout << "--- Threading with no params Example ---" << std::endl;
	{
		std::thread threadExample{ operationWithNoParam };
		threadExample.join();
	}

	// Threading with params
	std::cout << "--- Threading with params Example ---" << std::endl;
	{
		std::string strExample = "string param";
		int numExample = 32;
		std::thread threadExample{ operationWithParams, numExample, std::ref(strExample) };
		threadExample.join();
	}

	// Threading with return value
	std::cout << "--- Threading with return value Example ---" << std::endl;
	// 1. pass by ref
	{
		int numExample = 0;
		std::thread threadExample{ operationWithRefReturn, std::ref(numExample) };
		threadExample.join();
		std::cout << numExample << std::endl;
	}
	// 2. get by lambda
	{
		int numExample = 0;
		std::thread threadExample{ [&](void) {numExample = operationWithLambdaReturn(); } };
		threadExample.join();
		std::cout << numExample << std::endl;
	}
	// 3. use async

	// Thread local variable keyword
	std::cout << "--- Thread local variable keyword Example ---" << std::endl;
	{
		// thread_local variable is a storage duration specifier that is scoped in each thread func
		thread_local int localNum = 0;

		std::thread threadExample_1{ [](void) {

			for (int count = 0; count < 10; count++)
			{
				std::cout << "thread 1 : " << localNum++ << std::endl;
			}

		}};

		std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(10));

		std::thread threadExample_2([](void) {

			for (int count = 0; count < 10; count++)
			{
				std::cout << "thread 2 : " << localNum++ << std::endl;
			}

		});

		threadExample_1.join();
		threadExample_2.join();
	}

	// Mutex example
	// 
	// mutex can handle data race, race condition problem
	// critical section that is locking with mutex must be minimized as possible
	// when mutex is unlocked, next thread that accesses the critical section is not ordered by call time
	// mutex is neither copyable nor movable
	// undefined operation can easily occur when lock() or unlock() is multipled or missing
	std::cout << "--- Mutex Example ---" << std::endl;
	{
		std::mutex mutex;
		int num = 0;
		std::thread threadExample_1{ operationWithMutex, std::ref(num), std::ref(mutex) };
		std::thread threadExample_2{ operationWithMutex, std::ref(num), std::ref(mutex) };
		threadExample_1.join();
		threadExample_2.join();
		std::cout << num << std::endl;
	}

	// Mutex lock guard example
	//
	// basic lock() or unlock() from std::mutex is weak at developers' fault
	// mutex guard can prevent those faults by maintaining mutex's life cycle as a scope based object
	//
	// other RAII idiom following locks 
	//
	// 1) lock_guard
	// 2) scoped_lock
	// 3) shared_lock
	// 4) unique_lock
	// unique_lock is a movable mutex. slightly heavy than lock_guard but has more functionalities
	//
	//
	std::cout << "--- Mutex lock guard Example ---" << std::endl;
	{
		struct Item
		{
			std::mutex mutex;
			int num = 0;
		};

		Item itemExample;
		auto threadFunc = [](Item& item) 
		{
			{
				std::lock_guard<std::mutex>(item.mutex);
				// lines(in scope) bellow std::lock_guard are all critical sections
				item.num++;
			}
		};

		std::vector<std::thread> threadsExample(10);
		for (auto& th : threadsExample)
		{
			th = std::thread(threadFunc, std::ref(itemExample));
		}
		for (auto& th : threadsExample)
		{
			th.join();
		}

		std::cout << itemExample.num << std::endl;
	}

	// Dead Lock code
	//
	// waiting for never unlocking mutex
	// commented second locking code will make self dead lock
	// this can be occur easily by developers' fault.
	// can be prevented by several standard locking libraries.
	//
	// case 1. self dead lock
	{
		std::mutex mutexExample;
		std::lock_guard<std::mutex> lockGuard_1(mutexExample);
		//std::lock_guard<std::mutex> lockGuard_2(mutexExample);

		// 1) one way
		std::recursive_mutex recurMutex;
		std::lock_guard<std::recursive_mutex> lockGuardRecur_1(recurMutex);
		std::lock_guard<std::recursive_mutex> lockGuardRecur_2(recurMutex);
	}

	// case 2. mutual dead lock
	std::cout << "--- Mutual dead lock example ---" << std::endl;
	{
		struct DeadLockObj
		{
			std::mutex mtx;
			int num = 0;
		};

		// func_1 tries to lock lhs's mutex first
		auto func_1 = [](DeadLockObj& lhs, DeadLockObj& rhs) 
		{
			std::lock_guard<std::mutex> lck_1(lhs.mtx);
			lhs.num++;
			std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(100));
			std::lock_guard<std::mutex> lck_2(rhs.mtx);
			rhs.num++;
		};

		// func_2 tries to lock rhs's mutex first
		auto func_2 = [](DeadLockObj& lhs, DeadLockObj& rhs)
		{
			std::lock_guard<std::mutex> lck_1(rhs.mtx);
			rhs.num++;
			std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(100));
			std::lock_guard<std::mutex> lck_2(lhs.mtx);
			lhs.num++;
		};

		DeadLockObj deadLockExample_1;
		DeadLockObj deadLockExample_2;

		std::thread threadExample_1(func_1, std::ref(deadLockExample_1) , std::ref(deadLockExample_2));
		
		// dead lock occcur when call func_1 and func_2 both at same.
		// 
		// locking order of mutex matter when locking more than two mutexes.
		// 
		//std::thread threadExample_2(func_2, deadLockExample_1, deadLockExample_2);

		// calling both func_1 or func_2 doesn't occur dead lock
		//
		// because they both are waiting for the same mutex to be unlocked or locked
		std::thread threadExample_2(func_1, std::ref(deadLockExample_1), std::ref(deadLockExample_2));

		threadExample_1.join();
		threadExample_2.join();

		std::cout << deadLockExample_1.num << std::endl;
		std::cout << deadLockExample_2.num << std::endl;
	}

	// Scoped Lock standard locking library example
	//
	// above code is conidering the order of locking code line to avoid dead lock
	// those way is vulnerable to the faults from developers
	// 
	// so there is standard library for that solution such as scoped lock bellow
	std::cout << "--- scoped lock example ---" << std::endl;
	{
		struct DeadLockObj
		{
			std::mutex mtx;
			int num = 0;
		};

		auto func_1 = [](DeadLockObj& lhs, DeadLockObj& rhs)
		{
			std::scoped_lock<std::mutex, std::mutex> lck_1(lhs.mtx, rhs.mtx);
			lhs.num++;
			rhs.num++;
		};

		auto func_2 = [](DeadLockObj& lhs, DeadLockObj& rhs)
		{
			std::scoped_lock<std::mutex, std::mutex> lck_1(rhs.mtx, lhs.mtx);
			rhs.num++;
			lhs.num++;
		};

		DeadLockObj deadLockExample_1;
		DeadLockObj deadLockExample_2;
		
		std::thread threadExample_1(func_1, std::ref(deadLockExample_1), std::ref(deadLockExample_2));
		std::thread threadExample_2(func_2, std::ref(deadLockExample_1), std::ref(deadLockExample_2));

		threadExample_1.join();
		threadExample_2.join();

		std::cout << deadLockExample_1.num << std::endl;
		std::cout << deadLockExample_2.num << std::endl;
	}
}