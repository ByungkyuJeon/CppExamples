#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>

/// 여행가 A는 N x N 크기의 정사각형 공간 위에 서 있습니다. 이 공간은 1 x 1 크기의 정사각형으로 나누어져 
/// 있습니다. 가장 왼족 위 좌표는 (1, 1)이며, 가장 오른쪽 아래 좌표는 (N, N)에 해당합니다. 여행가 A는 
/// 상, 하, 좌, 우 방향으로 이동할 수 있으며, 시작 좌표는 항상 (1, 1)입니다. 우리 앞에는 여행가  A가 이동
/// 할 계획이 적힌 계획서가 놓여 있습니다. 
/// 
/// 계획서에는 하나의 줄에 띄어쓰기를 기준으로 하여 L, R, U, D 중 하나의 문자가 반복적으로 적혀 있습니다.
/// 각 문자의 의미는 방향입니다.
/// 
/// 사각형을 벗어나는 명령은 무시됩니다.
void ImplementationProblem_1()
{
	const std::vector<int> outColumnMovement{ 0, 0, 1, -1 };
	const std::vector<int> outRowMovement{ 1, -1, 0, 0 };

	int outN;
	std::cin >> outN;

	std::vector<char> outDirections;
	char inputBuffer;
	for (int counter = outN; counter > 0; counter--)
	{
		std::cin >> inputBuffer;
		outDirections.emplace_back(inputBuffer);
	}


	double consumedTime = TimeChecker::CheckTime([&] {

		int X = 1, Y = 1;

		std::vector<int> translatedDirections;

		for (const auto& elem : outDirections)
		{
			switch (elem)
			{
			case('R'):
				translatedDirections.emplace_back(0);
				break;
			case('L'):
				translatedDirections.emplace_back(1);
				break;
			case('D'):
				translatedDirections.emplace_back(2);
				break;
			case('U'):
				translatedDirections.emplace_back(3);
				break;
			}
		}

		for (const auto& elem : translatedDirections)
		{
			if ((X + outColumnMovement[elem] <= outN) && (Y + outRowMovement[elem] <= outN)
				&& (X + outColumnMovement[elem] > 0) && (Y + outRowMovement[elem] > 0))
			{
				X += outColumnMovement[elem];
				Y += outRowMovement[elem];
			}
		}

		std::cout << X << " " << Y << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}




void main_CodingProblems_Implementation()
{
	ImplementationProblem_1();
}