#include "DiamondInheritance.h"

void main_DiamondInheritanceExample()
{
	/// DIAMOND INHERITANCE INSTANCIATION 
	
	/// instanciation procedure without virtual inheritance
	/// 
	/// 1. root class constructor
	/// 2. parent 1 class constructor
	/// 3. root class constructor
	/// 4. parent 2 class constructor
	/// 5. child class constructor
	/// 
	/// 6. child class destructor
	/// 7. parent 2 class destructor
	/// 8. root class destructor
	/// 9. parent 1 class destructor
	/// 10. root class destructor
	/// 
	/// class size
	/// 
	/// 1. root class virtual table address
	/// 2. root class member data
	/// 3. parent 1 class member data
	/// 4. root class virtual table address
	/// 5. parent 2 class member data
	/// 6. child class member data
	std::cout << "--- Inheritance without virtual keyword ---" << std::endl;
	{
		std::cout << "instanciation procedure" << std::endl;
		std::unique_ptr<DiamondInheritanceExampleClass_Child> exampleClass = std::make_unique<DiamondInheritanceExampleClass_Child>();
		std::cout << "class size : " << sizeof(*exampleClass) << std::endl;
	}
	
	 
	///	instanciation procedure with virtual inheritance
	/// 
	/// 1. root class constructor
	/// 2. parent 1 class constructor
	/// 3. parent 2 class constructor
	/// 4. child class constructor
	/// 
	/// 5. child class destructor
	/// 6. parent 2 class destructor
	/// 7. parent 1 class destructor
	/// 8. root class destructor
	/// 
	/// class size
	/// 
	/// 1. parent 1 class's virtual table address
	/// 2. parent 1 member data
	/// 3. parent 2 class's virtual table address
	/// 4. parent 2 member data
	/// 5. child member data
	/// 6. root class's virtual table address
	/// 7. root class member data
	std::cout << "--- virtual diamond Inheritance ---" << std::endl;
	{
		std::cout << "instanciation procedure" << std::endl;
		std::unique_ptr<DiamondInheritanceExampleClass_Child_Virtual> exampleClass = std::make_unique<DiamondInheritanceExampleClass_Child_Virtual>();
		std::cout << "class size : " << sizeof(*exampleClass) << std::endl;
	}
}
