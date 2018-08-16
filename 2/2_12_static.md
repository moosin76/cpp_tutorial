# static

# C언어의 static

먼저 C언어에서 static에 대해서 정리해보면

지역변수에서 선언된 static:
> 한번만 초기화 되고 지역변수와 달리 함수가 종료되어도 소멸되지 않음

전역변수에서 선언된 static:
> 선언된 파일내에서만 접근이 가능함

# static 멤버변수 (클래스 변수)

전체 클래스에서 하나만 존재하고 클래스의 객체들이 공유하는 변수이다.  
다음은 객체가 생성될때 전체 생성된 객체를 카운트 합니다.

```c
#include <iostream>
using namespace std;

class Simple {
  static int objCount;
public :
  Simple() {
    objCount++;
    cout << objCount << "번째 객체 : 생성" << endl;
  }
  Simple(const Simple& copy) {
    objCount++;
    cout << objCount << "번째 객체 : 복사생성" << endl;
  }
};
// static 변수의 초기화
int Simple::objCount = 0;

int main() {
  Simple obj1;
  Simple obj2 = obj1;
  return 0;
}
```
위의 코드처럼 **static 변수의 초기화는 class 외부에서 해야 한다**.  
만약 생성자 함수에서 static변수를 초기화 한다면 매번 객체가 생성될때 마다 초기화 될것이다.  
생성자에서 static 변수를 초기화하면 컴파일 에러가 발생한다.

## static 변수의 다른 접근 방법
위의 Simple클래스의 static 변수는 private로 선언되어 클래스 내부에서만 접근이 가능하다.  
하지만 public으로 선언되면 클래스의 이름 또는 객체의 이름을 통해 어디서든 접근이 가능하다.

```c
#include <iostream>
using namespace std;

class Simple {
public:
  static int objCount; // public 에서 선언

  Simple() {
    objCount++;
    cout << objCount << "번째 객체 : 생성" << endl;
  }
  Simple(const Simple& copy) {
    objCount++;
    cout << objCount << "번째 객체 : 복사생성" << endl;
  }
};
// static 변수의 초기화
int Simple::objCount = 0;

int main() {
  Simple obj1;
  Simple obj2 = obj1;

  cout << "Simple 객체는 총 " << Simple::objCount << "개 생성됨" << endl;
  cout << "Simple 객체는 총 " << obj1.objCount << "개 생성됨" << endl;
  cout << "Simple 객체는 총 " << obj2.objCount << "개 생성됨" << endl;

  return 0;
}
```

static 변수는 `Simple::objCount` 형태로 접근이 가능하다.  
당연하게도 `obj1.objCount` 형태로도 접근이 가능하다.

# static 멤버함수

static 멤버함수의 특성 역시 static 멤버변수의 특성과 동일하다.

- 선언된 클래스의 모든 객체가 공유한다.
- public으로 선언하면 클래스이름을 이용해 호출이 가능하다.
- 객체 맴버로 존재하는것이 아니다.

위와 같은 특성때문에 static 멤버함수에서는 객체멤버 변수에는 접근할 수 없다.

```c
#include <iostream>
using namespace std;

class Simple {
  static int sNum;
  int mNum;
public:
  Simple(int num = 0) : mNum(num) {}
  static void Adder(int n) {
    sNum += n;
    // mNum += n; // 컴파일 에러
  }
  void add(int n) {
    sNum += n;
    mNum += n;
  }

  void display() {
    cout << "static 변수 : " << sNum << endl;
    cout << "멤버 변수 : " << mNum << endl;
  }
};
int Simple::sNum = 5;

int main() {
  Simple obj1(10);
  Simple obj2(200);
  
  obj1.add(5);
  Simple::Adder(10);
  cout << "obj1 : " << endl;
  obj1.display();
  cout << endl << "obj2 : " << endl;
  obj2.display();
  return 0;
}
```

# const static 멤버변수
const 변수는 초기화 리스트에서 초기화를 한다고 했다.  
하지만 const static 변수는 다음과 같이 선언과 동시에 초기화가 가능하다.  
(정수 자료형만 가능함)

```c
#include <iostream>
using namespace std;

class myData {
public :
  const static int AGE = 43;
  const static int WEIGHT = 77;
};

int main() {
  cout << myData::AGE << endl;
  cout << myData::WEIGHT << endl;
  return 0;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)