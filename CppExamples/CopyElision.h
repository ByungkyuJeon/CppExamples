#pragma once

/// EXAMPLE SOURCE CLASS
/// 
/// used as member of example classes
class CopyElisionExampleSourceClass
{
public:
	CopyElisionExampleSourceClass() = default;
	CopyElisionExampleSourceClass(int num) : mNum{ num } {}

	void print();

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
	void SetSource_Value(CopyElisionExampleSourceClass source);

	/// call by lvalue reference case
	void SetSource_LRef(CopyElisionExampleSourceClass& source);

	/// call by const lvalue reference case
	void SetSource_LRefConst(const CopyElisionExampleSourceClass& source);

	/// call by rvalue reference case
	void SetSource_RRef(CopyElisionExampleSourceClass&& source);

private:
	CopyElisionExampleSourceClass mExampleSource;
};

/// main function entry for this example
/// 
/// to execute example, call this function
void executeCopyElisionExample();