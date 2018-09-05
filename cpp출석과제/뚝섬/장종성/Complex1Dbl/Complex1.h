#ifndef COMPLEX1_H_INCLUDED     // COMPLEX1_H_INCLUDED 가 정의되지 않았으면 #endif 까지 컴파일.
#define COMPLEX1_H_INCLUDED		// 중복하여 컴파일 되지 않게 하기 위해 COMPLEX1_H_INCLUDED를 정의

// 클래스 Complex1 정의
class Complex1					
{
	// 실수부 및 허수부 
	double rPart, iPart;		
public:	// 아래의 멤버는 가시성 지시어 public으로 선언
	// 생성자 실수부를 r 허수부를 i로 초기화
	Complex1(double r = 0, double i = 0) :rPart(r), iPart(i) {} 
	// 허수부의 부호를 바꾸는 함수
	Complex1 conj() const						
	{
		// 허수부의 부호를 바꿔 객체를 새로 생성하여 반환
		return Complex1(rPart, -iPart);			
	}
	// 복소수의 더하기 연산을 하는 함수
	Complex1 add(const Complex1 &c) const		
	{
		// 복소수의 더하기 연산을 진행한 값으로 객체를 생성하여 반환
		return Complex1(rPart + c.rPart, iPart + c.iPart);	
	}
	// 복소수의 빼기 연산을 하는 함수
	Complex1 sub(const Complex1 &c) const		
	{
		// 복소수의 빼기 연산을 진행한 값으로 객체를 생성하여 반환
		return Complex1(rPart - c.rPart, iPart - c.iPart);	
	}
	// 복수수의 곱하기 연산을 하는 함수 mul의 원형 선언
	Complex1 mul(const Complex1 &c) const;
	// 복소수의 나누기 연산을 하는 함수 div의 원형 선언
	Complex1 div(const Complex1 &c) const;
	// 복소수 값을 출력하는 함수 display의 원형 선언
	void display() const;						
};
#endif