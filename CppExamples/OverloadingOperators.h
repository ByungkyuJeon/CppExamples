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

	const std::string& GetName() const
	{
		return mName;
	}

	float GetX() const
	{
		return mX;
	}

	float GetY() const
	{
		return mY;
	}

	float GetZ() const
	{
		return mZ;
	}

	/// COMPARISON OPERATORS
	///
	/// as a member function
	bool operator==(const OverloadingOperatorsExampleClass& other);
	bool operator!=(const OverloadingOperatorsExampleClass& other) { return true; } // not implemented
	bool operator<(const OverloadingOperatorsExampleClass& other);
	bool operator<=(const OverloadingOperatorsExampleClass& other) { return true; } // not implemented
	bool operator>(const OverloadingOperatorsExampleClass& other) { return true; } // not implemented
	bool operator>=(const OverloadingOperatorsExampleClass& other) { return true; } // not implemented

	/// ARITHMATIC OPERATORS
	///
	/// as a member function
	OverloadingOperatorsExampleClass operator+(const OverloadingOperatorsExampleClass& other) { return *this; } // not implemented
	OverloadingOperatorsExampleClass operator-(const OverloadingOperatorsExampleClass& other) { return *this; } // not implemented
	OverloadingOperatorsExampleClass operator*(const OverloadingOperatorsExampleClass& other) { return *this; } // not implemented
	OverloadingOperatorsExampleClass operator/(const OverloadingOperatorsExampleClass& other) { return *this; } // not implemented
	OverloadingOperatorsExampleClass operator%(const OverloadingOperatorsExampleClass& other) { return *this; } // not implemented

private:
	std::string mName;

	float mX;
	float mY;
	float mZ;
};

/// COMPARISON OPERATORS
///
/// as a non-member function
/*
bool operator==(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return true; } // not implemented
bool operator!=(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return true; } // not implemented
bool operator<(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return true; } // not implemented
bool operator<=(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return true; } // not implemented
bool operator>(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return true; } // not implemented
bool operator>=(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return true; } // not implemented
*/

/// ARITHMATIC OPERATORS
///
/// as a non-member function
OverloadingOperatorsExampleClass operator+(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs);
/*
OverloadingOperatorsExampleClass operator-(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return lhs; } // not implemented
OverloadingOperatorsExampleClass operator*(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return lhs; } // not implemented
OverloadingOperatorsExampleClass operator/(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return lhs; } // not implemented
OverloadingOperatorsExampleClass operator%(const OverloadingOperatorsExampleClass& lhs, const OverloadingOperatorsExampleClass& rhs) { return lhs; } // not implemented
*/

std::ostream& operator<<(std::ostream& stream, const OverloadingOperatorsExampleClass& exampleClass);

void main_OverloadingOperatorsExample();