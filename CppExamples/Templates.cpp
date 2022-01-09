#include "Templates.h"

// template implementation in cpp file
template<typename T>
T implInCpp(T param)
{
	std::cout << "template implementation in cpp file" << '\n';
	std::cout << typeid(T).name() << '\n';
	return param;
}

// explicit template instanciation
template int implInCpp<int>(int);
template double implInCpp<double>(double);

void executeTemplatesExample()
{
	// 0.1 multiple type template
	std::cout << add<double, int>(3.9, 2) << '\n';
	// 0.2 none
	std::cout << mult<double, 3>(3.9) << '\n';
	// 0.3 parameter pack (c ++ 17)
	print("parameter", " pack");
	// implementation in cpp file
	implInCpp<int>(3);

	// 1. Function Template
	// 
	// 1.1 type deduction calling
	std::cout << add(3, 5) << '\n';
	std::cout << add(4.1, 2.2) << '\n';
	// 1.2 explicitly wroted calling
	std::cout << add<int>(4, 9) << '\n';
	std::cout << add<float>(2.1f, 9.3f) << '\n';

	// 2. Class Template
	Stack<int> stackExample;
	stackExample.push(3);
	std::cout << stackExample.size() << '\n';
	stackExample.pop();
	std::cout << stackExample.size() << '\n';
	 
	// 3. Aliasing Template
	customType<int> aliasingExample;
	std::cout << typeid(aliasingExample).name() << '\n';
	
	// 4. Variable Template
	int intPi = pi<int>;
	double doublePi = pi<double>;

	std::cout << intPi << '\n';
	std::cout << doublePi << '\n';
}
