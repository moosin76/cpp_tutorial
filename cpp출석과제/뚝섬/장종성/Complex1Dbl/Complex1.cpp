#include <iostream>				// 콘솔 입출력을 위한 해더파일 포함
#include "Complex1.h"			// Complex1 클래스 사용을 위한 해더파일 포함
using namespace std;			// std 명칭공간을 사용

//복수수의 곱하기 연산을 하는 함수 mul 정의. 
Complex1 Complex1::mul(const Complex1 &c) const 
{
	// 복소수의 곱하기 연산을 진행
	double r = rPart * c.rPart - iPart * c.iPart;	
	double i = rPart * c.iPart - iPart * c.rPart;
	return Complex1(r, i);	//새로 생성된 객체를 반환.						
}

//복수수의 나누기 연산을 하는 함수 div 정의.
Complex1 Complex1::div(const Complex1 &c) const 
{
	// 복소수의 나누기 연산을 진행
	double d = c.rPart * c.rPart + c.iPart * c.iPart;	
	Complex1 c1 = mul(c.conj());
	return Complex1(c1.rPart / d, c1.iPart / d); //새로 생성된 객체를 반환.
}

// 복소수 값을 출력하는 함수 display 정의.
void Complex1::display() const		
{
	cout << "(" << rPart;			// ( 와 rPart 값을 출력
	if (iPart > 0)					// iPart 값이 양수이면
		cout << "+j" << iPart;		// +j 와 iPart 값을 출력
	else if (iPart < 0)				// iPart 값이 음수이면
		cout << "-j" << -iPart;		// -j 와 iPart 값을 출력
	cout << ")";					// ) 출력
}
