#pragma once


#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>


int Euclidean(int inA, int inB)
{
	if (inB == 0)
	{
		return inA;
	}

	return Euclidean(inB, inA % inB);
}

/// 유클리드 호제법을 통한 최대공약수를 구하는 프로그램을 작성하시오
void DFSBFS_Problem_1()
{
	int A, B;
	std::cin >> A >> B;

	double consumedTime = TimeChecker::CheckTime([&] {

		std::cout << Euclidean(A, B) << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void DFS(std::vector<std::vector<int>>& inGraph, int inIdx, std::vector<bool>& inVisited)
{
	inVisited[inIdx] = true;
	std::cout << inIdx << " ";

	for (const auto& elem : inGraph[inIdx])
	{
		if (!inVisited[elem])
		{
			DFS(inGraph, elem, inVisited);
		}
	}
}

void BFS(std::vector<std::vector<int>>& inGraph, int inIdx, std::vector<bool>& inVisited)
{
	std::queue<int> bfsQueue;
	bfsQueue.push(inIdx);
	inVisited[bfsQueue.front()] = true;

	while (bfsQueue.size() > 0)
	{
		std::cout << bfsQueue.front() << " ";
		for (const auto& elem : inGraph[bfsQueue.front()])
		{
			if (!inVisited[elem])
			{
				bfsQueue.push(elem);
				inVisited[elem] = true;
			}
		}
		bfsQueue.pop();
	}
}

/// 그래프 하나를 만들어 DFS, BFS 하시오
void DFSBFS_Problem_2()
{
	double consumedTime_DFS = TimeChecker::CheckTime([] {

		std::vector<std::vector<int>> graph{
		{},
		{2, 3, 8},
		{1, 7},
		{1, 4, 5},
		{3, 5},
		{3, 4},
		{7},
		{2, 6, 8},
		{1, 7}
		};

		std::vector<bool> visited;
		for (int counter = graph.size(); counter > 0; counter--)
		{
			visited.emplace_back(false);
		}

		DFS(graph, 1, visited);

		std::cout << std::endl;
	});

	std::cout << "consumed time : " << consumedTime_DFS << " ms" << std::endl;

	double consumedTime_BFS = TimeChecker::CheckTime([] {

		std::vector<std::vector<int>> graph{
		{},
		{2, 3, 8},
		{1, 7},
		{1, 4, 5},
		{3, 5},
		{3, 4},
		{7},
		{2, 6, 8},
		{1, 7}
		};

		std::vector<bool> visited;
		for (int counter = graph.size(); counter > 0; counter--)
		{
			visited.emplace_back(false);
		}

		BFS(graph, 1, visited);

		std::cout << std::endl;
	});

	std::cout << "consumed time : " << consumedTime_BFS << " ms" << std::endl;
}

int IsBfsDone(const std::vector<bool>& inVisited)
{
	for (size_t idx = 0; idx < inVisited.size(); idx++)
	{
		if (!inVisited[idx])
		{
			return idx;
		}
	}

	return -1;
}

/// N x M 크기의 얼음 틀이 있습니다. 구멍이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 표시됩
/// 니다. 구멍이 뚫려 있는 부분끼리 상, 하, 좌, 우로 붙어 있는 경우 서로 연결되어 있는 것으로 간주합니다.
/// 이때 얼음 틀의 모양이 주어졌을 때 생성되는 총 아이스크림의 개수를 구하는 프로그램을 작성하세요.
void DFSBFS_Problem_3()
{
	const std::vector<int> columnMovement{ 0, 0, 1, -1 };
	const std::vector<int> rowMovement{ 1, -1, 0, 0 };

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> input;
	std::string lineReadBuffer;
	std::vector<bool> visited;

	for (int lineCounter = N; lineCounter > 0; lineCounter--)
	{
		input.emplace_back(std::vector<int>());
		std::cin >> lineReadBuffer;
		for (const auto& elem : lineReadBuffer)
		{
			input[N - lineCounter].emplace_back(elem - '0');
			if(elem - '0' == 1) { visited.emplace_back(true); }
			else{ visited.emplace_back(false); }
		}
	}

	double consumedTime = TimeChecker::CheckTime([&] {

		std::vector<std::vector<int>> graph;
		int result = 0;
		
		// make graph
		for (size_t outerIdx = 0; outerIdx < input.size(); outerIdx++)
		{
			for (size_t innerIdx = 0; innerIdx < input[outerIdx].size(); innerIdx++)
			{
				graph.emplace_back(std::vector<int>());

				if (input[outerIdx][innerIdx] == 0)
				{
					for (int movementCounter = 0; movementCounter < 4; movementCounter++)
					{
						if (outerIdx + columnMovement[movementCounter] < 0 || outerIdx + columnMovement[movementCounter] > N - 1
							|| innerIdx + rowMovement[movementCounter] < 0 || innerIdx + rowMovement[movementCounter] > M - 1)
						{
							continue;
						}

						if (input[outerIdx + columnMovement[movementCounter]][innerIdx + rowMovement[movementCounter]] == 0)
						{
							(*(graph.end() - 1)).emplace_back((outerIdx + columnMovement[movementCounter]) * M + (innerIdx + rowMovement[movementCounter]));
						}
					}
				}
			}
		}

		int visitableIdx;

		while ((visitableIdx = IsBfsDone(visited)) != -1)
		{
			result++;

			DFS(graph, visitableIdx, visited);
		}

		std::cout << std::endl << result << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void DFS_4(std::vector<std::vector<int>> inGraph, int inColumn, int inRow, int inN, int inM, const std::vector<int>& inColumnMovement, const std::vector<int>& inRowMovement, int inStep, std::vector<int>& inRouteSteps)
{
	if (inColumn == inN - 1 && inRow == inM - 1)
	{
		inRouteSteps.emplace_back(inStep);
		return;
	}

	inGraph[inColumn][inRow] = 0;
	int columnBuffer, rowBuffer;

	for (int directionCounter = 0; directionCounter < 4; directionCounter++)
	{
		columnBuffer = inColumn + inColumnMovement[directionCounter];
		rowBuffer = inRow + inRowMovement[directionCounter];
		if (columnBuffer >= 0 && columnBuffer < inN
			&& rowBuffer >= 0 && rowBuffer < inM
			&& inGraph[columnBuffer][rowBuffer] == 1)
		{
			DFS_4(inGraph, columnBuffer, rowBuffer, inN, inM, inColumnMovement, inRowMovement, inStep + 1, inRouteSteps);
		}
	}
}

/// 동빈이는 N x M 크기의 직사각형 형태이 미로에 갇혔습니다. 미로에는 여러 마리의 괴물이 있어 이를 
/// 피해 탈출해야 합니다.
/// 동빈이의 위치는 (1,1) 이며 미로의 출구는 (N,M)의 위치에 존재하며 한 번에 한 칸씩 이동할 수 있습니
/// 다. 이때 괴물이 있는 부분은 0으로, 괴물이 없는 부분은 1로 표시되어 있습니다. 미로는 반드시 탈출할
/// 수 있는 형태로 제시됩니다.
/// 이때 동빈이가 탈출하기 위해 움직여야 하는 최소 칸의 개수를 구하세요. 칸을 셀 때는 시작 칸과 마지막
/// 칸을 모두 포함해서 계산합니다.
void DFSBFS_CodingProblem_4()
{
	const std::vector<int> columnMovement{ 0, 0, 1, -1 };
	const std::vector<int> rowMovement{ 1, -1, 0, 0 };

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> input;
	std::string lineReader;
	for (int counter = N; counter > 0; counter--)
	{
		input.emplace_back(std::vector<int>());
		std::cin >> lineReader;
		for (const auto& elem : lineReader)
		{
			(*(input.end() - 1)).emplace_back(elem - '0');
		}
	}

	double consumedTime = TimeChecker::CheckTime([&] {
		
		std::vector<int> routeSteps;

		DFS_4(input, 0, 0, N, M, columnMovement, rowMovement, 1, routeSteps);

		std::cout << *(std::min_element(routeSteps.begin(), routeSteps.end())) << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblems_DFSBFS()
{
	//DFSBFS_Problem_1();

	//DFSBFS_Problem_2();

	//DFSBFS_Problem_3();

	DFSBFS_CodingProblem_4();
}