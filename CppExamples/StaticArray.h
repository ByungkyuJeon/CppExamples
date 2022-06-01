#pragma once

#include "DataStructureTypes.h"

template<typename T, s_size_t size>
class StaticArray
{
public:
	StaticArray() : m_Size(size) {};

	// delete for no need
	StaticArray(const StaticArray& other) = delete;
	StaticArray(const StaticArray&& other) = delete;
	const StaticArray& operator=(const StaticArray& other) = delete;
	const StaticArray& operator=(const StaticArray&& other) = delete;

	inline T& operator[](s_size_t InIndex) { return m_Data[InIndex]; };

private:
	s_size_t m_Size;
	T m_Data[size];
};