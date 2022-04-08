#pragma once
#include <string>

template<typename T>
void printType(T&& val)
{
	auto temp = std::forward<T>(val);
	std::cout << typeid(temp).name() << '\n';
}

void executeTypeDeduction()
{
	auto intVal = 1;
	std::cout << typeid(intVal).name() << '\n';
	auto doubleVal = 5.4;
	std::cout << typeid(doubleVal).name() << '\n';

	std::string str = "type deduction";

	printType(str);
	printType(std::move(str));


	std::string& strLRef = str;
	std::cout << typeid(strLRef).name() << '\n';
	std::string&& strRRef = std::move(str);
	std::cout << typeid(strRRef).name() << '\n';

}