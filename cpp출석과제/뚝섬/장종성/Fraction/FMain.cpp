#include <iostream>			// 콘솔 입출력을 위한 해더파일 포함
#include "Fraction.h"			// Fraction 클래스를 사용하기 위한 해더파일 포함
using namespace std;			// 명칭공간 std 사용

int main() {				// 프로그램 진입 main함수 정의
  Fraction su1(5, -15);		// 5/-15를 su1객체에 저장 기약분수가 되면 –1/3
  Fraction su2(4, 10);		// 4/10을 su12객체에 저장 기약분수가 되면 2/5
  Fraction su3;			// 연산하여 저장할 객체 su3 선언

  su3 = su1.add(su2);		// su1 + su2 계산하여 s3에 저장
  su1.display();			// su1객채를 출력
  cout << " + ";			// + 출력
  su2.display();			// su2객채를 출력
  cout << " = ";			// = 출력
  su3.display();			// su3객채를 출력
  cout << endl;			// 개행 출력

  su3 = su1.subtract(su2);	        // su1 - su2 계산하여 s3에 저장
  su1.display();			// su1객채를 출력
  cout << " - ";			// - 출력
  su2.display();			// su2객채를 출력
  cout << " = ";			// = 출력
  su3.display();			// su3객채를 출력
  cout << endl;			// 개행 출력

  su3 = su1.multiply(su2);	        // su1 * su2 계산하여 s3에 저장
  su1.display();			// su1객채를 출력
  cout << " * ";			// * 출력
  su2.display();			// su2객채를 출력
  cout << " = ";			// = 출력
  su3.display();			// su3객채를 출력
  cout << endl;			// 개행 출력

  su3 = su1.devide(su2);		// su1 / su2 계산하여 s3에 저장
  su1.display();			// su1객채를 출력
  cout << " / ";			// / 출력
  su2.display();			// su2객채를 출력
  cout << " = ";			// = 출력
  su3.display();			// su3객채를 출력
  cout << endl;			// 개행 출력

  su3 = su1.conSign();		// su1 객체의 부호를 변경하여 su3에 저장
  su1.display();			// su1객채를 출력
  cout << " 부호변경 : ";		// 문자열 출력
  su3.display();			// su3객체 출력
  cout << endl;			// 개행 출력
  return 0;			// 프로그램 종료
}