#pragma once

#include <iostream>
#include <vector>

class StandardAlgorithmsExampleClass
{
public:

	explicit StandardAlgorithmsExampleClass() : mInt{ 0 }, mDouble{ 0 }{}
	StandardAlgorithmsExampleClass(int inInt, double inDouble) : mInt{ inInt }, mDouble{ inDouble }{}

	~StandardAlgorithmsExampleClass() noexcept {}

	void SetIntVal(int num)
	{
		mInt = num;
	}

	void SetDoubleVal(double num)
	{
		mDouble = num;
	}

	int GetIntVal() const
	{
		return mInt;
	}

	double GetDoubleVal() const
	{
		return mDouble;
	}

	bool operator<(const StandardAlgorithmsExampleClass& other) const
	{
		return mInt < other.mInt;
	}

	bool operator<(int num) const
	{
		return mInt < num;
	}

	bool operator==(const StandardAlgorithmsExampleClass& other) const
	{
		return mInt == other.GetIntVal();
	}

	bool operator==(int num) const
	{
		return mInt == num;
	}

	void Print() const
	{
		std::cout << "[integer : " << mInt << " / " << "double : " << mDouble << " ]" << std::endl;
	}

private:

	int mInt;
	double mDouble;
};

bool operator<(int num, const StandardAlgorithmsExampleClass& rhs);

std::shared_ptr<StandardAlgorithmsExampleClass> Sum(std::shared_ptr<StandardAlgorithmsExampleClass> lhs, const StandardAlgorithmsExampleClass& rhs);

bool DescendingCondition(const StandardAlgorithmsExampleClass& lhs, const StandardAlgorithmsExampleClass& rhs);

void PrintVector(const std::vector<StandardAlgorithmsExampleClass>& InVector, char* InText);

void executeStandardAlgorithmsExample();