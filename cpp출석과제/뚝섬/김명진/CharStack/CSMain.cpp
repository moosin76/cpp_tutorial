#include <iostream>						// 콘솔 입출력을 위한 해더파일 포함
#include "CharStack.h"					// CharStack 클래스를 사용하기 위한 해더파일 포함
using namespace std;					// 명칭공간 std 사용

int main()								// 프로그램 진입 main함수 정의
{
	CharStack chStack;					// 문자열을 저장할 수 있는 스택객체 선언
	char str[20];						// 문자를 입력받기 위한 배열 선언 

	cout << "영어 단어를 입력하시오 : ";	// 안내문 출력	
	cin >> str;							// 문자열을 입력받아 str배열에 저장

	char *pt = str;						// 포인터 pt를 선언하고 입력받은 문자열의 주소를 저장
	while (*pt)							// 문장열의 끝이 아니면 반복
		chStack.push(*(pt++));			// 스택에 문자를 넣고 포인터 pt를 1증가.

	cout << "역순 단어 출력 : ";			// 안내문 출력
	while (!chStack.chkEmpty())			// 스택이 비어 있지 않으면 반복
		cout << chStack.pop();			// 스택에서 하나씩 꺼내와 콘솔에 출력
	cout << endl;						// 개행 출력
	return 0;							// 프로그램 종료
}