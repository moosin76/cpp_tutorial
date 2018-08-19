# 기본 대입연산자
잠시 복사생성자에 대해 복습합니다.  
복사생성자는 다음과 같은 특성이 있다.

- 정의하지 않으면 기본 복사 생성자가 삽입된다.
- 기본 복사생성자는 얕은복사를 진행한다.
- 동적할당을 하는 멤버가 있을 경우 깊은복사를 하기위해 직접 정의해야 한다.

대입연산자도 다음과 같은 특성이 있다.

- 정의하지 않으면 **기본 대입연산자** 가 삽입된다.
- 기본 대입연산자는 얕은복사를 진행한다.
- 동적할당을 하는 멤버가 있을 경우 깊은복사를 하기위해 직접 정의해야 한다.

앞서 복사생성자와 같은 문제가 발생하므로 객체 맴버중에 동적할당을 하여 깊은 복사가 필요한 경우에 대입연산자를 다중정의 해야 한다.

## 기본 대입연산자의 문제점

```c
#include <iostream>
#include <cstring>
using namespace std;

class Person {
  char *name;
  int age;
public :
  Person() : age(0){
    name = NULL; // 빈객체가 소멸될때 에러가 delete연산을 막음
  }
  Person(const char* name, int age)
    : age(age)
  {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  ~Person() {
    cout << name << " ~Person() 호출" << endl;
    delete[] name;
  }

  void showInfo() {
    cout << "이름 : " << name << endl;
    cout << "나이 : " << age << endl;
  }
};

int main() {
  Person man1("남기용", 43);
  Person man2;

  man2 = man1;
  man1.showInfo();
  man2.showInfo();
  return 0;
}
```
기본 대입연산자는 앝은복사를 진행하기 때문에 멤버변수 `name`이 동적할당되어 소멸자에 의해서 두번 삭제가 되기 때문에 오류가 발생된다.  

## 대입연산자 오버로딩

다음과 같이 Person 객체에 대입연산자 오버로딩을 하여 문제를 해결할 수 있다.
```
Person& operator=(const Person& ref) {
  age = ref.age; // 정적멤버는 일반 대입한다.

  delete[] name; // 메모리 누수를 막기위한 메모리 해제
  name = new char[strlen(ref.name) + 1]; // 새로 할당받는다
  strcpy(name, ref.name);
  return *this;
}
```

# 상속구조에서 대입연산자 호출

파생 클래스의 대입연산자에서 명시하지 않으면 기초클래스의 대입연산자는 호출되지 않는다.
```c
#include <iostream>
#include <cstring>
using namespace std;

class Person {
  char *name;
  int age;
public :
  Person() : age(0){
    name = NULL; 
  }
  Person(const char* name, int age)
    : age(age)
  {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  virtual ~Person() {
    delete[] name;
  }

  virtual void showInfo() {
    cout << "이름 : " << name << endl;
    cout << "나이 : " << age << endl;
  }

  Person& operator=(const Person& ref) {
    age = ref.age;

    delete[] name;
    name = new char[strlen(ref.name) + 1];
    strcpy(name, ref.name);
    return *this;
  }
};

class Student : public Person {
  char * school;
public :
  Student() {
    school = NULL;
  }

  Student(const char* name, int age, const char* school) 
    : Person(name, age)
  {
    this->school = new char[strlen(school) + 1];
    strcpy(this->school, school);
  }

  ~Student() {
    delete[] school;
  }

  virtual void showInfo() {
    Person::showInfo();
    cout << "학교 : " << school << endl;
  }

  Student& operator=(Student& ref) {
    delete[] school;
    school = new char[strlen(ref.school) + 1];
    strcpy(school, ref.school);
    return *this;
  }
};

int main() {
  Student man1("남기용", 43, "방송통신대학교");
  Student man2;

  man2 = man1;
  man1.showInfo();
  man2.showInfo();
  return 0;
}
```

Student 클래스의 `operator=`함수에서 Person 클래스의 대입이 이루어 지지 않기 때문에 `man2.name`은 NULL 값을 가지게 될 것이다.  
이러한경우 명시적으로 Person객체의 대입연산자를 호출하여야 한다.

Studend 클래스의 대입연산자를 다음과 같이 변경하자.

```c
Student& operator=(Student& ref) {
  Person::operator=(ref); // 기초 클래스의 대입연산자 호출

  delete[] school;
  school = new char[strlen(ref.school) + 1];
  strcpy(school, ref.school);
  return *this;
}
```




