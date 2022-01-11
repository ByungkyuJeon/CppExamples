#pragma once

// At Effective cpp, const keyworded function, parameter, return type are recommended
//
// const keyword helps to catch errors from compiler at use
// meaning of 'const' may differ from compiler to the developer
//
// compiler(비트수준 상수성) : no modification to any member variables except static ones
// developer(개념적인 상수성) : can modify little to some member variables but not to affect object's statement
//
// 상수 함수가 필요한 이유
// 
// 1. 클래스 인터페이스 설계 측면
// 객체를 변경할 수 있는 함수과 구분하여 설계
// 
// 2. 코드 효율
// 상수 객체에 대한 사용을 개방함으로써 프로그램의 실행 성능을 끌어내기에 용이
//
//
// 
// 상수 멤버 함수와 비상수 함수의 기능 중복 시 개선 방안
//
// 비상수 함수가 상수 함수를 호출하도록 구성할 것
class TextBlock
{
public:
	const char& operator[](size_t pos) const
	{
		return textArr[pos];
	}

	char& operator[](size_t pos)
	{
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[pos]);
	}

private:
	char textArr[10];
};
