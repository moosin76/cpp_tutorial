#include <iostream>				// 콘솔 입출력을 위한 해더파일 포함
#include "Complex1.h"			// Complex1 클래스 사용을 위한 해더파일 포함
using namespace std;			// std 명칭공간을 사용

int main()						// 프로그램 진입 main함수 정의
{
	Complex1 c1(1, 2);			// c1이라는 객체 선언하고 1과 2를 매개변수로 전달
	Complex1 c2(2, 3);			// c2이라는 객체 선언하고 2와 3을 매개변수로 전달
	Complex1 c3 = c1.add(c2);	// c1객체와 c2객체의 값을 더하는 add함수를 호출 하여 c3객체에 대입
	 
	c1.display();				// c1 객체의 display 함수를 호출
	cout << " + ";				// + 출력
	c2.display();				// c2 객체의 display 함수 호출
	cout << " = ";				// = 출력
	c3.display();				// c3 객체의 display 함수 호출
	cout << endl;				// 개행 출력

	c3 = c1.mul(10.0);			// 10.0값을 전달하면 double 값 1개를 받는 Complex1객체가 자동으로 생성되어 mul 함수의 인자로 됨
	c1.display();				// c1객체의 display 함수를 호출
	cout << " * 10 = ";			// * 10 = 출력
	c3.display();				// c3 객체의 display 함수 호출
	cout << endl;				// 개행 출력
	return 0;					// 프로그램 종료
}