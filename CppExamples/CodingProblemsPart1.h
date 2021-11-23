#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "TimeChecker.h"

/// 문제 1 : 당신은 음식점의 계산을 도와주는 점원입니다. 카운터에는 거스름돈으로 사용할 500원, 100원, 50원, 10원짜리
/// 동전이 무한히 존재한다고 가정합니다. 손님에게 거슬러 주어야 할 돈이 N원일 때 거슬러 주어야 할 동전의 최소 개수를 
/// 구하세요. 단, 거슬러 줘야 할 돈 N은 항상 10의 배수입니다.
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

/// 문제 2 : 어떠한 수 N이 1이 될 대까지 다음의 두 과정 중 하나를 반복적으로 선택하여 수행하려고 합니다. 단, 두 번째 연산은 
/// N이 K로 나누어 떨어질 때만 선택할 수 있습니다.
/// 1. N에서 1을 뺍니다.
/// 2. N을 K로 나눕니다.
/// N과 K가 주어질 때 N이 1이 될 때까지 1번 혹은 2번의 과정을 수행해야 하는 최소 횟수를 구하는 프로그램을 작성하세요. 
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

/// 문제 3 : 각 자리가 숫자(0부터 9)로만 이루어진 문자열 S가 주어졌을 때, 왼쪽부터 오른쪽으로 하나씩 모든 숫자를 
/// 확인하며 숫자 사이에 'x' 혹은 '+' 연산자를 넣어 결과적으로 만들어질 수 있는 가장 큰 수를 구하는 프로그램을
/// 작성하세요. 단, +보다 x를 먼저 계산하는 일반적인 방식과는 달리, 모든 연산은 왼쪽에서부터 순서대로 이루어진다고 가정합니다.
/// 
/// 예를 들어 02984라는 문자열로 만들 수 있는 가장 큰 수는 ((((0 + 2) x 9) x 8) x 4) = 576입니다.
/// 또한 만들어질 수 있는 가장 큰 수는 항상 20억 이하의 정수가 되도록 입력이 주어집니다.
void Problem_3_Trial_1()
{
	std::string outStr;

	std::cin >> outStr;

	double consumedTime = TimeChecker::CheckTime([&] {

		std::vector<int> nums;

		for (const auto& elem : outStr)
		{
			nums.emplace_back(elem - '0');
		}

		int result = nums[0];

		for (size_t idx = 1; idx < nums.size(); idx++)
		{
			if (result != 0 && nums[idx] != 0)
			{
				result *= nums[idx];
			}
			else
			{
				result += nums[idx];
			}
		}

		std::cout << result << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// remove making vector container
/// number 1 has to be considered also
void Problem_3_Final()
{
	std::string outStr;

	std::cin >> outStr;

	double consumedTime = TimeChecker::CheckTime([&] {
		
		int result = outStr[0] - '0';

		for (size_t idx = 1; idx < outStr.size(); idx++)
		{
			if (result > 1 && outStr[idx] > 1)
			{
				result *= outStr[idx] - '0';
			}
			else
			{
				result += outStr[idx] - '0';
			}
		}

		std::cout << result << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblemsPart1()
{
	/// Greedy Problems

	//Problem_1();
	
	//Problem_2_InEfficient();
	//Problem_2_Efficient_Trial_1()
	//Problem_2_Efficient();

	//Problem_3_Trial_1();
	//Problem_3_Final();
}