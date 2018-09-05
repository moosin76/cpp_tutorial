#include <iostream>		// �ܼ� ������� ���� �ش����� ����
#include "Fraction.h"	// Bunsu Ŭ������ ����ϱ� ���� �ش����� ����
using namespace std;	// ��Ī���� std ���

// �ΰ��� ������ �Ű������� �޴� ������
Fraction::Fraction(int numerator, int denominator) {
  // �и� 0�ϰ��
  if (denominator == 0) {
    cout << "�и�� 0�� �ɼ� �����ϴ�." << endl; // �����޽��� ���
    exit(1); // ���α׷� ����
  }
  // -��ȣ�� �׻� ���ڿ��� ������ �ȴ�
  if (denominator < 0) { // �и� ������ ���	
    numerator = -numerator; // ���� ��ȣ �ٲ�
    denominator = -denominator; // �и� ��ȣ �ٲ�
  }

  int gcd = GetGCD(abs(numerator), denominator);	// ���м��� �����ϱ� ���� �ִ������� ���´�
  this->numerator = numerator / gcd;		// ���ڸ� �ִ������� ������ ����
  this->denominator = denominator / gcd;		// �и� �ִ������� ������ ����
}

// �м��� ��ȣ�� �ٲٴ� ������ �ϴ� �Լ� conSign ����
Fraction Fraction::conSign() const {
  return Fraction(-numerator, denominator); // ������ ��ȣ�� �ٲپ� �м��� ��ȯ
}

// �ΰ��� �м��� ���������ϴ� �Լ� add ����
Fraction Fraction::add(const Fraction& b) const {
  int n = numerator * b.denominator + b.numerator * denominator; // ����Ͽ� ���ڳ��� �������� 
  return Fraction(n, denominator*b.denominator); // ����� �и�� ���м��� �����Ͽ� ��ȯ
}

// �ΰ��� �м��� ���������ϴ� �Լ� subtract ����
Fraction Fraction::subtract(const Fraction& b) const {
  int n = numerator * b.denominator - b.numerator * denominator; // ����Ͽ� ���ڳ��� �������� 
  return Fraction(n, denominator*b.denominator); // ����� �и�� ���м��� �����Ͽ� ��ȯ
}

// �ΰ��� �м��� ���������ϴ� �Լ� multiply ����
Fraction Fraction::multiply(const Fraction& b) const {
  // ���ڳ��� �и𳢸� ���Ͽ� Bunsu�� �����Ͽ� ��ȯ
  return Fraction(numerator * b.numerator, denominator*b.denominator);
}

// �ΰ��� �м��� �����������ϴ� �Լ� devide ����
Fraction Fraction::devide(const Fraction& b) const {
  Fraction temp(b.denominator, b.numerator);	// b�� ���� �и� ��ġ�� �ٲ� temp�м� ����
  return this->multiply(temp); // ���� ��ü�� ���ϱ� ������ ������ �м��� ��ȯ
}
// �м��� ����ϴ� �Լ� display ����
void Fraction::display() const {
  cout << "(";				// ( ���
  cout << numerator;				// ���ڸ� ���
  if (denominator != 1)				// �и� 1�� �ƴϸ�
    cout << "/" << denominator;		// �и� ���
  cout << ")";				// ) ���
}

// �ִ����� ���ϴ� �Լ� 
int Fraction::GetGCD(int num1, int num2) {
  int temp = minVal(num1, num2); // ������
  // �μ� � ���������� ���������� �Ѵ� 0�̸� �ִ�����
  while (num1%temp != 0 || num2 % temp != 0) { // �Ѵ� 0�� ���� ������ 
    temp--; // temp�� 1�� �ٿ����� �ִ� ������� ã�´�.
  }
  return temp; // �ִ� ����� ��ȯ
}