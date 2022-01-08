#include "ObjectSlicing.h"

#include <memory>

void executeObjectSlicingExample()
{
	/// OBJECT SLICING EXAMPLE
	///
	/// when child class instance is copied to its parent class, appearing child class's data loss is called object slicing
	/// 
	/// loss of data
	/// 1. virtual table address
	/// 2. child class data
	/// 
	/// solution to object slicing problem
	/// 1. deleting copy assignment function in base class, qualify copy constructor to 'protected' - blocks
	/// 2. 
	{
		ObjectSlicingExampleClass_Child exampleClass_Child{ 9 };
		exampleClass_Child.Print();

		/// gets child instance refernce to parent type
		/// object slicing does not occur
		ObjectSlicingExampleClass_Parent_Sliced& exampleClass_ParentRef = exampleClass_Child;
		exampleClass_ParentRef.Print();

		/// parent class' copy constructor is called
		/// object slicing occurred
		ObjectSlicingExampleClass_Parent_Sliced exampleClass_ParentVal_Sliced = exampleClass_Child;
		exampleClass_ParentVal_Sliced.Print();

		/// SOLUTION 1
		/// 
		/// parent class's copy constructor can not be called
		/// object slicing can not occur (compiler error)
		/// 
		/// instead, call child class's copy constructor
		/// 
		std::cout << "--- solution 1 ---" << std::endl;
		// ObjectSlicingExampleClass_Parent_Blocked exampleClass_parentVal_Blocked = exampleClass_Child; // COMPILER ERROR
		ObjectSlicingExampleClass_Child exampleClass_CopiedByConstructor{ exampleClass_Child };
		exampleClass_CopiedByConstructor.Print();
		// size of copied class

		/// SOLUTION 2
		///
		/// 
		/// parent class's copy constructor can not be called
		/// object slicing can not occur (compiler error)
		/// 
		/// instead, explicitly implement 'clone()' function and copy from that
		
		//ObjectSlicingExampleClass_Parent_Blocked exampleClass_CopiedByClone = exampleClass_Child.Clone();
	}



}
