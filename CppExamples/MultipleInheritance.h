#pragma once

#include <iostream>

/// ********************
/// MULTIPLE INHERITANCE
/// ********************

/// case of using mutiple inheritance architecture
///
/// 1. child classes must have several base classes' properties
/// 2. for flexible architecture, base classes are fractionated by abstract, interface, implemented

/// Multiple Inheritance Example Parent Class 1
class MultipleInheritanceExampleClass_Parent_1
{
public:
	MultipleInheritanceExampleClass_Parent_1() : mNum_Parent_1 { 0 }
	{
		std::cout << "parent 1 class constructor called" << std::endl;
	}

	virtual ~MultipleInheritanceExampleClass_Parent_1() noexcept
	{
		std::cout << "parent 1 class destructor called" << std::endl;
	}

	int mNum_Parent_1;
};

/// Multiple Inheritance Example Parent Class 2
class MultipleInheritanceExampleClass_Parent_2
{
public:
	MultipleInheritanceExampleClass_Parent_2() : mNum_Parent_2 { 0 } 
	{
		std::cout << "parent 2 class constructor called" << std::endl;
	}

	virtual ~MultipleInheritanceExampleClass_Parent_2() noexcept
	{
		std::cout << "parent 2 class destructor called" << std::endl;
	}

	int mNum_Parent_2;
};

/// Multiple Inheritance Example Child Class
///
/// Inheritancing order affects call procedure of constructors and destructors
/// 
/// child class's size is sum of
/// 1. base classes' virtual table address (4bytes on 32bit os, 8bytes on 64bit os)
/// 2. base classes' member variable size
/// 3. child class's virtual table address (4bytes on 32bit os, 8bytes on 64bit os)
/// 4. child class's member variable size
class MultipleInheritanceExampleClass_Child : public MultipleInheritanceExampleClass_Parent_1, public MultipleInheritanceExampleClass_Parent_2
											// public MultipleInheritanceExampleClass_Parent_2, MultipleInheritanceExampleClass_Parent_1
{
public:
	MultipleInheritanceExampleClass_Child() : mNum_Child { 0 }
	{
		std::cout << "child class constructor called" << std::endl;
	}

	~MultipleInheritanceExampleClass_Child() noexcept
	{
		std::cout << "child class destructor called" << std::endl;
	}

	int mNum_Child;
};

void executeMultipleInheritanceExample();