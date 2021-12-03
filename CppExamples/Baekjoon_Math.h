#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

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

/// 대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.
/// 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
/// 둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고,
///  이어서 N명의 점수가 주어진다.점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
/// 각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
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

/// 상근이의 동생 상수는 수학을 정말 못한다.상수는 숫자를 읽는데 문제가 있다.이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다.상근이는 세 자리 수 두 개를 칠판에 써주었다.그 다음에 크기가 큰 수를 말해보라고 했다.
/// 상수는 수를 다른 사람과 다르게 거꾸로 읽는다.예를 들어, 734와 893을 칠판에 적었다면, 상수는 이 수를 437과 398로 읽는다.따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.
/// 두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.
/// 첫째 줄에 상근이가 칠판에 적은 두 수 A와 B가 주어진다. 두 수는 같지 않은 세 자리 수이며, 0이 포함되어 있지 않다.
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

