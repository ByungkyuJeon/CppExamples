#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

/// ���డ A�� N x N ũ���� ���簢�� ���� ���� �� �ֽ��ϴ�. �� ������ 1 x 1 ũ���� ���簢������ �������� 
/// �ֽ��ϴ�. ���� ���� �� ��ǥ�� (1, 1)�̸�, ���� ������ �Ʒ� ��ǥ�� (N, N)�� �ش��մϴ�. ���డ A�� 
/// ��, ��, ��, �� �������� �̵��� �� ������, ���� ��ǥ�� �׻� (1, 1)�Դϴ�. �츮 �տ��� ���డ  A�� �̵�
/// �� ��ȹ�� ���� ��ȹ���� ���� �ֽ��ϴ�. 
/// 
/// ��ȹ������ �ϳ��� �ٿ� ���⸦ �������� �Ͽ� L, R, U, D �� �ϳ��� ���ڰ� �ݺ������� ���� �ֽ��ϴ�.
/// �� ������ �ǹ̴� �����Դϴ�.
/// 
/// �簢���� ����� ����� ���õ˴ϴ�.
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

/// ���� N�� �ԷµǸ� 00�� 00�� 00�ʺ��� N�� 59�� 59�ʱ����� ��� �ð� �߿��� 3�� �ϳ��� ���ԵǴ�
/// ��� ����� ���� ���ϴ� ���α׷��� �ۼ��ϼ���. ���� ��� 1�� �Է����� �� ������ 3�� �ϳ��� ���Ե�
/// �� �����Ƿ� ����� �ϴ� �ð��Դϴ�.
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

/// �ູ �ձ��� �ս� ������ ü���ǰ� ���� 8 x 8 ��ǥ ����Դϴ�. �ս� ������ Ư���� �� ĭ�� ����Ʈ�� ��
/// �ֽ��ϴ�. ����Ʈ�� �ſ� �漺������ ���Ϸμ� ���� ������ �����մϴ�.
/// 
/// ����Ʈ�� ���� Ÿ�� �ֱ� ������ �̵��� �� ���� L�� ���·θ� �̵��� �� ������ ���� �����δ� ���� �� ��
/// ���ϴ�.
/// 
/// ����Ʈ�� Ư�� ��ġ���� ������ ���� 2���� ���� �̵��� �� �ֽ��ϴ�.
/// 1. �������� �� ĭ �̵��� �ڿ� �������� �� ĭ �̵��ϱ�
/// 2. �������� �� ĭ �̵��� �ڿ� �������� �� ĭ �̵��ϱ�
/// 
/// ��ó�� 8 x 8 ��ǥ ���󿡼� ����Ʈ�� ��ġ�� �־����� �� ����Ʈ�� �̵��� �� �ִ� ����� ���� �����
/// �� ���α׷��� �ۼ��ϼ���. �ս��� �������� �� ��ġ�� ǥ���� ���� 1���� 8�� ǥ���ϸ�, �� ��ġ�� ǥ���� 
/// ���� a���� h�� ǥ���մϴ�.
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

/// �Էµ� ���ڿ��� �Ųٷ� ������ ����Ͻÿ�
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

/// ���ĺ� �빮�ڿ� ����(0~9)�θ� ������ ���ڿ��� �Է����� �־����ϴ�. �̶� ��� ���ĺ��� ����������
/// �� �����Ͽ� �̾ ����� �ڿ�, �� �ڿ� ��� ���ڸ� ���� ���� �̾ ����մϴ�.
/// ���� ��� K1KA5CB7�̶�� ���� ������ ABCKK13�� ����մϴ�.
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