#ifndef __FRACTION__
#define __FRACTION__

class Fraction
{
  int numerator; // 분자
  int denominator; // 분모

public: 
  // 생성자
  Fraction(int numerator=1, int denominator=1);
  // 분수의 기호를 바꾸는 연산을 하는 함수 conSign의 원형선언
  Fraction conSign() const;
  // 두개의 분수를 덧셈연산하는 함수 add의 원형선언
  Fraction add(const Fraction& b) const;
  // 두개의 분수를 뺄셈연산하는 함수 subtract의 원형선언
  Fraction subtract(const Fraction& b) const;
  // 두개의 분수를 곱셈연산하는 함수 multiply의 원형선언
  Fraction multiply(const Fraction& b) const;
  // 두개의 분수를 나눗셈연산하는 함수 devide의 원형선언
  Fraction devide(const Fraction& b) const;
  // 분수를 출력하는 함수 display 원형선언
  void display() const;

private: 
  // 절대값을 반환하는 인라인 함수
  inline int abs(int num) {
    return num < 0 ? -num : num; // 음수이면 부호를 바꾸어 반환
  }
  // 두값을 비교하여 작은값을 반환하는 인라인 함수
  inline int minVal(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
  }
  // 최대공약수 구하는 함수
  int GetGCD(int num1, int num2);
};

#endif