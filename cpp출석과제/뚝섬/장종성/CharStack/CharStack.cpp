#include <iostream>				// �ܼ� ������� ���� �ش����� ����
#include "CharStack.h"			// CharStack Ŭ������ ����ϱ� ���� �ش����� ����
using namespace std;			// ��Ī���� std ���

bool CharStack::push(char ch)	// ���ÿ� ������ ������ ���� push �Լ��� ����
{
	if (chkFull()) {			// ������ �������ִٸ�
		cout << "������ ���� �� �ֽ��ϴ�." << endl; // �޽��� ���
		return false;			// �����͸� ���� �ʾ������� false�� ��ȯ
	}
	buf[--top] = ch;			// ���� top�� ���� 1 ���� �� buf�� top ��ġ�� ch�� ����
	return true;				// �����͸� �־������� true�� ��ȯ
}

char CharStack::pop()			// ���ÿ��� �����͸� ������ pop�Լ��� ����
{
	if (chkEmpty()) {			// ���ÿ� �����Ͱ� ���ٸ�
		cout << "���ÿ� �����Ͱ� �����ϴ�." << endl;	// �޽��� ���
		return 0;				// �����Ͱ� �������� 0�� ��ȯ
	}
	return buf[top++];			// buf�� top��ġ�� ���� ��ȯ�ϰ� top�� 1����
}