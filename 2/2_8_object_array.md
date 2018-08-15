# 객체 배열
앞서 만든 Person 객체는 생성시 이름과 나이를 입력받았다.  
Person 객체를 배열로 생성하게 되면 다음과 같은 형식이 될것이다

```c
Person arr[10];
// 또는
Person* pArr = new Person[10];
```

이러한 형태로 선언하려면 이에 맞는 생성자가 있어야 한다.  
Person 객체에 매개변수를 받지 않는 객체를 선언하고, 이름과 나이를 설정하는 함수를 만들어보자.

추가 메서드
 - Person() : 매개변수를 받지 않는 생성자
 - setInfo(char* name, int age) : 이름과 나이를 전달받아 저장

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
  Person(); // 매개변수가 없는 생성자 추가
  ~Person();
  void showInfo() const;
  void setInfo(char*, int); // 이름과 나이를 세팅하는 함수 추가
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

### 객체 배열 사용 예제
`main.cpp`

```c
#include <iostream>
using namespace std;
#include "Person.h"
#include <cstring>

int main() {
  Person arr[3]; // Person 객체 배열
  char name[100]; // 이름을 입력받기 위한 변수
  int age; // 나이 입력
  char *pName; // 동적할당하고 가리킬 포인터
  int len; // 동적할당 길이정보 
  
  cout << "***** 정보 입력" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "이름 : ";
    cin >> name;
    cout << "나이 : ";
    cin >> age;
    len = strlen(name) + 1;
    pName = new char[len]; // 동적할당
    strcpy(pName, name);
    arr[i].setInfo(pName, age);
  }

  cout << endl << "***** 입력받은 배열 출력" << endl;
  for (int i = 0; i < 3; i++) {
    arr[i].showInfo();
  }

  return 0;
}
```

### 객체 포인터 배열 사용예제

Person 객체는 같고 `main.cpp`만 변경됩니다. 

`main.cpp`

```c
#include <iostream>
using namespace std;
#include "Person.h"
#include <cstring>

int main() {
  Person* arr[3]; // Person객체 포인터 배열
  char name[100];
  int age;

  cout << "***** 정보 입력" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "이름 : ";
    cin >> name;
    cout << "나이 : ";
    cin >> age;
    arr[i] = new Person(name, age); // 동적할당
  }

  cout << endl << "***** 입력받은 배열 출력" << endl;
  for (int i = 0; i < 3; i++) {
    arr[i]->showInfo();
  }

  cout << endl << "***** 동적할당받은 객체 소멸" << endl;
  for (int i = 0; i < 3; i++) {
    delete arr[i];
  }

  return 0;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)