#include "VectorsArrays.h"

#include <vector>
#include <array>
#include <chrono>
#include <iostream>

#include "TimeChecker.h"

void main_VectorsArraysExample()
{
	/// ARRAY TYPES IN CPP
	{
		/// 1. C Stytle Array In Stack Memory
		/// 
		/// array size must be const (non-dynamic)
		const int elementCount_Const = 100;
		int cStyleArray_Stack[elementCount_Const] = { 0 };

		/// 2. C Style Array In Heap Memory
		/// 
		/// array size is dynamic at initiation
		/// but can not resize at runtime
		int* cStyleArray_Heap = (int*)malloc(sizeof(int) * elementCount_Const);
		free(cStyleArray_Heap);

		/// 3. Cpp Style Array In Heap Memory
		///
		/// array size is dynamic at initiation
		/// but can not resize at runtime
		int* cppStyleArray_Heap = new int[elementCount_Const];
		delete[](cppStyleArray_Heap);

		/// 4. Standard Library Array In Stack Memory
		///
		/// array size must be const(non-dynamic)
		std::cout << "--- standard library array in stack memory ---" << std::endl;
		std::array<int, elementCount_Const> exampleArray{ 0 };
		std::cout << "array instance size : " << sizeof(exampleArray) << std::endl; // int 4 bytes * 50

		/// 5. Standard Library Vector In Heap Memory
		///
		/// vector size is dynamic at initiation
		/// can resize at runtime
		std::cout << "--- standard library vector in heap memory ---" << std::endl;
		std::vector<int> exampleVector(elementCount_Const, 0);
		std::cout << "vector instance size : " << sizeof(exampleVector) << std::endl
			<< "vector size : " << exampleVector.size() << " / vector capacity : " << exampleVector.capacity() << std::endl;
	}


	/// VECTORS SIZE AND INFORMATION POINTING
	{
		std::vector<int> exampleVector(10, 0);

		/// 1. Containing Data
		/// vector points at start of elements address (8 bytes at 64bit OS / 4 bytes at 32bit OS)
		/// vector's elements size data (8 bytes)
		/// vector's capacity data (8 bytes)
		std::cout << "--- vector's containing data ---" << std::endl
			<< "vector data pointers size : " << sizeof(exampleVector) << std::endl
			<< "vector's elements size : " << exampleVector.size() << std::endl
			<< "vector's container capacity : " << exampleVector.capacity() << std::endl;

		/// 2. Vector's Auto Resizing
		///
		/// vectors capacity is automatically up-sized when element is added and its size > capacity
		/// when auto resizing happen, known time complexity for container libraries are not guaranteed
		/// 
		/// insertion : O(n)'
		std::cout << "--- vector's auto resizing ---" << std::endl;
		for (int addCount = 30; addCount > 0; addCount--)
		{
			exampleVector.emplace_back(10);
			std::cout << "vector's size : " << exampleVector.size() << std::endl
				<< "vector's capacity : " << exampleVector.capacity() << std::endl;
		}
	}


	/// VECTOR ADDING ELEMENT
	///
	/// Vector emplace_back and push_back
	///
	/// emplace_back can remove temporary object instance when adding into vector
	/// since c++17 emplace_back returns reference to the object added
	/// therefore, emplace_back skips redundant temporary stack memory and move operation which is more optimized than push_back
	{
		std::vector<VectorsArraysExampleClass> exampleVector;

		/// temporary object generated in stack
		/// after that internal move operation required
		/// 
		/// emplace_back<T>(T&& _Val)
		exampleVector.emplace_back(VectorsArraysExampleClass(10, 10.0)); 

		/// temporary object is not generated
		exampleVector.emplace_back(10, 10.0);
	}


	/// VECTOR LIBRARIES' TIME COMPLEXITY
	std::cout << "--- vector time complexity ---" << std::endl;
	{
		std::vector<int> exampleVector(30, 0);

		/// 1. Vector Random Access
		/// 
		/// time complexity : O(1)
		std::cout << "vector random access : " 
			<< TimeChecker::CheckTime([&]()
				{
					exampleVector[10];
				})
			<< " seconds" << std::endl;

		/// 2. Vector Insertion(or removal) at End
		///
		/// time complexity : O(1)
		std::cout << "vector insertion at back : "
			<< TimeChecker::CheckTime([&]()
				{
					exampleVector.emplace_back(10);
					// exampleVector.pop_back();
				})
			<< " seconds" << std::endl;

		/// 3. Vector Insertion(or removal) at Somewhere not End
		///
		/// element movement operation needed from insertion spot to vector's end
		/// time complexity : O(n)
		std::cout << "vector insertion at somewhere not back : "
			<< TimeChecker::CheckTime([&]()
				{
					exampleVector.emplace(exampleVector.begin(), 10);
					//exampleVector.erase(exampleVector.begin() + 10);
				})
			<< " seconds" << std::endl;

		
		
		/// 4. Vector Resizing (Capacity) And Preventing For Optimization
		///
		/// when adding element to vector container, resizing can happen and can be non-efficient
		/// to prevent that, reserving memory size is needed
		{
			std::vector<int> exampleTemp;
			std::cout << "vector's auto resizing time complexity :" << TimeChecker::CheckTime([&]()
			{
for (int addCount = 30; addCount > 0; addCount--)
{
	exampleTemp.emplace_back(10);
}
			}) << std::endl;
		}

		/// reserved
		{
		std::vector<int> exampleTemp;
		exampleVector.reserve(30);
		std::cout << "vector's emplacing with reserved capacity time complexity :" << TimeChecker::CheckTime([&]()
			{
				for (int addCount = 30; addCount > 0; addCount--)
				{
					exampleTemp.emplace_back(10);
				}
			}) << std::endl;
		}


		/// 5. Vector Remove Function 
		/// 
		/// removing specific elements in vector can be efficiently wroted by remove and erase functions

		/// 5.1  an inefficient way of removing specific elements in array
		/// needs O(n) for shifting when erase occur
		{
			std::vector<int> exampleVector{ 9, 3, 4, 1, 6, 7, 7, 2, 3, 5, 7, 7, 2 };
			for (auto itr = exampleVector.begin(); itr != exampleVector.end();)
			{
				if (*itr == 7)
				{
					itr = exampleVector.erase(itr);
				}
				else
				{
					itr++;
				}
			}

			/// printing result
			std::cout << "--- inefficient way 1 ---" << std::endl;
			for (const auto& elem : exampleVector)
			{
				std::cout << elem << " ";
			}
		}

		/// 5.2  an inefficient way of removing specific elements in array
		/// needs one more vector object
		{
			std::vector<int> exampleVector{ 9, 3, 4, 1, 6, 7, 7, 2, 3, 5, 7, 7, 2 };
			std::vector<int> exampleRemoved;
			for (auto& elem : exampleVector)
			{
				if (elem != 7)
				{
					exampleRemoved.emplace_back(elem);
				}
			}

			/// printing result
			std::cout << std::endl << "--- inefficient way 2 ---" << std::endl;
			for (const auto& elem : exampleRemoved)
			{
				std::cout << elem << " ";
			}
		}

		/// 5.3 efficient way of removing specific elements in array
		///
		/// no need of additional temporal object
		/// less need of shifting
		/// 
		/// used std::remove and std::vector.erase
		/// 
		/// std::remove works like below (primitive type int works like copy)
		/// null is not actually null.(just for showing)
		/// (1) { 9, 3, 4, 1, 6, 2, 7, null, 3, 5, 7, 7, 2 }
		/// (2) { 9, 3, 4, 1, 6, 2, 3, null, null, 5, 7, 7, 2 }
		/// (3) { 9, 3, 4, 1, 6, 2, 3, 5, null, null, 7, 7, 2 }
		/// (4) { 9, 3, 4, 1, 6, 2, 3, 5, 2, null, 7, 7, null }
		/// (5 - erase) { 9, 3, 4, 1, 6, 2, 3, 5, 2 }
		{
			std::vector<int> exampleVector{ 9, 3, 4, 1, 6, 7, 7, 2, 3, 5, 7, 7, 2 };
			exampleVector.erase(std::remove(exampleVector.begin(), exampleVector.end(), 7), exampleVector.end());

			/// printing result
			std::cout << std::endl << "--- efficient way ---" << std::endl;
			for (const auto& elem : exampleVector)
			{
				std::cout << elem << " ";
			}
		}
	}


	/// LIBRARIES WITH CUSTOM CONDITIONS
	///
	/// example code currently wroted just for std::remove_if 
	{
		std::vector<int> exampleVector{ 9, 3, 4, 1, 6, 7, 7, 2, 3, 5, 7, 7, 2 };
		auto itr = std::remove_if(exampleVector.begin(), exampleVector.end(), [](int num)
			{
				if (num % 2 == 0)
				{
					return true;
				}
				return false;
			});
		exampleVector.erase(itr, exampleVector.end());

		/// printing result
		std::cout << std::endl << "--- remove_if with custom condition ---" << std::endl;
		for (const auto& elem : exampleVector)
		{
			std::cout << elem << " ";
		}
	}
}
