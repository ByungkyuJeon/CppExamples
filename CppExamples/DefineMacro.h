#pragma once

// #define
//
// is just changing code where it is used

#define ADD_NO_BRACKET(x, y) x + y
#define ADD(x, y) (x + y)

#define EXP(x) (x * x)

void executeDefineMacroExample()
{
	// 1. missing bracket problem
	std::cout << ADD_NO_BRACKET(3, 5) << '\n'; // works fine
	std::cout << ADD_NO_BRACKET(3, 5) * 2 << '\n'; // backet problem occur
	std::cout << ADD(3, 5) * 2 << '\n'; // works properly

	// 2. increment, decrement problem
	int a = 4;
	std::cout << EXP(a++) << '\n';

	// 3. debugging problem
	// defined macro doesn't go up to symbol table
}