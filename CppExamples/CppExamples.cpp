#pragma once

// General Cpp Examples
#include "Defines.h"
#include "ClassMemorysize.h"
#include "CopyElision.h"
#include "FunctionRVO.h"
#include "MembersInit.h"
#include "OverloadingOperators.h"
#include "ForLoop.h"
#include "SmartPointers.h"
#include "LinearInheritance.h"
#include "MultipleInheritance.h"
#include "DiamondInheritance.h"
#include "ObjectSlicing.h"
#include "DynamicCasting.h"
#include "VectorsArrays.h"
#include "FunctionObject.h"
#include "StandardAlgorithms.h"
#include "SortingAlgorithms.h"
#include "DataStructure.h"
#include "StandardDataStructure.h"
#include "ObjectConstructorList.h"
#include "CastConversion.h"
#include "DefineMacro.h"
#include "Bitset.h"
#include "Templates.h"
#include "TypeDeduction.h"
#include "StackRewinding.h"
#include "Threading.h"
#include "MemoryTracking.h"
#include "MemoryPool.h"
#include "StaticArray.h"

// Effective C++ 3rd
#include "EffectiveCpp/ParameterEvaluation.h"
#include "EffectiveCpp/AvoidingCasting.h"
#include "EffectiveCpp/TemplateMetaProgramming.h"

// Effective Modern C++

class MemoryObject
{
	int x;
	float e;
};

int main()
{
	/// 1. CopyElision Example
	//executeCopyElisionExample();

	/// 2. OverloadingOperators Example
	//executeOverloadingOperatorsExample();

	/// 3. ForLoop Example
	//executeForLoopExample();

	/// 4. MembersInit Example
	//executeMembersInitExample();

	/// 5. Smart Pointers Example
	//executeSmartPointersExample();

	/// 6. LinearInheritance Example
	//executeLinearInheritanceExample();

	/// 7. MultipleInheritance Example
	//executeMultipleInheritanceExample();
	
	/// 8. DiamondInheritance Example
	//executeDiamondInheritanceExample();

	/// 9. Object Slicing Example
	//executeObjectSlicingExample();

	/// 10. Dynamic Casting Example
	//executeDynamicCastingExample();

	/// 11. Arrays and Vectors
	//executeVectorsArraysExample();

	/// 12. FunctionObjectExample
	//executeFunctionObejctExample();

	/// 13. StandardAlgorithmsExample
	//executeStandardAlgorithmsExample();

	/// 14. SortingAlgorithmsExample
	//executeSortingAlgorithmsExample();

	/// 15. DataStructureExample
	//executeDataStructureExample();

	/// 16. StandardDataStructureExample
	//executeStandardDataStructure();

	// 17. CastConversion
	//executeCastings();

	// 18. DefineMacro
	//executeDefineMacroExample();

	// 19. Bitset
	//executeBitset();

	// 20. Templates
	//executeTemplatesExample();

	// 21. TypeDeduction
	//executeTypeDeduction();

	// 22. StackRewinding
	//executeStackRewinding();

	// 23. ParameterEvaluation
	//executeParameterEvaluationExample();

	// 24. AvoidingCasting
	//executeAvoidingCasting();

	// 25. TMP (Template Meta Programming)
	//executeTemplateMetaProgramming();

	// 26. Threading
	//executeThreading();

	// 27. MemoryTracking
	//executeMemoryTracking();

	// 28. MemoryPool
	/*CreateMemoryPool<MemoryObject>();

	auto func1 = []()
	{
		for (int count = 0; count < 10000; count++)
		{
			MemoryObject* obj = bknew<MemoryObject>();
			bkfree<MemoryObject>(obj);
		}
	};

	auto func2 = []()
	{
		for (int count = 0; count < 10000; count++)
		{
			MemoryObject* obj = new MemoryObject();
			delete(obj);
		}
	};

	double time = TimeChecker::CheckTime(func1);
	std::cout << time << "ms" << std::endl;
	time = TimeChecker::CheckTime(func2);
	std::cout << time << "ms" << std::endl;*/

	// 29. Static Array
	StaticArray<int, 1000> testArray;
	int arr[1000];

	double time;
	time = TimeChecker::CheckTime([&]()
	{
		for (int idx = 0; idx < 1000; idx++)
		{
			arr[idx] = 1;
			arr[idx];
		}
	});

	std::cout << "origin : " << time << " ms" << std::endl;

	time = TimeChecker::CheckTime([&]()
	{
		for (int idx = 0; idx < 1000; idx++)
		{
			testArray[idx] = 1;
			testArray[idx];
		}
	});

	std::cout << "custom : " << time << " ms" << std::endl;
}