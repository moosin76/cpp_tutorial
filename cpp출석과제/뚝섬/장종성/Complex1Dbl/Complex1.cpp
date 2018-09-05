#include <iostream>				// �ܼ� ������� ���� �ش����� ����
#include "Complex1.h"			// Complex1 Ŭ���� ����� ���� �ش����� ����
using namespace std;			// std ��Ī������ ���

//�������� ���ϱ� ������ �ϴ� �Լ� mul ����. 
Complex1 Complex1::mul(const Complex1 &c) const 
{
	// ���Ҽ��� ���ϱ� ������ ����
	double r = rPart * c.rPart - iPart * c.iPart;	
	double i = rPart * c.iPart - iPart * c.rPart;
	return Complex1(r, i);	//���� ������ ��ü�� ��ȯ.						
}

//�������� ������ ������ �ϴ� �Լ� div ����.
Complex1 Complex1::div(const Complex1 &c) const 
{
	// ���Ҽ��� ������ ������ ����
	double d = c.rPart * c.rPart + c.iPart * c.iPart;	
	Complex1 c1 = mul(c.conj());
	return Complex1(c1.rPart / d, c1.iPart / d); //���� ������ ��ü�� ��ȯ.
}

// ���Ҽ� ���� ����ϴ� �Լ� display ����.
void Complex1::display() const		
{
	cout << "(" << rPart;			// ( �� rPart ���� ���
	if (iPart > 0)					// iPart ���� ����̸�
		cout << "+j" << iPart;		// +j �� iPart ���� ���
	else if (iPart < 0)				// iPart ���� �����̸�
		cout << "-j" << -iPart;		// -j �� iPart ���� ���
	cout << ")";					// ) ���
}
