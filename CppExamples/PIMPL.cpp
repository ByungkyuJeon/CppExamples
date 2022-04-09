#include "PIMPL.h"

#include <iostream>

class PIMPLExampleClass::NestedClass
{
public:
	void Print();

private:
	int num = 5;
};

void PIMPLExampleClass::NestedClass::Print()
{
	std::cout << "PIMPLExampleClass::NestedClass::Print() called" << std::endl;
}

PIMPLExampleClass::PIMPLExampleClass()
	: mNestedClass{ new NestedClass() }
{
	std::cout << "constructed" << std::endl;
}

PIMPLExampleClass::~PIMPLExampleClass()
{
	if (mNestedClass != nullptr)
	{
		std::cout << "nested class deleted" << std::endl;

		delete(mNestedClass);
	}
}

void PIMPLExampleClass::Print()
{
	if (mNestedClass != nullptr)
	{
		mNestedClass->Print();
	}
}

void executePIMPLExample()
{
	PIMPLExampleClass exampleClass;

	exampleClass.Print();
}
