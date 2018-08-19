# 객체포인터 변수

기초 클래스의 포인터 변수는 파생클래스의 객체도 가리킬 수 있다.

다음 Person 클래스, Student 클래스, PartTimeStudent 클래스가 있다.

```c
class Person {
  (...)
}

class Student : public Person {
  (...)
}

class PartTimeStudent : public Student {
  (...)
}
```

이때 Person 객체의 포인터가 Student객체와 PartTimeStudent객체를 가리킬수 있다.

```c
Person *ptr = new Student();
Person *ptr2 = new PartTimeStudent();
```

C++에서는 기초 클래스의 포인터 변수는 기초 클래스 및 기초클래스를 직접 또는 간접적으로 상속하는 모든 객체를 가리킬 수 있다.


```c
#include <iostream>
using namespace std;

class Person {
public:
  void sleep() {
    cout << "잠을 잡니다." << endl;
  }
  void whoAreYou() {
    cout << "나는 사람입니다." << endl;
  }
};

class Student :public Person
{
public:
  void study() {
    cout << "공부를 합니다." << endl;
  }
  void whoAreYou() {
    cout << "나는 학생입니다." << endl;
  }
};

class PartTimeStudent : public Student
{
public:
  void work() {
    cout << "일을 합니다." << endl;
  }
  void whoAreYou() {
    cout << "나는 근로학생입니다." << endl;
  }
};

int main() {
  Person* man1 = new Person;
  Person* man2 = new Student;
  Person* man3 = new PartTimeStudent;

  cout << "Person ::" << endl;
  man1->whoAreYou();
  man1->sleep();
  cout << endl;
  
  cout << "Student ::" << endl;
  man2->whoAreYou();
  man2->sleep();
  // man2->study(); // 컴파일 에러
  cout << endl;

  cout << "PartTimeStudent ::" << endl;
  man3->whoAreYou();
  man3->sleep();
  // man3->study(); // 컴파일 에러
  // man3->work(); // 컴파일 에러
  cout << endl;
  return 0;
}
```

예제에서는 whoAreYou() 메서드를 재정의(overriding) 하였다 
실제 객체가 Student 이거나 PartTimeStudent 클래스 라고 해도 Person 객체 포인터 변수로 가리키는 경우에는 Person객체의 맴버에만 접근이 가능하다.

# 가상함수(virtual function)

## 정적 연결
위의 예제의 whoAreYou() 메서드 처럼 **객체포인터의 유형에 따라 호출 되는 함수가 결정**된다.  
이러한 경우를 **정적 연결**(static binding)이라고 한다.

위 예제에서 main함수의 내용을 다음과 같이 변경해보자.

```c
(...)

int main() {
  Person* man1 = new PartTimeStudent;
  Student* man2 = new PartTimeStudent;
  PartTimeStudent* man3 = new PartTimeStudent;
  
  man1->whoAreYou();
  man2->whoAreYou();
  man3->whoAreYou();
  return 0;
}
```

## 동적 연결
**실제 객체에 따라 호출되는 함수가 결정**되는 방법을 **동적 연결**(dynamic binding) 이라고 한다.  
동적 연결은 실행중에 포인터가 가리키는 실제 객체의 함수가 호출된다.

C++에서는 동적연결을 구현하기 위해 **가상함수**(virtual function)를 사용한다.  
가상함수는 함수의 원형 앞에 `virtual` 키워드를 붙여 표현 한다.

위 예제의 whoAreYou()메서드를 가상함수로 바꿔보자.

```c
#include <iostream>
using namespace std;

class Person {
public:
  void sleep() {
    cout << "잠을 잡니다." << endl;
  }
  virtual void whoAreYou() { // 가상함수
    cout << "나는 사람입니다." << endl;
  }
};

class Student :public Person
{
public:
  void study() {
    cout << "공부를 합니다." << endl;
  }
  void whoAreYou() { // 명시하지 않았지만 상속의 형태로 가상함수가 됨
    cout << "나는 학생입니다." << endl;
  }
};

class PartTimeStudent : public Student
{
public:
  void work() {
    cout << "일을 합니다." << endl;
  }
  void whoAreYou() {
    cout << "나는 근로학생입니다." << endl;
  }
};

int main() {
  Person* man1 = new PartTimeStudent;
  Student* man2 = new PartTimeStudent;
  PartTimeStudent* man3 = new PartTimeStudent;
  
  man1->whoAreYou();
  man2->whoAreYou();
  man3->whoAreYou();
  return 0;
}
```
## 가상함수 동작 방식 이해

객체가 생성되면 멤버 함수는 개체 내부에 존재 하는게 아니라 객체외부의 함수가 존재하고 그 **함수를 포인터로 참조**하게 된다.

가상함수가 포함된 객체가 생성되는 경우 컴파일러는 **가상함수 테이블**(Virtual Table)을 만든다.  

