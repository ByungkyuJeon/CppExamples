#pragma once

#include "FunctionRVO.h"
#include <vector>


/// GET FUNCTION BY VALUE
///
/// returns primitive type by value
/// return variable is member variable
/// 
/// RVO doesn't intervenes
/// value copying occur
/// 
/// but, primitive type copying is not big deal
/// doesn't really matter whether it's returned by value or not
/// because their sizes are not bigger than pointer variables
int FunctionRVOExampleClass_1::GetNum_Value()
{
	return mNum;
}

/// GET FUNCTION BY REFERENCE
///
/// returns primitive type by const reference 
/// return variable is member variable
/// 
/// RVO doesn't intervenes
/// no copying
/// 
/// but, primitive type copying is not big deal
/// doesn't really matter whether it's returned by reference or not
/// because their sizes are not bigger than pointer variables
const int& FunctionRVOExampleClass_1::GetNum_Ref()
{
	return mNum;
}

/// GET FUNCTION BY VALUE
///
/// returns class type by value
/// return variable is member variable
/// 
/// RVO doesn't intervenes
/// value copying occur
/// 
/// class(struct) types matter whether it's copied when returning
/// because their sizes are not limited and mostly are bigger than pointer values
/// 
/// NOT GOOD
FunctionRVOExampleSourceClass FunctionRVOExampleClass_1::GetSourceClass_Value()
{
	return mSourceClass;
}

/// GET FUNCTION BY VALUE
///
/// returns class type by const reference
/// return variable is member variable
/// 
/// RVO doesn't intervenes
/// no copying
/// 
/// class(struct) types matter whether it's copied when returning
/// because their sizes are not limited and mostly are bigger than pointer values
/// 
/// GOOD 
const FunctionRVOExampleSourceClass& FunctionRVOExampleClass_1::GetSourceClass_Ref()
{
	return mSourceClass;
}



/// RETURNING BOUNDED VARIABLE BY VALUE
///
/// returns class type by value
/// return variable is bounded in its function
/// 
/// RVO intervenes(guaranteed)
/// no copying
/// 
/// GOOD
std::vector<FunctionRVOExampleSourceClass> FunctionRVOExampleClass_2::GetSourceClass_Value()
{
	std::vector<FunctionRVOExampleSourceClass> sourceVector = std::vector<FunctionRVOExampleSourceClass>(5);

	return sourceVector;
}

/// RETURNING BOUNDED VARIABLE BY MOVABLE RVALUE USING std::move
///
/// returns class type by value
/// return variable is bounded in its function
/// 
/// RVO intervenes(guaranteed)
/// no copying
/// 
/// no need of std::move 
/// 
/// BAD
std::vector<FunctionRVOExampleSourceClass> FunctionRVOExampleClass_2::GetSourceClass_Move()
{
	std::vector<FunctionRVOExampleSourceClass> sourceVector = std::vector<FunctionRVOExampleSourceClass>(5);
	return std::move(sourceVector);
}

/// RETURNING BOUNDED VARIABLE WITH IF STATEMENT
///
/// returns class type by value
/// return variable is bounded in its function
/// 
/// RVO is not guaranteed
/// no copying
/// 
/// BAD
std::vector<FunctionRVOExampleSourceClass> FunctionRVOExampleClass_2::GetSourceClass_If(bool IsTrue)
{
	std::vector<FunctionRVOExampleSourceClass> sourceVectorFirst = std::vector<FunctionRVOExampleSourceClass>(5);
	std::vector<FunctionRVOExampleSourceClass> sourceVectorSecond = std::vector<FunctionRVOExampleSourceClass>(3);

	if (IsTrue)
	{
		return sourceVectorFirst;
	}
	else
	{
		return sourceVectorSecond;
	}

	return sourceVectorFirst;
}
