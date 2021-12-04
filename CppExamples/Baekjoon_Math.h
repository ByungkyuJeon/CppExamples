#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include "TimeChecker.h"

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

/// ���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�. ����� �׵鿡�� ���� ������ �˷���� �Ѵ�.
/// ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.
/// ��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����,
///  �̾ N���� ������ �־�����.������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.
/// �� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.
void Baekjoon_Math_4344()
{
	int C, N, inputBuffer;
	double result, average;
	std::vector<int> scores;
	std::cin >> C;

	for (int outerCounter = C; outerCounter > 0; outerCounter--)
	{
		scores.clear();
		average = 0;
		result = 0;
		std::cin >> N;
		for (int innerCounter = N; innerCounter > 0; innerCounter--)
		{
			std::cin >> inputBuffer;
			scores.emplace_back(inputBuffer);
		}

		average = static_cast<double>(std::accumulate(scores.begin(), scores.end(), 0)) / static_cast<double>(scores.size());

		for (const auto& elem : scores)
		{
			if (elem > average)
			{
				result++;
			}
		}

		std::cout << std::fixed;
		std::cout.precision(3);
		std::cout << static_cast<double>(result) / static_cast<double>(scores.size()) * 100.0 << "%" << std::endl;
	}
}

/// ������� ���� ����� ������ ���� ���Ѵ�.����� ���ڸ� �дµ� ������ �ִ�.�̷��� ������ ���ϴ� ����� ���ؼ� ����̴� ���� ũ�⸦ ���ϴ� ������ ���־���.����̴� �� �ڸ� �� �� ���� ĥ�ǿ� ���־���.�� ������ ũ�Ⱑ ū ���� ���غ���� �ߴ�.
/// ����� ���� �ٸ� ����� �ٸ��� �Ųٷ� �д´�.���� ���, 734�� 893�� ĥ�ǿ� �����ٸ�, ����� �� ���� 437�� 398�� �д´�.����, ����� �� ���� ū ���� 437�� ū ����� ���� ���̴�.
/// �� ���� �־����� ��, ����� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
/// ù° �ٿ� ����̰� ĥ�ǿ� ���� �� �� A�� B�� �־�����. �� ���� ���� ���� �� �ڸ� ���̸�, 0�� ���ԵǾ� ���� �ʴ�.
void Beakjoon_Math_2908()
{
	int inputBuffer;
	std::string strBuffer;
	std::vector<int> nums;

	for (int counter = 0; counter < 2; counter++)
	{
		strBuffer.clear();
		std::cin >> inputBuffer;
		strBuffer.append(std::to_string(inputBuffer));
		std::swap(strBuffer[0], strBuffer[2]);
		nums.emplace_back(std::stoi(strBuffer));
	}
		
	std::cout << std::max(nums[0], nums[1]) << std::endl;
}

/// �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
/// 2~n/2 ����
void Baekjoon_Math_1978_Trial_1()
{
	int N, inputBuffer;
	int result = 0;
	std::vector<int> nums;

	std::cin >> N;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		nums.emplace_back(inputBuffer);
	}

	for (const auto& elem : nums)
	{
		if (elem > 1) { result++; }
		for (int checker = 2; checker <= elem / 2; checker++)
		{
			if (elem % checker == 0)
			{
				result--;
				break;
			}
		}
	}

	std::cout << result << std::endl;
}

/// �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
/// 2~sqrt(n) ����
void Baekjoon_Math_1978_Trial_2()
{
	int N, inputBuffer;
	std::vector<int> nums;
	int result = 0;

	std::cin >> N;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		nums.emplace_back(inputBuffer);
	}

	for (const auto& elem : nums)
	{
		if (elem > 1) { result++; }
		for (int checker = 2; checker <= static_cast<int>(sqrt(elem)); checker++)
		{
			if (elem % checker == 0)
			{
				result--;
				break;
			}
		}
	}

	std::cout << result << std::endl;
}

int Calculate_Baekjoon_2922_MaxRange(int num)
{
	if (num < 2) { return 1; }

	return 6 * (num - 1);
}

int Calculate_Baekjoon_2922_MinRange(std::unordered_map<int, int>& cache, int num)
{
	if (num < 1) { return -1; }
	else if (cache.find(num) != cache.end())
	{
		return cache[num];
	}

	cache.emplace(num, ((num - 2) * 6) + Calculate_Baekjoon_2922_MinRange(cache, num - 1));

	return cache[num];
}

/// ���� �׸��� ���� ���������� �̷���� ������ �ִ�. 
/// �׸����� ���� �ٿ� ���� �߾��� �� 1���� �����ؼ� �̿��ϴ� �濡 ���ư��鼭 1�� �����ϴ� ��ȣ�� �ּҷ� �ű� �� �ִ�. 
/// ���� N�� �־����� ��, ������ �߾� 1���� N�� ����� �ּ� ������ ���� ������ �� ��
/// �� ���� ���� ����������(���۰� ���� �����Ͽ�)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
/// ���� ���, 13������ 3��, 58������ 5���� ������.
void Baekjoon_Math_2292()
{
	std::unordered_map<int, int> cacheTable
	{
		{1, 1},
		{2, 2}
	};

	int N, minBuffer;
	std::cin >> N;

	double consumedTime = TimeChecker::CheckTime([&] {

		for (int counter = 1; counter < 20; counter++)
		{
			minBuffer = Calculate_Baekjoon_2922_MinRange(cacheTable, counter);
			if (minBuffer <= N && N < minBuffer + Calculate_Baekjoon_2922_MaxRange(counter))
			{
				std::cout << counter << std::endl;
				break;
			}
		}
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void Baekjoon_Math_2292_Tiral_2()
{
	int N;
	std::cin >> N;

	if (N == 1) { std::cout << 1 << std::endl; return 0; }

	int lowerNum = 2;
	int circleNum = 2;
	while (true)
	{
		if (lowerNum <= N && N < (lowerNum = lowerNum + (6 * (circleNum - 1))))
		{
			std::cout << circleNum << std::endl;
			break;
		}

		circleNum++;
	}
}