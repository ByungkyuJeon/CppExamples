#pragma once

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

class StandardDataStructureExampleClass
{
public:
	StandardDataStructureExampleClass() : mInt{ 0 }, mDouble{ 0 }{}
	StandardDataStructureExampleClass(int inInt, double inDouble) : mInt{ inInt }, mDouble{ inDouble }{}
	StandardDataStructureExampleClass(const StandardDataStructureExampleClass& other) : mInt{ other.mInt }, mDouble{ other.mDouble }{}
	StandardDataStructureExampleClass(StandardDataStructureExampleClass&& other) noexcept : mInt{ std::move(other.mInt) }, mDouble{ std::move(other.mDouble) } {}

	bool operator==(const StandardDataStructureExampleClass& other) const
	{
		return mInt == other.GetIntValue();
	}

	int GetIntValue() const
	{
		return mInt;
	}

	double GetDoubleValue() const
	{
		return mDouble;
	}

	void Print() const
	{
		std::cout << "int value : " << mInt << " / double value : " << mDouble << std::endl;
	}

private:
	int mInt;
	double mDouble;
};

/// custom hash function object
struct ClassHashExample
{
	std::size_t operator()(const StandardDataStructureExampleClass& classHash) const noexcept
	{
		/// 8 shifting integer value + double value mod 200 (200 is random range)
		return ((static_cast<std::size_t>(classHash.GetIntValue()) << 8) + static_cast<std::size_t>(classHash.GetDoubleValue())) % 200;
	}
};

/// injected custom specialization of std::hash
template<>
struct std::hash<StandardDataStructureExampleClass>
{
	std::size_t operator()(StandardDataStructureExampleClass& classHash) const noexcept
	{
		return ((static_cast<std::size_t>(classHash.GetIntValue()) << 8) + static_cast<std::size_t>(classHash.GetDoubleValue())) % 200;
	}
};

