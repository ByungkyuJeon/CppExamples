#pragma once
#include <string>

const int MinimumPasswordLength = 8;
void encrypt(std::string& password) {}
struct CustomType {};

// Proper Position of Definition Example
//
// when definitions of variables locates in place, there will be less code and more efficient
// 
// Wrong Example 1
std::string encryptPassword_Example1(const std::string& password)
{
	// unnecessary construction. defined too early
	// if exception is throwed bellow, this line does unnecessary destruction
	std::string encrypted;

	if (password.length() < MinimumPasswordLength)
	{
		throw "Password is too short";
	}

	// already constructed before. multiple construction
	encrypted = password;
	encrypt(encrypted);
	return encrypted;
}


// Wrong Example 2
std::string encryptPassword_Example2(const std::string& password)
{
	if (password.length() < MinimumPasswordLength)
	{
		throw "Password is too short";
	}

	// now definition position is right in place
	// no unnecessary destruction affected by exception
	std::string encrypted;

	// already constructed before. multiple construction
	encrypted = password;
	encrypt(encrypted);
	return encrypted;
}

// Right Example
std::string encryptPassword_Example3(const std::string& password)
{
	if (password.length() < MinimumPasswordLength)
	{
		throw "Password is too short";
	}

	// now definition position is right in place
	// no unnecessary destruction affected by exception
	// no multiple construction
	std::string encrypted(password);
	encrypt(encrypted);
	return encrypted;
}



// Proper position of variable definition in loop
void inLoopExample(int loopCount)
{
	// A
	CustomType customType;
	for (int count = 0; count < loopCount; count++)
	{
		//customType += i;
	}

	// B
	for (int count = 0; count < loopCount; count++)
	{
		CustomType customTypeInner;
	}

	// case A : construction 1, destruction 1, assignment n
	// case B : construction n, destruction n
	// 
	// A is more efficient if assignment is lighter than construction and destruction
	// B is more efficient if construction and destruction is lighter than assignment
}