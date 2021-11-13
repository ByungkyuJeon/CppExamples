#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

#include "TimeChecker.h"
#include "ExampleHelperClass.h"

class SortingAlgorithmsExampleClass
{
public:

	SortingAlgorithmsExampleClass() : mInt{ 0 }, mDouble{ 0 }{}
	SortingAlgorithmsExampleClass(int inInt, double inDouble) : mInt{ inInt }, mDouble{ inDouble }{}

	bool operator < (const SortingAlgorithmsExampleClass& other) const { return mInt < other.GetIntVal(); }
	bool operator > (const SortingAlgorithmsExampleClass& other) const { return mInt > other.GetIntVal(); }

	int GetIntVal() const { return mInt; }
	double GetDoubleVal() const { return mDouble; }

	void Print() const
	{
		std::cout << "[integer : " << mInt << " / " << "double : " << mDouble << " ]" << std::endl;
	}

private:

	int mInt;
	double mDouble;
};

std::ostream& operator<<(std::ostream& os, const SortingAlgorithmsExampleClass& exampleClass)
{
	return os << "[integer : " << exampleClass.GetIntVal() << " / " << "double : " << exampleClass.GetDoubleVal() << " ]";
}



/// 1. Selection Sort
///
/// 
template<typename Type>
void SelectionSort(std::vector<Type>& arr)
{
	size_t minIdx{ 0 };

	for (size_t primaryIdx = 0; primaryIdx < arr.size(); primaryIdx++)
	{
		minIdx = primaryIdx;

		for (size_t secondaryIdx = primaryIdx; secondaryIdx < arr.size(); secondaryIdx++)
		{
			if (arr[minIdx] > arr[secondaryIdx])
			{
				minIdx = secondaryIdx;
			}
		}

		std::swap(arr[primaryIdx], arr[minIdx]);
	}
}


/// 2. Bubble Sort
///
/// 
template<typename Type>
void BubbleSort(std::vector<Type>& arr)
{
	for (size_t primaryIdx = 0; primaryIdx < arr.size() - 1; primaryIdx++)
	{
		for (size_t secondaryIdx = 0; secondaryIdx < arr.size() - 1 - primaryIdx; secondaryIdx++)
		{
			if (arr[secondaryIdx] > arr[secondaryIdx + 1])
			{
				std::swap(arr[secondaryIdx], arr[secondaryIdx + 1]);
			}
		}
	}
}


/// 3. Insertion Sort
///
/// 
template<typename Type>
void InsertionSort(std::vector<Type>& arr)
{
	for (size_t primaryIdx = 0; primaryIdx < arr.size(); primaryIdx++)
	{
		for (size_t secondaryIdx = 0; secondaryIdx < primaryIdx; secondaryIdx++)
		{
			if (arr[primaryIdx] < arr[secondaryIdx])
			{
				for (size_t thirdIdx = primaryIdx; thirdIdx > secondaryIdx; thirdIdx--)
				{
					std::swap(arr[thirdIdx], arr[thirdIdx - 1]);
				}
			}
		}
	}
}


/// 4. Quick Sort Type 1
///
/// main concept : divide and conquer
/// 
/// time complexity : average O(NlogN)
///					  max	  O(N^2)
/// 
/// type 1 processes more comparing operation than type 2
///					  less swapping operation than type 2 
template<typename Type>
void QuickSort_Type1(std::vector<Type>& arr, size_t leftIdx, size_t rightIdx)
{
	/// if doesn't know container's arrange state 
	///
	/// location of pivot doesn't have any advantage or disadvantage
	/// so normally pivot is just set to left or right
	Type& pivot{ arr[leftIdx] };
	size_t smallerIdx{ leftIdx + 1 }, biggerIdx{ rightIdx };

	/// divide process
	while (true)
	{
		while (smallerIdx <= rightIdx && arr[smallerIdx] < pivot)
			smallerIdx++;
		while (biggerIdx >= leftIdx + 1 && arr[biggerIdx] > pivot)
			biggerIdx--;

		if(smallerIdx <= biggerIdx)
		{
			std::swap(arr[smallerIdx], arr[biggerIdx]);
		}
		else { break; }
	}

	std::swap(arr[leftIdx], arr[smallerIdx - 1]);

	/// conquer process
	if (smallerIdx > leftIdx + 2)
		QuickSort_Type1(arr, leftIdx, smallerIdx - 2);
	if (smallerIdx < rightIdx)
		QuickSort_Type1(arr, smallerIdx, rightIdx);
}



