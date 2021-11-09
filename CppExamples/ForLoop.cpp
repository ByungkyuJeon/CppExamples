#pragma once

#include "ForLoop.h"
#include <vector>
#include <iostream>

/// Overloading operator <<
std::ostream& operator<<(std::ostream& os, const ForLoopExampleClass& exampleClass)
{
	return os << exampleClass.GetName() << " : " << exampleClass.GetNum();
}

void main_ForLoopExample()
{
	int counter = 0;

	std::vector<ForLoopExampleClass> exampleVector
	{
		{"exampleClass 1", 1},
		{"exampleClass 2", 2},
		{"exampleClass 3", 3},
		{"exampleClass 4", 4},
		{"exampleClass 5", 5},
		{"exampleClass 6", 6},
		{"exampleClass 7", 7},
		{"exampleClass 8", 8},
		{"exampleClass 9", 9}
	};

	/// LOOPING READONLY
	std::cout << "*** read only loop ***" << std::endl;

	/// LOOP CASE 1
	///
	/// index looping
	std::cout << "--- index looping --- " << std::endl;
	for (std::size_t idx = 0; idx < exampleVector.size(); idx++)
	{
		std::cout << exampleVector[idx] << std::endl;
	}

	/// LOOP CASE 2
	///
	/// iterator looping
	std::cout << "--- iterator looping ---" << std::endl;
	for (auto itr = exampleVector.begin(); itr != exampleVector.end(); itr++)
	{
		std::cout << *itr << std::endl;
	}

	/// LOOP CASE 3
	///
	/// ranged for looping
	std::cout << "--- ranged for looping ---" << std::endl;
	for (auto & exampleClass : exampleVector)
	{
		std::cout << exampleClass << std::endl;
	}



	/// LOOPING WITH WRITE
	std::cout << "*** wirte loop ***" << std::endl;

	/// LOOP CASE 1
	///
	/// Works fine
	/// 
	/// index based looping isn't affected by resizing capacity
	/// 
	/// can read added elements while looping
	counter = 0;
	std::cout << "--- index looping ---" << std::endl;
	for (std::size_t idx = 0; idx < exampleVector.size(); idx++)
	{
		if (exampleVector[idx].GetNum() == 3)
		{
			counter++;
		}
		else
		{
			exampleVector.emplace_back("new example", 3);
		}

		std::cout << exampleVector[idx] << std::endl;
	}
	std::cout << "Count : " << counter << std::endl;
	std::cout << "Vector Size : " << exampleVector.size() << std::endl;

	/// LOOP CASE 2
	///
	/// throws std::bad_alloc exception
	/// 
	/// iterator based looping is affected by resizing capacity
	/// this problem can be resolved by reserving memory capacity before auto resizing happen
	/// 
	/// can read added elements while looping
	exampleVector.reserve(sizeof(exampleVector) + sizeof(ForLoopExampleClass) * 10);
	counter = 0;
	std::cout << "--- iterator looping ---" << std::endl;
	for (auto itr = exampleVector.begin(); itr != exampleVector.end(); itr++)
	{
		if (itr->GetNum() == 3)
		{
			counter++;
		}
		else
		{
			exampleVector.emplace_back("new example", 3);
		}

		std::cout << *itr << std::endl;
	}
	std::cout << "Counter : " << counter << std::endl;
	std::cout << "Vector Size : " << exampleVector.size() << std::endl;

	/// LOOP CASE 3
	///
	/// throws std::bad_alloc exception
	/// 
	/// ranged_for based looping is affected by resizing capacity
	/// this problem can be resolved by reserving memory capacity before auto resizing happen
	/// 
	/// can't read added elements while looping 
	exampleVector.reserve(sizeof(exampleVector) + sizeof(ForLoopExampleClass) * 10);
	counter = 0;
	std::cout << "--- ranged for loop ---" << std::endl;
	for (auto & exampleClass : exampleVector)
	{
		if (exampleClass.GetNum() == 3)
		{
			counter++;
		}
		else
		{
			exampleVector.emplace_back("new example", 3);
		}

		std::cout << exampleClass << std::endl;
	}

	std::cout << "Counter : " << counter << std::endl;
	std::cout << "Vector Size : " << exampleVector.size() << std::endl;
}
