#ifndef CHARSTACK_H_INCLUDED	// CHARSTACK_H_INCLUDED 가 정의되지 않았으면 #endif 까지 컴파일.
#define CHARSTACK_H_INCLUDED	// 중복하여 컴파일 되지 않게 하기 위해 CHARSTACK_H_INCLUDED를 정의

class CharStack {			// CharStack 클래스 정의
  enum { size = 20 };	// 스택의 크기를 지정 할 상수 size를 선언 및 초기화
  int top;					  // 스택의 데이터 위치를 가리키는 변수 top 선언
  char buf[size];			// 스택의 데이터를 저장할 배열
public:
  CharStack()					// 생성자로서 클래스명과 같고 반환형이 없음.
  {
    top = size;				// top을 size값으로 초기화
  }
  bool chkEmpty() const	// 스택의 데이터가 비어있는지 검사하는 함수로 내부에서 멤버의 값 변경을 허용하지 않음
  {
    return top == size;	// top과 size의 값이 값으면 데이터가 없음으로 true를 반환
  }
  bool chkFull() const  // 스택에 데이터가 가득 차있는 검사하는 함수로 내부에서 멤버의 값 변경을 허용하지 않음
  {
    return !top;			  // 스택에 데이터가 모두차면 top은 0 이기 때문에 ! 연산으로 true를 반환
  }
  bool push(char ch);	  // 스택에 데이터 삽입을 위한 함수 push 원형 선언
  char pop();					  // 스택에서 데이터를 꺼내올 함수 pop의 원형 선언
};
#endif