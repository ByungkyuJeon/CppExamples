#pragma once

// Disabling automatically generated class codes(constructor, copy, assignment, etc.)
//
// 컴파일러는 클래스가 호출되는 코드를 기반으로 하여 
// 암시적으로 일부 함수들을 생성할 수 있고, 이를 통해 의도하지 않는 동작이 발생할 수 있다.
// 따라서, 암시적으로 컴파일러에 의해 생성될 수 있는 함수들을 미리 차단하는 것이 좋다.
// 
// Example 1
// 
// moving to private scope with no definition
class Player
{
public:
	Player() = default;
	~Player() {}

private:
	Player(Player& other); // disable copy constructor auto generation
	Player& operator=(const Player& other); // disable copy assignment auto generation
};

// Example 2
//
// explicitly disabling with 'delete'
class AnotherPlayer
{
public:
	AnotherPlayer() = default;
	~AnotherPlayer() {}

	AnotherPlayer(AnotherPlayer& other) = delete;
	AnotherPlayer& operator=(const AnotherPlayer& other) = delete;
};

// Example 3
//
// using base disabling class
class Uncopyable
{
protected:
	Uncopyable() {}
	~Uncopyable() {}
private:
	Uncopyable(Uncopyable& other);
	Uncopyable& operator=(const Uncopyable& other);
};
