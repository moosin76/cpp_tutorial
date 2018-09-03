# 함수 오버로딩(Function Overloading)

C 언어에서는 동일한 이름의 함수가 있다면 컴파일 에러가 발생합니다.  
C++에서는 함수의 기능이 확장되어 동일한 이름의 함수를 만들수 있습니다.

```cpp
#include <iostream>

int func(int num) {
  return num * 2;
}

int func(int num1, int num2) {
  return num1 + num2;
}

double func(double num) {
  return num / 2;
}

int main(void)
{
  std::cout << func(4) << std::endl;
  std::cout << func(5, 2) << std::endl;
  std::cout << func(8.7) << std::endl;
  return 0;
}
```
위의 실행결과를 보면   
`func(4)` 호출시 매개변수로 정수(int)자료형 1개를 매개변수로 받는 func함수를 호출하개 됩니다.  
`func(5, 2)` 호출시 매개변수로 정수(int)자료형 2개를 매개변수로 받는 func함수를 호출하개 됩니다.   
`func(8.7)` 호출시 매개변수로 실수(double)자료형 1개를 매개변수로 받는 func함수를 호출하개 됩니다.

함수호출시 전달되는 매개변수를 통해 호출하고자 함수의 구분이 가능합니다.
- 매개변수의 자료형
- 매개변수의 개수

**주의: 반환자료형은 호출되는 함수를 구분하는 기준이 될수 없습니다.**

# 자료형 추론

`auto`를 사용하면 변수를 선언할때 특정 데이터형을 지정하지 않아도 자동으로 자료형을 결정하게 된다.

```c
#include <iostream>

int func(int num) {
  return num * 2;
}

int func(int num1, int num2) {
  return num1 + num2;
}

double func(double num) {
  return num / 2;
}

int main(void)
{
  auto num1 = func(5, 2);
  auto num2 = func(8.7);

  std::cout << sizeof(num1) << std::endl;
  std::cout << sizeof(num2) << std::endl;
  return 0;
}
```
---
[목록으로](https://github.com/moosin76/cpp_tutorial)