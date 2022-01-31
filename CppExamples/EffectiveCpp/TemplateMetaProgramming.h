#pragma once
#include <iostream>

template<int num>
struct Factorial
{
public:
	static const int value = num * Factorial<num - 1>::value;
};

template<>
struct Factorial<1>
{
	static const int value = 1;
};

void executeTemplateMetaProgramming()
{
	Factorial<3> exampleTMP;
	std::cout << exampleTMP.value << std::endl;
}