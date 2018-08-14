# 매개변수의 기본값(Default Value)
함수호출시 매개변수에 기본값을 지정합니다.

```cpp
#include <iostream>

int func(int num1 = 2, int num2 = 3) {
	return num1 * num2;
}

int main(void)
{
  std::cout << func() << std::endl; // 2, 3 전달
  std::cout << func(4) << std::endl; // 4, 3 전달
  std::cout << func(4, 4) << std::endl; // 4, 4 전달
  return 0;
}
```
- 기본값은 매개변수의 오른쪽부터 채워야 합니다.
- 기본값은 함수의 선언부에만 표현하면 됩니다.
```cpp
#include <iostream>

// 함수의 원형 선언
int func(int num1 = 2, int num2 = 3);

int main(void)
{
  std::cout << func() << std::endl; // 2, 3 전달
  std::cout << func(4) << std::endl; // 4, 3 전달
  std::cout << func(4, 4) << std::endl; // 4, 4 전달
  return 0;
}

// 함수의 정의
int func(int num1, int num2) {
  return num1 * num2;
}
```
---
[목록으로](https://github.com/moosin76/cpp_tutorial)