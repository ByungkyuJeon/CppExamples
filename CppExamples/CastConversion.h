#pragma once

class CastingParent
{
public:
	virtual void Print()
	{
		std::cout << "parent" << '\n';
	}
};

class CastingChild : public CastingParent
{
public:
	void Print() override
	{
		std::cout << "child" << '\n';
	}
};

class CastingChild_2 : public CastingParent
{
public:
	void Print() override
	{
		std::cout << "child 2" << '\n';
	}
};

void executeCastings()
{
	// static_cast
	// 
	// static_cast helps casting for checking several statements
	// may be more helpful preventing bugs than when using explicit and implicit casting
	// but still some casting errors might not be blocked 

	// 1. initializing casting
	{
		int numExample = static_cast<double>(3.2);
		std::vector<int> vecExample(5);
		std::cout << vecExample.size() << '\n';
		// explicit casting
		std::vector<int> vecExample_2 = (std::vector<int>)3.2;
		std::cout << vecExample_2.size() << '\n';
		// static_cast casting
		vecExample_2 = static_cast<std::vector<int>>(10);
		std::cout << vecExample_2.size() << '\n';
	}

	// 2. class up, down casting
	{
		CastingChild childExample{};
		childExample.Print();
		// 2.1 upcasting
		CastingParent& parentExample = static_cast<CastingParent&>(childExample);
		parentExample.Print();
		// 2.2 downcasting
		CastingChild& childExample_2 = static_cast<CastingChild&>(parentExample);
		childExample_2.Print();
	}

	// has to be careful list
	//
	// 1. void to any casting
	{
		int numExample = static_cast<double>(3.2);
		void* pVoid = static_cast<void*>(&numExample);
		double* pDouble = static_cast<double*>(pVoid);
		std::cout << pVoid << " " << pDouble << '\n';
	}
	// 2. explicit ptr casting
	{
		float* pFloat = new float(3.2f);
		int* pInt = (int*)pFloat;
		std::cout << *pInt << '\n';
		delete(pFloat);
	}
	// 3. Inheritance relation ptr casting
	//
	// addresses in relation of inheritance are treated as same type of pointers
	// static_cast doesn't check RTTI(Run Time Type Information) so problem occurs like bellow
	{
		CastingChild_2 child2Example;
		child2Example.Print();
		CastingParent& parentPtrExample = (CastingParent&)child2Example;
		parentPtrExample.Print();
		CastingChild* child1Example = static_cast<CastingChild*>(&parentPtrExample); // ptr casting error occur
		child1Example->Print();
	}

	// dynamic_cast
	//
	// dynamic_cast can be used for classes that has v-tables
	// checks RTTI(Run Time Type Information) so it's little slower than static_cast
	// but casting errors can be prevented while handling Inheritance relationship classes
	{
		CastingChild_2 child2Example;
		child2Example.Print();
		CastingParent& parentPtrExample = (CastingParent&)child2Example;
		parentPtrExample.Print();
		CastingChild* child1Example = dynamic_cast<CastingChild*>(&parentPtrExample); // ptr casting exception throwed

		if (child1Example != nullptr)
		{
			child1Example->Print();
		}
		else
		{
			std::cout << "can't not cast" << '\n';
		}
	}

	// const_cast
	//
	// const_cast offers manipulation ability to const keyword for pointers
	// if original variable is initialized using const keyword, there might be serious problem using const_cast
	{
		int noneConstNum = 30;

		const int* pValConst = &noneConstNum; // pointer's pointing value is const
		int* pConstCast = const_cast<int*>(pValConst); // cast to int*
		int* const pOtherValConst = const_cast<int* const>(pValConst); // cast to int* const
		std::cout << ++(*pConstCast) << " " << noneConstNum << '\n';

		int* const pPtrConst = &noneConstNum; // pointer value is const
		pConstCast = const_cast<int*>(pPtrConst); // cast to int*
		const int* pOtherPtrConst = const_cast<const int*>(pPtrConst); // cast to const int*
		std::cout << ++(*pConstCast) << " " << noneConstNum << '\n';

		// const_cast with const data
		// same address but different value
		// has to be careful
		const int num = 10;
		int* castNum = const_cast<int*>(&num); // no compiler error
		*castNum = 11;
		std::cout << " castNum : " << castNum << " origin Num : " << &num << '\n';
		std::cout << " castNum : " << *castNum << " origin Num : " <<  num << '\n';
	}

	// reinterpret_cast
	//
	// casts to other type if data size is same
	{
		int num = 2000;
		long* castNum = reinterpret_cast<long*>(&num);
		std::cout << num << " " << *castNum << '\n';
	}
}