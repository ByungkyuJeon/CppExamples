#pragma once

#include "ExampleHelperClass.h"

#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

class ExampleSourceClass
{
public:
	ExampleSourceClass() :mInt{ 0 }, mDouble{ 0 }{}
	ExampleSourceClass(int inInt, double inDouble) : mInt{ inInt }, mDouble{ inDouble }{}
	

	bool operator<(const ExampleSourceClass& other) const { return mInt < other.mInt; }
	bool operator>(const ExampleSourceClass& other) const { return mInt > other.mInt; }
	bool operator==(const ExampleSourceClass& other) const { return mInt == other.mInt; }

	int GetIntVal() const { return mInt; }
	double GetDoubleVal() const { return mDouble; }

private:
	int mInt;
	double mDouble;
};

std::ostream& operator<<(std::ostream& os, const ExampleSourceClass& source)
{
	return os << "[integer : " << source.GetIntVal() << " / " << "double : " << source.GetDoubleVal() << " ]";
}

class MaxHeapExampleClass
{
public:
	MaxHeapExampleClass() {}

	void Print() const
	{
		for (const auto& elem : mVector)
		{
			std::cout << elem << std::endl;
		}
	}

	void Add(ExampleSourceClass&& source)
	{
		mVector.emplace_back(std::move(source));
		Heapify();
	}

	void Remove(size_t inIdx)
	{
		if (inIdx < mVector.size() && inIdx >= 0)
		{
			mVector.erase(mVector.begin() + inIdx);
			Heapify();
		}
	}

	int GetDepth()
	{
		return static_cast<int>(std::ceil(std::log2(mVector.size() + 1)));
		
	}

	const ExampleSourceClass& GetRoot()
	{
		return mVector[0];
	}

	bool IsValid()
	{
		return mVector.size() > 0;
	}

protected:

	void Heapify()
	{
		size_t friendIdx = -1;
		size_t parentIdx = -1;
		size_t maxIdx = -1;

		for (int idx = mVector.size() - 1; idx > 0; idx -= 2)
		{
			parentIdx = GetParentNode(idx);
			if (parentIdx < 0 || parentIdx >= mVector.size()) { return; }

			friendIdx = GetFriendNode(idx);
			if (friendIdx < 0 || friendIdx >= mVector.size())
			{
				if ((maxIdx = GetMaxIdx(parentIdx, idx)) != parentIdx)
				{
					std::swap(mVector[parentIdx], mVector[maxIdx]);
				}
				continue;
			}

			if ((maxIdx = GetMaxIdx(parentIdx, GetFriendNode(idx), idx)) != parentIdx)
			{
				std::swap(mVector[parentIdx], mVector[maxIdx]);
			}
		}
	}

	size_t GetLeftChildNode(size_t nodeNum)
	{
		return 2 * nodeNum + 1;
	}

	size_t GetRightChildNode(size_t nodeNum)
	{
		return 2 * nodeNum + 2;
	}

	size_t GetParentNode(size_t nodeNum)
	{
		return (nodeNum - 1) / 2;
	}

	size_t GetFriendNode(size_t nodeNum)
	{
		if (nodeNum % 2 == 0)
		{
			return nodeNum - 1;
		}

		return nodeNum + 1;
	}

	size_t GetMaxIdx(size_t root, size_t left, size_t right)
	{
		size_t tempIdx = root;
		if (mVector[tempIdx] < mVector[left])
		{
			tempIdx = left;
		}
		if (mVector[tempIdx] < mVector[right])
		{
			tempIdx = right;
		}
		return tempIdx;
	}

	size_t GetMaxIdx(size_t root, size_t left)
	{
		if (mVector[root] < mVector[left])
		{
			return left;
		}
		return root;
	}

private:
	std::vector<ExampleSourceClass> mVector;
};


void main_DataStructureExample()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	MaxHeapExampleClass exampleClass;
	for (int elemCount = 50; elemCount > 0; elemCount--)
	{
		exampleClass.Add({ std::rand() % 1000, static_cast<double>(std::rand() / static_cast<double>(RAND_MAX / 1000)) });
	}

	exampleClass.Print();
}