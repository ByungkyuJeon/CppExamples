#pragma once

#include <iostream>

/// n�� �־����� ��, 1���� n���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

/// �������� �ƴ��� �Ǵ�
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