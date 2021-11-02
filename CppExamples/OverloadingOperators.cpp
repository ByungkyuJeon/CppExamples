#pragma once

#include"OverloadingOperators.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

const std::string& OverloadingOperatorsExampleClass::GetName() const
{
	return mName;
}

float OverloadingOperatorsExampleClass::GetX() const
{
	return mX;
}

float OverloadingOperatorsExampleClass::GetY() const
{
	return mY;
}

float OverloadingOperatorsExampleClass::GetZ() const
{
	return mZ;
}

bool OverloadingOperatorsExampleClass::operator==(const OverloadingOperatorsExampleClass& rhs)
{
	return (mX == rhs.GetX()) && (mY == rhs.GetY()) && (mZ == GetZ());
}

bool OverloadingOperatorsExampleClass::operator<(const OverloadingOperatorsExampleClass& rhs)
{
	return (sqrtf(exp2f(mX) + exp2f(mY) + exp2f(mZ))) < (sqrtf(exp2f(rhs.GetX()) + exp2f(rhs.GetY()) + exp2f(rhs.GetZ())));
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
		{"example 1", 1, 2, 3},
		{"example 2", 2, 3, 4},
		{"example 3", 9, -1, -4},
		{"example 4", 0, 2, 2}
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