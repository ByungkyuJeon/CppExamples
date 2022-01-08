#include "DynamicCasting.h"

#include <memory>

void executeDynamicCastingExample()
{
	/// STATIC CASTING
	std::cout << "--- static casting ---" << std::endl;
	{
		DynamicCastingExampleClass_Child_1 exampleClass = DynamicCastingExampleClass_Child_1();
		exampleClass.Print();

		/// upcasting
		///
		/// static casing
		auto upCasting = static_cast<DynamicCastingExampleClass_Parent&>(exampleClass);
		/// implicit casting
		upCasting = exampleClass;
		upCasting.Print();

		/// downcasting
		auto downCasting = static_cast<DynamicCastingExampleClass_Child_1&>(upCasting);
		downCasting.Print();

		/// downcasting to wrong child
		///
		/// complies success for this example class, but might occur crucial error or bug
		/// because child 2 class data is null
		auto downCasting_Other = static_cast<DynamicCastingExampleClass_Child_2&>(upCasting);
		downCasting_Other.Print();
	}

	/// DYNAMIC CASTING
	///
	/// dynamic casting looks up class's virtual table for type info
	/// if casting type doesn't match to class type, returns nullptr
	/// 
	/// many of cpp projects restricts using dynamic_cast
	/// because there is more proper way of class structure without using dynamic_cast
	/// using dynamic_cast means that software architecture or class structure(Inheritance) is in wrong way
	std::cout << "--- dynamic casting ---" << std::endl;
	{
		DynamicCastingExampleClass_Parent* exampleClass =  new DynamicCastingExampleClass_Child_1();
		exampleClass->Print();
		auto downCasting_Right = dynamic_cast<DynamicCastingExampleClass_Child_1*>(exampleClass);
		if (downCasting_Right == nullptr)
		{
			std::cout << "dynamic casting failed" << std::endl;
		}
		else
		{
			downCasting_Right->Print();
		}
		auto downCasting_Wrong = dynamic_cast<DynamicCastingExampleClass_Child_2*>(exampleClass);
		if (downCasting_Wrong == nullptr)
		{
			std::cout << "dynamic casting failed" << std::endl;
		}
		else
		{
			downCasting_Wrong->Print();
		}

	}
}
