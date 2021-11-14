#pragma once

#include <vector>
#include <iostream>

class ExampleHelperClass
{
public:
	template<typename Type>
	static void PrintVector(const std::vector<Type>& arr, std::ostream& os) noexcept
	{
		for (const auto& elem : arr)
		{
			os << elem << std::endl;
		}
	}

};