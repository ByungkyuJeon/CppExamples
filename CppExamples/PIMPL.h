#pragma once

// PIMPL Example
//
// 사용 목적
// 1. 컴파일 시간 단축 / ABI 호환성 보장
// 2. 소스 파일을 빌드해서 사용할 시, 소스 코드 은닉
//
// 단점
// 1. 호출 오버헤드
// 2. 자원 관리 오버헤드 (기존의 스택 메모리에서 PIMPL은 힙으로)
class PIMPLExampleClass
{
public:
	class NestedClass;

	PIMPLExampleClass();
	~PIMPLExampleClass();

	void Print();

private:
	NestedClass* mNestedClass;
};

void executePIMPLExample();