#pragma once

#include "TimeChecker.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

/// �����̴� �� ���� �迭 A�� B�� ������ �ֽ��ϴ�. �� �迭�� N���� ���ҷ� �����Ǿ� ������, �迭�� ����
/// �� ��� �ڿ����Դϴ�.
/// �����̴� �ִ� K ���� �ٲ�ġ�� ������ ������ �� �ִµ�, �ٲ�ġ�� �����̶� �迭 A�� �̾��� ���� �ϳ��� 
/// �迭 B�� �ִ� ���� �ϳ��� ��� �� ���Ҹ� ���� �ٲٴ� ���� ���մϴ�.
/// �������� ���� ��ǥ�� �迭 A�� ��� ������ ���� �ִ밡 �ǵ��� �ϴ� ���̸�, �������� �����̸� ���;� 
/// �մϴ�.
/// N, K, �׸��� �迭 A�� B�� ������ �־����� ��, �ִ� K ���� �ٲ�ġ�� ������ �����Ͽ� ���� �� �̾��� ��
/// �� A�� ��� ������ ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
void Sort_Problem_1_Approach_1()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> A, B;
	int inputBuffer;

	for (size_t counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		A.emplace_back(inputBuffer);
	}

	for (size_t counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		B.emplace_back(inputBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		size_t idxBuffer_A, idxBuffer_B;

		for (int swapCounter = K; swapCounter > 0; swapCounter--)
		{
			idxBuffer_A = std::min_element(A.begin(), A.end()) - A.begin();
			idxBuffer_B = std::max_element(B.begin(), B.end()) - B.begin();

			std::swap(A[idxBuffer_A], B[idxBuffer_B]);
		}

		std::cout << std::accumulate(A.begin(), A.end(), 0) << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// �����̴� �� ���� �迭 A�� B�� ������ �ֽ��ϴ�. �� �迭�� N���� ���ҷ� �����Ǿ� ������, �迭�� ����
/// �� ��� �ڿ����Դϴ�.
/// �����̴� �ִ� K ���� �ٲ�ġ�� ������ ������ �� �ִµ�, �ٲ�ġ�� �����̶� �迭 A�� �̾��� ���� �ϳ��� 
/// �迭 B�� �ִ� ���� �ϳ��� ��� �� ���Ҹ� ���� �ٲٴ� ���� ���մϴ�.
/// �������� ���� ��ǥ�� �迭 A�� ��� ������ ���� �ִ밡 �ǵ��� �ϴ� ���̸�, �������� �����̸� ���;� 
/// �մϴ�.
/// N, K, �׸��� �迭 A�� B�� ������ �־����� ��, �ִ� K ���� �ٲ�ġ�� ������ �����Ͽ� ���� �� �̾��� ��
/// �� A�� ��� ������ ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
void Sort_Problem_1_Approach_2()
{
	int N, K;
	std::cin >> N >> K;

	int inputBuffer;
	std::vector<int> A, B;
	for (int elemCounter = N; elemCounter > 0; elemCounter--)
	{
		std::cin >> inputBuffer;
		A.emplace_back(inputBuffer);
	}
	for (int elemCounter = N; elemCounter > 0; elemCounter--)
	{
		std::cin >> inputBuffer;
		B.emplace_back(inputBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		for (int swapCounter = K; swapCounter > 0; swapCounter--)
		{
			std::sort(A.begin(), A.end());
			std::sort(B.begin(), B.end());
			std::swap(*(A.begin()), *(B.end() - 1));
		}

		std::cout << std::accumulate(A.begin(), A.end(), 0) << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblems_Sort()
{
	//Sort_Problem_1_Approach_1();
	//Sort_Problem_1_Approach_2();
}