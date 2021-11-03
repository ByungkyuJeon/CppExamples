#pragma once

#include <string>

class ForLoopExampleClass
{
public:
	ForLoopExampleClass() = default;
	ForLoopExampleClass(std::string name, int num) : mName{ std::move(name) }, mNum{ num } {}

	const std::string& GetName() const
	{
		return mName;
	}

	int GetNum() const
	{
		return mNum;
	}

private:
	std::string mName;
	int mNum;
};

std::ostream& operator<<(std::ostream& os, const ForLoopExampleClass& exampleClass);

void main_ForLoopExample();
