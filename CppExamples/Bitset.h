#pragma once

#include <iostream>
#include <bitset>

// 비트 뺄셈
//
// STL bitset 에서 기본적으로 지원하지 않음
std::bitset<10> substract(std::bitset<10> lhs, std::bitset<10> rhs)
{
	std::bitset<10> borrow;

	while (rhs.any())
	{
		borrow = ~lhs & rhs;
		lhs = lhs ^ rhs;
		rhs = borrow << 1;
	}

	return lhs;
}

// 비트 덧셈
//
// STL bitset 에서 기본적으로 지원하지 않음
std::bitset<10> add(const std::bitset<10>& lhs, const std::bitset<10>& rhs)
{
	std::bitset<10> rhsTemp = rhs;
	std::bitset<10> carry;
	std::bitset<10> result = lhs;;

	while (rhsTemp.any())
	{
		carry = lhs & rhsTemp;
		result = result ^ rhsTemp;
		rhsTemp = carry << 1;
	}

	return result;
}

void executeBitset()
{
	{
		// aligned backward
		//
		// index 0 : 2^0
		// index 1 : 2^1
		// ...
		// index n : 2^(n-1)
		std::bitset<10> bitsetExample{ 50 };
		std::cout << bitsetExample << '\n'; // 비트 (2진수)
		std::cout << bitsetExample.to_ullong() << '\n'; // 10진수

		std::cout << bitsetExample.size() << '\n';
		std::cout << bitsetExample.any() << '\n';

		std::bitset<10> bitsetExample2{ 30 };
		bitsetExample[0] = bitsetExample[0] && bitsetExample2[0];
		std::cout << bitsetExample[0] << '\n';

		// bit-shift left
		std::cout << "bit-shift left" << '\n';
		std::cout << bitsetExample << '\n';
		std::cout << (bitsetExample << 3) << '\n';
		std::cout << bitsetExample << '\n';

		// bit-shift right
		bitsetExample = bitsetExample >> 6;
		std::cout << bitsetExample << '\n';

		// bit-or
		bitsetExample |= bitsetExample2;
		std::cout << bitsetExample << '\n';
	}

	// bit-substraction
	std::cout << "bit substraction" << '\n';
	{
		std::bitset<10> bitsetExample{ 50 };
		std::cout << bitsetExample << '\n';
		std::bitset<10> bitsetExample2{ 17 };
		std::cout << bitsetExample2 << '\n';
		std::cout << substract(bitsetExample, bitsetExample2) << '\n';
		std::cout << substract(bitsetExample, bitsetExample2).to_ulong() << '\n';
	}

	// bit-add operation
	std::cout << "bit add" << '\n';
	{
		std::bitset<10> bitsetExample{ 50 };
		std::cout << bitsetExample << '\n';
		std::bitset<10> bitsetExample2{ 18 };
		std::cout << bitsetExample2 << '\n';
		std::cout << add(bitsetExample, bitsetExample2) << '\n';
		std::cout << add(bitsetExample, bitsetExample2).to_ulong() << '\n';
	}
}