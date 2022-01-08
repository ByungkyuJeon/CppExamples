#include "MultipleInheritance.h"

#include <memory>

void executeMultipleInheritanceExample()
{
	/// CALL PROCEDURE AFFECTED BY INHERITANCE ORDER
	///
	/// in case of : public parent 1 class, parent 2 class
	std::cout << "--- call procedure affected by inheritance order ---" << std::endl;
	{
		/// calling order
		/// 
		/// 1. parent 1 class constructor
		/// 2. parent 2 class constructor
		/// 3. child class constructor
		/// 4. child class destructor
		/// 5. parent 2 class destructor
		/// 6. parent 1 class destructor
		std::unique_ptr<MultipleInheritanceExampleClass_Child> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Child>();
	}

	/// POLYMORPHISM WITH INDICATING VIRTUAL TABLE
	///
	std::cout << "--- polymorphism ---" << std::endl;
	/// initiating with parent 1
	/// 
	/// exampleClass's virtual table pointer address -> child class's virtual table
	{
		std::unique_ptr<MultipleInheritanceExampleClass_Parent_1> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Child>();
	}
	/// initiating with parent 2
	/// 
	/// exampleClass's virtual table pointer address -> child class's virtual table
	{
		std::unique_ptr<MultipleInheritanceExampleClass_Parent_2> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Child>();
	}
	/// initiating with child
	/// 
	/// exampleClass's virtual table pointer address -> child class's virtual table
	{
		std::unique_ptr<MultipleInheritanceExampleClass_Child> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Child>();
	}


	/// SIZE OF DERIVED CLASS
	///
	std::cout << "--- size of derived class ---" << std::endl;
	/// size of parent 1 class
	{
		std::unique_ptr<MultipleInheritanceExampleClass_Parent_1> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Parent_1>();
		std::cout << "size of base 1 class : " << sizeof(*exampleClass) << std::endl;
	}
	/// size of parent 2 class
	{
		std::unique_ptr<MultipleInheritanceExampleClass_Parent_2> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Parent_2>();
		std::cout << "size of base 2 class : " << sizeof(*exampleClass) << std::endl;
	}
	/// size of derived class
	{
		std::unique_ptr<MultipleInheritanceExampleClass_Child> exampleClass = std::make_unique<MultipleInheritanceExampleClass_Child>();
		std::cout << "size of derived class : " << sizeof(*exampleClass) << std::endl;
	}
}
