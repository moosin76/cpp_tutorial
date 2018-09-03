# 예외 처리

예외란 프로그램이 수행되는 도중에 발생되는 **예외적인 상황**을 의미한다.  
몇가지 상황을 에로 들면 다음과 같다.

- 나이를 입력하는데 0보다 작은 수를 입력하는 경우
- 나눗셈을 하는데 나누는 수가 0이 되는 경우
- 주민등록 번호 13자리르 입력하라고 했는데 14자리가 입력된 경우

예외는 위의 경우 처럼 문법적인 오류가 아닌 프로그램의 논리에 맞지 않는 상황을 의미한다.

```c
#include <iostream>
using namespace std;

int main() {
  int num1, num2;
  
  cout << "두개의 수를 입력 : ";
  cin >> num1 >> num2;

  cout << "몫 : " << num1 / num2 << endl;
  cout << "나머지 : " << num1 % num2 << endl;
  return 0;
}
```
실행을하고 2번째 수입력에 0을 입력하면 프로그램이 중단된다.

## if 문을 이용한 예외 처리

다음과 같이 if문을 이용해서 예외를 처리할 수도 있다.

```c
#include <iostream>
using namespace std;

int main() {
  int num1, num2;
  
  cout << "두개의 수를 입력 : ";
  cin >> num1 >> num2;

  if (num2 == 0) {
    cout << "나누는 수는 0이 될 수 없습니다." << endl;
    cout << "프로그램을 다시 시작하세요." << endl;
    exit(1);
  } else {
    cout << "몫 : " << num1 / num2 << endl;
    cout << "나머지 : " << num1 % num2 << endl;
  }
  return 0;
}
```
하지만 if문을 사용하여 예외 처리를 하는 경우 예외처리를 위한 코드와 프로그램의 흐름을 구성하는 코드를 쉽게 구분하지 못한다.

## C++의 예외 처리 체계

C++에서 예외처리는 `try`블럭, `catch`블럭 그리고 `throw`문장으로 구성된다.

```c
#include <iostream>
using namespace std;

int main() {
  int num1, num2;

  cout << "두개의 수를 입력 : ";
  cin >> num1 >> num2;

  try { // 예외 상황이 발생할수 있는 부분
    if (num2 == 0) { 
      throw num2; // int 자료형을 던진다.
    }

    cout << "몫 : " << num1 / num2 << endl;
    cout << "나머지 : " << num1 % num2 << endl;
  }
  catch (int err) { // int 자료형을 받아서 처리한다.
    cout << "나누는 수는 " << err << "이 될 수 없습니다." << endl;
    cout << "프로그램을 다시 시작하세요." << endl;
  }
  cout << "프로그램을 종료합니다." << endl;
  return 0;
}
```
`try`블럭 내부내에서 예외가 발생하면 `throw` 문장이 던지는 자료형에 해당하는 `catch` 블럭이 실행된다.  
예외가 발생되지 않는다면 `catch`블럭은 실행되지 않는다.

