#pragma once

#include <iostream>

/// ********************
/// DIAMOND INHERITANCE
/// ********************

/// Example root class
class DiamondInheritanceExampleClass_Root
{
public: 
	DiamondInheritanceExampleClass_Root() : mNum_Root { 0 }
	{
		std::cout << "root class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Root() noexcept
	{
		std::cout << "root class destructor called" << std::endl;
	}

	int mNum_Root;
};

/// Example parent 1 class without virtual inheritance
class DiamondInheritanceExampleClass_Parent_1 : public DiamondInheritanceExampleClass_Root
{
public:

	DiamondInheritanceExampleClass_Parent_1() : mNum_Parent_1 { 0 }
	{
		std::cout << "parent 1 class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Parent_1() noexcept
	{
		std::cout << "parent 1 class destructor called" << std::endl;
	}

	int mNum_Parent_1;
};

/// Example parent 2 class without virtual inheritance
class DiamondInheritanceExampleClass_Parent_2 : public DiamondInheritanceExampleClass_Root
{
public:

	DiamondInheritanceExampleClass_Parent_2() : mNum_Parent_2{ 0 }
	{
		std::cout << "parent 2 class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Parent_2() noexcept
	{
		std::cout << "parent 2 class destructor called" << std::endl;
	}

	int mNum_Parent_2;
};

/// Example parent 1 class with virtual inheritance
class DiamondInheritanceExampleClass_Parent_1_Virtual : virtual public DiamondInheritanceExampleClass_Root
{
public:

	DiamondInheritanceExampleClass_Parent_1_Virtual() : mNum_Parent_1{ 0 }
	{
		std::cout << "parent 1 class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Parent_1_Virtual() noexcept
	{
		std::cout << "parent 1 class destructor called" << std::endl;
	}

	int mNum_Parent_1;
};

/// Example parent 2 class with virtual inheritance
class DiamondInheritanceExampleClass_Parent_2_Virtual : virtual public DiamondInheritanceExampleClass_Root
{
public:

	DiamondInheritanceExampleClass_Parent_2_Virtual() : mNum_Parent_2 { 0 }
	{
		std::cout << "parent 2 class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Parent_2_Virtual() noexcept
	{
		std::cout << "parent 2 class destructor called" << std::endl;
	}

	int mNum_Parent_2;
};

/// Example child class inherited from non-virtual parents
class DiamondInheritanceExampleClass_Child : public DiamondInheritanceExampleClass_Parent_1, public DiamondInheritanceExampleClass_Parent_2
{
public:

	DiamondInheritanceExampleClass_Child()
	{
		std::cout << "child class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Child() noexcept
	{
		std::cout << "child class destructor called" << std::endl;
	}
};

/// Example child class inherited from virtually inherited parents
class DiamondInheritanceExampleClass_Child_Virtual : public DiamondInheritanceExampleClass_Parent_1_Virtual, public DiamondInheritanceExampleClass_Parent_2_Virtual
{
public:

	DiamondInheritanceExampleClass_Child_Virtual()
	{
		std::cout << "child class constructor called" << std::endl;
	}

	virtual ~DiamondInheritanceExampleClass_Child_Virtual() noexcept
	{
		std::cout << "child class destructor called" << std::endl;
	}
};


void executeDiamondInheritanceExample();