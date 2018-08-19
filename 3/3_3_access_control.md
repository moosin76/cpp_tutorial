# protected

가시성 지시어 `protected`에 대해 다음과 같이 설명하였다.
> 상속 관계에 놓였을때 파생클래스에서 접근 허용

파생클래스는 상속을 통해 기초 클래스의 멤버를 상속받는다.  
이때 상속을 받는다고 하더라도 `private` 멤버에는 직접적인 접근을 허용하지 않는다.  
`public` 멤버는 어디에서나 접근이 가능하기 때문에 외부의 접근은 차단하고 파생클래스에서 직접적인 접근을 허용할 때 `protected` 지시어를 사용하여 멤버를 구성한다.

```c
#include <iostream>
using namespace std;

class Base {
private:
  int privateNum;
protected:
  int protectedNum;
public :
  int publicNum;
  Base() {
    privateNum = 10;
    protectedNum = 20;
    publicNum = 30;
  }
};

class Derived : public Base
{
public :
  void showBaseNum() {
    // cout << privateNum;; // 컴파일 에러
    cout << protectedNum;
    cout << publicNum;
  }
};

int main() {
  Derived obj;  
  obj.showBaseNum();  
  cout << endl;
  // cout << obj.protectedNum; // 컴파일 에러  
  cout << obj.publicNum;  
  return 0;
}
```

가시성 지시어의 접근 범위

가시성 지시어| 접근 범위
---|---
**private** | <ul><li>소속클래스</li><li>친구 클래스 및 친구 함수</li></ul>
**protected** | <ul><li>소속클래스</li><li>친구 클래스 및 친구 함수</li><li>파생 클래스</li><li>파생클래스의 친구 클래스 및 친구 함수</li></ul>
**private** | <ul><li>모든 범위</li></ul>

# 가시성 상속

클래스를 상속할때에 가시성 지시어를 지정하게 되어 있다. 기본값은 (private)

가시성 상속은 기초 클래스로 부터 상속받은 멤버가 파생 클래스의 멤버로 가지게 되는 가시성 상한을 나타낸다.

## private 상속
```c
class Derived : private Base {
  (...)
}
```
기초 클래스의 멤버 접근 상한이 private 이다.
기초 클래스의 public, protected 멤버가 private 접근 범위로 변경된다.  

모든 멤버에 대해 접근할 수 없으므로 사실상 의미없는 상속이 된다.

## protected 상속
```c
class Derived : protected Base {
  (...)
}
```
기초 클래스의 멤버 접근 상한이 protected 이다.  
기초 클래스의 public 멤버가 protected 접근 범위로 변경된다.

위의 예제를 protected 상속으로 변경하면  다음 문장에서 컴파일 에러가 발생한다.

```c
cout << obj.publicNum;

```
기초 클래스의 `publicNum` 변수가 *protected* 접근 권한을 갖게 되어 외부에서 접근 할 수 없게 된다. 

## public 상속
```c
class Derived : public Base {
  (...)
}
```
기초 클래스의 멤버 접근 상한이 public 이므로 어떠한 변화도 없이 사용이 가능하다.  

**특별한 경우를 제외하고 `public` 상속만 사용하자.**