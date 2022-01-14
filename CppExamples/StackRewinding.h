#pragma once

struct StackRewindingExample
{
public:
	StackRewindingExample() : mNum{ 0 } {}

	int GetNum() const
	{
		return mNum;
	}

	void Increment() // throws exception when mNum is greater then 5
	{
		if (mNum == 5)
		{
			throw mNum + 1; // Stack Rewinding
		}
		mNum++;
	}

	void Print() const
	{
		std::cout << mNum << std::endl;
	}

private:
	int mNum;
};

void thrower_1(StackRewindingExample& example)
{
	try
	{
		example.Increment();
	}
	catch(int num)
	{
		std::cout << "Throwed " << num << " from thrower 1" << std::endl;
		throw num + 1; // Stack Rewinding
	}
}

void thrower_2(StackRewindingExample& example)
{
	try
	{
		thrower_1(example);
	}
	catch (int num)
	{
		std::cout << "Throwed " << num << " from thrower 2" << std::endl;
		throw num + 1; // Stack Rewinding
	}
}

void executeStackRewinding()
{
	StackRewindingExample example;

	try
	{
		for (int counter = 0; counter < 10; counter++)
		{
			// Stack Winding
			thrower_1(example);
		}
	}
	catch (int num)
	{
		std::cout << "Throwed " << num << " from main" << std::endl;
		std::cout << "Origin " << example.GetNum() << " from example obj" << std::endl;
		// if throw, runtime error occur
		// throw num; 
	}
}