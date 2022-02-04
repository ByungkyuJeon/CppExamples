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
}