/// 5. Quick Sort Type 2
///
/// main concept : divide and conquer
/// 
/// time complexity : average O(NlogN)
///					  max	  O(N^2)
/// 
/// type 2 processes less comparing operation than type 1
///					  more swapping operation than type 1 
template<typename Type>
void QuickSort_Type2(std::vector<Type>& arr, size_t leftIdx, size_t rightIdx)
{
	Type& pivot{ arr[leftIdx] };
	size_t shiftIdx{ leftIdx + 1 }, checkIdx{ rightIdx };

	/// divide process
	while (true)
	{
		while (checkIdx >= leftIdx + 1 && arr[checkIdx] > pivot)
			checkIdx--;

		if (shiftIdx <= checkIdx)
		{
			std::swap(arr[shiftIdx++], arr[checkIdx]);
		}
		else { break; }
	}

	std::swap(arr[leftIdx], arr[shiftIdx - 1]);

	/// conquer process
	if (shiftIdx > leftIdx + 2)
		QuickSort_Type2(arr, leftIdx, shiftIdx - 2);
	if (shiftIdx < rightIdx)
		QuickSort_Type2(arr, shiftIdx, rightIdx);
}





void main_SortingAlgorithmsExample()
{
	std::vector<SortingAlgorithmsExampleClass> exampleVector
	{
		{39, 11.6},
		{2, 5.2},
		{17, 19.9},
		{54, 92.1},
		{7, 67.0},
		{23, 109.4},
		{90, 79.5},
		{66, 40.7},
		{41, 54.4},
		{82, 10.3}
	};


	/// 1. Selection Sort Example
	std::cout << "--- Selection Sort Example ---" << std::endl;
	std::cout << "time : " << TimeChecker::CheckTime([&]()
		{
			//SelectionSort(exampleVector);
		}) << " ms" << std::endl;
	ExampleHelperClass::PrintVector(exampleVector, std::cout);


	/// 2. Bubble Sort Example
	std::cout << "--- Bubble Sort Example ---" << std::endl;
	std::cout << "time : " << TimeChecker::CheckTime([&]()
		{
			//BubbleSort(exampleVector);
		}) << " ms" << std::endl;
	ExampleHelperClass::PrintVector(exampleVector, std::cout);


	/// 3. Insertion Sort Example
	std::cout << "--- Insertion Sort Example ---" << std::endl;
	std::cout << "time : " << TimeChecker::CheckTime([&]()
		{
			InsertionSort(exampleVector);
		}) << " ms" << std::endl;
	ExampleHelperClass::PrintVector(exampleVector, std::cout);


	/// 4. Quick Sort Type 1 Example
	std::cout << "--- Quick Sort Type 1 Example ---" << std::endl;
	std::cout << "time : " << TimeChecker::CheckTime([&]()
		{
			QuickSort_Type1(exampleVector, 0, exampleVector.size() - 1);
		}) << " ms" << std::endl;
	ExampleHelperClass::PrintVector(exampleVector, std::cout);


	/// 5. Quick Sort Type 2 Example
	std::cout << "--- Quick Sort Type 2 Example ---" << std::endl;
	std::cout << "time : " << TimeChecker::CheckTime([&]()
		{
			QuickSort_Type2(exampleVector, 0, exampleVector.size() - 1);
		}) << " ms" << std::endl;
	ExampleHelperClass::PrintVector(exampleVector, std::cout);


	/// 6. Heap Sort
	/// 
	/// heap sort is implemented in "DataStructure.h" with implementation of heap tree structure
	

}
