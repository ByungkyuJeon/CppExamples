#include "LinearInheritance.h"

#include <array>
#include <ctime>

void main_LinearInheritanceExample()
{
	/// DERIVED CLASS INITIALIZATION
	///
	/// 1. parent constructor
	/// 2. child  constructor
	/// 3. child  destructor
	/// 4. parent destructor
	std::cout << "--- derived class initialization ---" << std::endl;
	{
		std::shared_ptr<LinearInheritanceExampleClass_Child_1> exampleClass = std::make_shared<LinearInheritanceExampleClass_Child_1>();
	}

	/// CLASS INHERITANCE QUALIFIER
	///
	/// 1. public Inheritance qualifier
	/// accessable from child	- public/protected
	/// accessable from outside - public
	/// 
	/// 2. protected Inheritance qualifier
	/// accessable from child	- public/protected
	/// accessable from outside - none
	/// 
	/// 3. private Inheritance qualifier
	/// accessable from chid	- none
	/// accessable from outside	- none
	std::cout << "--- class inheritance qualifier ---" << std::endl;
	{
		std::shared_ptr<LinearInheritanceExampleClass_Child_1> exampleClass = std::make_shared<LinearInheritanceExampleClass_Child_1>();
		exampleClass->mNum_Public;
		// must access inside the class
		// exampleClass->mNum_Protected

		// can not access
		// exampleClass->mNum_Private
	}


	/// VIRTUAL DESTRUCTOR (dynamic polymorphism)
	///
	/// if using smart pointer, there will be no problem like this
	std::cout << "--- virtual destructor ---" << std::endl;
	{
		/// 1. Instanciating parent object to parent class variable
		std::cout << "* parent to parent" << std::endl;
		/// 
		/// -> parent constructor
		/// -> parent destructor
		LinearInheritanceExampleClass_Parent* exampleClass = new LinearInheritanceExampleClass_Parent();
		delete(exampleClass);
	}

	{
		/// 2. Instanciating child object to child class variable
		std::cout << "* child to child" << std::endl;
		/// 
		/// -> parent constructor
		/// -> child constructor
		/// -> child destructor
		/// -> parent destructor
		LinearInheritanceExampleClass_Child_1* exampleClass = new LinearInheritanceExampleClass_Child_1();
		delete(exampleClass);
	}

	{
		/// 3. Instanciating child object to parent class variable
		std::cout << "* child to parent" << std::endl;
		/// 
		/// if parent class destructor doesn't have virtual keyword added
		/// 
		/// -> parent constructor
		/// -> child constructor
		/// -> parent destructor
		/// 
		/// if parent class destructor have virtual keyword
		/// 
		/// -> parent constructor
		/// -> child constructor
		/// -> child destructor
		/// -> parent destructor
		LinearInheritanceExampleClass_Parent* exampleClass = new LinearInheritanceExampleClass_Child_1();
		delete(exampleClass);
	}



	/// DYNAMIC POLYMORPHISM
	///
	/// dynamic polymorphism works based on internal virtual table
	/// every classes that have virtual functions are internally pointing to its own virtual table
	/// virtual table has virtual function addresses in it and forwards function calls to them
	/// 
	/// pointer data size to its own virtual table (4bytes on 32bit os / 8bytes on 64bit os)
	/// 
	/// parent class -> parent virtual table
	/// child_1 class -> child_1 virtual table
	/// child_2 class -> child_2 virtual table
	{
		const int classCount = 5;
		std::array<std::unique_ptr<LinearInheritanceExampleClass_Parent>, classCount> exampleArray;
		std::srand(std::time(nullptr));
		std::cout << "--- dynamic polymorphism ---" << std::endl;

		for (int idx = 0; idx < classCount; idx++)
		{
			if (std::rand() % 2 == 0)
			{
				exampleArray[idx] = std::make_unique<LinearInheritanceExampleClass_Child_1>();
			}
			else
			{
				exampleArray[idx] = std::make_unique<LinearInheritanceExampleClass_Child_2>();
			}
		}
	}


}
