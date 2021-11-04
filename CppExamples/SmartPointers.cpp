#include "SmartPointers.h"

#include <memory>

void main_SmartPointersExample()
{
	/// POINTER EXAMPLE
	std::cout << "--- styles of pointers ---" << std::endl;

	/// 1. C STYLE POINTER 
	///
	/// c style pointer doesn't call class's constructor and destructor
	/// 
	/// must call free for deallocating of heap memory
	SmartPointersExampleSourceClass* examplePtr_c = (SmartPointersExampleSourceClass*)std::malloc(sizeof(SmartPointersExampleSourceClass));
	std::free(examplePtr_c);

	/// 2. C++ STYLE POINTER
	///
	/// c++ style pointer calls class's constructor and destructor
	/// 
	/// must call delete for deallocation of heap memory
	SmartPointersExampleSourceClass* examplePtr_cpp = new SmartPointersExampleSourceClass();
	delete(examplePtr_cpp);

	/// 3. C++ SMART POINTER STYLE POINTER
	///
	/// smart pointer style pointer calls class's contructor and desturctor
	/// 
	/// don't have to call any operation for deallocation of heap memory
	std::unique_ptr<SmartPointersExampleSourceClass> examplePtr_Unique = std::make_unique<SmartPointersExampleSourceClass>();
	std::shared_ptr<SmartPointersExampleSourceClass> examplePtr_Shared = std::make_shared<SmartPointersExampleSourceClass>();
	std::weak_ptr<SmartPointersExampleSourceClass> examplePtr_Weak = examplePtr_Shared;



	/// POINTER SIZE
	std::cout << "--- pointer sizes ---" << std::endl;
	
	/// c style, cpp style pointer size : 8 bytes
	/// unique pointer size : 8 bytes
	/// shared, weak pointer size : 16 bytes
	examplePtr_c = (SmartPointersExampleSourceClass*)std::malloc(sizeof(SmartPointersExampleSourceClass));
	std::cout << "c style pointer size : " << sizeof(examplePtr_c) << std::endl;

	examplePtr_cpp = new SmartPointersExampleSourceClass();
	std::cout << "cpp style pointer size : " << sizeof(examplePtr_cpp) << std::endl;

	std::cout << "unique smart pointer size : " << sizeof(examplePtr_Unique) << std::endl;
	std::cout << "shared smart pointer size : " << sizeof(examplePtr_Shared) << std::endl;
	std::cout << "weak samrt pointer size : " << sizeof(examplePtr_Weak) << std::endl;

	free(examplePtr_c);
	delete(examplePtr_cpp);



	/// SMART POINTER SCOPE BASED LIFE CYCLE
	///
	/// when scope ends, smart pointer also gets deallocated
	std::cout << "--- smart pointers scope based life cycle ---" << std::endl;
	{
		std::shared_ptr<SmartPointersExampleSourceClass> examplePtr_scope = std::make_shared<SmartPointersExampleSourceClass>();
	}



	/// SHARED POINTER'S ADDITIONAL DATA
	std::cout << "--- shared pointer's additional managing data ---" << std::endl;
	std::cout << "shared pointer's reference count : " << examplePtr_Shared.use_count() << std::endl;



	/// WEAK POINTER's ADDITIONAL DATA
	///
	/// weak pointer points other shared pointer's pointing data
	/// weak point's pointing doesn't affect reference count
	/// pointing data can not be manipulated by weak pointer
	std::cout << "--- weak pointer's additional managing data ---" << std::endl;
	// prints pointing shared pointer's reference count
	std::cout << "weak pointer's reference count : " << examplePtr_Weak.use_count() << std::endl;

	/// to manipulate pointing data, weak pointer has to be converted to std::shared_ptr with lock() operation
	{
		std::shared_ptr<SmartPointersExampleSourceClass> lockedWeakPtr = examplePtr_Weak.lock();
		// affects pointing shared pointer's reference count
		std::cout << "weak pointer's reference count : " << examplePtr_Weak.use_count() << std::endl;
	}

	/// scope ended, locking operation expired
	std::cout << "weak pointer's reference count : " << examplePtr_Weak.use_count() << std::endl;
}
