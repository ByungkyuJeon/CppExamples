#pragma once

#include "TimeChecker.h"
#include <iostream>
#include <vector>
#include <string>

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




void main_CodingProblems_Implementation()
{
	ImplementationProblem_1();
}