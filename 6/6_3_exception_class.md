# 예외 처리 클래스 설계

예외 처리 클래스를 설계하면 예외가 발생한 원인에 대한 정보를 보다 자세히 담을수 있다.

`Accout.h`

```c
#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <iostream>
#include <string>
using namespace std;

class DepositException {
  int money;
public:
  DepositException(int money) : money(money) {}
  void ShowException() {
    cout << "[입금불가  : " << money << "]" << endl;
  }
};

class WithdrawException {
  int balance;
  int money;
public:
  WithdrawException(int money, int balance)
    : money(money), balance(balance) {}
  void ShowException() {
    cout << "[출금불가 : " << money << ",  잔액 : " << balance << "]" << endl;
  }
};

class Account {
  string accNum; // 계좌번호
  int balance; // 잔액
public:
  Account(const char* accNum, int money)
    : balance(money), accNum(accNum) {}
  void Deposit(int money) {
    if (money <= 0) {
      DepositException exp(money); // 예외객체 생성
      throw exp; // DepositException 자료형 throw
    }
    balance += money;
  }
  void Withdraw(int money) {
    if (balance < money) {
      throw WithdrawException(money, balance);
    }
    balance -= money;
  }
  void showInfo() {
    cout << "계좌번호 : " << accNum << endl;
    cout << "잔액 : " << balance << endl;
  }
};

#endif
```

```c
#include <iostream>
using namespace std;
#include "Account.h"

int main() {
  Account acc("12345-6-789012", 10000);

  try {
    acc.Deposit(5000);
    acc.Deposit(-200);
  }
  catch (DepositException &e) {
    e.ShowException();
  }

  acc.showInfo();
  cout << endl;

  try {
    acc.Withdraw(4000);
    acc.Withdraw(30000);
  }
  catch (WithdrawException &e) {
    e.ShowException();
  }
  acc.showInfo();
  return 0;
}
```

# 예외 처리 클래스 상속

예외 처리 클래스도 상속받을수 있다.

`Account.h`
```
(...)

// AccountException 추상 클래스를 만든다.
class AccountException {
public:
  virtual void ShowException() = 0;
};

// 추상클래스를 상속 받는다.
class DepositException : public AccountException {
  (...)
};

// 추상클래스를 상속 받는다.
class WithdrawException : public AccountException {
  (...)
};

(...)

```

main 함수의 try~catch블럭을 다음과 같이 단순화할 수 있다.

```
try {
  (...)
}
catch (AccountException &e) {
  (...)
}
```

전체 코드

Account.h
```
#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <iostream>
#include <string>
using namespace std;

class AccountException {
public:
  virtual void ShowException() = 0;
};

class DepositException : public AccountException {
  int money;
public:
  DepositException(int money) : money(money) {}
  void ShowException() {
    cout << "[입금불가  : " << money << "]" << endl;
  }
};

class WithdrawException : public AccountException {
  int balance;
  int money;
public:
  WithdrawException(int money, int balance)
    : money(money), balance(balance) {}
  void ShowException() {
    cout << "[출금불가 : " << money << ",  잔액 : " << balance << "]" << endl;
  }
};

class Account {
  string accNum; // 계좌번호
  int balance; // 잔액
public:
  Account(const char* accNum, int money)
    : balance(money), accNum(accNum) {}
  void Deposit(int money) {
    if (money <= 0) {
      DepositException exp(money); // 예외객체 생성
      throw exp; // DepositException 자료형 throw
    }
    balance += money;
  }
  void Withdraw(int money) {
    if (balance < money) {
      throw WithdrawException(money, balance);
    }
    balance -= money;
  }
  void showInfo() {
    cout << "계좌번호 : " << accNum << endl;
    cout << "잔액 : " << balance << endl;
  }
};

#endif
```

`main.cpp`
```c
#include <iostream>
using namespace std;
#include "Account.h"

int main() {
  Account acc("12345-6-789012", 10000);

  try {
    acc.Deposit(5000);
    acc.Deposit(-200);
  }
  catch (AccountException &e) {
    e.ShowException();
  }

  acc.showInfo();
  cout << endl;

  try {
    acc.Withdraw(4000);
    acc.Withdraw(30000);
  }
  catch (AccountException &e) {
    e.ShowException();
  }
  acc.showInfo();
  return 0;
}
```