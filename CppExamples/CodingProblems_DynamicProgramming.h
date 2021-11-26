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

/// �Ǻ���ġ ���� N�� ° ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�
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

/// ���� ����� ������ �ķ��� ����ϰ��� �޶ѱ� ������ �ķ�â�� ���� �����Ϸ��� �մϴ�. �޶ѱ� ��������
/// ���� ���� �ķ�â�� �ִµ� �ķ�â��� ���������� �̾��� �ֽ��ϴ�.
/// �� �ķ�â���� ������ ���� �ķ��� �����ϰ� ������ ���� ����� �ķ�â�� ���������� ��Ż�Ͽ� �ķ��� 
/// ������ �����Դϴ�. �̶� �޶ѱ� ��â������ ������ �� �����ϴ� �ķ�â�� �߿��� ���� ������ �ķ� â��
/// ���ݹ����� �ٷ� �˾�ç �� �ֽ��ϴ�.
/// ���� ���� ���簡 ���������� ��Ű�� �ʰ� �ķ�â�� ��Ż�ϱ� ���ؼ��� �ּ��� �� ĭ �̻� ������ ��
/// ��â�� ��Ż�ؾ� �մϴ�.
/// ���� ���縦 ���� �ķ�â�� N���� ���� ������ �־����� �� ���� �� �ִ� �ķ��� �ִ��� ���ϴ� ���α׷��� 
/// �ۼ��ϼ���. 
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
} // TODO :: �����ʿ�


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


/// ���� X�� �־����� ��, ���� X�� ����� �� �ִ� ������ ������ ���� 4�����Դϴ�.
/// 1. X�� 5�� ������ ��������, 5�� �����ϴ�.
/// 2. X�� 3���� ������ ��������, 3���� �����ϴ�.
/// 3. X�� 2�� ������ ��������, 2�� �����ϴ�.
/// X���� 1�� ���ϴ�.
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


/// N���� ������ ȭ�� �ֽ��ϴ�. �� ȭ����� ������ �ּ������� �̿��ؼ� �� ��ġ�� ���� M���� �ǵ��� 
/// �Ϸ��� �մϴ�. �̶� �� ������ ȭ��� �� ���� ����� �� �ֽ��ϴ�.
/// ���� ��� 2��, 3�� ������ ȭ�� ���� ���� 15���� ����� ���� 3���� 5�� ����ϴ� ���� ���� �ּ����� 
/// ȭ�� �����Դϴ�.
/// M���� ����� ���� �ּ����� ȭ�� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
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