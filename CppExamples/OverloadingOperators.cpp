#pragma once

#include"OverloadingOperators.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

bool OverloadingOperatorsExampleClass::operator==(const OverloadingOperatorsExampleClass& other)
{
	return (mX == other.GetX()) && (mY == other.GetY()) && (mZ == other.GetZ());
}

bool OverloadingOperatorsExampleClass::operator<(const OverloadingOperatorsExampleClass& other)
{
	return (sqrtf(exp2f(mX) + exp2f(mY) + exp2f(mZ))) < (sqrtf(exp2f(other.GetX()) + exp2f(other.GetY()) + exp2f(other.GetZ())));
}

OverloadingOperatorsExampleClass operator+(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs)
{
	OverloadingOperatorsExampleClass result = OverloadingOperatorsExampleClass{ lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY(), lhs.GetZ() + rhs.GetZ() };
	return result;
}

std::ostream& operator<<(std::ostream& stream, const OverloadingOperatorsExampleClass& exampleClass)
{
	return stream << exampleClass.GetName() << " " 
		<< exampleClass.GetX() << " " 
		<< exampleClass.GetY() << " "
		<< exampleClass.GetZ() << std::endl;
}

void main_OverloadingOperatorsExample()
{
	std::vector<OverloadingOperatorsExampleClass> exampleClass
	{
		{"example 1 : ", 1, 2, 3},
		{"example 2 : ", 2, 3, 4},
		{"example 3 : ", 9, -1, -4},
		{"example 4 : ", 0, 2, 2}
	};

	for (auto exClass : exampleClass)
	{
		std::cout << exClass;
	}

	std::sort(exampleClass.begin(), exampleClass.end());

	for (auto exClass : exampleClass)
	{
		std::cout << exClass;
	}
}