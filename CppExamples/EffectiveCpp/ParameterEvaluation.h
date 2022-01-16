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
	// 1. "new Player"을 실행합니다.
	// 2. makeException를 호출합니다.
	// 3. Player(Player*) 멤버 함수를 호출합니다.
	// 이 때 makeException 호출 부분에서 예외가 발생하면
	// "new Player"으로 만들어졌던 포인터가 유실됩니다.
	processPlayer(Player(new Player()), makeException());
}