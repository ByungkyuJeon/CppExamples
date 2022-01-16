#pragma once
#include <functional>
#include <iostream>

// in c++ parameter evaluation order is unknown
// 
// if functions' return value is passed like bellow,
// code operation can change in different compilers or framework or operating systems.
// for portability of code, avoid these form of codes
int num = 0;

void callingFunction(int a, int b, int c) // prints 10, 15, 17
{
	std::cout << a << " " << b << " " << c << std::endl;
	// prints 17, 15, 10
}

// failing example
//
//
class Player
{
public:
	Player() : mNum{ 0 }, friendPlayer{ nullptr }{};
	Player(Player* other) : mNum{ 0 }
	{
		friendPlayer = other;
	};

	int getNum() const
	{
		return mNum;
	}

private:
	int mNum;
	Player* friendPlayer;
};

int makeException()
{
	throw 1;
}

void processPlayer(Player player, int num)
{
	std::cout << "example process" << std::endl;
}

void executeParameterEvaluationExample()
{
	callingFunction(
		[] {std::cout << "func_1 : " << (num += 2) << std::endl; return num; }(),
		[] {std::cout << "func_1 : " << (num += 5) << std::endl; return num; }(),
		[] {std::cout << "func_1 : " << (num += 10) << std::endl; return num; }()
	);

	// this code bellow can cause memory leak when operates in order bellow
	// 1. "new Player"�� �����մϴ�.
	// 2. makeException�� ȣ���մϴ�.
	// 3. Player(Player*) ��� �Լ��� ȣ���մϴ�.
	// �� �� makeException ȣ�� �κп��� ���ܰ� �߻��ϸ�
	// "new Player"���� ��������� �����Ͱ� ���ǵ˴ϴ�.
	processPlayer(Player(new Player()), makeException());
}