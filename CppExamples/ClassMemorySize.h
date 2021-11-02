#pragma once

/// EXAMPLE 1
/// 
/// cpp classes(structs) memory allocation rule
/// 
/// 1. Their member variables' start memory address should be multiple of their own size.
/// 2. Total size of class(struct) should be multiple number of own max variable size 
/// 3. The additional memory is called padding 

class SizeExampleClass_1
{
public:

	// get size from this function
	int GetSize();

private:

	/// LESS EFFICIENT DECLARATION ORDER
	/// 
	/// total size of member variables is 16 bytes, but size of class will be 24 bytes because of padding
	/// total size of member variables : 16 bytes
	/// total size of padding : 8 bytes
	/// total size of class : 24 bytes

	// 4 bytes
	int mAge;
	// 8 bytes
	double mHealth;
	// 4 bytes
	int mHeight;

private:

	/// THE MOST EFFICIENT DECLARATION ORDER
	/// 
	/// total size of member variables is 16 bytes and there will be no padding
	/// total size of member variables : 16 bytes
	/// total size of padding : 0 bytes
	/// total size of class : 16 bytes

	// double mHealth;
	// int mAge;
	// int mHeight;

	/// OR

	// int mAge;
	// int mHeight;
	// double mHealth;
};


/// EXAMPLE 2
///
/// preventing false sharing in multithreading environment
/// 
/// generally cpu's cache line is 64 bytes, and class size on memory may cause trouble(false sharing)
/// class size should be divisor of cpu cache line(64 bytes) e.g - 16 bytes, 32 bytes, 64 bytes
/// keyword alignas(int) C++11 will prevent this problem
/// there will be automatically inserted pedding till the size specified

class alignas(32) SizeExampleClass_2
{
public:

	// get size from this function
	int GetSize();

private:

	/// total size of member variables : 16 bytes
	/// total size of padding : 16 bytes
	/// total size of class : 32 bytes

	// 8 bytes
	double mHealth;
	// 4 bytes
	int mAge;
	// 4 bytes
	int mHeight;
};