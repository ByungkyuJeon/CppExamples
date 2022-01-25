#pragma once

#include <iostream>

/// ******************
/// LINEAR INHERITANCE
/// ******************

/// Example parent class
class LinearInheritanceExampleClass_Parent
{
public:

	LinearInheritanceExampleClass_Parent() : mNum_Public{ 0 }, mNum_Protected{ 0 }, mNum_Private{ 0 }
	{
		std::cout << "parent class constructor called" << std::endl;
	}

	/// DYNAMIC POLYMORPHISM
	/// 
	/// this destructor function address is stored in virtual table
	/// base class's destructor must be 'virtual public' or 'protected'
	virtual ~LinearInheritanceExampleClass_Parent()
	{
		std::cout << "parent class destructor called" << std::endl;
	}

	/// DYNAMIC POLYMORPHISM
	/// 
	/// this Print() function address is stored in virtual table
	virtual void Print()
	{
		std::cout << "called print from parent" << std::endl;
	}

	int mNum_Public; 

protected:

	int mNum_Protected;

private:

	int mNum_Private;
};

/// Example child class 1
class LinearInheritanceExampleClass_Child_1 : public LinearInheritanceExampleClass_Parent
									// protected InheritanceExampleClass_Parent
									// private InheritanceExampleClass_Parent
{
public:

	LinearInheritanceExampleClass_Child_1()
	{
		std::cout << "child 1 class constructor called" << std::endl;
	}

	~LinearInheritanceExampleClass_Child_1()
	{
		std::cout << "child 1 class destructor called" << std::endl;
	}

	/// DYNAMIC POLYMORPHISM
	/// 
	/// this Print() function address is stored in virtual table
	void Print() override
	{
		std::cout << "print called from child 1" << std::endl;
	}
};

/// Example child class 2
class LinearInheritanceExampleClass_Child_2 : public LinearInheritanceExampleClass_Parent
									// protected InheritanceExampleClass_Parent
									// private InheritanceExampleClass_Parent
{
public:

	LinearInheritanceExampleClass_Child_2()
	{
		std::cout << "child 2 class constructor called" << std::endl;
	}

	~LinearInheritanceExampleClass_Child_2()
	{
		std::cout << "child 2 class destructor called" << std::endl;
	}

	/// DYNAMIC POLYMORPHISM
	/// 
	/// this Print() function address is stored in virtual table
	void Print() override
	{
		std::cout << "print called from child 2" << std::endl;
	}
};

// Example child with public inheritance
class LinearInheritanceExampleClass_Child_3 : public LinearInheritanceExampleClass_Parent
{
public:
	void Print() override
	{
		// can access base's public variable
		// treated as 'public'
		std::cout << mNum_Public << std::endl;
		// can access base's protected variable
		// treated as 'protected'
		std::cout << mNum_Protected << std::endl;
		// std::cout << mNum_Private << std::endl; // can not access base's private variable
	}
};

// Example child with protected inheritance
class LinearInheritanceExampleClass_Child_4 : protected LinearInheritanceExampleClass_Parent
{
public:
	void Print() override
	{
		// can access base's public variable
		// treated as 'protected'
		std::cout << mNum_Public << std::endl;
		// can access base's protected variable
		// treated as 'protected'
		std::cout << mNum_Protected << std::endl;
		// std::cout << mNum_Private << std::endl; // can not access base's private variable
	}
};

// Example child with private inheritance
class LinearInheritanceExampleClass_Child_5 : private LinearInheritanceExampleClass_Parent
{
public:
	void Print() override
	{
		// can access base's public variable
		// treated as 'private'
		std::cout << mNum_Public << std::endl;
		// can access base's protected variable
		// treated as 'private'
		std::cout << mNum_Protected << std::endl;
		// std::cout << mNum_Private << std::endl; // can not access base's private variable
	}
};


/// Example Abstract Parent Class
/// 
/// can not be Instanciated
/// has minimum one of pure virtual functions
/// 
/// abstract base class(interface) is useful for division of labour in developer corp.
/// interface might be flexible when interface doesn't define function implementations and member variables
class LinearInheritanceExampleClass_Parent_Abstract
{
public:

	/// Pure virtual function
	virtual void Print() = 0;
};

/// Example Child Class Derived From Abstract Parent Class
/// 
/// must override pure virtual function
class LinearInheritanceExampleClass_Child_Abstract : public LinearInheritanceExampleClass_Parent_Abstract
{
public:
	void Print() override
	{
		std::cout << "print called from child derived from abstract class" << std::endl;
	}
};

void executeLinearInheritanceExample();