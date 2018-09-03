#include <iostream>				// 콘솔 입출력을 위한 해더파일 포함
#include "CharStack.h"			// CharStack 클래스를 사용하기 위한 해더파일 포함
using namespace std;			// 명칭공간 std 사용

bool CharStack::push(char ch)	// 스택에 데이터 삽입을 위한 push 함수의 정의
{
	if (chkFull()) {			// 스택이 가득차있다면
		cout << "스택이 가득 차 있습니다." << endl; // 메시지 출력
		return false;			// 데이터를 넣지 않았음으로 false를 반환
	}
	buf[--top] = ch;			// 먼저 top의 값을 1 감소 후 buf의 top 위치에 ch를 저장
	return true;				// 데이터를 넣었음으로 true를 반환
}

char CharStack::pop()			// 스택에서 데이터를 꺼내올 pop함수의 정의
{
	if (chkEmpty()) {			// 스택에 데이터가 없다면
		cout << "스택에 데이터가 없습니다." << endl;	// 메시지 출력
		return 0;				// 데이터가 없음으로 0을 반환
	}
	return buf[top++];			// buf의 top위치에 값을 반환하고 top을 1증가
}