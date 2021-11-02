#pragma once

#include<vector>

/// EXAMPLE SOURCE CLASS
/// 
/// used as member of example classes
class FunctionRVOExampleSourceClass
{
public:
	FunctionRVOExampleSourceClass() {}
	~FunctionRVOExampleSourceClass() {}
};

/// EXAMPLE 1
///
/// example for returning its own members
/// 
/// the main goal is to know when does the RVO intervenes and when doesn't
class FunctionRVOExampleClass_1
{
public:

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
	int GetNum_Value();

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
	const int& GetNum_Ref();

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
	FunctionRVOExampleSourceClass GetSourceClass_Value();

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
	const FunctionRVOExampleSourceClass& GetSourceClass_Ref();

private:
	int mNum;
	FunctionRVOExampleSourceClass mSourceClass;
};


/// EXAMPLE 2
///
/// example for returning variables that are bounded in class
/// 
/// the main goal is to know when does the RVO intervenes and when doesn't
class FunctionRVOExampleClass_2
{
public:

	/// RETURNING BOUNDED VARIABLE BY VALUE
	///
	/// returns class type by value
	/// return variable is bounded in its function
	/// 
	/// RVO intervenes(guaranteed)
	/// no copying
	/// 
	/// GOOD
	std::vector<FunctionRVOExampleSourceClass> GetSourceClass_Value();

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
	std::vector<FunctionRVOExampleSourceClass> GetSourceClass_Move();

	/// RETURNING BOUNDED VARIABLE WITH IF STATEMENT
	///
	/// returns class type by value
	/// return variable is bounded in its function
	/// 
	/// RVO is not guaranteed
	/// no copying
	/// 
	/// BAD
	std::vector<FunctionRVOExampleSourceClass> GetSourceClass_If(bool IsTrue);
};
