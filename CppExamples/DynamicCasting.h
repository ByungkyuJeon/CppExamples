#pragma once

#include <iostream>

class DynamicCastingExampleClass_Parent
{
public:

	DynamicCastingExampleClass_Parent() = default;

	virtual ~DynamicCastingExampleClass_Parent() noexcept = default;

	virtual void Print()
	{
		std::cout << "parent class print called" << std::endl;
	}

};

class DynamicCastingExampleClass_Child_1 : public DynamicCastingExampleClass_Parent
{
public:

	DynamicCastingExampleClass_Child_1() = default;
	~DynamicCastingExampleClass_Child_1() = default;

	void Print() override
	{
		std::cout << "child class 1 print called" << std::endl;
	}
};

class DynamicCastingExampleClass_Child_2 : public DynamicCastingExampleClass_Parent
{
public:

	DynamicCastingExampleClass_Child_2() = default;
	~DynamicCastingExampleClass_Child_2() = default;

	void Print() override
	{
		std::cout << "child class 2 print called" << std::endl;
	}
};

void executeDynamicCastingExample();