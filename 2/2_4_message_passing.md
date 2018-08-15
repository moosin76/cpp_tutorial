# 객체간의 상호작용(message passing)
객체와 객체간의 서로 필요한 기능을 실행하기 위해 상대 객체의 기능을 실행하도록 요구하는 것을 메세지를 보낸다고 한다.

이번에는 과일장수 클래스와 구매자 클래스를 구현해보고 클래스간의 상호작용을 해보도록하겠습니다.

# 과일장수 클래스

#### 과일장수 클래스의 속성

속성 | 설명
---|---
int APPLE_PRICE | 사과의 가격
int numOfApple | 사과 개수
int myMoney | 돈

#### 과일장수 클래스의 메서드

메서드 | 설명
---|---
initMembers() | 멤버 변수를 초기값을 설정합니다.
saleApples() | 사과를 판매합니다.
showStatus() | 사과의 개수와 금액을 출력합니다.

`Seller.h`
```c
#ifndef __SELLER_H__
#define __SELLER_H__

class Seller
{
  int APPLE_PRICE;
  int numOfApple;
  int myMoney;
public:
  void initMembers(int price, int num);
  int saleApples(int money);
  void showStatus();
};

#endif
```

`Seller.cpp`
```c
#include <iostream>
#include "Seller.h"
using namespace std;

void Seller::initMembers(int price, int num) {
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

void Seller::showStatus() {
  cout << "남은 사과 : " << numOfApple << endl;
  cout << "판매 수익 : " << myMoney << endl;
}
```

# 구매자 클래스

#### 구매자 클래스 속성

속성 | 설명
---|---
int myMoney | 돈
int numOfApple | 사과 개수

#### 구매자 클래스 메서드

메서드 | 설명
---|---
initMembers() | 멤버 변수를 초기값을 설정합니다.
buyApples() | 사과를 구매합니다.
showStatus() | 사과의 개수와 금액을 출력합니다.

`Buyer.h`

```c
#ifndef __BUYER_H__
#define __BUYER_H__
#include "Seller.h"

class Buyer
{
  int myMoney;
  int numOfApple;
public:
  void initMembers(int money);
  void buyApples(Seller &seller, int money);
  void showStatus();
};

#endif
```

`Buyer.cpp`

```c
#include <iostream>
#include "Buyer.h"
using namespace std;

void Buyer::initMembers(int money) {
  myMoney = money;
  numOfApple = 0;
}

void Buyer::buyApples(Seller &seller, int money) {
  numOfApple += seller.saleApples(money);
  myMoney -= money;
}

void Buyer::showStatus() {
  cout << "사과 개수 : " << numOfApple << endl;
  cout << "현재 잔액 : " << myMoney << endl;
}
```

# 객체간의 상호작용(Message Passing)

객체 생성은 `일반적인 변수 선언 방식`과 `동적할당 방식(포인터)`으로 두가지가 존재 한다.  
`main.cpp` 예제에서 주석으로 설명합니다.

`main.cpp`
```c
#include <iostream>
using namespace std;
#include "Seller.h"
#include "Buyer.h"

int main() {
  Seller seller; // 일반적인 변수 선언 방식(스택)
  seller.initMembers(1000, 20); // 일반변수이므로 .로 접근
    
  Buyer* buyer = new Buyer(); // 동적 할당방식(힙)
  buyer->initMembers(20000); // 포인터이므로 ->로 접근

  buyer->buyApples(seller, 5000); // 5천원만큼 사과 구매
  
  cout << "판매자 현황" << endl;
  seller.showStatus();
  cout << endl << "구매자 현황" << endl;
  buyer->showStatus();
  return 0;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)