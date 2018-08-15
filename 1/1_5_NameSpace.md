# 이름공간(namespace)
특정 영역에 이름을 붙여주기 위한 문법적 요소이다.  
`::` (범위지정연산자)를 이용해 접근합니다.

```c
#include <iostream>

namespace space {
  int num = 1;
  void func() {
    std::cout << "space의 num : " << num << std::endl;
  }
}

namespace otherSpace {
  int num = 2;
  void func() {
    std::cout << "otherSpace의 num : " << num << std::endl;
  }
}

int main(void)
{
  space::func();
  otherSpace::func();
  return 0;
}
```

# 이름공간 함수의 선언부와 정의를 구분하기
```c
#include <iostream>

namespace space {
  int num = 1;
  void func();
}

namespace otherSpace {
  int num = 2;
  void func();
}

int main(void)
{
  space::func();
  otherSpace::func();
  return 0;
}

void space::func() {
  std::cout << "space의 num : " << num << std::endl;
}

void otherSpace::func() {
  std::cout << "otherSpace의 num : " << num << std::endl;
}
```

# 이름공간의 중첩
```c
#include <iostream>

namespace space {
  void func();
  
  namespace otherSpace {
    void func();
  }
}

int main(void)
{
  space::func();
  space::otherSpace::func();
  return 0;
}

void space::func() {
  std::cout << "space의 func 호출" << std::endl;
}

void space::otherSpace::func() {
  std::cout << "space::otherSpace의 func호출" << std::endl;
}
```

# using 명령을 사용하여 이름공간 명시
`std`는 C++ 표준라이브러리의 이름공간입니다.  
지금까지 `std::cout`, `std::cin`, `std:endl` 처럼 객체에 접근할때 `::`를 써서 접근하였는데 std처럼 자주 쓰이는 것은 `using` 명령을 통행 **기본 이름공간으로 지정**할수 있습니다.
```c
#include <iostream>
using namespace std; // std 이름공간을 기본 이름공간으로 지정

int main(void)
{
  char name[100];
  cout << "이름을 입력하세요 : ";
  cin >> name;
  cout << name << "님 안녕하세요." << endl;
  return 0;
}
```

# ::(범위지정연산자)의 또다른 기능

범위지정 연산자를 이용하여 전역변수에 접근할 수 있습니다.

```c
#include <iostream>
using namespace std;

int val = 100; // 전역변수

int main(void)
{
  int val = 20;
  cout << val << endl; // 지역변수 출력
  cout << ::val << endl; // 전역변수 출력
  return 0;
}
```
---
[목록으로](https://github.com/moosin76/cpp_tutorial)