#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

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

/// 정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는
/// 모든 경우의 수를 구하는 프로그램을 작성하세요. 예를 들어 1을 입력했을 때 다음은 3이 하나라도 포함되
/// 어 있으므로 세어야 하는 시각입니다.
void ImplementationProblem_2()
{
	int outN;
	std::cin >> outN;

	double consumedTime = TimeChecker::CheckTime([&] {

		int result = 0;

		for (int hour = 0; hour <= outN; hour++)
		{
			for (int minute = 0; minute < 60; minute++)
			{
				for (int second = 0; second < 60; second++)
				{
					if (std::to_string(hour).find('3') != std::string::npos 
						|| std::to_string(minute).find('3') != std::string::npos 
						|| std::to_string(second).find('3') != std::string::npos)
					{
						result++;
					}
				}
			}
		}

		std::cout << result << std::endl;

	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// conbining string makes so slow
void ImplementationProblem_2_Failure()
{
	int outN;
	std::cin >> outN;

	double consumedTime = TimeChecker::CheckTime([&] {

		int result = 0;

		for (int hour = 0; hour <= outN; hour++)
		{
			for (int minute = 0; minute < 60; minute++)
			{
				for (int second = 0; second < 60; second++)
				{
					if ((std::to_string(hour) + std::to_string(minute) + std::to_string(second)).find('3') != std::string::npos)
					{
						result++;
					}
				}
			}
		}

		std::cout << result << std::endl;

		});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// 행복 왕국의 왕실 정원은 체스판과 같은 8 x 8 좌표 평면입니다. 왕실 정원의 특정한 한 칸에 나이트가 서
/// 있습니다. 나이트는 매우 충성스러운 신하로서 매일 무술을 연마합니다.
/// 
/// 나이트는 말을 타고 있기 때문에 이동을 할 때는 L자 형태로만 이동할 수 있으며 정원 밖으로는 나갈 수 없
/// 습니다.
/// 
/// 나이트는 특정 위치에서 다음과 같은 2가지 경우로 이동할 수 있습니다.
/// 1. 수평으로 두 칸 이동한 뒤에 수직으로 한 칸 이동하기
/// 2. 수직으로 두 칸 이동한 뒤에 수평으로 한 칸 이동하기
/// 
/// 이처럼 8 x 8 좌표 평면상에서 나이트의 위치가 주어졌을 때 나이트가 이동할 수 있는 경우의 수를 출력하
/// 는 프로그램을 작성하세요. 왕실의 정원에서 행 위치를 표현할 때는 1부터 8로 표현하며, 열 위치를 표현할 
/// 때는 a부터 h로 표현합니다.
void ImplementationProblem3()
{
	const std::vector<int> columnMovement{ 1, -1, 1, -1, 2, 2, -2, -2 };
	const std::vector<int> rowMovement{ 2, 2, -2, -2, 1, -1, 1, -1 };

	std::string inputPos;
	std::cin >> inputPos;

	double consumedTime = TimeChecker::CheckTime([&] {

		int column = (inputPos[0] - 'a') + 1;
		int row = inputPos[1] - '0';
		int result = 0;

		for (int idx = 0; idx < 8; idx++)
		{
			if (column + columnMovement[idx] > 0 && row + rowMovement[idx] > 0
				&& column + columnMovement[idx] <= 8 && row + rowMovement[idx] <= 8)
			{
				result++;
			}
		}

		std::cout << result << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// 입력된 문자열을 거꾸로 뒤집어 출력하시오
void ImplementationProblem4()
{
	std::string inputStr;
	std::cin >> inputStr;

	double consumedTime = TimeChecker::CheckTime([&] {
		
		for (size_t idx = 0; idx < inputStr.size() / 2; idx++)
		{
			std::swap(inputStr[idx], inputStr[inputStr.size() - 1 - idx]);
		}

		std::cout << inputStr << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

/// 알파벳 대문자와 숫자(0~9)로만 구성된 문자열이 입력으로 주어집니다. 이때 모든 알파벳을 오름차순으
/// 로 정렬하여 이어서 출력한 뒤에, 그 뒤에 모든 숫자를 더한 값을 이어서 출력합니다.
/// 예를 들어 K1KA5CB7이라는 값이 들어오면 ABCKK13을 출력합니다.
void ImplementationProblem5()
{
	std::string inputStr;
	std::cin >> inputStr;

	double consumedTime = TimeChecker::CheckTime([&] {
		
		std::string characters;
		std::vector<int> numbers;

		for (const auto& elem : inputStr)
		{
			if (elem >= '0' && elem <= '9')
			{
				numbers.emplace_back(elem - '0');
			}
			else
			{
				characters.push_back(elem);
			}
		}
		
		std::sort(characters.begin(), characters.end());
		auto Sum = std::accumulate(numbers.begin(), numbers.end(), 0);

		std::cout << characters << Sum << std::endl;
	});

	std::cout << "consumed time : " << consumedTime << " ms" << std::endl;
}

void main_CodingProblems_Implementation()
{
	//ImplementationProblem_1();

	//ImplementationProblem_2();
	//ImplementationProblem_2_Failure();

	//ImplementationProblem3();

	//ImplementationProblem4();

	//ImplementationProblem5();
}