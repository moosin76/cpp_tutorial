# 생성자(constructor)
생성자란 객체가 만들어진 직후 자동으로 호출되는 함수이며 단 한번만 호출되어진다.  
일반적으로 멤버 변수의 값을 초기화 하는등의 기능을 구현한다.

### 생성자의 특징
- 생성자의 이름은 클래스의 이름과 같다
- 생성자는 반환자료형이 없고, return 명령으로 값을 반환할 수 없다.
- 일반적으로 생성자는 public으로 선언한다.

생성자 함수도 함수오버로딩이 가능합니다.

### 생성자의 기본적인 선언 형식

```c
class ClassName {
  (...)

public: 
  ClassName() { (...) } // 생성자 함수
  ClassName(params) { (...) } // 생성자 함수 다중정의 가능
  
  (...)
};
```

# 기본 생성자
객체 생성시에는 반드시 하나의 생성자가 호출 되어야 합니다.  
하지만 구매자 클래스나 판매자 클래스에는 생성자가 없습니다.  
이렇게 생성자가 하나도 없다면 컴파일러가 기본생성자를 생성합니다.  
기본생성자는 다음과 같은 형태가 됩니다.

```c
class Seller {
  (...)
public:
  Seller() {} // 기본생성자
  (...)
};
```
기본생성자는 어떠한 매개변수도 받지 않고 어떠한 동작도 하지 않습니다.

# 과일장수 시뮬레이터에 생성자 추가하기

`Seller.h`  
`initMemers()` 관련 코드를 삭제 합니다.
```c
#ifndef __SELLER_H__
#define __SELLER_H__

class Seller
{
  int APPLE_PRICE;
  int numOfApple;
  int myMoney;
public:
  Seller(int price, int num); // 생성자 함수 선언
  int saleApples(int money);
  void showStatus() const;
};

#endif
```

`Seller.cpp`  
`initMemers()` 관련 코드를 삭제 합니다.
```c
#include <iostream>
#include "Seller.h"
using namespace std;

Seller::Seller(int price, int num) {
  APPLE_PRICE = price;
  numOfApple = num;
  myMoney = 0;
}

int Seller::saleApples(int money) {
  int num = money / APPLE_PRICE;
  numOfApple -= num;
  myMoney += money;
  return num;
}

void Seller::showStatus() const {
  cout << "남은 사과 : " << numOfApple << endl;
  cout << "판매 수익 : " << myMoney << endl;
}
```

`Buyer.h`  
`initMemers()` 관련 코드를 삭제 합니다.

```c
#ifndef __BUYER_H__
#define __BUYER_H__
#include "Seller.h"

class Buyer
{
  int myMoney;
  int numOfApple;
public:
  Buyer(int money); // 생성자 함수
  void buyApples(Seller &seller, int money);
  void showStatus() const;
};

#endif
```

`Buyer.cpp`  
`initMemers()` 관련 코드를 삭제 합니다.

```c
#include <iostream>
#include "Buyer.h"
using namespace std;

Buyer::Buyer(int money) {
  myMoney = money;
  numOfApple = 0;
}

void Buyer::buyApples(Seller &seller, int money) {
  numOfApple += seller.saleApples(money);
  myMoney -= money;
}

void Buyer::showStatus() const {
  cout << "사과 개수 : " << numOfApple << endl;
  cout << "현재 잔액 : " << myMoney << endl;
}
```

`main.cpp`  
동적할당 방식의 코드를 일반 변수선언 방식으로 바꾸겠습니다.  
생성자를 통해 변수를 생성합니다.

```c
#include <iostream>
using namespace std;
#include "Seller.h"
#include "Buyer.h"

int main() {
  Seller seller(1000,20); // 변수선언할 때 생성자함수의 매개변수를 전달합니다.
  Buyer buyer(20000);
  
  buyer.buyApples(seller, 5000); 
  
  cout << "판매자 현황" << endl;
  seller.showStatus();
  cout << endl << "구매자 현황" << endl;
  buyer.showStatus();
  return 0;
}
```

# 초기화 리스트와 const 멤버 변수
판매자 클래스의 멤버 변수 `APPLE_PRICE`는 처음 생성될때 값이 설정되고 프로그램 실행 중간에 값이 변하면 안됩니다.  
그렇기 때문에 이것을 상수화 시키려면 `const` 키워드를 사용하여 다음과 같이 해야 합니다.

`Seller.h`  
```
(...)

const int APPLE_PRICE;

(...)
```
문제는 이렇게 상수화가된 멤버의 경우 생성자 함수 내부에서 조차 상수이기 때문에 값을 변경할 수 없습니다.
이러한 경우에 초기화 리스트(Member Initializer)를 사용하여 상수를 초기화 합니다.

`Seller.cpp` 에서 다음과 같이 생성자 함수를 변경합니다.

```c
(...)

Seller::Seller(int price, int num) 
  : APPLE_PRICE(price)
{
  numOfApple = num;
  myMoney = 0;
}

(...)
```

초기화 리스트는 함수의 머리부분 끝애 : 하고 `맴버변수(초기화값)` 형태로 작성하며 여러개를 할 경우 , 로 연결합니다.

`Seller.cpp` 에서 다음과 같이 생성자 함수를 변경합니다.

```c
(...)

Seller::Seller(int price, int num) 
  : APPLE_PRICE(price), numOfApple(num), myMoney(0)
{
  // 초기화 리스트로 모두 초기화
}

(...)
```

*구매자 클래스도 초기화 리스트에서 값을 초기화 하도록 변경해보세요.*

# 초기화 리스트와 참조자

초기화 리스트의 특징을 활용하여 멤버변수로 참조자변수 선언하는것도 가능합니다.

```c
#include <iostream>
using namespace std;

class AAA {
public:
  AAA() {
    cout << "AAA 객체 생성" << endl;
  }
  void showMe() const {
    cout << "AAA 클래스 입니다" << endl;
  }
};

class BBB {
  AAA &ref;
  const int &num;
public:
  BBB(AAA &r, const int &n)
    :ref(r), num(n) // 초기화 리스트를 사용하면 참조자도 객체생성시 초기화 
  {
    cout << "BBB 객체 생성" << endl;
  }
  void showMe() const {
    ref.showMe();
    cout << "BBB 객체의 num : " << num << endl;
  }
};

int main() {
  AAA obj1;
  BBB obj2(obj1, 20);
  obj2.showMe();
  return 0;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)