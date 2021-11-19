#pragma once

#include <iostream>
#include <set>
#include <map>
#include <ctime>

void main_StandardDataStructure()
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
}