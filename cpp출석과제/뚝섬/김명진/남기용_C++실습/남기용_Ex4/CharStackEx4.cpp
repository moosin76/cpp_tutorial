#include <iostream>				// �ܼ� ������� ���� �ش����� ����
#include "CharStackEx4.h"			// CharStack Ŭ������ ����ϱ� ���� �ش����� ����
using namespace std;			// ��Ī���� std ���

bool CharStackEx4::push(char ch)	// ���ÿ� ������ ������ ���� push �Լ��� ����
{
  if (chkFull()) {			// ������ �������ִٸ�
    cout << "������ ���� �� �ֽ��ϴ�." << endl; // �޽��� ���
    return false;			// �����͸� ���� �ʾ������� false�� ��ȯ
  }
  buf[--top] = ch;			// ���� top�� ���� 1 ���� �� buf�� top ��ġ�� ch�� ����
  return true;				// �����͸� �־������� true�� ��ȯ
}

char CharStackEx4::pop()			// ���ÿ��� �����͸� ������ pop�Լ��� ����
{
  if (chkEmpty()) {			// ���ÿ� �����Ͱ� ���ٸ�
    cout << "���ÿ� �����Ͱ� �����ϴ�." << endl;	// �޽��� ���
    return 0;				// �����Ͱ� �������� 0�� ��ȯ
  }
  return buf[top++];			// buf�� top��ġ�� ���� ��ȯ�ϰ� top�� 1����
}