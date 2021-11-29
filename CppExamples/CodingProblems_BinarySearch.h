#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


/// ���� �����̴� ���� ���� �θ���� ����ؼ� ���� ���� �ϱ�� �߽��ϴ�. ������ ������ ���� ����� ����
/// �ϴ�. �����̳� ������ ���� ��հԵ� ������ ���� ���̰� �������� �ʽ��ϴ�. ��ſ� �� ���� �ȿ� ��
/// �� ���� �� ���̴� ���ܱ�� �߶� �����ݴϴ�.
/// ���ܱ⿡ ����(H)�� �����ϸ� �������� ���� �� ���� �����մϴ�. ���̰� H���� �� ���� H ���� �κ��� �߸� ���̰�,
/// ���� ���� �߸��� �ʽ��ϴ�.
/// ���� ��� ���̰� 19, 14, 10, 17cm�� ���� ������ �հ� ���ܱ� ���̸� 15cm�� �����ϸ� �ڸ� �� ���� 
/// ���̴� 15, 14, 10, 15cm�� �� ���Դϴ�. ���� ���� ���̴� ���ʴ�� 4, 0, 0, 2cm�Դϴ�. �մ��� 6cm
/// ��ŭ�� ���̸� �������ϴ�.
/// �մ��� ���� �� ��û�� �� ���̰� M�� �� ��� M��ŭ�� ���� ��� ���� ���ܱ⿡ ������ �� �ִ� ������
/// �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
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

/// N���� ���Ҹ� �����ϰ� �ִ� ������ ������������ ���ĵǾ� �ֽ��ϴ�. �̶� �� �������� x�� �����ϴ� Ƚ
/// ���� ����ϼ���. ���� ��� ���� {1, 1, 2, 2, 2, 2, 3}�� ���� �� x = 2���, ���� �������� ���� 2��
/// ���Ұ� 4���̹Ƿ� 4�� ����մϴ�.
/// ��, �� ������ �ð� ���⵵ O(logN)���� �˰����� �������� ������ �ð� �ʰ� ������ �޽��ϴ�.
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