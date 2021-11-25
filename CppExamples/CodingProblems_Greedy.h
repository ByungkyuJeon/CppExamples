#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "TimeChecker.h"

/// ���� 1 : ����� �������� ����� �����ִ� �����Դϴ�. ī���Ϳ��� �Ž��������� ����� 500��, 100��, 50��, 10��¥��
/// ������ ������ �����Ѵٰ� �����մϴ�. �մԿ��� �Ž��� �־�� �� ���� N���� �� �Ž��� �־�� �� ������ �ּ� ������ 
/// ���ϼ���. ��, �Ž��� ��� �� �� N�� �׻� 10�� ����Դϴ�.
/// 
/// Greedy
void GreedyProblem_1()
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

/// ���� 2 : ��� �� N�� 1�� �� ����� ������ �� ���� �� �ϳ��� �ݺ������� �����Ͽ� �����Ϸ��� �մϴ�. ��, �� ��° ������ 
/// N�� K�� ������ ������ ���� ������ �� �ֽ��ϴ�.
/// 1. N���� 1�� ���ϴ�.
/// 2. N�� K�� �����ϴ�.
/// N�� K�� �־��� �� N�� 1�� �� ������ 1�� Ȥ�� 2���� ������ �����ؾ� �ϴ� �ּ� Ƚ���� ���ϴ� ���α׷��� �ۼ��ϼ���. 
/// 
/// greeedy
void GreedyProblem_2_InEfficient()
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
void GreedyProblem_2_Efficient_Trial_1()
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
void GreedyProblem_2_Efficient()
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

/// ���� 3 : �� �ڸ��� ����(0���� 9)�θ� �̷���� ���ڿ� S�� �־����� ��, ���ʺ��� ���������� �ϳ��� ��� ���ڸ� 
/// Ȯ���ϸ� ���� ���̿� 'x' Ȥ�� '+' �����ڸ� �־� ��������� ������� �� �ִ� ���� ū ���� ���ϴ� ���α׷���
/// �ۼ��ϼ���. ��, +���� x�� ���� ����ϴ� �Ϲ����� ��İ��� �޸�, ��� ������ ���ʿ������� ������� �̷�����ٰ� �����մϴ�.
/// 
/// ���� ��� 02984��� ���ڿ��� ���� �� �ִ� ���� ū ���� ((((0 + 2) x 9) x 8) x 4) = 576�Դϴ�.
/// ���� ������� �� �ִ� ���� ū ���� �׻� 20�� ������ ������ �ǵ��� �Է��� �־����ϴ�.
void GreedyProblem_3_Trial_1()
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
void GreedyProblem_3_Final()
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

/// �� ������ ���谡�� N�� �ֽ��ϴ�. ���谡 ��忡���� N���� ���谡�� ������� '������'�� �����ߴµ�, 
/// �������� ���� ���谡�� ���� ������ ���� ���� ��Ȳ���� ����� ��ó�� �ɷ��� �������ϴ�.
/// ���谡 ������� ���谡 �׷��� �����ϰ� �����ϰ��� �������� X�� ���谡�� �ݵ�� X�� �̻����� ������ ���谡 �׷쿡 
/// �����ؾ� ������ ���� �� �ֵ��� �����߽��ϴ�.
/// ������� �ִ� ��� ���谡 �׷��� ���� �� �ִ��� �ñ��մϴ�. N���� ���谡�� ���� ������ �־�������,
/// ������ ���� �� �ִ� �׷� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
void GreedyProblem_4_Trial()
{
	size_t adventurerNumber;

	std::cin >> adventurerNumber;

	std::vector<int> adventurerFearNums;

	for (size_t num = adventurerNumber; num > 0; num--)
	{
		std::cin >> adventurerNumber;
		adventurerFearNums.emplace_back(adventurerNumber);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		int teamNumber = 0;

		std::sort(adventurerFearNums.begin(), adventurerFearNums.end());

		for (size_t outerIdx = 0; outerIdx < adventurerFearNums.size(); outerIdx++)
		{
			for (size_t innerIdx = outerIdx; innerIdx < adventurerFearNums.size(); innerIdx++)
			{
				if ((innerIdx - outerIdx + 1) >= adventurerFearNums[innerIdx])
				{
					teamNumber++;
					outerIdx = innerIdx + 1;
					break;
				}
			}
		}

		std::cout << teamNumber << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// deleted outer for iteration
void GreedyProblem_4_Final()
{
	size_t adventurerNum;
	std::cin >> adventurerNum;
	
	std::vector<int> adventurerFearNums;
	for(size_t inputCounter = adventurerNum; inputCounter > 0; inputCounter--)
	{
		std::cin >> adventurerNum;
		adventurerFearNums.emplace_back(adventurerNum);
	}

	double consumedTime = TimeChecker::CheckTime([&] {
		
		int teamCount = 0;
		size_t lookingIdx = 0;

		for (size_t idx = 0; idx < adventurerFearNums.size(); idx++)
		{
			if (idx - lookingIdx + 1 >= adventurerFearNums[idx])
			{
				teamCount++;
				lookingIdx = idx + 1;
				idx++;
			}
		}

		std::cout << teamCount << std::endl;
		
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblems_Greedy()
{
	/// Greedy Problems

	//GreedyProblem_1();
	
	//GreedyProblem_2_InEfficient();
	//GreedyProblem_2_Efficient_Trial_1()
	//GreedyProblem_2_Efficient();

	//GreedyProblem_3_Trial_1();
	//GreedyProblem_3_Final();

	//GreedyProblem_4_Trial();
	//GreedyProblem_4_Final();
}