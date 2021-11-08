#include "FunctionObject.h"

void main_FunctionObejctExample()
{
	/// FUNCTION OBJECT EXAMPLE
	/// 
	/// function obejct is a concept that is part of function oriented programming
	/// FunctionObjectExampleClass is a cpp class that overrides operator()
	/// so class's Instance can be wroted and called just like functions 
	/// and also can be treated like a variable 
	FunctionObjectExampleClass exampleClass{};
	std::cout << *exampleClass((char*)"Function Object Example Class") << std::endl;
	std::cout << *exampleClass((char*)"hello") << std::endl;

	[&]()
	{
		std::cout << *exampleClass((char*)"called from other function") << std::endl;
	}();
}