void executeStandardDataStructure()
{
	std::srand(std::time(nullptr));

	/// std::set Data Structure from Standard Library
	{
		std::cout << "--- std::set example --- " << std::endl;

		std::set<int> exampleSet;
		/// std::set structure 

		///
		/// base structure : red black binary tree
		/// 
		/// time complexity : find O(logN)
		///					  insertion O(logN)
		///					  deletion O(logN)
		/// 
		/// when chaged, elements always arranged (Always Sorted)
		/// 
		/// no element duplication allowed (No Duplication)
		/// 
		for (int initCounter = 0; initCounter < 30; initCounter++)
		{
			exampleSet.emplace(std::rand() % 200);
		}


		std::cout << "--- standard set example ---" << std::endl;
		for (const auto& elem : exampleSet)
		{
			std::cout << elem << std::endl;
		}
	}


	/// std::multiset Data Structure from Standard Library
	{
		std::cout << "--- std::multiset example ---" << std::endl;

		/// std::multiset structure
		///
		/// same as std::set structure but difference in duplication
		/// 
		/// multi_set container's elements can be duplicated 
		/// 
		/// when changed, elements are guaranteed to be arranged
		/// 
		std::multiset<int> exampleMultiset;

		for (int initCounter = 0; initCounter < 30; initCounter++)
		{
			exampleMultiset.emplace(std::rand() % 200);
		}

		for (const auto& elem : exampleMultiset) { std::cout << elem << std::endl; }
	}

	/// std::map Data Structure from Standard Library
	{
		std::cout << "--- std::map example 1 ---" << std::endl;

		/// std::map structure
		///
		/// same as std::set with internal implementation of red-black tree, difference in key-value pair structure
		/// 
		/// when changed, elements are guaranteed to be arranged based on key
		/// elements can not be duplicated
		int gradualKeyCounter = 30;

		std::map<int, float> exampleMap;

		for (int initCounter = 0; initCounter <= 30; initCounter++)
		{
			/// either way works
			exampleMap.emplace(gradualKeyCounter, static_cast<double>(std::rand() / static_cast<double>(RAND_MAX / 200)));
			//exampleMap[gradualKeyCounter] = static_cast<double>(std::rand() / static_cast<double>(RAND_MAX / 200));

			gradualKeyCounter--;
		}
		for (const auto& elem : exampleMap) { std::cout << "key : " << elem.first << " / value : " << elem.second << std::endl; }


		/// assignment at existing key
		///
		/// std::map automatically updates value when assignment at existing key occur
		std::cout << "--- std::map assignment at existing key example ---" << std::endl;
		for (int elemKey = 0; elemKey < exampleMap.size(); elemKey++)
		{
			/// emplace doesn't update the value when specific key is 
			//exampleMap.emplace(elemKey, 0);
			exampleMap[elemKey] = 0;
		}
		for (const auto& elem : exampleMap) { std::cout << "key : " << elem.first << " / value : " << elem.second << std::endl; }


		/// default initiation when calling unconstructed key-value
		///
		/// key 31 is not constructed right now
		/// when calling not existing key 31, value will be initiated by default value
		/// 
		/// so using square bracket need more careful for developers
		std::cout << "--- default initiation when calling unconstructed key-value --- " << std::endl
			<< "unconstructed key : 31 / initiated value : " << exampleMap[31] << std::endl;
		
	}

	
	/// std::multimap example
	///
	/// same as std::map but multimap allows keys to be duplicated
	std::cout << "--- std::multimap example ---" << std::endl;
	{
		std::multimap<int, int> exampleMultiMap;

		for (int initCounter = 0; initCounter <= 30; initCounter++)
		{
			exampleMultiMap.emplace(1, static_cast<double>(std::rand() / static_cast<double>(RAND_MAX / 200)));
		}
		for(const auto& elem : exampleMultiMap) { std::cout << "key : " << elem.first << " / value : " << elem.second << std::endl; }
	}

	/// std::unordered_set example 1
	///
	/// with primitive type elements
	/// 
	/// unordered_set is totally difference from std::set
	/// 
	/// uses std::hash internally so this contatiner can not be sorted
	/// but time complexity of 'emplace', 'find' and 'erase' operations is O(1)
	/// 
	/// element duplication not allowed
	/// 
	/// time complexity : insertion O(1), when re-hashing O(n)
	///					  deletion O(1)
	///					  find O(1)
	std::cout << "--- std::unordered_set example with primitive type elements ---" << std::endl;
	{
		std::unordered_set<std::string> exampleUnorderedSet;
		/// by reserving, operation re-hashing can be prevented
		exampleUnorderedSet.reserve(50);
		/// by setting max_load_factor, re-hashing time can be operated
		exampleUnorderedSet.max_load_factor(2);


		for (int initCounter = 0; initCounter < 30; initCounter++)
		{
			exampleUnorderedSet.emplace("UnorderedSet" + std::to_string(std::rand() % 200));
		}

		for (const auto& elem : exampleUnorderedSet) 
		{ 
			std::cout << "value : " << elem 
			<< " / hash : " << std::hash<std::string>()(elem) 
			<< " / bucket : " << exampleUnorderedSet.bucket(elem) << std::endl; 
		}
	}

	/// std::unordered_set example 2
	///
	/// with class types
	/// 
	/// needs custom hash function object
	/// needs operator== override
	std::cout << "--- std::unordered_set example with class types ---" << std::endl;
	{
		std::unordered_set<StandardDataStructureExampleClass, ClassHashExample> exampleUnordered_Set;

		for (int initCounter = 0; initCounter < 30; initCounter++)
		{
			exampleUnordered_Set.emplace(StandardDataStructureExampleClass{ rand() % 200, static_cast<double>(rand() / static_cast<double>(RAND_MAX / 200)) });
		}

		for (const auto& elem : exampleUnordered_Set)
		{
			std::cout << "hash : " << ClassHashExample()(elem) << " / ";
			elem.Print();
		}
	}

	/// std::unordered_map example
	///
	/// same as std::unordered_set with key-value element structure
	std::cout << "--- std::unordered_map example ---" << std::endl;
	{
		std::unordered_map<int, StandardDataStructureExampleClass> exampleUnordered_Map;

		for (int initCounter = 0; initCounter < 30; initCounter++)
		{
			exampleUnordered_Map.emplace(initCounter, StandardDataStructureExampleClass(rand() % 200, static_cast<double>(rand() / static_cast<double>(RAND_MAX / 200))));
		}

		for (const auto& elem : exampleUnordered_Map)
		{
			std::cout << "hash : " << ClassHashExample()(elem.second) << " / ";
			elem.second.Print();
		}
	}

	/// std::list example
	///
	/// interaly implemented as doubly-linked list 
	/// 
	/// time complexity : insertion O(1)
	///					  deletion O(1)
	///					  find O(n)
	/// 
	/// fast random access is not supported
	/// 
	/// std::list properties
	/// 1. front element memory address
	/// 2. back element memory address
	/// 3. size of list
	{
		std::list<int> exampleList;

		for (std::size_t initCounter = 0; initCounter < 30; initCounter++)
		{
			/// all of these operations' time complexity are O(1)
			exampleList.emplace_back(rand() % 200);
			// exampleList.emplace_front(rand() % 200);
			// exampleList.insert(exampleList.begin(), rand() % 200);
			// exampleList.pop_front();
			// exampleList.pop_back();
		}

		/// can not access by this bracket expression
		/// no implementation of operator[]
		//exampleList[1];

		/// finding element in list
		/// time complexity for find in list is O(n)
		auto itr = std::find(exampleList.begin(), exampleList.end(), 1);
		if (itr != exampleList.end())
		{
			// found
		}

		/// sort, merge for list
		std::list<int> exampleList_1{ 5,3,4,1,2 };
		std::list<int> exampleList_2{ 10,6,8,7,9 };

		exampleList_1.sort();
		exampleList_2.sort();

		/// operands should be in sorted state
		exampleList_1.merge(exampleList_2);

		for (const auto& elem : exampleList_1)
		{
			std::cout << elem << std::endl;
		}
	}
}