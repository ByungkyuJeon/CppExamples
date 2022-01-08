#pragma once

#include<string>
#include<memory>
#include<iostream>


class FunctionObjectExampleClass
{
public:
	FunctionObjectExampleClass() : mStr{ std::make_unique<std::string>() } {}
	~FunctionObjectExampleClass() = default;

	const std::string* operator()(char* str) const
	{
		mStr->append(str);
		return mStr.get();
	}

private:

	std::unique_ptr<std::string> mStr;
};


void executeFunctionObejctExample();