#pragma once

// Assignment Operator
//
// when making copy assignment operator three things have to be considered
// 
// 1. returning *this recommended
// 2. consider handling class or struct itself
//
// there is 3 ways to handle assigning itself
// 1) compare and check objects' addresses
// 2) adjust code order
// 3) use swapping
class Player
{
public:
	Player() : mNum{ 0 } {};

	Player& operator=(const Player& other)
	{
		// 1) comparing objects' addresses
		if (this == &other)
		{
			return *this;
		}
		// copy
		this->mNum = other.mNum;
		return *this;
	}

private:
	int mNum;
};

// swapping example
class AnotherPlayer
{
public:
	AnotherPlayer() : mNum{ 0 } {};

	void swap(AnotherPlayer& other)
	{
		// data swapping code
		int temp = other.mNum;
		other.mNum = this->mNum;
		this->mNum = temp;
	}

	AnotherPlayer& operator=(const AnotherPlayer& other)
	{
		// make a copy
		AnotherPlayer temp(other);
		// call swap function
		this->swap(temp);
		return *this;
	}

	AnotherPlayer& operator=(AnotherPlayer& other)
	{
		this->swap(other);
		return *this;
	}


private:
	int mNum;
};