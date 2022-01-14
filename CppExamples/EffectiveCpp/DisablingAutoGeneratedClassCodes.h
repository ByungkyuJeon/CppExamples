#pragma once

// Disabling automatically generated class codes(constructor, copy, assignment, etc.)
//
// �����Ϸ��� Ŭ������ ȣ��Ǵ� �ڵ带 ������� �Ͽ� 
// �Ͻ������� �Ϻ� �Լ����� ������ �� �ְ�, �̸� ���� �ǵ����� �ʴ� ������ �߻��� �� �ִ�.
// ����, �Ͻ������� �����Ϸ��� ���� ������ �� �ִ� �Լ����� �̸� �����ϴ� ���� ����.
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
