#include <iostream>						// �ܼ� ������� ���� �ش����� ����
#include "CharStack.h"					// CharStack Ŭ������ ����ϱ� ���� �ش����� ����
using namespace std;					// ��Ī���� std ���

int main()								// ���α׷� ���� main�Լ� ����
{
	CharStack chStack;					// ���ڿ��� ������ �� �ִ� ���ð�ü ����
	char str[20];						// ���ڸ� �Է¹ޱ� ���� �迭 ���� 

	cout << "���� �ܾ �Է��Ͻÿ� : ";	// �ȳ��� ���	
	cin >> str;							// ���ڿ��� �Է¹޾� str�迭�� ����

	char *pt = str;						// ������ pt�� �����ϰ� �Է¹��� ���ڿ��� �ּҸ� ����
	while (*pt)							// ���忭�� ���� �ƴϸ� �ݺ�
		chStack.push(*(pt++));			// ���ÿ� ���ڸ� �ְ� ������ pt�� 1����.

	cout << "���� �ܾ� ��� : ";			// �ȳ��� ���
	while (!chStack.chkEmpty())			// ������ ��� ���� ������ �ݺ�
		cout << chStack.pop();			// ���ÿ��� �ϳ��� ������ �ֿܼ� ���
	cout << endl;						// ���� ���
	return 0;							// ���α׷� ����
}