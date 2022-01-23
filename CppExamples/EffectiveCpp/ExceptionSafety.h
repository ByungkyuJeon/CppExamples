#pragma once

#include <algorithm>

// Exception Safety
//
// exception safety has rules of two
//
// when exception occur,
// 1. no memory leak
// 2. no data corruption
//
// there are three exception safety levels as bellow
//
// 1. basic guarantee 
// guarantees safety with no data corruption, no memory leak but process state is unpredictable. 
// it can be in any state that is valid
//
// 2. strong guarantee
//
// guarantees safety with no data corruption, no memory leak and process state is predictable.
// when exception occur program restores the state as before the function was called.
// 
// 3. nothrow guarantee
// guarantees that there is no exception in the function.
// 
//
// One of the method of implementing strong guarantee : copy and swap
class ExceptionSafetyExample
{
public:
	ExceptionSafetyExample() = default;

	// copy constructor
	// copies to temporary object and swap
	// this method is not the best solution for every case
	ExceptionSafetyExample(const ExceptionSafetyExample& other)
	{
		ExceptionSafetyExample temp{ other };
		this->swap(temp);
	}

	void swap(ExceptionSafetyExample& other)
	{
		int temp = other.mNum;
		other.mNum = this->mNum;
		this->mNum = temp;
	}

private:
	int mNum = 0;
};

