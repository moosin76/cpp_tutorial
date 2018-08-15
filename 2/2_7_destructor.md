# 소멸자(destructor)
소멸자는 객체 소멸시 자동으로 호출되는 함수입니다.  
소멸자는 다음의 특징을 갖습니다.

- 소멸자의 이름은 클래스와 같고 앞에 ~가 붙는다.
- 소멸자는 반환자료형이 없고, `return` 명령으로 값을 반환할 수 없다.
- 소멸자는 매개변수가 없다.
- 소멸자는 다중정의(함수오버로딩) 할 수 없으며 클래스에 단 하나만 정의한다.
- 소멸자는 일반적으로 public 멤버로 선언한다.
- 상속으로 통해 파생클래스에 정의하는 경우 `virtual`을 지정하여 가상함수가 되도록 하는것이 좋다

### 생성자의 기본적인 선언 형식

```c
class ClassName {
  (...)

public: 
  ~ClassName() { (...) } // 소멸자 함수
  
  (...)
};
```

소멸자 함수는 이러한 특징 때문에 일반적으로 클래스에서 동적할당된 멤버 변수가 있다면 이때 같이 제거하는게 일반적이다.

# Person 클래스 
이름과 나이를 갖으며 생성시 전달받은 문자열을 그 길이만큼 동적할당하여 저장한다.

## Pserson 클래스 속성

속성 | 설명
---|---
char* name | 이름
int age | 나이

## Pserson 클래스 메서드

속성 | 설명
---|---
Person | 생성자
~Person | 소멸자
showMe | 이름과 나이를 출력

`Person.h`
```c
#ifndef __PERSON__
#define __PERSON__

class Person
{
  char* name;
  int age;
public:
  Person(const char*, int);
  ~Person();
  void showInfo() const;
};

#endif
```

`Person.cpp`
```c
#include <iostream>
#include "Person.h"
#include <cstring>
using namespace std;

Person::Person(const char* myname, int myage)
  : age(myage)
{
  int len = strlen(myname) + 1;
  name = new char[len];
  strcpy(name, myname);
}


Person::~Person()
{
  cout << name << " 객체 소멸" << endl;
  delete[] name;
}

void Person::showInfo() const {
  cout << "이름 : " << name << endl;
  cout << "나이 : " << age << endl;
}
```

`main.cpp`
```c
#include <iostream>
using namespace std;
#include "Person.h"

int main() {
  Person p1("ki yong", 43);
  Person p2("yoo bin", 22);
  p1.showInfo();
  p2.showInfo();
  return 0;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)