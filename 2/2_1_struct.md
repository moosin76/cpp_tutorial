# C++에서 구조체

구조체란 하나이상의 자료형을 묶어서 새로운 자료형으로 정의하여 사용하는 자료형입니다.  
C언어의 구조체는 데이터만 정의할 수 있지만, C++에서는 데이터와 함수를 함께 정의할 수 있다.

다음은 구조체를 이용해 카운터를 만들어본다

`main.cpp`

```c
#include <iostream>
using namespace std;

typedef struct _counter {
  int value;
  
  void reset() {
    value = 0;
  }
  void count() {
    value++;
  }
  int getValue() {
    return value;
  }
} Counter;

int main() {
  Counter counter = { 0 }; // 생성시 0으로 초기화
  counter.count(); // 1증가
  counter.count();
  cout << counter.getValue() << endl; // 현재값 출력
  counter.count();
  counter.count();
  cout << counter.getValue() << endl;
  counter.reset(); // 0 으로 초기화
  cout << counter.getValue() << endl;
  return 0;
}
```

위의 구조체의 함수를 선언부와 정의부로 구분하여 작성할 수 있다.

`main.cpp`

```c
#include <iostream>
using namespace std;

typedef struct _counter {
  int value;
  void reset();
  void count();
  int getValue();
} Counter;

void Counter::reset() {
  value = 0;
}
void Counter::count() {
  value++;
}
int Counter::getValue() {
  return value;
}

(...)
```

이렇게 구분하여 작성하는 것은 헤더파일과 소스코드로 구분하여 작성할 수 있다.

- Couner.h : 카운터 구조체 정보를 가지고 있는 헤더파일
- Counter.cpp : 카운터 구조체의 함수들을 정의하는 소스파일
- main.cpp : main 함수를 작성하는 프로그램 진입 파일

`Counter.h`

```c
#ifndef __COUNTER_H__
#define __COUNTER_H__

typedef struct _counter {
  int value;
  void reset();
  void count();
  int getValue();
} Counter;

#endif
```

`Counter.cpp`

```c
#include "Counter.h"

void Counter::reset() {
  value = 0;
}
void Counter::count() {
  value++;
}
int Counter::getValue() {
  return value;
}
```

`main.cpp`

```c
#include <iostream>
#include "Counter.h"
using namespace std;

int main() {
  Counter counter = { 0 }; // 생성시 0으로 초기화
  counter.count(); // 1증가
  counter.count();
  cout << counter.getValue() << endl; // 현재값 출력
  counter.count();
  counter.count();
  cout << counter.getValue() << endl;
  counter.reset(); // 0 으로 초기화
  cout << counter.getValue() << endl;
  return 0;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)

