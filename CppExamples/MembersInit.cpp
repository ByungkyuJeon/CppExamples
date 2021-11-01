#pragma once

#include <string>
#include <memory>

/// EXAMPLE SOURCE CLASS
/// 
/// used as member of example classes
class MembersInitExampleSourceClass
{
public:
	MembersInitExampleSourceClass() {}

	MembersInitExampleSourceClass(int num)
	{
		mNum = num;
		mFloat = 0;
	}

	MembersInitExampleSourceClass(float num)
	{
		mNum = 0;
		mFloat = num;
	}

	~MembersInitExampleSourceClass() {}
private:
	int mNum;
	float mFloat;
};

/// EXAMPLE 1
/// 
/// wasting stack memory by copying class object in constructor
class MembersInitExampleClass_1
{
public:

	MembersInitExampleClass_1()
	{
		mNum = 0;
	}

	/// WRONG
	/// 
	/// waste of 1 copy for ExampleSourceClass occur
	/// 
	/// constructor initializes ExampleSourceClass in constructor stack frame and copies to member variable mExampleSource
	/// after initialzation, copy of ExampleSourceClass is deleted (destructor called)
	MembersInitExampleClass_1(int num)
	{
		mExampleSource = MembersInitExampleSourceClass(num);
	}

	/// RIGHT
	///
	/// No waste of memory in constructor
	///
	/// can be solved by using member initializer list
	MembersInitExampleClass_1(float num) : mExampleSource{ MembersInitExampleSourceClass(num) } {}

	/// NO MATTER
	///
	/// for primitive types, either way doesn 't matter. machine code is same
	MembersInitExampleClass_1(double num) : mNum{ num } {}

	~MembersInitExampleClass_1() {}

private:

	double mNum;
	MembersInitExampleSourceClass mExampleSource;
};

/// EXAMPLE 2
///
/// cpp rule of three / five
/// 
/// if there are pointer members in class(struct), then additional constructors and assignment overloadings are required
/// 
/// 1. destructor - deallocation of heap memory object required
/// 2. copy constructor - (if wants) class deep copy code required or maybe shallow copy by just copying pointer variable
/// 3. move constructor - (if wants) all class members move code required
/// 4. copy assignment - same as 2
/// 5. move assignment - same as 3
/// 
/// if a class has pointer in its member, managing variable's lifecycle might be treaky
/// so, in general environment, using pointer member variable is not recommended (not smart pointer, just pointer)
/// 
class MembersInitExampleClass_2
{
public:
	/// complier's default constructor
	/// = default is meaning of using default constructor which is made by compiler
	MembersInitExampleClass_2() = default;

	/// delete keyword
	/// 
	/// deletes definitions of constructor, copy/move constructors, copy/move assignment
	/// might be useful for static classes for blocking instanciation
	/// might be useful for singleton classes for blocking copy/move constructors and assignments
	/// 
	//MembersInitExampleClass_2() = delete;

	/// custom argument constructor
	/// 1 copy initialization for string type
	MembersInitExampleClass_2(std::string str, int num) : mStr{ std::move(str) }, mNum{ num }{}

	/// copy constructor
	MembersInitExampleClass_2(const MembersInitExampleClass_2& other) : mStr{ other.mStr }, mNum{ other.mNum }{}

	/// move constructor
	///
	/// no memory allocation happens, so use keyword noexcept
	MembersInitExampleClass_2(MembersInitExampleClass_2&& other) noexcept : mStr{ std::move(other.mStr) }, mNum{ other.mNum }{}

	/// copy assignment
	///
	/// operator= overloading
	/// 
	/// self assignment safety code required
	/// because when self assignment occur, there will be memory leak for member pointer variables
	MembersInitExampleClass_2& operator=(const MembersInitExampleClass_2& other)
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
	/// move assingment
	///
	/// operator= overloading
	/// 
	/// self assignment safety code required
	/// because when self assignment occur, there will be memory leak for member pointer variables
	/// 
	/// no memory allocation happens, so use keyword noexcept
	/// if there is no keyword noexcept, move assignment call is not guaranteed
	MembersInitExampleClass_2& operator=(MembersInitExampleClass_2&& other) noexcept
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

	/// destructor
	///
	/// no memory allocation happens, so use keyword noexcept
	~MembersInitExampleClass_2() noexcept {}

private:

	std::string mStr;
	int mNum;

	/// Pointer variable example which needs rule of five (deep copying)
	///
	/// but if using smart pointer variable, then those rule of five doesn't need
	/// because smart pointers are perfectly suits to RAII
	/// 
	//char* mChar;
	//std::unique_ptr<char> mSmartPointer;
};


/// CALL EXAMPLE
///
/// 
static int main_MembersInitExample()
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