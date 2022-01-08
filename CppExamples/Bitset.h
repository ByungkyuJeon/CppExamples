#pragma once

#include <iostream>
#include <bitset>

void executeBitset()
{
	std::bitset<10> bitsetExample{ 10100101101 };
	std::cout << bitsetExample << '\n'; // 비트 (2진수)
	std::cout << bitsetExample.to_ullong() << '\n'; // 10진수

	std::cout << bitsetExample.size() << '\n';
	std::cout << bitsetExample.any() << '\n';

	std::bitset<10> bitsetExample2{ 1001110001 };
	bitsetExample[0] = bitsetExample[0] && bitsetExample2[0];
	std::cout << bitsetExample[0] << '\n';

	bitsetExample = bitsetExample << 3;
	std::cout << bitsetExample << '\n';

	bitsetExample = bitsetExample >> 6;
	std::cout << bitsetExample << '\n';

	bitsetExample |= bitsetExample2;
	std::cout << bitsetExample << '\n';

	
}