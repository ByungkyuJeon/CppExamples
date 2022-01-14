#pragma once
#include <cstdlib>

// in destructor, there should not be code for calling virtual functions
//
// Reason
//
// will not call derived class's function

// Example 1
//
// designed considering polymorphism base class's destructor should be virtual
// in opposite, non virtual base class's destructor should not be virtual
//
// Reason 
// when destructing derived class in form of base class
// there can be memory leak by calling only base class's destructor
class Player
{
public:
	Player() = default;
	virtual ~Player();

	virtual void Jump() {}
};

// Example 2 
// 
// no exception should not be thrown 
// there are 3 ways of this
Player::~Player()
{
	try
	{
		// destructor code
	}
	catch (...)
	{
		// writing log code
		// 1. close program
		std::abort();
		// 2. ignore
		//
		// if ignoring, there must be no problem after exception
	}
}

// Example 3
//
// if exception might occur in destructor, seperation can be a good solution
class AnotherPlayer
{
public:
	AnotherPlayer() :closed{ false } {};
	~AnotherPlayer();

	void close()
	{
		// close something before calling destructor
	}

private:
	bool closed;
};

AnotherPlayer::~AnotherPlayer()
{
	if (!closed)
	{
		try
		{
			// close something
		}
		catch (...)
		{
			// writing log code
			// aborting or ignoring
			std::abort();
		}
	}
}