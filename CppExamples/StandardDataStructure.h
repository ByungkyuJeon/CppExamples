#pragma once

#include <iostream>
#include <set>
#include <map>
#include <ctime>

void main_StandardDataStructure()
{
	/// std::set Data Structure from Standard Library
	{
		std::srand(std::time(nullptr));
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

		std::cout << "--- standard multiset example ---" << std::endl;
		for (const auto& elem : exampleMultiset)
		{
			std::cout << elem << std::endl;
		}
	}
}