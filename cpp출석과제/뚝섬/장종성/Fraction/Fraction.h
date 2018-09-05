#ifndef __FRACTION__
#define __FRACTION__

class Fraction
{
  int numerator; // ����
  int denominator; // �и�

public: 
  // ������
  Fraction(int numerator=1, int denominator=1);
  // �м��� ��ȣ�� �ٲٴ� ������ �ϴ� �Լ� conSign�� ��������
  Fraction conSign() const;
  // �ΰ��� �м��� ���������ϴ� �Լ� add�� ��������
  Fraction add(const Fraction& b) const;
  // �ΰ��� �м��� ���������ϴ� �Լ� subtract�� ��������
  Fraction subtract(const Fraction& b) const;
  // �ΰ��� �м��� ���������ϴ� �Լ� multiply�� ��������
  Fraction multiply(const Fraction& b) const;
  // �ΰ��� �м��� �����������ϴ� �Լ� devide�� ��������
  Fraction devide(const Fraction& b) const;
  // �м��� ����ϴ� �Լ� display ��������
  void display() const;

private: 
  // ���밪�� ��ȯ�ϴ� �ζ��� �Լ�
  inline int abs(int num) {
    return num < 0 ? -num : num; // �����̸� ��ȣ�� �ٲپ� ��ȯ
  }
  // �ΰ��� ���Ͽ� �������� ��ȯ�ϴ� �ζ��� �Լ�
  inline int minVal(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
  }
  // �ִ����� ���ϴ� �Լ�
  int GetGCD(int num1, int num2);
};

#endif