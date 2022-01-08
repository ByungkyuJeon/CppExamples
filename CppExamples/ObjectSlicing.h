#pragma once

#include <iostream>
#include <memory>

class ObjectSlicingExampleClass_Parent_Sliced
{
public:
	ObjectSlicingExampleClass_Parent_Sliced() :mNum_Parent{ 0 } {}
	ObjectSlicingExampleClass_Parent_Sliced(int num) : mNum_Parent{ num } {}

	virtual ~ObjectSlicingExampleClass_Parent_Sliced() noexcept = default;
	
	virtual void Print()
	{
		std::cout << "parent class print called, member variable value : " << mNum_Parent << std::endl;
	}

	int mNum_Parent;
};

class ObjectSlicingExampleClass_Parent_Blocked
{
public:

	ObjectSlicingExampleClass_Parent_Blocked() : mNum_Parent{ 0 } {}
	ObjectSlicingExampleClass_Parent_Blocked(int num) : mNum_Parent{ num } {}

	// copy assignment block
	ObjectSlicingExampleClass_Parent_Blocked& operator=(ObjectSlicingExampleClass_Parent_Blocked other) = delete;

	virtual ~ObjectSlicingExampleClass_Parent_Blocked() noexcept = default;

	// explicit copy function
	virtual std::unique_ptr<ObjectSlicingExampleClass_Parent_Blocked> Clone() { return nullptr; }

	int mNum_Parent;

protected:

	// copy constructor block
	ObjectSlicingExampleClass_Parent_Blocked(const ObjectSlicingExampleClass_Parent_Blocked& other) = default;
};

class ObjectSlicingExampleClass_Child : public ObjectSlicingExampleClass_Parent_Sliced
{
public:

	ObjectSlicingExampleClass_Child() : mNum_Child{ 0 } {}
	ObjectSlicingExampleClass_Child(int num) : mNum_Child{ num } {}

	void Print() override
	{
		std::cout << "child class print called, parent variable value : " 
			<< mNum_Parent 
			<< " / member variable value : "
			<< mNum_Child 
			<< std::endl;
	}

private:
	
	int mNum_Child;
};


void executeObjectSlicingExample();