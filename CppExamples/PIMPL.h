#pragma once

// PIMPL Example
//
// ��� ����
// 1. ������ �ð� ���� / ABI ȣȯ�� ����
// 2. �ҽ� ������ �����ؼ� ����� ��, �ҽ� �ڵ� ����
//
// ����
// 1. ȣ�� �������
// 2. �ڿ� ���� ������� (������ ���� �޸𸮿��� PIMPL�� ������)
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