# 파생클래스의 생성자 및 소멸자

## 생성자

위의 예제에서도 보았듯이 파생 클래스의 생성자함수 초기화 리스트에서 기초 클래스의 생성자를 호출한다.

파생 클래스에서 명시적으로 기초 클래스의 생성자 함수를 호출하지 않더라도 암묵적으로 기초클래스의 생성자 함수가 호출된다.

## 소멸자 

소멸자도 생성자와 마찬가지로 파생클래스의 객체가 소멸될때 기초클래스의 소멸자가 호출된다.

다음 예제에서 생성자와 소멸자의 호출을 살펴보자

```c
#include <iostream>
using namespace std;

class Base {
  int baseNum;
public :
  Base() 
    :baseNum(20) 
  {
    cout << "Base() 생성자 호출 : " << baseNum << endl;
  }

  Base(int num) 
    : baseNum(num) 
  {
    cout << "Base(int num) 생성자 호출 : " << baseNum << endl;
  }

  ~Base() {
    cout << "~Base() 소멸자 호출 : " << baseNum << endl;
  }
};

class Derived : public Base
{
  int derivedNum;
public :
  Derived() 
    : derivedNum(50) 
  {
    cout << "Derived() 생성자 호출 : " << derivedNum << endl;
  }

  Derived(int num) 
    : Base(num), derivedNum(num) 
  {
    cout << "Derived(int num) 생성자 호출 : " << derivedNum << endl;
  }

  ~Derived() {
    cout << "~Derived() 소멸자 호출 : " << derivedNum << endl;
  }
};

int main() {
  cout << "case 1 ........." << endl;
  Derived obj1;

  cout << endl;
  cout << "case 2 ........." << endl;
  Derived obj(15);

  cout << endl;
  cout << "프로그램 종료............" << endl;
  return 0;
}
```

28행 ~ 32행의 어떠한 인자도 받지 않는 생성자 호출시 암묵적으로 기초 클래스의 생성자가 호출되는 것을 알 수 있다.

먼저 기초클래스가 먼저 생성되고 파생 클래스가 생성되며, Stack 구조처럼 파생클래스가 먼저 소멸되고 기초 클래스가 소멸된다.