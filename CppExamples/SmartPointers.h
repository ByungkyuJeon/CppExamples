#pragma once

#include<iostream>

/// EXAMPLE SOURCE CLASS
///
/// smart pointers suits RAII (Resource Acquisition Is Initialization)
/// RAII means that resource's life cycle matches to object's life cycle
/// 
/// smart pointers' life cycle is scope based
class SmartPointersExampleSourceClass
{
public:
	SmartPointersExampleSourceClass()
	{
		std::cout << "constructor called" << std::endl;
	}

	~SmartPointersExampleSourceClass() noexcept
	{
		std::cout << "destructor called" << std::endl;
	}
};



/// POSSIBLE MEMORY LEAK BY USING SMART POINTERS
class SmartPointersExampleClass
{
public:

	SmartPointersExampleClass()
	{
		std::cout << "constructor called" << std::endl;
	}

	~SmartPointersExampleClass() noexcept
	{
		std::cout << "destructor called" << std::endl;
	}

	/// MEMORY LEAK
	///
	/// pointing mutually each other will cause memory leak when objects are deleted
	/// this problem can be solved by unsing weak pointer instead
	void SetFriend(const SmartPointersExampleClass& other)
	{
		mFriend_Shared = std::make_shared<SmartPointersExampleClass>(other);
		mFriend_Weak = std::make_shared<SmartPointersExampleClass>(other);
	}

private:
	std::shared_ptr<SmartPointersExampleClass> mFriend_Shared;
	std::weak_ptr<SmartPointersExampleClass> mFriend_Weak;
};


void main_SmartPointersExample();