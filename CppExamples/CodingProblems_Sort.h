#pragma once

#include "TimeChecker.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

/// 동빈이는 두 개의 배열 A와 B를 가지고 있습니다. 두 배열은 N개의 원소로 구성되어 있으며, 배열의 원소
/// 는 모두 자연수입니다.
/// 동빈이는 최대 K 번의 바꿔치기 연산을 수행할 수 있는데, 바꿔치기 연산이란 배열 A에 이쓴ㄴ 원소 하나와 
/// 배열 B에 있는 원소 하나를 골라서 두 원소를 서로 바꾸는 것을 말합니다.
/// 동빈이의 최종 목표는 배열 A의 모든 원소의 합이 최대가 되도록 하는 것이며, 여러분은 동빈이를 도와야 
/// 합니다.
/// N, K, 그리고 배열 A와 B의 정보가 주어졌을 때, 최대 K 번의 바꿔치기 연산을 수행하여 만들 수 이쓴ㄴ 배
/// 열 A의 모든 원소의 합의 최댓값을 출력하는 프로그램을 작성하세요.
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

/// 동빈이는 두 개의 배열 A와 B를 가지고 있습니다. 두 배열은 N개의 원소로 구성되어 있으며, 배열의 원소
/// 는 모두 자연수입니다.
/// 동빈이는 최대 K 번의 바꿔치기 연산을 수행할 수 있는데, 바꿔치기 연산이란 배열 A에 이쓴ㄴ 원소 하나와 
/// 배열 B에 있는 원소 하나를 골라서 두 원소를 서로 바꾸는 것을 말합니다.
/// 동빈이의 최종 목표는 배열 A의 모든 원소의 합이 최대가 되도록 하는 것이며, 여러분은 동빈이를 도와야 
/// 합니다.
/// N, K, 그리고 배열 A와 B의 정보가 주어졌을 때, 최대 K 번의 바꿔치기 연산을 수행하여 만들 수 이쓴ㄴ 배
/// 열 A의 모든 원소의 합의 최댓값을 출력하는 프로그램을 작성하세요.
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