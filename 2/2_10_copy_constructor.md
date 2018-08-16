# 복사생성자(Copy Constructor)

복사생성자는 같은 클래스의 객체를 복사하여 객체를 만드는 생성자이다.

## C++ 스타일의 초기화

우리는 지금까지 다음의 방식으로 변수를 초기화 했다.

```c
int num = 20;
int &ref = num;
```

c++ 에서는 다음과 같은 방식으로 변수의 초기화가 가능하다.

```c
int num(20);
int &ref(num);
```

두가지 초기화 방식은 결과적으로 동일하다.

## 기본 복사생성자

복사생성자를 명시적으로 선언하지 않으면 컴파일러는 객체의 멤버를 그대로 복사하여 객체를 생성하는 복사생성자를 자동으로 만든다.

```cpp
#include <iostream>
using namespace std;

class Point {
  int x;
  int y;
public:
  Point(int x = 0, int y = 0) : x(x), y(y) { }

  Point& setX(int x) {
    this->x = x;
    return *this;
  }

  Point& setY(int y) {
    this->y = y;
    return *this;
  }

  void show() {
    cout << "[" << x << "," << y << "]" << endl;
  }
};

int main() {
  Point p1(10, 50);
  Point p2 = p1; // 복사
  p1.setX(15).setY(35);
  cout << "p1 : ";
  p1.show();
  cout << "p2 : ";
  p2.show();
  return 0;
}
```

위의 코드에서 `Point p2 = p1` 을 다음의 코드로 바꿔도 같은 결과가 된다.

```c
Point p2(p1);
```

기본 복사생성자는 다음과 같은 형태이다.

```c
class ClassName {
  (...)

public :
  ClassName(const ClassName& copy) 
    : ( /* 초기화 리스트에서 모든 맴버 복사 */ ) 
  { }

  (...)
}
```

위의 코드에 복사생성자를 만들어 보면 다음과 같이 된다.

```c
Point(const Point& copy)  // 복사생성자
  : x(copy.x), y(copy.y) 
{
  cout << "복사생성자 호출" << endl;
}
```

# 깊은 복사와 얕은 복사

기본 복사생성자 처럼 모든 멤버를 각각 복사하는 방식을 얕은 복사라고 한다.  
다음 코드에서 얕은 복사의 문제점이 무엇인지 확인해 보자.

기존에 만들었었던 Person 클래스를 활용합니다.

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
  Person();
  ~Person();
  void showInfo() const;
  void setInfo(char*, int);
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

Person::Person() 
  : age(0)
{
  cout << "빈 객체 생성" << endl;
  name = NULL;
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

void Person::setInfo(char* myname, int myage) {
  name = myname;
  age = myage;
}
```

`main.cpp`
```c
#include <iostream>
#include "Person.h"
using namespace std;

int main() {
  Person man1("ki yong", 43);
  Person man2 = man1;
  man1.showInfo();
  man2.showInfo();
  return 0;
}
```

객체 소멸시 동적할당된 객체를 삭제할때 문제가 발생됩니다.

## 깊은복사 생성자 정의

다음과 같이 복사생성자를 정의합니다.

**Person.h**에서 복사생성자를 선언합니다.

```c
class Person {
(...)
public :
  Person(const Person& copy); // 복사생성자 선언

(...)
};

```

**Person.cpp**에서 복사생성자를 정의합니다.

```c
(...)

Person::Person(const Person& copy) 
  : age(copy.age)
{
  int len = strlen(copy.name) + 1;
  name = new char[len];
  strcpy(name, copy.name);
}

(...)
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)