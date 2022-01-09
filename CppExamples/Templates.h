#pragma once
#include <iostream>
#include <vector>

// TEAMPLATES
//
// template instantiation goes when called at compile time

// 1. Function Template
//
// one type template
template<typename T>
T add(T a, T b)
{
	return a + b;
}

// multiple type template
template<typename T, typename S>
T add(T a, S b)
{
	return a + static_cast<T>(b);
}

// none type parameter template
template<typename T, int N>
T mult(T a)
{
	return a * N;
}

// parameter pack (c++ 17)
template<typename ...T>
void print(T&& ... params)
{
	(std::cout << ... << params) << '\n';
}

// template implementation in cpp file
template<typename T>
T implInCpp(T param);

// 2. Class template
template<typename T>
class Stack
{
public:
	Stack() :mVec{ std::vector<T>() } {}

	void push(T elem)
	{
		mVec.emplace_back(std::move(elem));
	}

	void pop()
	{
		mVec.pop_back();
	}

	size_t size()
	{
		return mVec.size();
	}

private:
	std::vector<T> mVec;
};

// 3. Aliasing template
template<typename T>
using customType = std::vector<T>;

// 4. Variable template
template<typename T>
constexpr T pi = T(3.1415926535897932385L);

void executeTemplatesExample();