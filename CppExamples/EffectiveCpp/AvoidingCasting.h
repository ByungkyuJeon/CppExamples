#pragma once

// Avoiding casting
//
// cast conversion example is introduced in 'CastConversion.h'
//
// castings can cause various users' faults 
// try to hide cast conversion in fuction not to be visible
// try to minimize using cast conversion especially 'dynamic_cast'.
// those can cause lack of performance
// 
// do not use c style casting, prefer c++ style casting
// readability approves
// 
// avoiding cast conversion example 1
class AvoidCasting_Base
{
public:
	virtual void print()
	{
		std::cout << "base" << '\n';
	}
};

class AvoidCasting_Derived : public AvoidCasting_Base
{
public:
	virtual void print()
	{
		std::cout << "derived 1" << '\n';
	}
};

class AvoidCasting_Derived2 : public AvoidCasting_Base
{
public:
	virtual void print()
	{
		std::cout << "derived 2" << '\n';
	}
};

void executeAvoidingCasting()
{
	// wrong casting : implicit casting
	{
		AvoidCasting_Derived exampleDerived;
		AvoidCasting_Derived* pExampleDerived = &exampleDerived;
		AvoidCasting_Base* exampleBaseInst = &exampleDerived; // implicit casting
		AvoidCasting_Derived2* pExampleDerived2 = static_cast<AvoidCasting_Derived2*>(exampleBaseInst); // explicit casting
		pExampleDerived2->print(); // compiler doesn't check RTTI(Run Time Type Infomation) for static_cast or implicit cast
	}

	// avoiding solution 1
	{
		// operation using given example classes
		std::vector<std::shared_ptr<AvoidCasting_Base>> pInsts;
		for (int count = 0; count < 10; count++)
		{
			pInsts.emplace_back(std::make_shared<AvoidCasting_Derived>());
			pInsts.emplace_back(std::make_shared<AvoidCasting_Derived2>());
		}

		// don't use dynamic cast
		// call well designed virtual function
		for (const auto& elem : pInsts)
		{
			elem->print();
		}
	}
}