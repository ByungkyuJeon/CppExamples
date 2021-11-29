#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


/// 오늘 동빈이는 여행 가신 부모님을 대신해서 떡집 일을 하기로 했습니다. 오늘은 떢볶이 떡을 만드는 날입
/// 니다. 동빈이네 떡볶이 떡은 재밌게도 떡볶이 떡의 길이가 일정하지 않습니다. 대신에 한 봉지 안에 들어가
/// 는 떡의 총 길이는 절단기로 잘라서 맞춰줍니다.
/// 절단기에 높이(H)를 지정하면 줄지어진 떡을 한 번에 절단합니다. 높이가 H보다 긴 떡은 H 위의 부분이 잘릴 것이고,
/// 낮은 떡은 잘리지 않습니다.
/// 예를 들어 높이가 19, 14, 10, 17cm인 떡이 나란히 잇고 절단기 높이를 15cm로 지정하면 자른 뒤 떡의 
/// 높이는 15, 14, 10, 15cm가 될 덧입니다. 잘인 떡의 길이는 차례대로 4, 0, 0, 2cm입니다. 손님은 6cm
/// 만큼의 길이를 가져갑니다.
/// 손님이 왔을 때 요청한 총 길이가 M일 때 적어도 M만큼의 떡을 얻기 위해 절단기에 설정할 수 있는 높이의
/// 최댓값을 구하는 프로그램을 작성하세요.
void BinarySearch_Problem_1_Solution_1()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> riceCakes;
	int numBuffer;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> numBuffer;
		riceCakes.emplace_back(numBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		int maxLength = *(std::max_element(riceCakes.begin(), riceCakes.end()));
		int result = 0;

		for (int possibleLength = maxLength - 1; possibleLength > 0; possibleLength--)
		{
			result = 0;
			for (int idx = 0; idx < riceCakes.size(); idx++)
			{
				if (riceCakes[idx] > possibleLength)
				{
					result += (riceCakes[idx] - possibleLength);
				}
			}
			if (result >= M)
			{
				result = possibleLength;
				break;
			}
		}

		std::cout << result << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

int BinarySearch_1(const std::vector<int>& arr, int inFront, int inBack, int inM)
{
	if (abs(inBack - inFront) <= 1)
	{
		return inFront;
	}

	int result = 0;

	for (const auto& elem : arr)
	{
		if (elem > inFront + ((inBack - inFront) / 2))
		{
			result += elem - (inFront + ((inBack - inFront) / 2));
		}
	}

	if(result >= inM)
	{
		return BinarySearch_1(arr, inFront + ((inBack - inFront) / 2), inBack, inM);
	}
	else if(result < inM)
	{
		return BinarySearch_1(arr, inFront, inFront + ((inBack - inFront) / 2), inM);
	}

	return -1;
}

void BinarySearch_Problem_1_Solution_2()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> riceCakes;
	int inputBuffer;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		riceCakes.emplace_back(inputBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		int result;

		if ((result = BinarySearch_1(riceCakes, 0, 1000000000, M)) == -1)
		{
			std::cout << "no possible item exists" << std::endl;
		}
		else
		{
			std::cout << result << std::endl;
		}

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

int BinarySearch_2(const std::vector<int>& arr, int inFront, int inBack, int inX)
{
	if (abs(inBack - inFront) <= 1)
	{
		if (arr[inFront] == inX) { return inFront; }
		else if (arr[inBack] == inX) { return inBack; }

		return -1;
	}

	if (arr[inFront + ((inBack - inFront) / 2)] >= inX)
	{
		return BinarySearch_2(arr, inFront, inFront + ((inBack - inFront) / 2), inX);
	}
	else
	{
		return BinarySearch_2(arr, inFront + ((inBack - inFront) / 2), inBack, inX);
	}
}

/// N개의 원소를 포함하고 있는 수열이 오름차순으로 정렬되어 있습니다. 이때 이 수열에서 x가 등장하는 횟
/// 수를 계산하세요. 예를 들어 수열 {1, 1, 2, 2, 2, 2, 3}이 있을 때 x = 2라면, 현재 수열에서 값이 2인
/// 원소가 4개이므로 4를 출력합니다.
/// 단, 이 문제는 시간 복잡도 O(logN)으로 알고리즘을 설계하지 않으면 시간 초과 판정을 받습니다.
void BinarySearch_Problem_2()
{
	int N, x;
	std::cin >> N >> x;

	std::vector<int> numbers;
	numbers.reserve(N);
	int inputBuffer;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		numbers.emplace_back(inputBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		int startIdx = BinarySearch_2(numbers, 0, N, x);
		int result = 0;

		if (startIdx == -1)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			for (int idx = startIdx; ; idx++)
			{
				if (numbers[idx] != x)
				{
					std::cout << result << std::endl;
					break;
				}

				result++;
			}
		}
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblems_BinarySearch()
{
	//BinarySearch_Problem_1_Solution_1();
	//BinarySearch_Problem_1_Solution_2();

	//BinarySearch_Problem_2();
}