#pragma once

#include<string>
#include<iostream>

/// EXAMPLE 1
///
/// 
class OverloadingOperatorsExampleClass
{
public:

	OverloadingOperatorsExampleClass() = default;
	OverloadingOperatorsExampleClass(std::string name, float x, float y, float z) : mName{ std::move(name) }, mX{ x }, mY{ y }, mZ{ z }{}
	OverloadingOperatorsExampleClass(float x, float y, float z) : mName{ "" }, mX{ x }, mY{ y }, mZ{ z }{}

	const std::string& GetName() const;

	float GetX() const;
	float GetY() const;
	float GetZ() const;

	bool operator==(const OverloadingOperatorsExampleClass& rhs);
	bool operator<(const OverloadingOperatorsExampleClass& rhs);

private:
	std::string mName;

	float mX;
	float mY;
	float mZ;
};

OverloadingOperatorsExampleClass operator+(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs);

std::ostream& operator<<(std::ostream& stream, const OverloadingOperatorsExampleClass& exampleClass);


void main_OverloadingOperatorsExample();