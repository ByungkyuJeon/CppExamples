#pragma once

#include <iostream>

/// n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
void Baekjoon_Math_8393()
{
	int N, result = 0;
	std::cin >> N;

	for(int counter = N; counter > 0; counter--)
	{
		result += counter;
	}

	std::cout << result << std::endl;
}

/// 윤년인지 아닌지 판단
void Baekjoon_Math_2753()
{
	int N;
	bool result = false;
	std::cin >> N;

	if (N % 4 == 0 && (N % 400 == 0 || N % 100 != 0))
	{
		result = true;
	}

	std::cout << static_cast<int>(result) << std::endl;
}