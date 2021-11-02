
#include "MembersInit.h"

/// CALL EXAMPLE
///
/// 
void main_MembersInitExample()
{
	/// calling default constructor
	MembersInitExampleClass_2 ExampleClass{ "hello", 10 };

	/// calling copy constructor
	MembersInitExampleClass_2 ExampleClass_Copy_1{ ExampleClass };
	MembersInitExampleClass_2 ExampleClass_Copy_2 = ExampleClass;

	// calling move constructor
	MembersInitExampleClass_2 ExampleClass_Move_1{ std::move(ExampleClass) };

	// calling copy assignment
	MembersInitExampleClass_2 ExampleClass_CopyAssign;
	ExampleClass_CopyAssign = ExampleClass;

	// calling move assignment
	MembersInitExampleClass_2 ExampleClass_MoveAssign;
	ExampleClass_MoveAssign = std::move(ExampleClass);

}

/// move assingment
///
/// operator= overloading
/// 
/// self assignment safety code required
/// because when self assignment occur, there will be memory leak for member pointer variables
/// 
/// no memory allocation happens, so use keyword noexcept
/// if there is no keyword noexcept, move assignment call is not guaranteed
MembersInitExampleClass_2& MembersInitExampleClass_2::operator=(MembersInitExampleClass_2&& other) noexcept
{
	/// self assignment safty code
	if (&other == this)
	{
		return *this;
	}

	mStr = std::move(other.mStr);
	mNum = other.mNum;
	return *this;
}

/// copy assignment
///
/// operator= overloading
/// 
/// self assignment safety code required
/// because when self assignment occur, there will be memory leak for member pointer variables
MembersInitExampleClass_2& MembersInitExampleClass_2::operator=(const MembersInitExampleClass_2& other)
{
	/// self assignment safety code 
	if (&other == this)
	{
		return *this;
	}

	mStr = other.mStr;
	mNum = other.mNum;
	return *this;
}
