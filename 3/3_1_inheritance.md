# 상속

어떤 클래스들의 공통적인 특성을 갖는 클래스를 **기초 클래스**라고 한다.  
**파생 클래스**는 기초 클래스의 모든 특성을 포함하며 고유의 특성도 갖을 수 있다.

- 기초클래스(base class)는 상위 클래스(superclass), 부모 클래스(parent class) 라고도 한다.
- 파생클래스(derived class)는 하위 클래스(subclass), 자식 클래스(child class) 라고도 한다.

![클래스의 상속](/images/inheitance.svg "클래스의 상속")

## 클래스의 상속의 선언

```c
class 파생클래스이름 : 가시성지시어 기초클래스이름 {
  (...)
}
```

# 클래스 상속 예제

Person 클래스와 Student클래스를 정의하고 메서드 재정의에 대해 알아보자

## Person 클래스
속성|설명|
---|---
char name[50] |  이름
int age | 나이

메서드|설명|
---|---
Person() | 생성자
setName() | 이름 초기화
whoAreYou() | 정보를 출력

`Person.h`
```c
#ifndef __PERSON__
#define __PERSON__

class Person
{
  char name[50];
  int age;
public:
  Person(const char* name, int age);
  void setName(const char* name);
  void whoAreYou() const;
};

#endif
```

`Person.cpp`
```c
#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;

Person::Person(const char* name, int age)
  : age(age)
{
  strcpy(this->name, name);
}

void Person::setName(const char* name) {
  strcpy(this->name, name);
}

void Person::whoAreYou() const {
  cout << "이름 : " << name << endl;
  cout << "나이 : " << age << endl;
}
```

`main.cpp`
```c
#include <iostream>
#include "Person.h"
using namespace std;

int main() {
  Person man1("남기용", 43);
  man1.whoAreYou();
  cout << endl;
  return 0;
}
```

## Student 클래스
속성|설명|
---|---
char school[50] |  학교

메서드|설명|
---|---
Student() | 생성자
setSchool() | 학교명 초기화
whoAreYou() | 정보를 출력

`Student.h`

```c
#ifndef __STUDENT__
#define __STUDENT__
#include "Person.h" // 부모 클래스 포함

class Student : public Person
{
  char school[50];
public:
  Student(const char* name, int age, const char* school);
  void setSchool(const char* school);
  void whoAreYou() const;
};

#endif
```

`Student.cpp`
```c
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(const char* name, int age, const char* school)
  : Person(name, age) // 부모 클래스의 생성자 호출
{
  strcpy(this->school, school);
}

void Student::setSchool(const char* school) {
  strcpy(this->school, school);
}

void Student::whoAreYou() const {
  Person::whoAreYou(); // 부모클래스의 whoAreYou메서드 호출
  cout << "학교 : " << school << endl;
}
```

`main.cpp`

```c
#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

int main() {
  Person man1("남기용", 43);
  man1.whoAreYou();
  cout << endl;

  Student man2("서용준", 22, "방송통신대학교");
  man2.whoAreYou();
  cout << endl;

  man2.setName("유빈");
  man2.setSchool("서울대학교");
  man2.whoAreYou();
  return 0;
}
```
## 메서드 재정의(overriding)
위의 예제에서처럼 기초클래스에도 whoAreYou 메서드가 있고, 파생클래스에도 whoAreYou 메서드가 있는데
이렇게 파생 클래스에서 기초 클래스의 메서드와 동일한 이름, 동일한 매개변수, 반환자료형을 갖는 메서드를 정의하는 것을 메서드 **재정의**(overriding)라고 한다.

동일한 이름이어도 매개변수의 개수 또는 자료형이 다르다면 그것은 재정의가 아닌 **다중정의**(overloading)이다



