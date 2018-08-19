# 추상 클래스(Abstract Class)

기초클래스의 일부 메서드으 구체적 구현이 없는 순수 가상함수를 (Pure Virtual Function) 포함하는 클래스이다.  
추상 클래스로는 객체를 직집 정의 할 수 없고, 파생 클래스를 통해서 객체를 구현해야 한다.

## 순수가상함수

순수 가상함수는 실제 구현이 없는 가상함수이다.  
순수 가상함수 선언방법은 다음과 같이 함수의 선언 끝에 `= 0`을 붙여준다.

```c
virtual ReturnType FunctionName(Params) = 0;
```

```c
#include <iostream>
using namespace std;

class Person {
public:
  virtual void myAction() = 0; // 순수가상함수
  void startAction() {
    cout << "Good morning!" << endl;
    myAction();
    cout << "Sleep!" << endl;
  }
};

class Student : public Person {
public:
  virtual void myAction() {
    cout << "Study ..." << endl;
  }
};

class Employee : public Person {
public:
  void myAction() {
    cout << "Work ..." << endl;
  }
};

int main() {
  Person* man1 = new Student;
  Person* man2 = new Employee;

  man1->startAction();
  cout << endl;
  man2->startAction();
  return 0;
}
```

예제에서 처럼 Person 클래스는 순수 가상함수를 포함하기 때문에 직접 객체를 생성하면 안됩니다.

순수가상함수가 없고, 기초클래스로부터 상속받은 순수가상함수를 모두 재정의한 클래스를 **상세 클래스**라고 합니다.  
예제에서는 Student와 Employee클래스가 상세 클래스입니다.

기초 클래스의 포인터는 파생클래스객체를 가리킬 수 있으므로 29, 30행 문장이 가능합니다.  
그리고 Person 클래스의 순수 함수 myAction을 호출하면 실제 호출되는 함수는 상세 클래스의 myAction 함수가 호출 됩니다.

## 다형성 

위의 예제에서처럼 같은 함수가 호출되더라도 그 동작이 달라지는 특성이 있다.  
이러한 특성을 다형성(polymorphism)이라고 한다.