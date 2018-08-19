# 다중상속

둘 이상의 클래스를 동시에 상속하는 것을 다중상속 이라고 한다.

예를 들어 다음 예제는 Person, Student, Employee, PartTimeStudent 클래스로 구성되어 있습니다.  
다음과 그림과 같은 구조로 상속됩니다.

![다중상속 예제 구조](/images/multi_inheritance.svg)

## Person 클래스

순수가상함수를 포함하는 **추상클래스**입니다.

`Person.h`
```c
#ifndef __PERSON__
#define __PERSON__

class Person {
  char* name;
public:
  Person(const char* name);
  virtual ~Person();
  void sayName();
  virtual void whoAreYou() = 0; // 순수가상함수
};

#endif
```
`Person.cpp`
```c
#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;

Person::Person(const char* name) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  cout << "Person()" << endl;
}

Person::~Person() {
  delete[] name;
}

void Person::sayName() {
  cout << "이름 : " << name << endl;
};
```

## Student 클래스
Person 클래스를 상속하며 순수가상함수를 재정의(overriding)하는 **상세클래스**입니다.

`Student.h`

```c
#ifndef __STUDENT__
#define __STUDENT__

#include "Person.h"

class Student : public Person {
  char* school;
public:
  Student(const char*name, const char* school);
  virtual ~Student();
  void saySchool();
  virtual void whoAreYou();
};

#endif
```
`Student.cpp`
```c
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(const char*name, const char* school)
  : Person(name)
{
  this->school = new char[strlen(school) + 1];
  strcpy(this->school, school);
  cout << "Student()" << endl;
}

Student::~Student() {
  delete[] school;
}

void Student::saySchool() {
  cout << "학교 : " << school << endl;
}

void Student::whoAreYou() {
  sayName();
  saySchool();
}
```

## Employee 클래스

Person 클래스를 상속하며 순수가상함수를 재정의(overriding)하는 **상세클래스**입니다.

`Employee.h`
```c
#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include "Person.h"

class Employee : public Person {
  char* company;
public:
  Employee(const char*name, const char*company);
  virtual ~Employee();
  void sayCompany();
  virtual void whoAreYou();
};

#endif
```

`Employee.cpp`
```c
#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;

Employee::Employee(const char*name, const char*company)
  : Person(name)
{
  this->company = new char[strlen(company) + 1];
  strcpy(this->company, company);
  cout << "Employee()" << endl;
}

Employee::~Employee() {
  delete[] company;
}

void Employee::sayCompany() {
  cout << "회사 :" << company << endl;
}

void Employee::whoAreYou() {
  sayName();
  sayCompany();
}
```

## PartTimeStudent 클래스
Student 클래스와 Employee 클래스를 모두 상속하는 다중상속 구조의 클래스입니다.
이때 Person 클래스가 중복상속 됩니다.

`PartTimeStudent.h`
```c
#ifndef __PART_TIME_STUDENT__
#define __PART_TIME_STUDENT__

#include "Student.h"
#include "Employee.h"

class PartTimeStudent : public Student, public Employee {
public:
  PartTimeStudent(const char* name, const char*school, const char* company);
  virtual void whoAreYou();
};

#endif
```

`PartTimeStudent.cpp`
```c
#include "PartTimeStudent.h"
#include <iostream>
using namespace std;

PartTimeStudent::PartTimeStudent(const char* name, const char*school, const char* company)
  : Student(name, school), Employee(name, company) 
{
  cout << "PartTimeStudent()" << endl;
}

void PartTimeStudent::whoAreYou() {
  Student::sayName();
  saySchool();
  sayCompany();
}
```

### 중복상속
중복상속된 Person객체의 경우 `Student::name` 과 `Employee::name` 변수는 서로 다른 공간에 할당됩니다.  

`sayName()`함수 처럼 중복된 메서드가 있는 경우에도 실행이 모호하기 때문에 실행할 부모클래스를 명시하여 호출하여야 합니다.

## main함수

`main.cpp`
```c
#include <iostream>
using namespace std;

#include "PartTimeStudent.h"

int main() {
  cout << "객체 생성 순서" << endl;
  PartTimeStudent man1("남기용", "방송통신대", "이지코드");
  cout << "객체 생성 완료" << endl << endl;

  man1.whoAreYou();
  cout << endl;
  man1.Student::whoAreYou();
  cout << endl;
  man1.Employee::whoAreYou();
  return 0;
}
```