```c
#include <iostream>
using namespace std;

class AAA {
public:
  virtual void func1() { 
    cout << "func1()" << endl;
  }
  virtual void func2() {
    cout << "func2()" << endl;
  }
};

class BBB : public AAA {
public:
  virtual void func1() {
    cout << "BBB::func1()" << endl;
  }
  void func3() {
    cout << "func3()" << endl;
  }
};

int main() {
  AAA* aptr = new AAA();
  aptr->func1();

  AAA* bptr = new BBB();
  bptr->func1();
  return 0;
}
```
위의 예제를 실행하면 다음 그림과 같은 가상함수 테이블이 만들어지고 실제 객체의 포인터가 가리키는 함수가 실행 되는것이다.

![가상함수 테이블 참조](/images/virtual.svg)

# 가상 소멸자

`virtual`로 선언된 소멸자를 가상 소멸자라고 한다.

소멸자의 특징을 이야기할 때 다음과 같은 특징이 있다고 했다.
> 상속으로 통해 파생클래스에 정의하는 경우 `virtual`을 지정하여 가상함수가 되도록 하는것이 좋다

다음 예제를 보고 소멸자를 가상조멸자로 지정하는 이유를 생각해 보자.

```c
#include <iostream>
#include <cstring>
using namespace std;

class Base {
  char * strBase;
public :
  Base(const char* str) {
    strBase = new char[strlen(str) + 1];
    strcpy(strBase, str);
  }
  ~Base() {
    cout << "~Base()" << endl;
    delete[] strBase;
  }
};

class Derived : public Base {
  char * strDerived;
public :
  Derived(const char* str1, const char* str2) 
    : Base(str1)
  {
    strDerived = new char[strlen(str2) + 1];
    strcpy(strDerived, str2);
  }
  ~Derived() {
    cout << "~Derived()" << endl;
    delete[] strDerived;
  }
};

int main() {
  Base* ptr = new Derived("fisrt", "second");
  delete ptr;
  return 0;
}
```

실행 결과를 보면 Base객체 포인터 이기 때문에 소멸자 호출시 Base객체의 소멸자만 호출되는 것을 알 수 있다.  

그렇기 때문에 상속을 할 때에는 기초 클래스의 소멸자를 가상함수로 해야 한다.

기초클래스의 소멸자를 가상함수로 변경해보자
```c
(...)

  virtual ~Base() {
    cout << "~Base()" << endl;
    delete[] strBase;
  }

(...)
```

# 상속관계에서 형변환 cast

상속관계에 있는 클래스들에 속하는 객체의 포인터 또는 참조 사이에 형변환이 일어날 수 있다.  
이때 *파생클래스 -> 기초클래스로 변환을 **업 캐스팅** 이라고 하고, 기초클래스 -> 파생클래스로 변환을 **다운 캐스팅** 이라고 한다.

```c
#include <iostream>
using namespace std;

class Base {
public:
  Base() {}
  virtual ~Base() {}
};

class Derived : public Base {
public:
  Derived() {}
  ~Derived() {}
};

int main() {
  Base* ptrBase1 = new Base;
  Derived* ptrDerived1 = new Derived;

  Base* ptrBase2 = ptrDerived1; // 업캐스팅
  Derived* ptrDerived2 = ptrBase1; // 다운캐스팅 : 컴파일 에러
  return 0;
}
```

업캐스팅의 경우 파생클래스의 멤버를 사용하지 못하는것 외에 문제가 없기 때문에 컴파일러에서 묵시적 형변환을 허용한다.

다운캐스팅의 경우에는 문제가 된다. 기초 클래스의 실제 객체가 파생클래스라고 하더라도 컴파일러는 이것을 알지 못하기 때문에 문제가 발생 될 수 있어서 컴파일 에러가 발생된다.

`static_cast`로 형변환을 하게 되면 에러 없이 형변환이 가능하다.  
main함수의 내용을 다음과 같이 변경해보자.

```c
(...)

int main() {
  Base* ptrBase1 = new Base;
  Derived* ptrDerived1 = new Derived;

  Base* ptrBase2 = ptrDerived1; // 업캐스팅
  Derived* ptrDerived2 = static_cast<Derived*>(ptrBase1);

  if (ptrDerived2) {
    cout << "형변환 성공" << endl;
  }
  else {
    cout << "형변환 실패" << endl;
  }
  return 0;
}
```
형변환 성공이 되지만 문제는 `ptrDerived2`가 가리키는 실제 객체가 `Base` 이기 때문에 실행중에 문제가 발생할 수 있다.  
하지만 프로그래머가 `static_cast`명령으로 굳이 변환을 요구 하였으므로 이러한 문제는 프로그래머가 책임을 져야 한다.

이러한 경우에는 `dynamic_cast`로 형변환을 하게되면 변환할 수 없는 경우에는 **널포인터**(null pointer)를 반환한다.

`static_cast` 명령을 `dynamic_cast`로 변경해보자.
```c
Derived* ptrDerived2 = static_cast<Derived*>(ptrBase1);
```
형변환을 할 수 없으므로 "형변환 실패"가 출력된다.







