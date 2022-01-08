#include "StandardAlgorithms.h"

#include <vector>
#include <algorithm>
#include <numeric>


bool operator<(int num, const StandardAlgorithmsExampleClass& rhs)
{
	return num < rhs.GetIntVal();
}

std::shared_ptr<StandardAlgorithmsExampleClass> Sum(std::shared_ptr<StandardAlgorithmsExampleClass> lhs, const StandardAlgorithmsExampleClass& rhs)
{
	lhs->SetIntVal(lhs->GetIntVal() + rhs.GetIntVal());
	lhs->SetDoubleVal(lhs->GetDoubleVal() + rhs.GetDoubleVal());
	
	return lhs;
}

bool DescendingCondition(const StandardAlgorithmsExampleClass& lhs, const StandardAlgorithmsExampleClass& rhs)
{
	return lhs.GetIntVal() > rhs.GetIntVal();
}

void PrintVector(const std::vector<StandardAlgorithmsExampleClass>& InVector, char* InText)
{
	std::cout << "--- " << InText << " ---" << std::endl;
	for (const auto& elem : InVector)
	{
		elem.Print();
	}
}

void executeStandardAlgorithmsExample()
{
	/// 1. Sorting
	/// 
	/// in non-descending order as default

	std::vector<StandardAlgorithmsExampleClass> exampleVector
	{
		{2, 5.2},
		{17, 19.9},
		{54, 92.1},
		{7, 67.0},
		{23, 109.4},
		{39, 11.6},
		{90, 79.5},
		{66, 40.7},
		{41, 54.4},
		{82, 10.3}
	};


	/// 1.1 std::sort
	/// 
	/// equal elements' order is not guaranteed to be preserved
	/// 
	/// time complexity : O(NlogN)
	/// 
	/// internal implementation : Introspective sort algorithm
	/// (1) quick sort
	/// (2) heap sort (when recursion depth exceeds number of elements being sorted
	/// (3) insertion sort (remained number of elements is below some threshold)
	std::sort(exampleVector.begin(), exampleVector.end());
	//std::sort(exampleVector.begin(), exampleVector.end(), DescendingCondition);
	PrintVector(exampleVector, (char*)"sort");


	/// 1.2 std::stable_sort
	/// 
	/// equal elements' order is not guaranteed to be preserved
	/// 
	/// time complexity : (if additional memory is available) O(NlogN)
	///					  (if N = std::distance(first, last)) O(2NlogN)
	std::stable_sort(exampleVector.begin(), exampleVector.end(), DescendingCondition);
	//std::stable_sort(exampleVector.begin(), exampleVector.end());
	PrintVector(exampleVector, (char*)"stable sort");


	/// 1.3 std::partial_sort
	/// 
	/// equal elements' order is not guaranteed to be preserved
	/// 
	/// time complexity : O(Nlog(middle - first))
	std::partial_sort(exampleVector.begin(), exampleVector.begin() + 5, exampleVector.end());
	//std::partial_sort(exampleVector.begin(), exampleVector.begin() + 5, exampleVector.end(), DescendingCondition);
	PrintVector(exampleVector, (char*)"partial sort");


	/// 1.4 std::nth_element
	///
	/// 
	std::nth_element(exampleVector.begin(), exampleVector.begin() + 5, exampleVector.end());
	PrintVector(exampleVector, (char*)"nth sort");


	/// 2. MIN / MAX
	/// std:min_element / max_element / minmax_element
	auto minmaxElem = std::minmax_element(exampleVector.begin(), exampleVector.end());

	std::cout << "--- minmax element ---" << std::endl;
	minmaxElem.first->Print();
	minmaxElem.second->Print();


	/// 3. Find Algorithms

	/// 2.1 std::find
	/// 
	/// normal search
	/// 
	/// time complexity : O(n)
	std::cout << "--- find ---" << std::endl;
	auto foundElem = std::find(exampleVector.begin(), exampleVector.end(), 39);
	if (foundElem != exampleVector.end())
	{
		foundElem->Print();
		std::cout << "distance to found element : " << std::distance(exampleVector.begin(), foundElem) << std::endl;
	}
	else
	{
		std::cout << "object not found" << std::endl;
	}


	/// 2.2 std::binary_search
	/// 
	/// binary search when container is in sorted state
	/// 
	/// time complexity : O(logN)
	std::cout << "--- binary search ---" << std::endl;
	std::sort(exampleVector.begin(), exampleVector.end());
	bool isFound = std::binary_search(exampleVector.begin(), exampleVector.end(), 39);
	if (isFound)
	{
		std::cout << "found" << std::endl;
	}
	else
	{
		std::cout << "not found" << std::endl;
	}


	/// 4. Accumulate Function
	/// 
	/// 4.1 std::accumulate
	/// 
	/// 
	std::cout << "--- accumulate ---" << std::endl;
	auto sum = std::accumulate(exampleVector.begin(), exampleVector.end(), std::make_shared<StandardAlgorithmsExampleClass>(0, 0), Sum);
	std::cout << "sum : "; 
	sum->Print();
	std::cout << "accumulation used shared pointer count : " << sum.use_count() << std::endl;

	
}
