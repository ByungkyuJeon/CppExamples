#pragma once

// At Effective cpp, const keyworded function, parameter, return type are recommended
//
// const keyword helps to catch errors from compiler at use
// meaning of 'const' may differ from compiler to the developer
//
// compiler(��Ʈ���� �����) : no modification to any member variables except static ones
// developer(�������� �����) : can modify little to some member variables but not to affect object's statement
//
// ��� �Լ��� �ʿ��� ����
// 
// 1. Ŭ���� �������̽� ���� ����
// ��ü�� ������ �� �ִ� �Լ��� �����Ͽ� ����
// 
// 2. �ڵ� ȿ��
// ��� ��ü�� ���� ����� ���������ν� ���α׷��� ���� ������ ����⿡ ����
//
//
// 
// ��� ��� �Լ��� ���� �Լ��� ��� �ߺ� �� ���� ���
//
// ���� �Լ��� ��� �Լ��� ȣ���ϵ��� ������ ��
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
