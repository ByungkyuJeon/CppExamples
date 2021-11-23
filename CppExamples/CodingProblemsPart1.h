#pragma once

#include <iostream>
#include <vector>
#include <array>
#include "TimeChecker.h"

/// ���� : ����� �������� ����� �����ִ� �����Դϴ�. ī���Ϳ��� �Ž��������� ����� 500��, 100��, 50��, 10��¥��
/// ������ ������ �����Ѵٰ� �����մϴ�. �մԿ��� �Ž��� �־�� �� ���� N���� �� �Ž��� �־�� �� ������ �ּ� ������ 
/// ���ϼ���. ��, �Ž��� ��� �� �� N�� �׻� 10�� ����Դϴ�.
/// 
/// Greedy
void Problem_1()
{
	int outChange;

	std::cin >> outChange;

	double consumedTime = TimeChecker::CheckTime([&] {
		int coinCount = 0;
		int change = outChange;

		std::array<int, 4> coins{ 500, 100, 50, 10 };

		for (const auto& elem : coins)
		{
			coinCount += change / elem;
			change %= elem;
		}

		std::cout << coinCount << std::endl;
	});

	std::cout << "Consumed Time : " << consumedTime << " ms" << std::endl;
}

/// ��� �� N�� 1�� �� ����� ������ �� ���� �� �ϳ��� �ݺ������� �����Ͽ� �����Ϸ��� �մϴ�. ��, �� ��° ������ 
/// N�� K�� ������ ������ ���� ������ �� �ֽ��ϴ�.
/// 1. N���� 1�� ���ϴ�.
/// 2. N�� K�� �����ϴ�.
/// N�� K�� �־��� �� N�� 1�� �� ������ 1�� Ȥ�� 2���� ������ �����ؾ� �ϴ� �ּ� Ƚ���� ���ϴ� ���α׷��� �ۼ��ϼ���. 
/// 
/// greeedy
void Problem_2_InEfficient()
{
	std::cout << "problem 2 inefficient" << std::endl;

	int outN, outK;

	std::cin >> outN >> outK;

	double consumedTime = TimeChecker::CheckTime([&] {

		int N = outN;
		int K = outK;
		int operationCount = 0;

		while (N != 1)
		{
			if (N % K == 0)
			{
				N /= K;
			}
			else
			{
				N--;
			}

			operationCount++;
		}

		std::cout << operationCount << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// shortening decrement steps
///
/// but multiple if syntax
void Problem_2_Efficient_Trial_1()
{
	std::cout << "problem 2 efficient" << std::endl;

	int outN, outK;

	std::cin >> outN >> outK;

	double consumedTime = TimeChecker::CheckTime([&] {

		int N = outN;
		int K = outK;
		int modOperationBuffer;
		int operationCount = 0;

		while (N != 1)
		{
			modOperationBuffer = N % K;

			if (modOperationBuffer == 0)
			{
				N /= K;
				operationCount++;
			}
			else
			{
				if ((N -= modOperationBuffer) == 0)
				{
					operationCount += modOperationBuffer - 1;
					break;
				}
				N /= K;

				operationCount += modOperationBuffer + 1;
			}
		}

		std::cout << operationCount << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// shortening decrement steps
///
/// only one if syntax
void Problem_2_Efficient()
{
	int outN, outK;
	std::cin >> outN >> outK;

	double consumedTime = TimeChecker::CheckTime([&] {
	
		int N = outN;
		int K = outK;
		int operationCount = 0;
		int modOperation;

		while (N != 1)
		{
			if ((N -= (modOperation = N % K)) == 0)
			{
				operationCount += modOperation - 1;
				break;
			}
			
			N /= K;
			operationCount += modOperation + 1;
		}
		
		std::cout << operationCount << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblemsPart1()
{
	/// Greedy Problems

	//Problem_1();
	Problem_2_InEfficient();
	Problem_2_Efficient();
}