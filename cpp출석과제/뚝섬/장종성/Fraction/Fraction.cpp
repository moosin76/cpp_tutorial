#include <iostream>		// 콘솔 입출력을 위한 해더파일 포함
#include "Fraction.h"	// Bunsu 클래스를 사용하기 위한 해더파일 포함
using namespace std;	// 명칭공간 std 사용

// 두개의 정수를 매개변수로 받는 생성자
Fraction::Fraction(int numerator, int denominator) {
  // 분모가 0일경우
  if (denominator == 0) {
    cout << "분모는 0이 될수 없습니다." << endl; // 오류메시지 출력
    exit(1); // 프로그램 종료
  }
  // -기호는 항상 분자에서 가지게 된다
  if (denominator < 0) { // 분모가 음수일 경우	
    numerator = -numerator; // 분자 기호 바꿈
    denominator = -denominator; // 분모 기호 바꿈
  }

  int gcd = GetGCD(abs(numerator), denominator);	// 기약분수로 저장하기 위해 최대공약수를 얻어온다
  this->numerator = numerator / gcd;		// 분자를 최대공약수로 나누어 저장
  this->denominator = denominator / gcd;		// 분모를 최대공약수로 나누어 저장
}

// 분수의 기호를 바꾸는 연산을 하는 함수 conSign 정의
Fraction Fraction::conSign() const {
  return Fraction(-numerator, denominator); // 분자의 기호를 바꾸어 분수를 반환
}

// 두개의 분수를 덧셈연산하는 함수 add 정의
Fraction Fraction::add(const Fraction& b) const {
  int n = numerator * b.denominator + b.numerator * denominator; // 통분하여 분자끼리 덧셈연산 
  return Fraction(n, denominator*b.denominator); // 통분한 분모로 새분수를 생성하여 반환
}

// 두개의 분수를 뺄셈연산하는 함수 subtract 정의
Fraction Fraction::subtract(const Fraction& b) const {
  int n = numerator * b.denominator - b.numerator * denominator; // 통분하여 분자끼리 뺄셈연산 
  return Fraction(n, denominator*b.denominator); // 통분한 분모로 새분수를 생성하여 반환
}

// 두개의 분수를 곱셈연산하는 함수 multiply 정의
Fraction Fraction::multiply(const Fraction& b) const {
  // 분자끼리 분모끼리 곱하여 Bunsu를 생성하여 반환
  return Fraction(numerator * b.numerator, denominator*b.denominator);
}

// 두개의 분수를 나눗셈연산하는 함수 devide 정의
Fraction Fraction::devide(const Fraction& b) const {
  Fraction temp(b.denominator, b.numerator);	// b의 분자 분모 위치를 바꾼 temp분수 생성
  return this->multiply(temp); // 현재 객체와 곱하기 연산을 수행한 분수를 반환
}
// 분수를 출력하는 함수 display 정의
void Fraction::display() const {
  cout << "(";				// ( 출력
  cout << numerator;				// 분자를 출력
  if (denominator != 1)				// 분모가 1이 아니면
    cout << "/" << denominator;		// 분모를 출력
  cout << ")";				// ) 출력
}

// 최대공약수 구하는 함수 
int Fraction::GetGCD(int num1, int num2) {
  int temp = minVal(num1, num2); // 작은값
  // 두수 어떤 작은값으로 나누었을때 둘다 0이면 최대공약수
  while (num1%temp != 0 || num2 % temp != 0) { // 둘다 0이 되지 않으면 
    temp--; // temp를 1씩 줄여가며 최대 공약수를 찾는다.
  }
  return temp; // 최대 공약수 반환
}