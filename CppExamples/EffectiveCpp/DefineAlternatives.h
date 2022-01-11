#pragma once

// 단순한 상수를 쓸 때는, #define 보다 const 객체 혹은 enum을 우선 생각하자.
//
// #define으로 전처리된 코드는 심볼 테이블에 포함되지 않아, 디버깅에 취약하다는 단점을 가지고 있다.
// #define으로 전처리된 코드는 가독성 측면에서 해로울 수 있다.

// 1. Alternative using const object
//
// #define 과 같은 기능과 성능을 가지면서도 단점을 보완할 수 있다.
class Player
{
private:
	static const int NumTurns = 5;
	// 클래스 내 선언부에서 사용할 목적이라면 NumTurns의 값을 선언부에 넣어주자
	// 해당 목적이 아니라면 cpp 정의부에서 값을 넣어주는 것이 c++ 표준이다.
	// 하지만 구식 컴파일러라면 표준 방식(정의부 값 지정)의 선언 정의가 컴파일러 오류로 나타날 수 있다.
	// 그런 경우 enum을 통해 해결할 수 있다.
	int scores[NumTurns];
};

// 2. Alternative using enum
class AnotherPlayer
{
private:
	enum { NumTurns = 5 };
	// 사용하고자 하는 상수를 enum 형태로 위와 같이 만들 수 있다.
	// enum을 통해 만든 상수는 주소나 참조자를 얻을 수 없다.
	// 또한 #define처럼 어떠한 형태로도 쓸데없는 메모리 할당을 수행하지 않는다는 점에서 장점이 있다.
	int scores[NumTurns];
};

// 3. Alternative using inline template function
#define SHIFT_LEFT(x, y) x >> y
// 위 매크로 함수는 단순 코드 치환식으로 작동하기 때문에 널리 알려진 문제점들이 있다.
// 1) 복합 연산코드 내 괄호 문제
// 2) 증감 복합 연산 코드 내 다중 증감 문제
//
// 위 문제점들을 아래와 같이 대체하여 해결할 수 있다.
// 정확히 동일한 기능과 성능을 하며 문제들이 해결되었다.
template<typename T>
T shiftLeft(T x, T y)
{
	return x >> y;
}