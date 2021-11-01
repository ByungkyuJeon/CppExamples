#pragma once

#include <iostream>

/// EXAMPLE SOURCE CLASS
/// 
/// used as member of example classes
class CopyElisionExampleSourceClass
{
public:
	CopyElisionExampleSourceClass() = default;
	CopyElisionExampleSourceClass(int num) : mNum{ num } {}

	void print()
	{
		std::cout << mNum << std::endl;
	}
private:
	int mNum;
};


/// EXAMPLE 1
///
/// goal is to make least copy and safety when setting member variables
/// 
class CopyElisionExampleClass_1
{
public:
	/// call by value case
	void SetSource_Value(CopyElisionExampleSourceClass source)
	{
		/// 1 copy generated
		/// ownership not changed
		///
		/// one for member assignment [mExampleSource]
		mExampleSource = source;

		/// 0 copy generated
		/// ownership moved
		mExampleSource = std::move(source);
	}
	/// call by lvalue reference case
	void SetSource_LRef(CopyElisionExampleSourceClass& source)
	{
		/// 1 copy generated
		/// ownership not changed
		///
		/// one for member assignment [mExampleSource]
		mExampleSource = source;

		/// 0 copy generated
		/// ownership moved
		mExampleSource = std::move(source);
	}
	/// call by const lvalue reference case
	void SetSource_LRefConst(const CopyElisionExampleSourceClass& source)
	{
		/// 1 copy generated
		/// ownership not changed
		///
		/// one for member assignment [mExampleSource]
		mExampleSource = source;

		/// 1 copy generated
		/// ownership not changed
		/// 
		/// one for member assignment [mExampleSource]
		mExampleSource = std::move(source);
	}
	/// call by rvalue reference case
	void SetSource_RRef(CopyElisionExampleSourceClass&& source)
	{
		/// 1 copy generated
		/// ownership not changed
		///
		/// one for member assignment [mExampleSource]
		mExampleSource = source;

		/// 0 copy generated
		/// original object's ownership changed
		mExampleSource = std::move(source);
	}
private:
	CopyElisionExampleSourceClass mExampleSource;
};

/// main function entry for this example
/// 
/// to execute example, call this function
static void main_CopyElisionExample()
{
	CopyElisionExampleSourceClass sourceClass = CopyElisionExampleSourceClass(10);
	CopyElisionExampleClass_1 copyElisionExampleClass;

	/// BEST CODE (not for all context)
	/// 
	/// CALL BY VALUE - lvalue
	///
	/// 1 copy generated
	/// 
	/// one for parameter [sourceClass]
	/// 
	/// with std::move in function : total 1 copy generated / ownership isn't moved (safe)
	/// without std::move in function : total 2 copies generated / ownership isn't moved (safe)
	copyElisionExampleClass.SetSource_Value(sourceClass);

	/// CALL BY VALUE - rvalue
	///
	/// 0 copy generated
	/// 
	/// with std::move in function : total 0 copy generated / ownership moved (not safe)
	/// without std::move in function : total 1 copies generated / ownership moved (not safe)
	copyElisionExampleClass.SetSource_Value(std::move(sourceClass));

	/// CALL BY REFERENCE - lvalue
	///
	/// 0 copy generated
	/// 
	/// with std::move in function : total 0 copy generated / ownership moved (not safe)
	/// without std::move in function : total 1 copies generated / ownership isn't moved (safe)
	copyElisionExampleClass.SetSource_LRef(sourceClass);

	/// CALL BY CONST REFERENCE - lvalue
	///
	/// 0 copy generated
	/// 
	/// with std::move in function : total 1 copy generated / ownership isn't moved (safe)
	/// without std::move in function : total 1 copies generated / ownership isn't moved (safe)
	copyElisionExampleClass.SetSource_LRefConst(sourceClass);

	/// CALL BY CONST REFERENCE - rvalue
	///
	/// 0 copy generated
	/// 
	/// with std::move in function : total 1 copy generated / ownership moved (not safe)
	/// without std::move in function : total 1 copies generated / ownership moved (not safe)
	copyElisionExampleClass.SetSource_LRefConst(std::move(sourceClass));

	/// CALL BY REFERENCE - rvalue
	///
	/// 0 copy generated
	/// 
	/// with std::move in function : total 0 copy generated / ownership moved (not safe)
	/// without std::move in function : total 1 copies generated / ownership moved (not safe)
	copyElisionExampleClass.SetSource_RRef(std::move(sourceClass));
}