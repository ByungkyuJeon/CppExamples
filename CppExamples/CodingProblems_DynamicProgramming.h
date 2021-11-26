#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int Fibonacci(std::map<size_t, size_t>& inCache, int inNum)
{
	if (inCache.find(inNum) != inCache.end())
	{
		return (*inCache.find(inNum)).second;
	}

	inCache.emplace(inNum, Fibonacci(inCache, inNum - 1) + Fibonacci(inCache, inNum - 2));

	return (*inCache.find(inNum)).second;
}

/// 피보나치 수열 N번 째 항을 구하는 프로그램을 작성하시오
void DynamicProgramming_Problem_1()
{
	int N;
	std::cin >> N;

	std::map<size_t, size_t> storedCache;
	storedCache.emplace(1, 1);
	storedCache.emplace(2, 1);

	double consumedTime = TimeChecker::CheckTime([&] {

		std::cout << Fibonacci(storedCache, N) << std::endl;

	});

	std::cout << "first consumed time : " << consumedTime << " ms" << std::endl;

	consumedTime = TimeChecker::CheckTime([&] {

		std::cout << Fibonacci(storedCache, N) << std::endl;

		});

	std::cout << "second consumed time : " << consumedTime << " ms" << std::endl;
}

/// 개미 전사는 부족한 식량을 충당하고자 메뚜기 마을의 식량창고를 몰래 공격하려고 합니다. 메뚜기 마을에는
/// 여러 개의 식량창고가 있는데 식량창고는 일직선으로 이어져 있습니다.
/// 각 식량창고에는 정해진 수의 식량을 저장하고 있으며 개미 전사는 식량창고를 선택적으로 약탈하여 식량을 
/// 빼앗을 예정입니다. 이때 메뚜기 정창병들은 일직선 상에 존재하는 식량창고 중에서 서로 인접한 식량 창고가
/// 공격받으면 바로 알아챌 수 있습니다.
/// 따라서 개미 전사가 정찰병에게 들키지 않고 식량창고를 약탈하기 위해서는 최소한 한 칸 이상 떨어진 식
/// 량창고를 약탈해야 합니다.
/// 개미 전사를 위해 식량창고 N개에 대한 정보가 주어졌을 때 얻을 수 있는 식량의 최댓값을 구하는 프로그램을 
/// 작성하세요. 
void DynamicProgramming_Problem_2()
{
	int N;
	std::cin >> N;

	std::vector<int> foods;
	int inputBuffer;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		foods.emplace_back(inputBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		int currentIdx = 0;
		int result = 0;

		while(currentIdx < foods.size())
		{
			if (currentIdx == foods.size() - 1) 
			{
				result += foods[currentIdx];
				break;
			}

			if (foods[currentIdx] >= foods[currentIdx + 1])
			{
				result += foods[currentIdx];
				currentIdx += 2;
				continue;
			}

			currentIdx++;
		}

		std::cout << result << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
} // TODO :: 수정필요


int Dynamic_3(std::map<int, int>& inCache, int inNum, int inCount)
{
	if (inCache.find(inNum) != inCache.end())
	{
		return (*inCache.find(inNum)).second;
	}

	std::vector<int> possibles;
	possibles.emplace_back(Dynamic_3(inCache, inNum - 1, inCount));
	if (inNum % 5 == 0) { possibles.emplace_back(Dynamic_3(inCache, inNum / 5, inCount)); }
	if (inNum % 3 == 0) { possibles.emplace_back(Dynamic_3(inCache, inNum / 3, inCount)); }
	if (inNum % 2 == 0) { possibles.emplace_back(Dynamic_3(inCache, inNum / 2, inCount)); }

	return (*std::min_element(possibles.begin(), possibles.end())) + 1;
}


/// 정수 X가 주어졌을 때, 정수 X에 사용할 수 있는 연산은 다음과 같이 4가지입니다.
/// 1. X가 5로 나누어 떨어지면, 5로 나눕니다.
/// 2. X가 3으로 나누어 떨어지면, 3으로 나눕니다.
/// 3. X가 2로 나누어 떨어지면, 2로 나눕니다.
/// X에서 1을 뺍니다.
void DynamicProgramming_Problem_3()
{
	int N;
	std::cin >> N;

	double consumedTime = TimeChecker::CheckTime([&] {

		std::map<int, int> cache
		{
			{1, 0},
			{2, 1},
			{3, 1},
			{4, 2}
		};

		std::cout << Dynamic_3(cache, N, 0) << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}


int Dynamic_4(std::map<int, int>& inCache, const std::vector<int>& inBills, int inNum, int inCount)
{
	if (inNum < 0) { return -1; }
	else if (inNum == 0) { return inCount; }
	if (inCache.find(inNum) != inCache.end())
	{
		return (*(inCache.find(inNum))).second;
	}

	std::vector<int> minBuffer;
	int resultBuffer;
	for (const auto& elem : inBills)
	{
		resultBuffer = Dynamic_4(inCache, inBills, inNum - elem, inCount + 1);
		if (resultBuffer == -1)
		{
			continue;
		}
		minBuffer.emplace_back(resultBuffer);
	}

	if (minBuffer.size() == 0) { return -1; }
	const auto& itr = std::min_element(minBuffer.begin(), minBuffer.end());

	inCache.emplace(itr - minBuffer.begin(), *itr);

	return *itr;
}


/// N가지 종류의 화폐가 있습니다. 이 화폐들의 개수를 최소한으로 이용해서 그 가치의 합이 M원이 되도록 
/// 하려고 합니다. 이때 각 종류의 화폐는 몇 개라도 사용할 수 있습니다.
/// 예를 들어 2원, 3원 단위의 화폐가 있을 때는 15원을 만들기 위해 3원을 5개 사용하는 것이 가장 최소한의 
/// 화폐 개수입니다.
/// M원을 만들기 위한 최소한의 화폐 개수를 출력하는 프로그램을 작성하세요.
void DynamicProgramming_Problem_4()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> bills;
	int inputBuffer;
	for (int counter = N; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		bills.emplace_back(inputBuffer);
	}

	double consumedTime = TimeChecker::CheckTime([&] {
		
		std::map<int, int> cache;

		std::cout << Dynamic_4(cache, bills, M, 0) << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

int Dynamic_5(std::map<int, std::map<int, int>>& inCache, const std::vector<std::vector<int>>& inTable, int inColumn, int inRow)
{
	if (inColumn >= inTable.size() || inColumn < 0 || inRow >= inTable[0].size() || inRow < 0) { return -1; }

	if (inCache.find(inColumn) != inCache.end()
		&& inCache[inColumn].find(inRow) != inCache[inColumn].end())
	{
		return inCache[inColumn][inRow];
	}

	std::vector<int> maxBuffer;
	int checkBuffer;
	for (int offset = -1; offset <= 1; offset++)
	{
		if ((checkBuffer = Dynamic_5(inCache, inTable, inColumn - 1, inRow + offset)) != -1)
		{
			maxBuffer.emplace_back(checkBuffer);
		}
	}

	if (maxBuffer.size() == 0) { return -1; }
	
	(*(inCache.emplace(inColumn, std::map<int, int>()).first)).second.emplace(inRow, (*std::max_element(maxBuffer.begin(), maxBuffer.end())) + inTable[inColumn][inRow]);
	return (*std::max_element(maxBuffer.begin(), maxBuffer.end())) + inTable[inColumn][inRow];

}

void DynamicProgramming_Problem_5()
{
	int T, N, M;
	std::vector<std::vector<int>> table;
	std::map<int, std::map<int, int>> cache;
	int inputBuffer;
	
	std::cin >> T;

	while (T > 0)
	{
		std::cin >> N >> M;
		table.clear();
		cache.clear();
		for (int outerCounter = N; outerCounter > 0; outerCounter--)
		{
			table.emplace_back(std::vector<int>());
			for (int innerCounter = M; innerCounter > 0; innerCounter--)
			{
				std::cin >> inputBuffer;
				table[N - outerCounter].emplace_back(inputBuffer);
				if (outerCounter == N)
				{
					(*(cache.emplace(N - outerCounter, std::map<int, int>()).first)).second.emplace(M - innerCounter, inputBuffer);
				}
			}
		}

		std::vector<int> maxBuffer;
		for (int idx = 0; idx < M; idx++)
		{
			if ((inputBuffer = Dynamic_5(cache, table, N - 1, M - idx - 1)) == -1)
			{
				continue;
			}

			maxBuffer.emplace_back(inputBuffer);
		}

		std::cout << *std::max_element(maxBuffer.begin(), maxBuffer.end()) << std::endl;
		T--;
	}
}

void main_CodingProblems_DynamicProgramming()
{
	//DynamicProgramming_Problem_1();

	//DynamicProgramming_Problem_2();

	//DynamicProgramming_Problem_3();

	//DynamicProgramming_Problem_4();

	DynamicProgramming_Problem_5();
}