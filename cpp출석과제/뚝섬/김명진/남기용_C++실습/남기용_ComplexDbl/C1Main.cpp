#include <iostream>				// �ܼ� ������� ���� �ش����� ����
#include "Complex1.h"			// Complex1 Ŭ���� ����� ���� �ش����� ����
using namespace std;			// std ��Ī������ ���

int main()						// ���α׷� ���� main�Լ� ����
{
	Complex1 c1(1, 2);			// c1�̶�� ��ü �����ϰ� 1�� 2�� �Ű������� ����
	Complex1 c2(2, 3);			// c2�̶�� ��ü �����ϰ� 2�� 3�� �Ű������� ����
	Complex1 c3 = c1.add(c2);	// c1��ü�� c2��ü�� ���� ���ϴ� add�Լ��� ȣ�� �Ͽ� c3��ü�� ����
	 
	c1.display();				// c1 ��ü�� display �Լ��� ȣ��
	cout << " + ";				// + ���
	c2.display();				// c2 ��ü�� display �Լ� ȣ��
	cout << " = ";				// = ���
	c3.display();				// c3 ��ü�� display �Լ� ȣ��
	cout << endl;				// ���� ���

	c3 = c1.mul(10.0);			// 10.0���� �����ϸ� double �� 1���� �޴� Complex1��ü�� �ڵ����� �����Ǿ� mul �Լ��� ���ڷ� ��
	c1.display();				// c1��ü�� display �Լ��� ȣ��
	cout << " * 10 = ";			// * 10 = ���
	c3.display();				// c3 ��ü�� display �Լ� ȣ��
	cout << endl;				// ���� ���
	return 0;					// ���α׷� ����
}