#pragma once

#include <Thread>

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

void executeThreading()
{
	// Threading with no param
	{
		std::thread threadExample{ operationWithNoParam };
		threadExample.join();
	}

	// Threading with params
	{
		std::string strExample = "string param";
		int numExample = 32;
		std::thread threadExample{ operationWithParams, numExample, std::ref(strExample) };
		threadExample.join();
	}

	// Threading with return value
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
}