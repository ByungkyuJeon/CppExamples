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
}